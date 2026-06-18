list p=18f452  
#include p18f452.inc  # Inclusion la librairie 18f452
variables UDATA
temp res 1 # reserve 1 octet pour une variable nommé temp

org 0 # Définit le debut du programme en tant que 0
nop # Ne fait rien
goto Start # Se deplace à l'étiquette Start

org 2A  # Définit le début du programme en tant que 2A (hexa)
Start  # Etiquette Start
movlw 45   # Charge 45 en hexadécimal soit 69 en base 10 dans W
movwf temp    # Deplace W dans temp
addwf temp,0  # Effectue W = W + temp => 138 en base 10
btfss WREG,3 # Regarde le 3eme bit de W (10001010 en binaire)  égal à 1 donc saute la prochaine étape (PC + 4)
swapf temp   # Ignoré 
andwf temp   # Fait un et logique entre W (138 en base 10) et temp (69 en base 10) et stocke le résultat dans temp, temp = 0 
nop # ne fait rien 
end # fin du programme