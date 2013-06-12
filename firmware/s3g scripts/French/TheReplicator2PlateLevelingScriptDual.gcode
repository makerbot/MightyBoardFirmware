(**** This is a build-platform calibration script for a Dual-Head MakerBot Replicator2 ****)
(**** Do not run this code on any other kind of machine! ****)
G21
G90

; Display a message to explain leveling

M70 ( Attendez...)

G162 X Y F2500 (home XY axes maximum)
G161 Z F1100 (home Z axis minimum)
G92 Z-5 (set Z to -5)
G1 Z0.0 (move Z to "0")
G161 Z F100 (home Z axis minimum)
G92 X152 Y75 Z0 

M71 (Tournez les 3 vis   sous la plaque      chauffante et serrezde quatre tours. )
M71 (On va ajuster les   tetes, je vais donc les deplacer dans   plusieurs positions )
M71 (Afin de verifier la hauteur des tetes   Tournez la vis pour qu'elles touchent...)
M71 (presque la plaque.  L'espace est juste  quand on peut mettreune fine feuille ...)
M71 (de papier qui toucheles tetes et la     plaque d'extrusion. )

M70 ( Attendez...)
; move to rear leveling pin
G1 X16.5 Y70 F3000
G1 Z0 F1000
M71 (Ajustez a l'arriere la vis pour qu'une  feuille s'ajuste    entre tete et plaque)
M70 ( Attendez...)
G1 Z5

; move to front right pin
G1 Y-70 X64.5 F3000
G1 Z0 F1000
M71 (Ajustez la vis avantdroite pour qu'une  feuille s'ajuste    entre tete et plaque)
M70 ( Attendez...)
G1 Z5

; move to front left pin
G1 X-33.5 Y-70 F3000
G1 Z0 F1000
M71 (Ajustez la vis avantgauche pour qu'une  feuille s'ajuste    entre tete et plaque)
M70 ( Attendez...)
G1 Z5

; repeat process to check leveling

M71 (Maintenant je vais  repasser ma tete surles trois coins pourvalider a nouveau.)
M70 ( Attendez...)
; move to rear levelling pin
G1 X16.5 Y70 F5000
G1 Z0 F1000
M71 (Ajustez a l'arriere la vis pour qu'une  feuille s'ajuste    entre tete et plaque)
M70 ( Attendez...)
G1 Z5

; move to front right pin
G1 Y-70 X119 F5000 
G1 Z0 F1000
M71 (Ajustez la vis avantdroite pour qu'une  feuille s'ajuste    entre tete et plaque)
M70 ( Attendez...)
G1 Z5

; move to front left pin
G1 Y-70 X-86.5 F5000
G1 Z0 F1000
M71 (Ajustez la vis avantgauche pour qu'une  feuille s'ajuste    entre tete et plaque)
M70 ( Attendez...)
G1 Z5

; move to center
G1 X16.5 Y0 F5000
G1 Z0 F1000
M71 (Derniere verif.     la feuille de papierdoit glisser entre  la tete et la plaque) 
