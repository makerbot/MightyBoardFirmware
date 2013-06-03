(**** This is a home axes script for any MakerBot Replicator ****)
G21 (set units to mm)
G90 (set positioning to absolute)
M70 ( Please wait...)

(**** begin homing ****)
G162 X Y F2500 (home XY axes maximum)
G161 Z F1100 (home Z axis minimum)
G92 Z-5 (set Z to -5)
G1 Z0.0 (move Z to "0")
G161 Z F100 (home Z axis minimum)
G92 X152 Y75 Z0
(M132 X Y Z A B (Recall stored home offsets for XYZAB axis)
(**** end homing ****)
