"""
GUI Front end for uploading firmware/bootloader/etc on Rep2/Rep2X Mightyboard
Best Used on smaller screens with Raspberry Pi, but can be used in any terminal

Limited screen output. Decrypts/shows AVRdude error messages for user and only shows progress/pass fail.

Subprocess calls taken from load_firmware.sh (Thanks Bill Canfield)

Author: Geoff Von Allmen
"""

import logging
import curses
import subprocess
import textwrap
import os
import sys
import fcntl
import time
import datetime

from optparse import OptionParser

# Default file name/port numbers
REP2_FILENAME = "mighty_two_rep2_v7.6.0.hex"        # Rep2 FW Filename
REP2X_FILENAME = "mighty_two_rep2x_v7.6.0.hex"      # Rep2X FW Filename
BREAK_ON_FAIL = True                                # False-> Completes all steps regardless of previous step pass/fail
                                                    # True -> Only moves on if current step passes
LOG_LEVEL = logging.INFO                            # Logging Level

class ProgramWrapper:
    """
    NOTE: All coordinates for curses are y, x (rows, cols)
    """

    def __init__(self, stdscr, port):
        # Setup logging
        logging.basicConfig(level=LOG_LEVEL,
                            format='%(asctime)s.%(msecs)d:%(levelname)-8s>>>%(message)s',
                            datefmt='%y-%m-%d %H:%M:%S',
                            filename='rep2_2x_upload_fw.log',
                            filemode='a')
        self.log = logging.getLogger(__name__)
        self.log.info("\n")
        self.port = port
        self.log.info("Break on Fail: {}".format(BREAK_ON_FAIL))

        # Get terminal size
        self.rows, self.cols = self.get_size()

        # Initiate basic colors
        curses.init_pair(1, curses.COLOR_BLACK, curses.COLOR_CYAN)
        curses.init_pair(2, curses.COLOR_BLACK, curses.COLOR_YELLOW)
        curses.init_pair(3, curses.COLOR_BLACK, curses.COLOR_WHITE)
        curses.init_pair(4, curses.COLOR_GREEN, curses.COLOR_BLACK)
        curses.init_pair(5, curses.COLOR_RED, curses.COLOR_BLACK)

        # Disable Cursor visibility and get screen
        curses.curs_set(0)
        self.stdscr = stdscr
        self.stdscr.refresh()

    def get_size(self):
        """
        Gets and returns the console size (Validated on Linux/Raspberry Pi)
        :return: (int, int) Rows, Columns
        """
        rows, columns = os.popen('stty size', 'r').read().split()
        self.log.debug("Rows: {0}, Cols: {1}".format(rows, columns))
        return int(rows), int(columns)

    def create_info_window(self):
        """
        Creates window to show directions/status updates
        :return: (curses.window)
        """
        # Create and position a 'back box' to allow user to go back to product selection
        window_start_y = 4
        window_start_x = 1
        window_height = self.rows-window_start_y-1
        window_width = self.cols - 2
        window = curses.newwin(window_height, window_width, window_start_y, window_start_x)
        return window

    def draw_background_window(self, product):
        """
        Draws a background window with product title at the top
        :param product: (String) Product name for screen title
        :return: None
        """
        # Clear the screen and set the background to the appropriate color with a title
        self.stdscr.erase()
        if product == 'Rep2':
            self.stdscr.bkgd(' ', curses.color_pair(1))
        elif product == 'Rep2X':
            self.stdscr.bkgd(' ', curses.color_pair(2))
        self.addstr_cen(product, self.stdscr, start_y=0)
        self.stdscr.refresh()

    def addstr_cen(self, message, window, start_y=None, attr=''):
        """
        Adds a string, centered vertically/horizontally in the window (unless start_y specified)
        Will wrap text if length is longer than the window width
        :param message: (String) Message to be displayed
        :param window: (curses.window) Window to add string to
        :param attr: (curses.attribute) Curses attribute to apply to text
        :return: None
        """
        height, width = window.getmaxyx()

        # Break lines into list
        lines = textwrap.wrap(message, width)

        # Find y center position if not given
        if start_y is None:
            start_y = (height - 1) / 2

        # Print each line in lines list
        for i in range(0, len(lines)):
            start_x = (width - len(lines[i])) / 2
            if attr:
                window.addstr(start_y + i, start_x, lines[i], attr)
            else:
                window.addstr(start_y + i, start_x, lines[i])

    def program_entry(self, product):
        """
        Displays main screen before programming starts
        :param product: (String) Product you're going to program (Rep2/Rep2X) - selects window color/title
        :return: None
        """

        # Initialize start screen with inner window and back window
        self.draw_background_window(product)
        inner_window = curses.newwin(self.rows-2, self.cols-2, 1, 1)
        self.addstr_cen("Press Enter to start", inner_window)
        inner_window.refresh()
        info_window = self.create_info_window()
        previous_result = None

        # Choose programming file
        if product == 'Rep2':
            filename = REP2_FILENAME
        else:
            filename = REP2X_FILENAME

        self.log.info("FW Filename: {}".format(filename))

        # Wait for enter key to start programming
        while True:
            self.log.info("Beginning programming sequence...")
            start_time = datetime.datetime.now()
            inner_window.erase()
            self.addstr_cen("Press Enter to Begin", inner_window, start_y=2)
            # Not executed first time through
            if previous_result is not None:
                self.addstr_cen("Previous Result:", info_window)
                if previous_result:
                    color = curses.color_pair(4)
                    msg = 'PASS'
                else:
                    color = curses.color_pair(5)
                    msg = 'FAIL'
                previous_result_y = info_window.getmaxyx()[0] / 2 + 1
                self.addstr_cen(msg, info_window, start_y=previous_result_y, attr=color)

            # Refresh windows and wait for keypress
            inner_window.refresh()
            info_window.refresh()
            char = self.stdscr.getch()

            # Look for enter key
            if char == 10:
                # Runs programming steps sequentially and breaks if any of them fail
                if BREAK_ON_FAIL:
                    passed = self.upload_fw("82u", inner_window, info_window, y_position=0)
                    if passed:
                       passed = self.upload_fw("1280", inner_window, info_window, y_position=1)
                    if passed:
                       passed = self.upload_fw("1280 FW", inner_window, info_window, y_position=2, filename=filename)
                # Runs programming steps sequentially but continues to next if any fail
                else:
                    passed_82u = self.upload_fw("82u", inner_window, info_window, y_position=0)
                    if not passed_82u:
                        self.stdscr.getch()
                    passed_1280 = self.upload_fw("1280", inner_window, info_window, y_position=1)
                    if not passed_1280:
                        self.stdscr.getch()
                    passed_1280_fw = self.upload_fw("1280 FW", inner_window, info_window, y_position=2,
                                                    filename=filename)
                    passed = passed_82u and passed_1280 and passed_1280_fw

                # Display final pass/fail results to screen
                info_window.erase()
                if passed:
                    self.addstr_cen("PASS", info_window, attr=curses.color_pair(4))
                    info_window.refresh()

                # Store result to display on main screen again and wait for keypress to continue
                end_time = datetime.datetime.now()
                self.log.info("Programming Time: {}".format(str(end_time - start_time)))
                self.log.info("Programming Sequence Complete")

                previous_result = passed
                self.stdscr.getch()

    def upload_fw(self, program, inner_window, info_window, y_position=0, filename=None):
        """
        Executes the appropriate upload program and updates the display with user actions
        :param program: (String) Name of program to execute (or chip to program)
        :param inner_window: (curses.window) Inner window reference
        :param info_window: (curses.window) Info window reference
        :param y_position: (Int) y position of inner_window to update (0, 1, 2)
        :param filename: (String) path to file to upload (for uploading firmware)
        :return: (Bool) Whether program passed or failed
        """

        if program == '82u':
            inner_window.erase()
            inner_window.refresh()
            info_window.erase()
            self.addstr_cen("Move cable to 82U (J18) and press Enter", info_window)
            info_window.refresh()
            self.stdscr.getch()
            inner_window.addstr(y_position, 0, "[    ] Updating " + program)
            inner_window.refresh()
            result = self.program_82u(inner_window, info_window)
        elif program == '1280':
            info_window.erase()
            self.addstr_cen("Move cable to 1280 (J19) and press Enter", info_window)
            info_window.refresh()
            self.stdscr.getch()
            inner_window.addstr(y_position, 0, "[    ] Updating " + program)
            inner_window.refresh()
            result = self.program_1280(inner_window, info_window)
        elif program == '1280 FW':
            info_window.erase()
            self.addstr_cen("Plug in USB cable and press enter", info_window)
            info_window.refresh()
            self.stdscr.getch()
            inner_window.addstr(y_position, 0, "[    ] Updating " + program)
            inner_window.refresh()
            result = self.upload_firmware(filename, inner_window, info_window)

        else:
            self.log.warning("Bad program name encountered: {}".format(program))

        # If passed, show that, else show the error encountered
        if result['passed']:
            inner_window.addstr(y_position, 1, "PASS", curses.color_pair(4))
        else:
            inner_window.addstr(y_position, 1, "FAIL", curses.color_pair(5))
            self.addstr_cen(result['errors'][0], info_window)
        inner_window.refresh()
        info_window.refresh()

        return result['passed']

    def check_programming_results(self, fn_output, returncode):
        """
        Checks for known errors in the output stream and returns a more user friendly message to the user
        Prevents user from having to sift through all the avrdude output
        :param fn_output: ([String]) Output from subprocess function
        :param returncode: (Int) Return code from subprocess
        :return: (String) Interpreted error message
        """
        # Define known errors
        error = ''
        no_target_error = {'error': "Target not detected", 'response': "Programmer not connected to board or "
                                                                       "board is not powered on"}
        no_programmer_error = {'error': "did not find any USB device",
                               'response': "Programmer not connected to computer"}
        no_programmer_usb = {'error': "can't open device",
                             'response': "Programmer not connected to computer or board not powered on"}
        file_not_found_error = {'error': "can't open input file",
                                'response': "Can't find input file"}
        rst_fail_error = {'error': 'RST fail', 'response': "Make sure programmer is connected to header and "
                                                           "board is powered on"}
        verification_error = {'error': 'verification error; content mismatch',
                              'response': 'Are you connected to the right header?'}
        kernel_driver_error = {'error': 'could not detach kernel driver',
                               'response': 'Programmer not connected or board not powered on'}

        # Interpret error messages returned by avrdude - using ifs as I only want first error encountered
        # in case other text is also found
        if no_target_error['error'] in fn_output:
            error = no_target_error['response']
        elif no_programmer_error['error'] in fn_output:
            error = no_programmer_error['response']
        elif no_programmer_usb['error'] in fn_output:
            error = no_programmer_usb['response']
        elif file_not_found_error['error'] in fn_output:
            error = file_not_found_error['response']
        elif rst_fail_error['error'] in fn_output:
            error = rst_fail_error['response']
        elif verification_error['error'] in fn_output:
            error = verification_error['response']
        elif kernel_driver_error['error'] in fn_output:
            error = kernel_driver_error['response']
        elif returncode != 0:
            error = "Undocumented Error Encountered"

        return error

    def program_82u(self, inner_window, info_window):
        """
        Programs the 82U via ISP (J18) and updates display
        :param inner_window: (curses.window) Inner window reference
        :param info_window: (curses.window) Info window reference
        :return: {passed: Bool, errors: [String]} whether it passed and any errors
        """
        passed = False
        errors = []
        self.log.info("Programming 82U...")

        # Update Info Window
        info_window.erase()
        self.addstr_cen("Programming 82U...", info_window)
        info_window.refresh()

        # Program Flash
        flash1 = subprocess.Popen(['avrdude', '-p', 'at90usb82', '-F', '-P', 'usb', '-c', 'avrispmkii', '-U',
                                   'flash:w:Makerbot-usbserial-revH-rep2X.hex'],
                                  stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
        # Gets current file control flags and adds Non Blocking to it
        flags = fcntl.fcntl(flash1.stderr, fcntl.F_GETFL)
        fcntl.fcntl(flash1.stderr, fcntl.F_SETFL, flags | os.O_NONBLOCK)

        # Execute the subprocess and read results
        flash1_err = self.read_output(flash1, inner_window, denominator=751, y_position=0)
        self.log.debug("Flash1_err: {}".format(flash1_err))

        # Log Flash1 Errors
        if flash1.returncode != 0:
            self.log.error("82U Programming Error, Flash1: \n" + flash1_err)
            errors.append(self.check_programming_results(flash1_err, flash1.returncode))
        else:
            passed = True

        # Program Fuses
        if passed:
            fuse = subprocess.Popen(['avrdude', '-p', 'at90usb82', '-F', '-P', 'usb', '-c', 'avrispmkii', '-U', 'lfuse:w:0xFF:m',
                                     '-U', 'hfuse:w:0xD9:m', '-U', 'efuse:w:0xF4:m', '-U', 'lock:w:0x0F:m'],
                                    stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
            # Gets current file control flags and adds Non Blocking to it
            flags = fcntl.fcntl(fuse.stderr, fcntl.F_GETFL)
            fcntl.fcntl(fuse.stderr, fcntl.F_SETFL, flags | os.O_NONBLOCK)

            # Execute the subprocess and read results
            fuse_err = self.read_output(fuse, inner_window, numerator=150, denominator=751, y_position=0)
            self.log.debug("Fuse_err: {}".format(fuse_err))

            # Log Fuse Errors
            if fuse.returncode != 0:
                self.log.error("82U Programming Error, Fuse: \n" + fuse_err)
                errors.append(self.check_programming_results(fuse_err, fuse.returncode))
                passed = False

        # Program flash a second time - seems to create better programming reliability
        if passed:
            flash2 = subprocess.Popen(['avrdude', '-p', 'at90usb82', '-F', '-P', 'usb', '-c', 'avrispmkii',
                                       '-U', 'flash:w:Makerbot-usbserial-revH-rep2X.hex'],
                                      stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
            # Gets current file control flags and adds Non Blocking to it
            flags = fcntl.fcntl(flash2.stderr, fcntl.F_GETFL)
            fcntl.fcntl(flash2.stderr, fcntl.F_SETFL, flags | os.O_NONBLOCK)

            # Execute the subprocess and read results
            flash2_err = self.read_output(flash2, inner_window, numerator=600, denominator=751, y_position=0)
            self.log.debug("Flash2_err: {}".format(flash2_err))

            # Log Flash2 Errors
            if flash2.returncode != 0:
                self.log.error("82U Programming Error, Flash2: \n" + flash2_err)
                errors.append(self.check_programming_results(flash2_err, flash2.returncode))
                passed = False

        self.log.info("82U Passed: {}".format(passed))
        self.log.info("82U Errors: {}".format(errors))

        return {'passed': passed, 'errors': errors}

    def program_1280(self, inner_window, info_window):
        """
        Programs the 1280 via ISP, collects errors an updates display
        :param inner_window: (curses.window) Inner window reference
        :param info_window: (curses.window) Info window reference
        :return: {passed: Bool, errors: [String]} whether it passed and any errors
        """
        passed = False
        errors = []
        self.log.info("Programming 1280 Bootloader...")

        # Update info window
        info_window.erase()
        self.addstr_cen("Programming 1280...", info_window)
        info_window.refresh()

        # Program bootloader subprocess
        flash = subprocess.Popen(['avrdude', '-p', 'm1280', '-F', '-P', 'usb', '-c', 'avrispmkii',
                                  '-U', 'flash:w:ATmegaBOOT_168_atmega1280.hex', '-U', 'lfuse:w:0xFF:m',
                                  '-U', 'hfuse:w:0xDA:m', '-U', 'efuse:w:0xF4:m', '-U', 'lock:w:0x0F:m'],
                                 stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
        # Gets current file control flags and adds Non Blocking to it
        flags = fcntl.fcntl(flash.stderr, fcntl.F_GETFL)
        fcntl.fcntl(flash.stderr, fcntl.F_SETFL, flags | os.O_NONBLOCK)

        # Execute the subprocess and read results
        flash_err = self.read_output(flash, inner_window, denominator=551, y_position=1)
        self.log.debug("1280_flash_err: {}".format(flash_err))

        # Log Flash Errors
        if flash.returncode != 0:
            self.log.error("1280 ISP Error: \n" + flash_err)
            errors.append(self.check_programming_results(flash_err, flash.returncode))
        else:
            passed = True

        self.log.info("1280 Passed: {}".format(passed))
        self.log.info("1280 Errors: {}".format(errors))

        return {'passed': passed, 'errors': errors}

    def upload_firmware(self, filename, inner_window, info_window):
        """
        Uploads the FW to the 1280 handling errors and updating screen along the way
        :param filename: (String) Path to filename to upload (.hex)
        :param inner_window: (curses.window) Inner window reference
        :param info_window: (curses.window) Info window reference
        :return: {passed: Bool, errors: [String]} whether it passed and any errors
        """

        passed = False
        errors = []
        limit = 5
        count = 0
        self.log.info("Programming 1280 Firmware...")

        # In case it doesn't work, give user up to limit tries to reconnect cable and try again
        while not passed and count <= limit:
            info_window.erase()
            self.addstr_cen("Uploading 1280 Firmware...", info_window)
            info_window.refresh()

            # If port has not been specified on command line, try to get it
            if self.port == '':
                port, err = self.get_ttyacm_port()
            # port has been specified on command line, force into trying to use it
            else:
                err = None
                port = self.port
            # indicate you're doing something in case Programmer times out (which can take a few seconds)
            inner_window.addstr(2, 1, "....")
            inner_window.refresh()
            errors = []
            count += 1

            # Upload Firmware subprocess
            flash = subprocess.Popen(['avrdude', '-F', '-p', 'm1280', '-P', port, '-c', 'stk500v1', '-b', '57600',
                                      '-U', 'flash:w:' + filename], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

            # Gets current file control flags and adds Non Blocking to it
            flags = fcntl.fcntl(flash.stderr, fcntl.F_GETFL)
            fcntl.fcntl(flash.stderr, fcntl.F_SETFL, flags | os.O_NONBLOCK)

            # Execute the subprocess and read results
            flash_err = self.read_output(flash, inner_window, denominator=151, y_position=2)
            self.log.debug("1280_FW_flash_err: {}".format(flash_err))

            # If an error was returned, give opportunity to try up to limit times
            if flash.returncode != 0:
                self.log.error("Firmware USB Upload Error: \n" + flash_err)
                errors.append(self.check_programming_results(flash_err, flash.returncode))
                if count <= limit:
                    inner_window.addstr(2, 1, "ERR ", curses.color_pair(5))
                    inner_window.refresh()
                    info_window.erase()
                    self.addstr_cen("Could not connect. Replug in USB cable and "
                                    "try again. Try #{0}/{1}".format(count, limit), info_window)
                    info_window.refresh()
                    self.stdscr.getch()
            else:
               passed = True

        self.log.info("1280 FW Passed: {}".format(passed))
        self.log.info("1280 FW Errors: {}".format(errors))

        return {'passed': passed, 'errors': errors}

    def get_ttyacm_port(self):
        """
        Gets current ttyACM ports
        :return (String, String) path to ttyACM# port, Errors if any exist
        """
        # Have to use shell=True to use wildcards
        port = subprocess.Popen(r'ls /dev/ttyACM*', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        port_std, port_err = port.communicate()
        self.log.debug("Port: {}".format(port_std))
        if port_err:
            self.log.debug("Port_err: {}".format(port_err))

        return port_std.strip(), port_err.strip()

    def read_output(self, sub_process, window, denominator, y_position, numerator=0):
        """
        Used to execute an AVR Subprocess and print what % done it is by monitoring the number of
        #'s found vs the number expected (Denominator)
        Prints % done to the window in y_position.
        Optionally set numerator if you want # to start at a predetermined value
        :param sub_process: (subprocess) Subprocess you're going to execute
        :param window: (curses.window) Curses Window to print to
        :param denominator: (Int) Number of expected #'s the subprocess will return
        :param y_position: (Int) Y position in the window to print
        :param numerator: (Int) Predetermined starting count for number of # signs
        :return (String) All text returned by subprocess
        """

        count = numerator
        sub_process_output = ''
        while True:
            try:
                # Try to get a char from the output stream
                char = os.read(sub_process.stderr.fileno(), 1)
                sub_process_output += char

                # calculate % Done and print to window
                if char == '#':
                    count += 1
                    percent = str((100 * count) / (denominator + 1)) + " %"  # Make sure it never says 100% (denom + 1)
                    window.addstr(y_position, 1, percent)
                    window.refresh()
                # if this is found in output stream, break early. Avr dude will retry up to 10 times otherwise
                if "programmer is not responding" in sub_process_output:
                    break

                # TODO: Don't know if this step works yet - need to get some data to see how to fix
                # Periodically AVRDude asks about resetting fuses, force a 'y' answer if this is asked
                if "Would you like this fuse to be changed back [y/n]" in sub_process_output:
                    sub_process.write(r'y\n')
                    self.log.info("Asked if fuse should be changed back: \n" + sub_process_output)

                # Check if subprocess has returned and if so, finish reading anything left in the buffer
                if sub_process.poll() is not None:
                    char = os.read(sub_process.stderr.fileno(), 2048)
                    sub_process_output += char
                    break
            # Means buffer is empty, nothing is ready to read
            except OSError:
                time.sleep(.1)
                # Check if subprocess has returned and if so, finish reading anything left in the buffer
                if sub_process.poll() is not None:
                    char = os.read(sub_process.stderr.fileno(), 2048)
                    sub_process_output += char
                    break
        return sub_process_output


def main(stdscr, product, port):
    """
    Wrapped main procedure to start program - wrapped via curses for proper setup/teardown
    :param stdscr: (curses.window) - Passed in via curses wrapper
    :param product: (String) Name of product to program (Rep2/Rep2X)
    :param port: (String) Port Name (IE, /dev/ttyACM0)
    :return: None
    """
    c = ProgramWrapper(stdscr, port)
    while True:
        # Show Product Select Screen
        try:
            c.program_entry(product)
        except KeyboardInterrupt:
            c.log.warning("Keyboard Interrupt Detected, exiting")
            sys.exit(1)

# Program Entry
if __name__ == "__main__":
    parser = OptionParser()
    parser.add_option("-p", "--product", dest="product", type="string", default='',
                      help="Product Name (Rep2, Rep2x)")
    parser.add_option("-d", "--port", dest="port", type="string", default='',
                      help="Port Name")
    (options, args) = parser.parse_args()

    # Curses wrapper to complete proper terminal setup/teardown upon exit or unhandled program exception
    if options.product.lower() == 'rep2':
        curses.wrapper(main, 'Rep2', options.port)
    elif options.product.lower() == 'rep2x':
        curses.wrapper(main, 'Rep2X', options.port)
    else:
        print "No product specified"
        print "Please use -p Rep2 or -p Rep2x"


