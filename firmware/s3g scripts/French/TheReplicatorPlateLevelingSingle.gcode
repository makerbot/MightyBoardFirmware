(**** This is a build-plate calibration script for a Single-Head MakerBot Replicator ****)
(**** Do not run this code on any other kind of machine! ****)
G21 (set units to mm)
G90 (set positioning to absolute)

M70 ( Attendez...)

(**** begin homing ****)
G162 X Y F2500 (home XY axes maximum)
G161 Z F1100 (home Z axis minimum)
G92 Z-5 (set Z to -5)
G1 Z0.0 (move Z to "0")
G161 Z F100 (home Z axis minimum)
G92 X152 Y75 Z0
(M132 X Y Z A B (Recall stored home offsets for XYZAB axis)
(**** end homing ****)

M71 (Tournez les 4 vis   sous la plaque      chauffante et serrezde quatre tours. )
M71 (On va ajuster la    tete , je vais donc la deplacer dans    plusieurs positions )
M71 (Afin de verifier la hauteur de la tete  Tournez les vis pourqu'elle touche...)
M71 (presque la plaque.  L'espace est juste  quand on peut mettreune fine feuille ...)
M71 (de papier qui touchela tete  et la      plaque d'extrusion. )
M70 ( Attendez...)

M70 ( Attendez...)
G1 Z5 F3300.0
G1 X0 Y-74 (Move to front of plate)
G1 Z0
M71 (Ajustez les deux visa l'avant   pour qu'une feuille s'ajusteentre tete et plaque)

M70 ( Attendez...)
G1 Z5 F3300.0
G1 X0 Y72 (Move to back of plate)
G1 Z0
M71 (Ajustez les deux visa l'arriere pour qu'une feuille s'ajusteentre tete et plaque)

M70 ( Attendez...)
G1 Z5 F3300.0
G1 Y0 X100
G1 Z0
M71 (Ajustez les deux visde droite   pour qu'une feuille s'ajusteentre tete et plaque)

M70 ( Attendez...)
G1 Z5 F3300.0
G1 X-100
G1 Z0
M71 (Ajustez les deux visde gauche   pour qu'une feuille s'ajusteentre tete et plaque)

M70 ( Attendez...)
G1 Z5 F3300.0
G1 Y0 X0
G1 Z0
M71 (Derniere verif.     la feuille de papierdoit glisser entre  la tete et la plaque) 
