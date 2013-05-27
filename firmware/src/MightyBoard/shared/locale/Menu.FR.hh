#ifndef FRENCH
#	error No French locale defined!
#endif

#ifdef MODEL_REPLICATOR
  static PROGMEM unsigned char SPLASH1_SINGLE_MSG[] = "   La Replicator    ";
  static PROGMEM unsigned char SPLASH1_DUAL_MSG[] =   "   La Replicator    ";
  static PROGMEM unsigned char SPLASH2_MSG[] =        "    ------------    ";
#elif MODEL_REPLICATOR2
  static PROGMEM unsigned char SPLASH1_SINGLE_MSG[] = "  La Replicator 2   ";
  static PROGMEM unsigned char SPLASH1_DUAL_MSG[] =   "  La Replicator 2X  ";
  static PROGMEM unsigned char SPLASH2_MSG[] =        "    ------------    ";
#else
  static PROGMEM unsigned char SPLASH1_MSG[] =        "      Makerbot      ";
  static PROGMEM unsigned char SPLASH2_MSG[] =        "    ------------    ";
#endif

static PROGMEM unsigned char SPLASH3_MSG[] =          "                    ";
static PROGMEM unsigned char SPLASH4_MSG[] =          "Firmware Version X.X";
static PROGMEM unsigned char SPLASH5_MSG[] =          "Francais, rev. : XXX";

static PROGMEM unsigned char SPLASH1A_MSG[] =         "       ECHEC!       ";
static PROGMEM unsigned char SPLASH2A_MSG[] =         "       SUCCES!      ";
static PROGMEM unsigned char SPLASH3A_MSG[] =         "     connectees.    ";
static PROGMEM unsigned char SPLASH4A_MSG[] =         " Les tetes sont mal ";
static PROGMEM unsigned char SPLASH5A_MSG[] =         "                    "; 

static PROGMEM unsigned char GO_MSG[] =               "Prechauffer !";
static PROGMEM unsigned char STOP_MSG[] =             "Refroidissement ... ";
static PROGMEM unsigned char RIGHT_TOOL_MSG[] =       "Tete de droite";
static PROGMEM unsigned char LEFT_TOOL_MSG[] =        "Tete de gauche";
static PROGMEM unsigned char PLATFORM_MSG[] =         "Plateforme";
static PROGMEM unsigned char TOOL_MSG[] =             "Extrudeur";

#ifdef MODEL_REPLICATOR2
  static PROGMEM unsigned char START_MSG[] =        "Bonjour ! Je suis   " \
                                                    "la Replicator 2.    " \
                                                    "Appuyez sur le M    " \
                                                    "rouge pour commencer";

  static PROGMEM unsigned char START_DUAL_MSG[] =   "Bonjour ! Je suis   " \
                                                    "la Replicator 2X.   " \
                                                    "Appuyez sur le M    " \
                                                    "rouge pour commencer";
#else
  static PROGMEM unsigned char START_MSG[] =        "Bonjour ! Je suis   " \
                                                    "la Replicator.      " \
                                                    "Appuyez sur le M    " \
                                                    "rouge pour commencer";
  static PROGMEM unsigned char START_DUAL_MSG[] =   "Bonjour ! Je suis   " \
                                                    "la Replicator Dual. " \
                                                    "Appuyez sur le M    " \
                                                    "rouge pour commencer";
#endif

static PROGMEM unsigned char BUTTONS1_MSG[] =       "Le 'M' clignotant   " \
                                                    "signifie en attente " \
                                                    "de commande pour    " \
                                                    "continuer.          ";
static PROGMEM unsigned char BUTTONS2_MSG[] =       "Le 'M' fixe signifie" \
                                                    "que je travaille et " \
                                                    "que de nouvelles    " \
                                                    "infos suivront ...  ";
static PROGMEM unsigned char EXPLAIN_MSG[] =        "Prochaine etape :   " \
                                                    "la configuration !  " \
                                                    "Nous allons ajuster " \
                                                    "la plateforme       ";                                  
static PROGMEM unsigned char LEVEL_MSG[] =          "de sorte qu'elle    " \
                                                    "soit au bon niveau. " \
                                                    "Le transport l'a    " \
                                                    "surement dereglee ..";
static PROGMEM unsigned char BETTER_MSG[] =         "Parfait ! Nous      " \
                                                    "allons maintenant   " \
                                                    "ajouter du filament " \
                                                    "de plastique ...    ";
static PROGMEM unsigned char TRYAGAIN_MSG[] =       "Essayons encore !   " \
                                                    "                    " \
                                                    "                    " \
                                                    "                    ";
static PROGMEM unsigned char GO_ON_MSG[]   =        "Laissons le filament" \
                                                    "se devider un peu .." \
                                                    "Besoin d'aide ? :   " \
                                                    "  makerbot.com/help ";     
static PROGMEM unsigned char SD_MENU_MSG[] =        "Parfait !           " \
                                                    "Allons dans le menu " \
                                                    "de la carte SD pour " \
                                                    "choisir un objet.   ";
static PROGMEM unsigned char FAIL_MSG[] =           "Allons au menu      " \
                                                    "principal           " \
                                                    "Besoin d'aide ? :   " \
                                                    "  makerbot.com/help ";
static PROGMEM unsigned char START_TEST_MSG[]=      "Je vais imprimer une" \
                                                    "serie de lignes pour" \
                                                    "pouvoir ajuster mes " \
                                                    "buses d'impression.."; // XXX old name: start[]
static PROGMEM unsigned char EXPLAIN1_MSG[] =       "Choisir le meilleur " \
                                                    "resultat pour chaque" \
                                                    "axe. Les lignes sont" \
                                                    "numerotees de 1 a 13";
static PROGMEM unsigned char EXPLAIN2_MSG[] =       "et la premiere est  " \
                                                    "plus longue.        " \
                                                    "Axe des Y : a gauche" \
                                                    "Axe des X : a droite";
static PROGMEM unsigned char END_MSG  [] =          "Super ! Parametres  " \
                                                    "enregistres. Je vais" \
                                                    "puvoir imprimer de  " \
                                                    "beaux modeles !     ";

static PROGMEM unsigned char SELECT_MSG[] =         "    Selectionnez    " \
                                                    "les meilleurs lignes";

static PROGMEM unsigned char DONE_MSG[]   = "Fini !";
static PROGMEM unsigned char NO_MSG[]     = "Non   ";
static PROGMEM unsigned char YES_MSG[]    = "Oui   ";

static PROGMEM unsigned char XAXIS_MSG[]  = "Axe des X";
static PROGMEM unsigned char YAXIS_MSG[]  = "Axe des Y";

static PROGMEM unsigned char HEATER_ERROR_MSG[] =   "Mes extrudeurs ne   " \
                                                    "chauffent pas.      " \
                                                    "Verifiez bien les   " \
                                                    "connexions !        ";

#ifdef MODEL_REPLICATOR2
  static PROGMEM unsigned char EXPLAIN_ONE_MSG[] =  "Je chauffe mes      " \
                                                    "extrudeurs pour     " \
                                                    "charger le filament." \
                                                    "Attention, les buses";
  static PROGMEM unsigned char EXPLAIN_TWO_MSG[] =  ".. sont brulantes ! " \
                                                    "Pendant la chauffe, " \
                                                    "enlevez le tube qui " \
                                                    "guide le filament ..";
  static PROGMEM unsigned char EXPLAIN_ONE_S_MSG[]= "Je chauffe mon      " \
                                                    "extrudeur pour      " \
                                                    "charger le filament." \
                                                    "Attention, la buse..";
  static PROGMEM unsigned char EXPLAIN_TWO_S_MSG[]= ".. est brulante !   " \
                                                    "Pendant la chauffe, " \
                                                    "enlevez le tube qui " \
                                                    "guide le filament ..";
  static PROGMEM unsigned char EXPLAIN_THRE_MSG[] = "du bloc d'extrusion." \
                                                    "Inserez du filament " \
                                                    "a travers le guide  " \
                                                    "jusqu'a ce qu'il ...";
  static PROGMEM unsigned char EXPLAIN_FOUR_MSG[] = "ressorte pres de la " \
                                                    "tete d'impression.  " \
                                                    "Ensuite, appuyez sur" \
                                                    "'M' pour continuer. ";
#else
  static PROGMEM unsigned char EXPLAIN_ONE_MSG[] =  "Maintenez la bague  " \
                                                    "grise en haut des   " \
                                                    "extrudeurs et tirez " \
                                                    "le guide filament.. ";
  static PROGMEM unsigned char EXPLAIN_TWO_MSG[] =  ".. pour l'enlever.  " \
                                                    "Inserez du filament " \
                                                    "a travers le guide  " \
                                                    "jusqu'a ce qu'il ...";
  static PROGMEM unsigned char EXPLAIN_ONE_S_MSG[]= "Maintenez la bague  " \
                                                    "grise en haut de    " \
                                                    "l'extrudeur et tirez" \
                                                    "le guide filament.. ";
  static PROGMEM unsigned char EXPLAIN_TWO_S_MSG[]= ".. pour l'enlever.  " \
                                                    "Inserez du filament " \
                                                    "a travers le guide  " \
                                                    "jusqu'a ce qu'il ...";
  static PROGMEM unsigned char EXPLAIN_THRE_MSG[] = "ressorte pres de la " \
                                                    "tete. Je chauffe mon" \
                                                    "extrudeur pour      " \
                                                    "charger le filament.";
  static PROGMEM unsigned char EXPLAIN_FOUR_MSG[] = "Cela va prendre     " \
                                                    "quelques minutes.   " \
                                                    "Attention, la buse  " \
                                                    "va etre tres chaude!";
#endif

static PROGMEM unsigned char HEATING_BAR_MSG[] =    "    Chauffage de    " \
                                                    "l'extrudeur en cours" \
                                                    "    Patientez SVP   " \
                                                    "                    ";
static PROGMEM unsigned char HEATING_PROG_MSG[] =   "    Progression :   " \
                                                    "                    " \
                                                    "                    " \
                                                    "                    ";
static PROGMEM unsigned char READY_SS_MSG[] =       "   Je suis prete!   " \
                                                    "Poussez le filament " \
                                                    "dans la tete ...    " \
                                                    "                    ";
static PROGMEM unsigned char READY_RIGHT_MSG[] =    "   Je suis prete!   " \
                                                    "Chargez du filament " \
                                                    "dans l'extrudeur de " \
                                                    "droite ...          ";
static PROGMEM unsigned char READY_LEFT_MSG[] =     "Parfait !           " \
                                                    "Chargez maintenant  " \
                                                    "le filament dans    " \
                                                    "l'extrudeur gauche. ";
static PROGMEM unsigned char READY_SINGLE_MSG[] =   "   Je suis prete!   " \
                                                    "Detachez le guide   " \
                                                    "et poussez le       " \
                                                    "filament ...        ";

#ifdef MODEL_REPLICATOR
  static PROGMEM unsigned char READY_REV_MSG[] =        "   Je suis prete!   " \
                                                        "Detachez le guide et" \
                                                        "retirez doucement le" \
                                                        "filament ...        ";
  static PROGMEM unsigned char READY_REV_DUAL_R_MSG[] = "   Je suis prete!   " \
                                                        "Detachez le guide,  " \
                                                        "ouvrez le levier et " \
                                                        "retirez le filament.";
  static PROGMEM unsigned char READY_REV_DUAL_L_MSG[] = "   Je suis prete!   " \
                                                        "Detachez le guide,  " \
                                                        "ouvrez le levier et " \
                                                        "retirez le filament.";
#else
  static PROGMEM unsigned char READY_REV_MSG[] =        "   Je suis prete!   " \
                                                        "Detachez le guide et" \
                                                        "retirez doucement le" \
                                                        "filament ...        ";
  static PROGMEM unsigned char READY_REV_DUAL_R_MSG[] = "   Je suis prete!   " \
                                                        "Detachez le guide et" \
                                                        "passez le levier a  " \
                                                        "droite. Tirez ...   ";
  static PROGMEM unsigned char READY_REV_DUAL_L_MSG[] = "   Je suis prete!   " \
                                                        "Detachez le guide et" \
                                                        "passez le levier a  " \
                                                        "gauche. Tirez ...   ";
#endif

static PROGMEM unsigned char TUG_MSG[]         =      "le filament jusqu'a " \
                                                      "ce que le moteur    " \
                                                      "L'entraine.         " \
                                                      "                    ";
static PROGMEM unsigned char STOP_MSG_MSG[]    =      "Quand le filament   " \
                                                      "sort de la buse,    " \
                                                      "Appuyez sur 'M' pour" \
                                                      "stopper l'extrudeur.";  // XXX old name: stop[]
static PROGMEM unsigned char STOP_EXIT_MSG[]   =      "Quand le filament   " \
                                                      "sort de la buse,    " \
                                                      "Appuyez sur 'M' pour" \
                                                      "quitter.            ";

#ifdef MODEL_REPLICATOR2
  static PROGMEM unsigned char STOP_REVERSE_MSG[]=    "Quand le filament   " \
                                                      "est totalement sorti" \
                                                      "Appuyez sur 'M' pour" \
                                                      "quitter.            ";            
  static PROGMEM unsigned char STOP_REV_DUAL_MSG[]=   "le filament et une  " \
                                                      "fois sorti, fermez  " \
                                                      "le levier et appuyez" \
                                                      "sur 'M' pour quitter";            
#else
  static PROGMEM unsigned char STOP_REVERSE_MSG[]=    "Quand le filament   " \
                                                      "est totalement sorti" \
                                                      "Appuyez sur 'M' pour" \
                                                      "quitter.            ";  
  static PROGMEM unsigned char STOP_REV_DUAL_MSG[]=   "Quand le filament   " \
                                                      "est totalement sorti" \
                                                      "Appuyez sur 'M' pour" \
                                                      "quitter.            ";
#endif

static PROGMEM unsigned char PUSH_HARDER_MSG[] =      "Ok !                " \
                                                      "Essayez de pousser  " \
                                                      "le filament un peu  " \
                                                      "plus fort ...       ";  // XXX old name: tryagain[]
static PROGMEM unsigned char KEEP_GOING_MSG[]  =      "Continuons.         " \
                                                      "                    " \
                                                      "En cas de probleme :" \
                                                      "makerbot.com/help   ";  // XXX old name: go_on[]
static PROGMEM unsigned char FINISH_MSG[]      =      "Super ! J'arrete les" \
                                                      "extrudeurs.         " \
                                                      "Appuyez sur 'M' pour" \
                                                      "continuer.          ";
static PROGMEM unsigned char GO_ON_LEFT_MSG[]  =      "Continuons.         " \
                                                      "Essayons l'extrudeur" \
                                                      "de gauche. Poussez  " \
                                                      "le filament ...     ";
static PROGMEM unsigned char TIMEOUT_MSG[]    =       "J'ai coupe le moteur" \
                                                      "apres 5 minutes.    " \
                                                      "Appuyez sur 'M' pour" \
                                                      "quitter.            ";

static PROGMEM unsigned char READY1_MSG[] =           "Tout est bon ? Pret";
static PROGMEM unsigned char READY2_MSG[] =           "a imprimer ?       ";
static PROGMEM unsigned char NOZZLE_MSG_MSG[] =       "La buse est-elle a ";        // XXX old name: ready1[]
static PROGMEM unsigned char HEIGHT_CHK_MSG[] =       "la bonne hauteur ? ";     // XXX old name: ready2[]
static PROGMEM unsigned char HEIGHT_GOOD_MSG[]=       "Oui, hauteur OK !  ";   // XXX old name: yes[]
static PROGMEM unsigned char TRY_AGAIN_MSG[]  =       "Non, recommencons. ";       // XXX old name: no[]

static PROGMEM unsigned char QONE_MSG[] =             "Du plastique sort-il";
static PROGMEM unsigned char QTWO_MSG[] =             "De l'extrudeur ?    ";
static PROGMEM unsigned char LOAD_RIGHT_MSG[] =       "Charger a droite"; 
static PROGMEM unsigned char LOAD_LEFT_MSG[] =        "Charger a gauche"; 
static PROGMEM unsigned char LOAD_SINGLE_MSG[] =      "Charger"; 
static PROGMEM unsigned char UNLOAD_SINGLE_MSG[]=     "Retirer"; 
static PROGMEM unsigned char UNLOAD_RIGHT_MSG[]=      "Retirer a droite"; 
static PROGMEM unsigned char UNLOAD_LEFT_MSG[] =      "Retirer a gauche"; 

static PROGMEM unsigned char JOG1_MSG[]  =        "     Mode manuel    ";
static PROGMEM unsigned char JOG2X_MSG[] =        "         X+         ";
static PROGMEM unsigned char JOG3X_MSG[] =        "      (Retour)  Y-> ";
static PROGMEM unsigned char JOG4X_MSG[] =        "         X-         ";
static PROGMEM unsigned char JOG2Y_MSG[] =        "         Y+         ";
static PROGMEM unsigned char JOG3Y_MSG[] =        " <-X  (Retour)  Z-> ";
static PROGMEM unsigned char JOG4Y_MSG[] =        "         Y-         ";
static PROGMEM unsigned char JOG2Z_MSG[] =        "         Z-         ";
static PROGMEM unsigned char JOG3Z_MSG[] =        " <-Y  (Retour)      ";
static PROGMEM unsigned char JOG4Z_MSG[] =        "         Z+         ";


static PROGMEM unsigned char DISTANCESHORT_MSG[] =  "COURT";
static PROGMEM unsigned char DISTANCELONG_MSG[] =   "LONG";
static PROGMEM unsigned char GAMEOVER_MSG[] =       "PERDU !";


static PROGMEM unsigned char HEATING_MSG[] =        "Chauffe:";
static PROGMEM unsigned char HEATING_SPACES_MSG[] = "Chauffe:            ";

static PROGMEM unsigned char BUILD_PERCENT_MSG[]  = " --%";
static PROGMEM unsigned char EXTRUDER1_TEMP_MSG[] = "Tete droite ---/---C";
static PROGMEM unsigned char EXTRUDER2_TEMP_MSG[] = "Tete gauche ---/---C";
static PROGMEM unsigned char PLATFORM_TEMP_MSG[]  = "Platforme   ---/---C";
static PROGMEM unsigned char EXTRUDER_TEMP_MSG[]  = "Extrudeur   ---/---C";


static PROGMEM unsigned char PREHEAT_SET_MSG[] =      "Param. Prechauffe   ";
static PROGMEM unsigned char RIGHT_SPACES_MSG[] =     "Tete de droite      ";   // XXX old name: right[]
static PROGMEM unsigned char LEFT_SPACES_MSG[] =      "Tete de gauche      ";   // XXX old name: left[]
static PROGMEM unsigned char PLATFORM_SPACES_MSG[] =  "Plateforme          ";   // XXX old name: platform[]
static PROGMEM unsigned char RESET1_MSG[] =           "Reinitialiser aux   ";   // XXX old name: set1[]
static PROGMEM unsigned char RESET2_MSG[] =           "parametres d'usine ?";
static PROGMEM unsigned char CANCEL_MSG[] =           "Annuler impression?";
static PROGMEM unsigned char CANCEL_PROCESS_MSG[] =   "Quitter processus ? ";

static PROGMEM unsigned char PAUSE_MSG[] =        "Mettre en pause     ";
static PROGMEM unsigned char UNPAUSE_MSG[] =      "Reprendre           ";

static PROGMEM unsigned char NOCARD_MSG[] =       "CarteSD introuvable ";
static PROGMEM unsigned char CARDERROR_MSG[] =    "Err. lecture CarteSD";
static PROGMEM unsigned char CARDFORMAT_MSG[] =   "Impossible de lire  " \
                                                  "ce format de carteSD" \
                                                  "Reformatez la carte " \
                                                  "au format FAT16.    ";
static PROGMEM unsigned char STATICFAIL_MSG[] =   "Erreur de lecture.  " \
                                                  "Si vous voyez ce    " \
                                                  "message pour la 1ere" \
                                                  "fois, reessayez.    ";
static PROGMEM unsigned char CARDSIZE_MSG[]   =   "Les cartes SD d'une " \
                                                  "capacite de plus de " \
                                                  "2Go ne sont pas     " \
                                                  "supportees.         ";

static PROGMEM unsigned char BUILD_MSG[] =            "Imprimer depuis SD ";
static PROGMEM unsigned char PREHEAT_MSG[] =          "Prechauffer        ";
static PROGMEM unsigned char UTILITIES_MSG[] =        "Utilitaires        ";
static PROGMEM unsigned char MONITOR_MSG[] =          "Ecran de controle  ";
static PROGMEM unsigned char JOG_MSG[] =              "Mode Manuel        ";
static PROGMEM unsigned char CALIBRATION_MSG[] =      "Calibrer les axes  ";
static PROGMEM unsigned char HOME_AXES_MSG[] =        "Axes a l'origine   ";
static PROGMEM unsigned char FILAMENT_OPTIONS_MSG[] = "Changer filament   ";
static PROGMEM unsigned char STARTUP_MSG[] =          "Script de demarrage";
static PROGMEM unsigned char VERSION_MSG[] =          "Numero de version  ";
static PROGMEM unsigned char DSTEPS_MSG[] =           "Debloquer Moteurs  ";
static PROGMEM unsigned char ESTEPS_MSG[] =           "Bloquer Moteurs    ";
static PROGMEM unsigned char PLATE_LEVEL_MSG[] =      "Ajuster plateforme ";
static PROGMEM unsigned char LED_BLINK_MSG[] =        "Clignotement LED   ";
static PROGMEM unsigned char LED_STOP_MSG[] =         "Arret Clignotement ";
static PROGMEM unsigned char PREHEAT_SETTINGS_MSG[] = "Param. Prechauffe  ";
static PROGMEM unsigned char SETTINGS_MSG[] =         "Param. Generaux    ";
static PROGMEM unsigned char RESET_MSG[] =            "RAZ Usine          ";
static PROGMEM unsigned char NOZZLES_MSG[] =          "Calibrer les buses ";
static PROGMEM unsigned char TOOL_COUNT_MSG[] =       "Nb. de tetes       ";
static PROGMEM unsigned char SOUND_MSG[] =            "Son                ";
static PROGMEM unsigned char HEIGHT_EN_MSG[] =        "Pause Active       ";
static PROGMEM unsigned char HEIGHT_VALUE_MSG[] =     "Position Z      mm ";
static PROGMEM unsigned char LED_MSG[] =              "Coul. LEDs         ";
static PROGMEM unsigned char LED_HEAT_MSG[] =         "LEDs Chauffe       ";
static PROGMEM unsigned char HEAT_TIMEOUT_MSG[] =     "Chauffe        m   ";
static PROGMEM unsigned char HELP_SCREENS_MSG[] =     "Affich. Aide       ";
static PROGMEM unsigned char EXIT_MSG[] =             "<< Sortie          ";
static PROGMEM unsigned char ACCELERATE_MSG[] =       "Acceleration       ";
static PROGMEM unsigned char BOT_STATS_MSG[] =        "Statistiques       ";
static PROGMEM unsigned char INFO_MSG[] =             "Infos et Reglages  ";
static PROGMEM unsigned char PLATFORM_EXIST_MSG[] =   "Lit Chauffant      ";

static PROGMEM unsigned char RED_COLOR_MSG[]    =     "ROUGE ";
static PROGMEM unsigned char ORANGE_COLOR_MSG[] =     "ORANGE";
static PROGMEM unsigned char PINK_COLOR_MSG[]   =     "ROSE  ";
static PROGMEM unsigned char GREEN_COLOR_MSG[]  =     "VERT  ";
static PROGMEM unsigned char BLUE_COLOR_MSG[]   =     "BLEU  ";
static PROGMEM unsigned char PURPLE_COLOR_MSG[] =     "VIOLET";
static PROGMEM unsigned char WHITE_COLOR_MSG[]  =     "BLANC ";
static PROGMEM unsigned char CUSTOM_COLOR_MSG[] =     "AUTRE ";
static PROGMEM unsigned char OFF_COLOR_MSG[]    =     "OFF   ";

static PROGMEM unsigned char TOOL_SINGLE_MSG[]  =     "1";
static PROGMEM unsigned char TOOL_DUAL_MSG[]    =     "2";

static PROGMEM unsigned char RIGHT_MSG[]   =      "Droite";
static PROGMEM unsigned char LEFT_MSG[]    =      "Gauche";
static PROGMEM unsigned char ERROR_MSG[]   =      "Erreur !";
static PROGMEM unsigned char NA_MSG[]      =      "  N/A    ";
static PROGMEM unsigned char WAITING_MSG[] =      "En cours";
static PROGMEM unsigned char WAIT_FOR_HOMING_MSG[] = "Remise a l'origine..";

static PROGMEM unsigned char HEATER_INACTIVITY_MSG[] = "Arret de la chauffe " \
                                                       "pour inactivite.    ";
static PROGMEM unsigned char HEATER_FAIL_SOFTWARE_CUTOFF_MSG[] =    "Erreur de chauffe #1" \
                                                                    "Temperature limite  " \
                                                                    "atteinte! Veuillez  " \
                                                                    "redemarrer.         ";
/*static PROGMEM unsigned char HEATER_FAIL_HARDWARE_CUTOFF_MSG[] =  "Surchauffe des buses" \
                                                                    "Coupure de securite!" \
                                                                    "Veuillez eteindre ou" \
                                                                    "redemarrer.         ";
*/
static PROGMEM unsigned char HEATER_FAIL_NOT_HEATING_MSG[] =        "Erreur de chauffe #2" \
                                                                    "Les extrudeurs ne   " \
                                                                    "chauffent pas bien. " \
                                                                    "Verifiez connectique";

static PROGMEM unsigned char HEATER_FAIL_DROPPING_TEMP_MSG[] =      "Erreur de chauffe #3" \
                                                                    "La temperature des  " \
                                                                    "tetes chute.        " \
                                                                    "Verifiez connectique";

static PROGMEM unsigned char HEATER_FAIL_NOT_PLUGGED_IN_MSG[] =     "Erreur de chauffe #4" \
                                                                    "Echec du releve de  " \
                                                                    "temperature.        " \
                                                                    "Verifiez connectique";

static PROGMEM unsigned char HEATER_FAIL_READ_TEMP_OUT_OF_RANGE_MSG[] = "Erreur de chauffe #5" \
                                                                        "Temperatures au-dela" \
                                                                        "des limites admises." \
                                                                        "Verifiez connectique";

static PROGMEM unsigned char TOTAL_TIME_MSG[]       =   "Temps de fabrication" \
                                                        "Total Cumule:      h";
static PROGMEM unsigned char LAST_TIME_MSG[]        =   "Dernier temps:  h  m";
static PROGMEM unsigned char BUILD_TIME_MSG[]       =   "Temps fabric.:  h  m"; 
static PROGMEM unsigned char LINE_NUMBER_MSG[]      =   "Ligne numero :      ";
static PROGMEM unsigned char BUILD_FINISHED_MSG []  =   "Fabrication terminee" \
                                                        "                    " \
                                                        "Temps total:    h  m";
static PROGMEM unsigned char TIME_SPECIFYING_LETTERS[] =    "h  m";
static PROGMEM unsigned char CLEAR_TIME_SPECIFYING_LETTERS[] =    "      ";
static PROGMEM unsigned char CLEAR_TIME_SPECIFYING_LETTERS_1DIGIT_H[] = "     ";

static PROGMEM unsigned char BACK_TO_MONITOR_MSG[] =            "Retour             ";
static PROGMEM unsigned char STATS_MSG[] =                      "Statistiques       ";
static PROGMEM unsigned char CHANGE_FILAMENT_HEIGHT_MSG[]  =    "Pause Axe Z        ";
static PROGMEM unsigned char CHANGE_FILAMENT_HEIGHT_HEADING[] = "    Pause Axe Z    ";
static PROGMEM unsigned char CANCEL_BUILD_MSG[]     =           "Annuler fabric.    "; 
static PROGMEM unsigned char CHANGE_FILAMENT_MSG[]  =           "Changer filament   "; 

static PROGMEM unsigned char CANCEL_PLATE_MSG[] =               "Annulation en cours " \
                                                                "Veuillez patienter. ";

static PROGMEM unsigned char SLEEP_MSG[]         =              "Veille longue      ";
static PROGMEM unsigned char RESTART_MSG[]       =              "Reprendre fabric.  ";

static PROGMEM unsigned char CHANGE_FILAMENT_WAIT_MSG[] =   "Changement filament " \
                                                            "Patienter svp, je   " \
                                                            "finis ce mouvement. "; 
static PROGMEM unsigned char CHANGE_FILAMENT_PREP_MSG[] =   "Changement filament " \
                                                            "Je vais en position " \
                                                            "d'attente.           ";

static PROGMEM unsigned char TIMED_OUT_OF_CHANGE_FILAMENT[] =   "Arret de la chauffe " \
                                                                "Je suis maintenant  " \
                                                                "en veille.          " \
                                                                "(Pause froide)      ";

static PROGMEM unsigned char SLEEP_WAIT_MSG[] =       "Preparation veille :" \
                                                      "Patienter svp, je   " \
                                                      "finis ce mouvement. ";  
static PROGMEM unsigned char SLEEP_PREP_MSG[] =       "Preparation veille :" \
                                                      "Je refroidis les    " \
                                                      "tetes et vais en    " \
                                                      "position d'attente. ";
static PROGMEM unsigned char RESTARTING_MSG[] =       "Reprise fabrication ";

static PROGMEM unsigned char ERROR_STREAM_INCOMPATIBLE_REP1[] = "/!\\ Vitesse de fab." \
                                                                "superieure a 50mm/s:" \
                                                                "Le format x3g donne " \
                                                                "un meilleur rendu.  "; 
static PROGMEM unsigned char ERROR_STREAM_VERSION[] = "Cette version du x3g" \
                                                      "ne m'est pas adaptee" \
                                                      "Pour de l'aide:     " \
                                                      "makerbot.com/help   ";
static PROGMEM unsigned char ERROR_BOT_TYPE_REP1[] =  "Ce fichier est pour " \
                                                      "une autre Replicator" \
                                                      "Besoin d'aide ? :   " \
                                                      "makerbot.com/help   ";
static PROGMEM unsigned char ERROR_BOT_TYPE_REP2[] =  "Ce fichier est pour " \
                                                      "une autre Replicator" \
                                                      "Besoin d'aide ? :   " \
                                                      "makerbot.com/help   ";
static PROGMEM unsigned char ERROR_SRAM[] = "L'UTILISATION SRAM  " \
                                            "DEPASSE LES 8K !    ";
static PROGMEM unsigned char ERROR_SD_CARD_REMOVED[] =            "Carte SD retiree    ";
static PROGMEM unsigned char ERROR_PLATFORM_HEATING_TIMEOUT[] =   "La plateforme a mis " \
                                                                  "trop longtemps a    " \
                                                                  "chauffer.           ";
static PROGMEM unsigned char ERROR_HEATING_TIMEOUT[] =        "L'extrudeur a mis   " \
                                                              "trop longtemps a    " \
                                                              "chauffer.           ";
static PROGMEM unsigned char ERROR_SD_CARD_BUILDING[] =       "Deja en cours de fab";
static PROGMEM unsigned char ERROR_SD_CARD_GENERIC[] =        "Err. lecture CarteSD";
static PROGMEM unsigned char ERROR_TEMP_RESET_EXTERNALLY[] =  "La temperature a ete" \
                                                              "modifiee. Allez dans" \
                                                              "le menu Filament,   " \
                                                              "puis reessayez.     ";

static PROGMEM unsigned char ERROR_INVALID_PLATFORM[] = "COMMANDE INVALIDE:  " \
                                                        "Commande recue pour " \
                                                        "la plaque chauffante" \
                                                        "que je n'ai pas.";
static PROGMEM unsigned char ERROR_INVALID_TOOL[] =     "TETE INVALIDE:      " \
                                                        "Commande recue pour " \
                                                        "une deuxieme tete or" \
                                                        "je n'ai qu'une tete.";
static PROGMEM unsigned char ACTIVE_FAN_MSG[]    =      "Ventilateur         ";

/// The level Plate Scripts walk users through a procedure to level the build plate
/// the gcode and s3g files for these scripts are located in firmware/s3g_scripts
/// the script loadDataFile.py converts s3g files to byte arrays to store in PROGMEM

#ifdef MODEL_REPLICATOR2
# define LEVEL_PLATE_SINGLE static uint8_t LevelPlateSingle[] PROGMEM = { 149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  132,  3,  105,  1,  0,  0,  20,  0,  131,  4,  136,  0,  0,  0,  20,  0,  140,  0,  0,  0,  0,  0,  0,  0,  0,  48,  248,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  142,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  87,  41,  4,  0,  24,  131,  4,  220,  5,  0,  0,  20,  0,  140,  229,  55,  0,  0,  148,  27,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  149,  0,  0,  0,  0,  84,  111,  117,  114,  110,  101,  122,  32,  108,  101,  115,  32,  51,  32,  118,  105,  115,  32,  32,  32,  0,  149,  1,  0,  0,  0,  115,  111,  117,  115,  32,  108,  97,  32,  112,  108,  97,  113,  117,  101,  32,  32,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  99,  104,  97,  117,  102,  102,  97,  110,  116,  101,  32,  101,  116,  32,  115,  101,  114,  114,  101,  122,  0,  149,  7,  0,  0,  0,  100,  101,  32,  113,  117,  97,  116,  114,  101,  32,  116,  111,  117,  114,  115,  46,  0,  149,  0,  0,  0,  0,  79,  110,  32,  118,  97,  32,  97,  106,  117,  115,  116,  101,  114,  32,  108,  97,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  116,  101,  116,  101,  44,  32,  106,  101,  32,  118,  97,  105,  115,  32,  100,  111,  110,  99,  32,  32,  0,  149,  1,  0,  0,  0,  108,  97,  32,  100,  101,  112,  108,  97,  99,  101,  114,  32,  100,  97,  110,  115,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  112,  108,  117,  115,  105,  101,  117,  114,  115,  32,  112,  111,  115,  105,  116,  105,  111,  110,  115,  0,  149,  0,  0,  0,  0,  65,  102,  105,  110,  32,  100,  101,  32,  118,  101,  114,  105,  102,  105,  101,  114,  32,  108,  97,  32,  0,  149,  1,  0,  0,  0,  104,  97,  117,  116,  101,  117,  114,  32,  100,  101,  32,  108,  97,  32,  116,  101,  116,  101,  32,  32,  0,  149,  1,  0,  0,  0,  84,  111,  117,  114,  110,  101,  122,  32,  108,  97,  32,  118,  105,  115,  32,  112,  111,  117,  114,  32,  0,  149,  7,  0,  0,  0,  113,  117,  101,  32,  108,  97,  32,  116,  101,  116,  101,  32,  116,  111,  117,  99,  104,  101,  46,  46,  0,  149,  0,  0,  0,  0,  112,  114,  101,  115,  113,  117,  101,  32,  108,  97,  32,  112,  108,  97,  113,  117,  101,  46,  32,  32,  0,  149,  1,  0,  0,  0,  76,  39,  101,  115,  112,  97,  99,  101,  32,  101,  115,  116,  32,  106,  117,  115,  116,  101,  32,  32,  0,  149,  1,  0,  0,  0,  113,  117,  97,  110,  100,  32,  111,  110,  32,  112,  101,  117,  116,  32,  109,  101,  116,  116,  114,  101,  0,  149,  7,  0,  0,  0,  117,  110,  101,  32,  102,  105,  110,  101,  32,  102,  101,  117,  105,  108,  108,  101,  32,  46,  46,  46,  0,  149,  0,  0,  0,  0,  100,  101,  32,  112,  97,  112,  105,  101,  114,  32,  113,  117,  105,  32,  116,  111,  117,  99,  104,  101,  0,  149,  1,  0,  0,  0,  108,  97,  32,  116,  101,  116,  101,  32,  101,  116,  32,  108,  97,  32,  112,  108,  97,  113,  117,  101,  0,  149,  7,  0,  0,  0,  100,  39,  101,  120,  116,  114,  117,  115,  105,  111,  110,  46,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  0,  0,  0,  0,  190,  25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  108,  105,  46,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  97,  32,  108,  39,  97,  114,  114,  105,  101,  114,  101,  32,  0,  149,  1,  0,  0,  0,  108,  97,  32,  118,  105,  115,  32,  112,  111,  117,  114,  32,  113,  117,  39,  117,  110,  101,  32,  32,  0,  149,  1,  0,  0,  0,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  0,  0,  0,  0,  190,  25,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  167,  17,  0,  0,  66,  230,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  128,  42,  45,  0,  24,  142,  166,  17,  0,  0,  66,  230,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  108,  97,  32,  118,  105,  115,  32,  97,  118,  97,  110,  116,  0,  149,  1,  0,  0,  0,  100,  114,  111,  105,  116,  101,  32,  112,  111,  117,  114,  32,  113,  117,  39,  117,  110,  101,  32,  32,  0,  149,  1,  0,  0,  0,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  167,  17,  0,  0,  66,  230,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  89,  238,  255,  255,  66,  230,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  76,  29,  0,  24,  142,  90,  238,  255,  255,  67,  230,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  108,  97,  32,  118,  105,  115,  32,  97,  118,  97,  110,  116,  0,  149,  1,  0,  0,  0,  103,  97,  117,  99,  104,  101,  32,  112,  111,  117,  114,  32,  113,  117,  39,  117,  110,  101,  32,  32,  0,  149,  1,  0,  0,  0,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  89,  238,  255,  255,  66,  230,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  77,  97,  105,  110,  116,  101,  110,  97,  110,  116,  32,  106,  101,  32,  118,  97,  105,  115,  32,  32,  0,  149,  1,  0,  0,  0,  114,  101,  112,  97,  115,  115,  101,  114,  32,  109,  97,  32,  116,  101,  116,  101,  32,  115,  117,  114,  0,  149,  1,  0,  0,  0,  108,  101,  115,  32,  116,  114,  111,  105,  115,  32,  99,  111,  105,  110,  115,  32,  112,  111,  117,  114,  0,  149,  7,  0,  0,  0,  118,  97,  108,  105,  100,  101,  114,  32,  97,  32,  110,  111,  117,  118,  101,  97,  117,  46,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  0,  0,  0,  0,  190,  25,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  128,  25,  27,  0,  24,  142,  0,  0,  0,  0,  189,  25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  97,  32,  108,  39,  97,  114,  114,  105,  101,  114,  101,  32,  0,  149,  1,  0,  0,  0,  108,  97,  32,  118,  105,  115,  32,  112,  111,  117,  114,  32,  113,  117,  39,  117,  110,  101,  32,  32,  0,  149,  1,  0,  0,  0,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  0,  0,  0,  0,  190,  25,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  247,  45,  0,  0,  66,  230,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  166,  93,  34,  0,  24,  142,  248,  45,  0,  0,  67,  230,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  108,  97,  32,  118,  105,  115,  32,  97,  118,  97,  110,  116,  0,  149,  1,  0,  0,  0,  100,  114,  111,  105,  116,  101,  32,  112,  111,  117,  114,  32,  113,  117,  39,  117,  110,  101,  32,  32,  0,  149,  1,  0,  0,  0,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  247,  45,  0,  0,  66,  230,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  9,  210,  255,  255,  66,  230,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  192,  198,  45,  0,  24,  142,  8,  210,  255,  255,  66,  230,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  108,  97,  32,  118,  105,  115,  32,  97,  118,  97,  110,  116,  0,  149,  1,  0,  0,  0,  103,  97,  117,  99,  104,  101,  32,  112,  111,  117,  114,  32,  113,  117,  39,  117,  110,  101,  32,  32,  0,  149,  1,  0,  0,  0,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  9,  210,  255,  255,  67,  230,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  0,  0,  0,  0,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  145,  59,  26,  0,  24,  142,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  68,  101,  114,  110,  105,  101,  114,  101,  32,  118,  101,  114,  105,  102,  46,  32,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  108,  97,  32,  102,  101,  117,  105,  108,  108,  101,  32,  100,  101,  32,  112,  97,  112,  105,  101,  114,  0,  149,  1,  0,  0,  0,  100,  111,  105,  116,  32,  103,  108,  105,  115,  115,  101,  114,  32,  101,  110,  116,  114,  101,  32,  32,  0,  149,  7,  0,  0,  0,  108,  97,  32,  116,  101,  116,  101,  32,  101,  116,  32,  108,  97,  32,  112,  108,  97,  113,  117,  101,  0,  137,  31 };
# define LEVEL_PLATE_LEN_SINGLE 2052
# define LEVEL_PLATE_DUAL static uint8_t LevelPlateDual[] PROGMEM = { 149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  132,  3,  105,  1,  0,  0,  20,  0,  131,  4,  136,  0,  0,  0,  20,  0,  140,  0,  0,  0,  0,  0,  0,  0,  0,  48,  248,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  142,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  87,  41,  4,  0,  24,  131,  4,  220,  5,  0,  0,  20,  0,  140,  229,  55,  0,  0,  148,  27,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  149,  0,  0,  0,  0,  84,  111,  117,  114,  110,  101,  122,  32,  108,  101,  115,  32,  51,  32,  118,  105,  115,  32,  32,  32,  0,  149,  1,  0,  0,  0,  115,  111,  117,  115,  32,  108,  97,  32,  112,  108,  97,  113,  117,  101,  32,  32,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  99,  104,  97,  117,  102,  102,  97,  110,  116,  101,  32,  101,  116,  32,  115,  101,  114,  114,  101,  122,  0,  149,  7,  0,  0,  0,  100,  101,  32,  113,  117,  97,  116,  114,  101,  32,  116,  111,  117,  114,  115,  46,  0,  149,  0,  0,  0,  0,  79,  110,  32,  118,  97,  32,  97,  106,  117,  115,  116,  101,  114,  32,  108,  101,  115,  32,  32,  32,  0,  149,  1,  0,  0,  0,  116,  101,  116,  101,  115,  44,  32,  106,  101,  32,  118,  97,  105,  115,  32,  100,  111,  110,  99,  32,  0,  149,  1,  0,  0,  0,  108,  101,  115,  32,  100,  101,  112,  108,  97,  99,  101,  114,  32,  100,  97,  110,  115,  32,  32,  32,  0,  149,  7,  0,  0,  0,  112,  108,  117,  115,  105,  101,  117,  114,  115,  32,  112,  111,  115,  105,  116,  105,  111,  110,  115,  0,  149,  0,  0,  0,  0,  65,  102,  105,  110,  32,  100,  101,  32,  118,  101,  114,  105,  102,  105,  101,  114,  32,  108,  97,  32,  0,  149,  1,  0,  0,  0,  104,  97,  117,  116,  101,  117,  114,  32,  100,  101,  115,  32,  116,  101,  116,  101,  115,  32,  32,  32,  0,  149,  1,  0,  0,  0,  84,  111,  117,  114,  110,  101,  122,  32,  108,  97,  32,  118,  105,  115,  32,  112,  111,  117,  114,  32,  0,  149,  7,  0,  0,  0,  113,  117,  39,  101,  108,  108,  101,  115,  32,  116,  111,  117,  99,  104,  101,  110,  116,  46,  46,  46,  0,  149,  0,  0,  0,  0,  112,  114,  101,  115,  113,  117,  101,  32,  108,  97,  32,  112,  108,  97,  113,  117,  101,  46,  32,  32,  0,  149,  1,  0,  0,  0,  76,  39,  101,  115,  112,  97,  99,  101,  32,  101,  115,  116,  32,  106,  117,  115,  116,  101,  32,  32,  0,  149,  1,  0,  0,  0,  113,  117,  97,  110,  100,  32,  111,  110,  32,  112,  101,  117,  116,  32,  109,  101,  116,  116,  114,  101,  0,  149,  7,  0,  0,  0,  117,  110,  101,  32,  102,  105,  110,  101,  32,  102,  101,  117,  105,  108,  108,  101,  32,  46,  46,  46,  0,  149,  0,  0,  0,  0,  100,  101,  32,  112,  97,  112,  105,  101,  114,  32,  113,  117,  105,  32,  116,  111,  117,  99,  104,  101,  0,  149,  1,  0,  0,  0,  108,  101,  115,  32,  116,  101,  116,  101,  115,  32,  101,  116,  32,  108,  97,  32,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  112,  108,  97,  113,  117,  101,  32,  100,  39,  101,  120,  116,  114,  117,  115,  105,  111,  110,  46,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  17,  6,  0,  0,  190,  25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  36,  97,  41,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  97,  32,  108,  39,  97,  114,  114,  105,  101,  114,  101,  32,  0,  149,  1,  0,  0,  0,  108,  97,  32,  118,  105,  115,  32,  112,  111,  117,  114,  32,  113,  117,  39,  117,  110,  101,  32,  32,  0,  149,  1,  0,  0,  0,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  18,  6,  0,  0,  190,  25,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  184,  23,  0,  0,  66,  230,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  128,  42,  45,  0,  24,  142,  184,  23,  0,  0,  66,  230,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  108,  97,  32,  118,  105,  115,  32,  97,  118,  97,  110,  116,  0,  149,  1,  0,  0,  0,  100,  114,  111,  105,  116,  101,  32,  112,  111,  117,  114,  32,  113,  117,  39,  117,  110,  101,  32,  32,  0,  149,  1,  0,  0,  0,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  184,  23,  0,  0,  66,  230,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  174,  243,  255,  255,  66,  230,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  63,  232,  29,  0,  24,  142,  174,  243,  255,  255,  67,  230,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  108,  97,  32,  118,  105,  115,  32,  97,  118,  97,  110,  116,  0,  149,  1,  0,  0,  0,  103,  97,  117,  99,  104,  101,  32,  112,  111,  117,  114,  32,  113,  117,  39,  117,  110,  101,  32,  32,  0,  149,  1,  0,  0,  0,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  175,  243,  255,  255,  66,  230,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  77,  97,  105,  110,  116,  101,  110,  97,  110,  116,  32,  106,  101,  32,  118,  97,  105,  115,  32,  32,  0,  149,  1,  0,  0,  0,  114,  101,  112,  97,  115,  115,  101,  114,  32,  109,  97,  32,  116,  101,  116,  101,  32,  115,  117,  114,  0,  149,  1,  0,  0,  0,  108,  101,  115,  32,  116,  114,  111,  105,  115,  32,  99,  111,  105,  110,  115,  32,  112,  111,  117,  114,  0,  149,  7,  0,  0,  0,  118,  97,  108,  105,  100,  101,  114,  32,  97,  32,  110,  111,  117,  118,  101,  97,  117,  46,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  17,  6,  0,  0,  190,  25,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  120,  56,  27,  0,  24,  142,  17,  6,  0,  0,  189,  25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  97,  32,  108,  39,  97,  114,  114,  105,  101,  114,  101,  32,  0,  149,  1,  0,  0,  0,  108,  97,  32,  118,  105,  115,  32,  112,  111,  117,  114,  32,  113,  117,  39,  117,  110,  101,  32,  32,  0,  149,  1,  0,  0,  0,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  18,  6,  0,  0,  190,  25,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  194,  43,  0,  0,  66,  230,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  90,  197,  31,  0,  24,  142,  195,  43,  0,  0,  67,  230,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  108,  97,  32,  118,  105,  115,  32,  97,  118,  97,  110,  116,  0,  149,  1,  0,  0,  0,  100,  114,  111,  105,  116,  101,  32,  112,  111,  117,  114,  32,  113,  117,  39,  117,  110,  101,  32,  32,  0,  149,  1,  0,  0,  0,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  194,  43,  0,  0,  66,  230,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  49,  224,  255,  255,  66,  230,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  208,  160,  37,  0,  24,  142,  49,  224,  255,  255,  66,  230,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  108,  97,  32,  118,  105,  115,  32,  97,  118,  97,  110,  116,  0,  149,  1,  0,  0,  0,  103,  97,  117,  99,  104,  101,  32,  112,  111,  117,  114,  32,  113,  117,  39,  117,  110,  101,  32,  32,  0,  149,  1,  0,  0,  0,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  49,  224,  255,  255,  67,  230,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  17,  6,  0,  0,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  149,  205,  22,  0,  24,  142,  18,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  68,  101,  114,  110,  105,  101,  114,  101,  32,  118,  101,  114,  105,  102,  46,  32,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  108,  97,  32,  102,  101,  117,  105,  108,  108,  101,  32,  100,  101,  32,  112,  97,  112,  105,  101,  114,  0,  149,  1,  0,  0,  0,  100,  111,  105,  116,  32,  103,  108,  105,  115,  115,  101,  114,  32,  101,  110,  116,  114,  101,  32,  32,  0,  149,  7,  0,  0,  0,  108,  97,  32,  116,  101,  116,  101,  32,  101,  116,  32,  108,  97,  32,  112,  108,  97,  113,  117,  101,  0,  137,  31 };
# define LEVEL_PLATE_LEN_DUAL 2059
#else
# define LEVEL_PLATE_SINGLE static uint8_t LevelPlateSingle[] PROGMEM = { 149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  132,  3,  105,  1,  0,  0,  20,  0,  131,  4,  136,  0,  0,  0,  20,  0,  140,  0,  0,  0,  0,  0,  0,  0,  0,  48,  248,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  142,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  87,  41,  4,  0,  24,  131,  4,  220,  5,  0,  0,  20,  0,  140,  229,  55,  0,  0,  148,  27,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  149,  0,  0,  0,  0,  84,  111,  117,  114,  110,  101,  122,  32,  108,  101,  115,  32,  52,  32,  118,  105,  115,  32,  32,  32,  0,  149,  1,  0,  0,  0,  115,  111,  117,  115,  32,  108,  97,  32,  112,  108,  97,  113,  117,  101,  32,  32,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  99,  104,  97,  117,  102,  102,  97,  110,  116,  101,  32,  101,  116,  32,  115,  101,  114,  114,  101,  122,  0,  149,  7,  0,  0,  0,  100,  101,  32,  113,  117,  97,  116,  114,  101,  32,  116,  111,  117,  114,  115,  46,  0,  149,  0,  0,  0,  0,  79,  110,  32,  118,  97,  32,  97,  106,  117,  115,  116,  101,  114,  32,  108,  97,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  116,  101,  116,  101,  32,  44,  32,  106,  101,  32,  118,  97,  105,  115,  32,  100,  111,  110,  99,  32,  0,  149,  1,  0,  0,  0,  108,  97,  32,  100,  101,  112,  108,  97,  99,  101,  114,  32,  100,  97,  110,  115,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  112,  108,  117,  115,  105,  101,  117,  114,  115,  32,  112,  111,  115,  105,  116,  105,  111,  110,  115,  0,  149,  0,  0,  0,  0,  65,  102,  105,  110,  32,  100,  101,  32,  118,  101,  114,  105,  102,  105,  101,  114,  32,  108,  97,  32,  0,  149,  1,  0,  0,  0,  104,  97,  117,  116,  101,  117,  114,  32,  100,  101,  32,  108,  97,  32,  116,  101,  116,  101,  32,  32,  0,  149,  1,  0,  0,  0,  84,  111,  117,  114,  110,  101,  122,  32,  108,  101,  115,  32,  118,  105,  115,  32,  112,  111,  117,  114,  0,  149,  7,  0,  0,  0,  113,  117,  39,  101,  108,  108,  101,  32,  116,  111,  117,  99,  104,  101,  46,  46,  46,  0,  149,  0,  0,  0,  0,  112,  114,  101,  115,  113,  117,  101,  32,  108,  97,  32,  112,  108,  97,  113,  117,  101,  46,  32,  32,  0,  149,  1,  0,  0,  0,  76,  39,  101,  115,  112,  97,  99,  101,  32,  101,  115,  116,  32,  106,  117,  115,  116,  101,  32,  32,  0,  149,  1,  0,  0,  0,  113,  117,  97,  110,  100,  32,  111,  110,  32,  112,  101,  117,  116,  32,  109,  101,  116,  116,  114,  101,  0,  149,  7,  0,  0,  0,  117,  110,  101,  32,  102,  105,  110,  101,  32,  102,  101,  117,  105,  108,  108,  101,  32,  46,  46,  46,  0,  149,  0,  0,  0,  0,  100,  101,  32,  112,  97,  112,  105,  101,  114,  32,  113,  117,  105,  32,  116,  111,  117,  99,  104,  101,  0,  149,  1,  0,  0,  0,  108,  97,  32,  116,  101,  116,  101,  32,  32,  101,  116,  32,  108,  97,  32,  32,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  112,  108,  97,  113,  117,  101,  32,  100,  39,  101,  120,  116,  114,  117,  115,  105,  111,  110,  46,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  229,  55,  0,  0,  149,  27,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  0,  0,  0,  0,  201,  228,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  42,  13,  59,  0,  24,  142,  0,  0,  0,  0,  202,  228,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  108,  101,  115,  32,  100,  101,  117,  120,  32,  118,  105,  115,  0,  149,  1,  0,  0,  0,  97,  32,  108,  39,  97,  118,  97,  110,  116,  32,  32,  32,  112,  111,  117,  114,  32,  113,  117,  39,  0,  149,  1,  0,  0,  0,  117,  110,  101,  32,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  0,  0,  0,  0,  202,  228,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  0,  0,  0,  0,  122,  26,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  81,  129,  40,  0,  24,  142,  0,  0,  0,  0,  122,  26,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  108,  101,  115,  32,  100,  101,  117,  120,  32,  118,  105,  115,  0,  149,  1,  0,  0,  0,  97,  32,  108,  39,  97,  114,  114,  105,  101,  114,  101,  32,  112,  111,  117,  114,  32,  113,  117,  39,  0,  149,  1,  0,  0,  0,  117,  110,  101,  32,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  0,  0,  0,  0,  122,  26,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  198,  36,  0,  0,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  168,  47,  34,  0,  24,  142,  198,  36,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  108,  101,  115,  32,  100,  101,  117,  120,  32,  118,  105,  115,  0,  149,  1,  0,  0,  0,  100,  101,  32,  100,  114,  111,  105,  116,  101,  32,  32,  32,  112,  111,  117,  114,  32,  113,  117,  39,  0,  149,  1,  0,  0,  0,  117,  110,  101,  32,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  198,  36,  0,  0,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  58,  219,  255,  255,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  139,  124,  55,  0,  24,  142,  58,  219,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  108,  101,  115,  32,  100,  101,  117,  120,  32,  118,  105,  115,  0,  149,  1,  0,  0,  0,  100,  101,  32,  103,  97,  117,  99,  104,  101,  32,  32,  32,  112,  111,  117,  114,  32,  113,  117,  39,  0,  149,  1,  0,  0,  0,  117,  110,  101,  32,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  58,  219,  255,  255,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  0,  0,  0,  0,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  69,  190,  27,  0,  24,  142,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  68,  101,  114,  110,  105,  101,  114,  101,  32,  118,  101,  114,  105,  102,  46,  32,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  108,  97,  32,  102,  101,  117,  105,  108,  108,  101,  32,  100,  101,  32,  112,  97,  112,  105,  101,  114,  0,  149,  1,  0,  0,  0,  100,  111,  105,  116,  32,  103,  108,  105,  115,  115,  101,  114,  32,  101,  110,  116,  114,  101,  32,  32,  0,  149,  7,  0,  0,  0,  108,  97,  32,  116,  101,  116,  101,  32,  101,  116,  32,  108,  97,  32,  112,  108,  97,  113,  117,  101,  0,  137,  31 };
# define LEVEL_PLATE_LEN_SINGLE 1608
# define LEVEL_PLATE_DUAL static uint8_t LevelPlateDual[] PROGMEM = { 149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  132,  3,  105,  1,  0,  0,  20,  0,  131,  4,  136,  0,  0,  0,  20,  0,  140,  0,  0,  0,  0,  0,  0,  0,  0,  48,  248,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  142,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  87,  41,  4,  0,  24,  131,  4,  220,  5,  0,  0,  20,  0,  140,  229,  55,  0,  0,  148,  27,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  149,  0,  0,  0,  0,  84,  111,  117,  114,  110,  101,  122,  32,  108,  101,  115,  32,  52,  32,  118,  105,  115,  32,  32,  32,  0,  149,  1,  0,  0,  0,  115,  111,  117,  115,  32,  108,  97,  32,  112,  108,  97,  113,  117,  101,  32,  32,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  99,  104,  97,  117,  102,  102,  97,  110,  116,  101,  32,  101,  116,  32,  115,  101,  114,  114,  101,  122,  0,  149,  7,  0,  0,  0,  100,  101,  32,  113,  117,  97,  116,  114,  101,  32,  116,  111,  117,  114,  115,  46,  0,  149,  0,  0,  0,  0,  79,  110,  32,  118,  97,  32,  97,  106,  117,  115,  116,  101,  114,  32,  108,  101,  115,  32,  32,  32,  0,  149,  1,  0,  0,  0,  116,  101,  116,  101,  115,  44,  32,  106,  101,  32,  118,  97,  105,  115,  32,  100,  111,  110,  99,  32,  0,  149,  1,  0,  0,  0,  108,  101,  115,  32,  100,  101,  112,  108,  97,  99,  101,  114,  32,  100,  97,  110,  115,  32,  32,  32,  0,  149,  7,  0,  0,  0,  112,  108,  117,  115,  105,  101,  117,  114,  115,  32,  112,  111,  115,  105,  116,  105,  111,  110,  115,  0,  149,  0,  0,  0,  0,  65,  102,  105,  110,  32,  100,  101,  32,  118,  101,  114,  105,  102,  105,  101,  114,  32,  108,  97,  32,  0,  149,  1,  0,  0,  0,  104,  97,  117,  116,  101,  117,  114,  32,  100,  101,  115,  32,  116,  101,  116,  101,  115,  32,  32,  32,  0,  149,  1,  0,  0,  0,  84,  111,  117,  114,  110,  101,  122,  32,  108,  101,  115,  32,  118,  105,  115,  32,  112,  111,  117,  114,  0,  149,  7,  0,  0,  0,  113,  117,  39,  101,  108,  108,  101,  115,  32,  116,  111,  117,  99,  104,  101,  110,  116,  46,  46,  46,  0,  149,  0,  0,  0,  0,  112,  114,  101,  115,  113,  117,  101,  32,  108,  97,  32,  112,  108,  97,  113,  117,  101,  46,  32,  32,  0,  149,  1,  0,  0,  0,  76,  39,  101,  115,  112,  97,  99,  101,  32,  101,  115,  116,  32,  106,  117,  115,  116,  101,  32,  32,  0,  149,  1,  0,  0,  0,  113,  117,  97,  110,  100,  32,  111,  110,  32,  112,  101,  117,  116,  32,  109,  101,  116,  116,  114,  101,  0,  149,  7,  0,  0,  0,  117,  110,  101,  32,  102,  105,  110,  101,  32,  102,  101,  117,  105,  108,  108,  101,  32,  46,  46,  46,  0,  149,  0,  0,  0,  0,  100,  101,  32,  112,  97,  112,  105,  101,  114,  32,  113,  117,  105,  32,  116,  111,  117,  99,  104,  101,  0,  149,  1,  0,  0,  0,  108,  101,  115,  32,  116,  101,  116,  101,  115,  32,  101,  116,  32,  108,  97,  32,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  112,  108,  97,  113,  117,  101,  32,  100,  39,  101,  120,  116,  114,  117,  115,  105,  111,  110,  46,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  229,  55,  0,  0,  148,  27,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  18,  6,  0,  0,  202,  228,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  218,  223,  55,  0,  24,  142,  17,  6,  0,  0,  201,  228,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  108,  101,  115,  32,  100,  101,  117,  120,  32,  118,  105,  115,  0,  149,  1,  0,  0,  0,  97,  32,  108,  39,  97,  118,  97,  110,  116,  32,  32,  32,  112,  111,  117,  114,  32,  113,  117,  39,  0,  149,  1,  0,  0,  0,  117,  110,  101,  32,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  17,  6,  0,  0,  202,  228,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  17,  6,  0,  0,  122,  26,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  81,  129,  40,  0,  24,  142,  18,  6,  0,  0,  122,  26,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  108,  101,  115,  32,  100,  101,  117,  120,  32,  118,  105,  115,  0,  149,  1,  0,  0,  0,  97,  32,  108,  39,  97,  114,  114,  105,  101,  114,  101,  32,  112,  111,  117,  114,  32,  113,  117,  39,  0,  149,  1,  0,  0,  0,  117,  110,  101,  32,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  17,  6,  0,  0,  122,  26,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  42,  39,  0,  0,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  207,  249,  31,  0,  24,  142,  42,  39,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  108,  101,  115,  32,  100,  101,  117,  120,  32,  118,  105,  115,  0,  149,  1,  0,  0,  0,  97,  32,  100,  114,  111,  105,  116,  101,  32,  32,  32,  32,  112,  111,  117,  114,  32,  113,  117,  39,  0,  149,  1,  0,  0,  0,  117,  110,  101,  32,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  42,  39,  0,  0,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  248,  228,  255,  255,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  23,  240,  49,  0,  24,  142,  249,  228,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  65,  106,  117,  115,  116,  101,  122,  32,  108,  101,  115,  32,  100,  101,  117,  120,  32,  118,  105,  115,  0,  149,  1,  0,  0,  0,  97,  32,  103,  97,  117,  99,  104,  101,  32,  32,  32,  32,  112,  111,  117,  114,  32,  113,  117,  39,  0,  149,  1,  0,  0,  0,  117,  110,  101,  32,  102,  101,  117,  105,  108,  108,  101,  32,  115,  39,  97,  106,  117,  115,  116,  101,  0,  149,  7,  0,  0,  0,  101,  110,  116,  114,  101,  32,  116,  101,  116,  101,  32,  101,  116,  32,  112,  108,  97,  113,  117,  101,  0,  149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  142,  249,  228,  255,  255,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  17,  6,  0,  0,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  11,  248,  24,  0,  24,  142,  18,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  68,  101,  114,  110,  105,  101,  114,  101,  32,  118,  101,  114,  105,  102,  46,  32,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  108,  97,  32,  102,  101,  117,  105,  108,  108,  101,  32,  100,  101,  32,  112,  97,  112,  105,  101,  114,  0,  149,  1,  0,  0,  0,  100,  111,  105,  116,  32,  103,  108,  105,  115,  115,  101,  114,  32,  101,  110,  116,  114,  101,  32,  32,  0,  149,  7,  0,  0,  0,  108,  97,  32,  116,  101,  116,  101,  32,  101,  116,  32,  108,  97,  32,  112,  108,  97,  113,  117,  101,  0,  137,  31 };
# define LEVEL_PLATE_LEN_DUAL 1611
#endif

/// the home axes script homes the XYZ axes and recalls home positions
/// TODO Get the gcode for this array since there is a string that needs to be translated inside.
#define HOME_AXES_SCRIPT static uint8_t HomeAxes[] PROGMEM = { 149,  2,  0,  0,  0,  65,  116,  116,  101,  110,  100,  101,  122,  46,  46,  46,  0,  132,  3,  105,  1,  0,  0,  20,  0,  131,  4,  136,  0,  0,  0,  20,  0,  140,  0,  0,  0,  0,  0,  0,  0,  0,  48,  248,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  142,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  87,  41,  4,  0,  24,  131,  4,  220,  5,  0,  0,  20,  0,  140,  229,  55,  0,  0,  148,  27,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  137,  31 };
#define HOME_AXES_SCRIPT_LEN 111
