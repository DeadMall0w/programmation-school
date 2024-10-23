


*Exemple de code* :
Paramètre : 
P1 : départ
P2 : tempon
P3 : Arrivée
n : taille de la pyramide
Fonction Hannoi(P1, P2, P3, n)
    si n > 1 alors
        Hannoi(P1, P3, P2, n-1)
        Déplacer(P1,P3)
        Hannoi(P2, P1, P3, n-1)
    sinon
        Déplacer(P1, P3)
    finsi
fin



**liste opération**
H(P1, P2, P3, 4)
-> H(P1,P3,P2,3)
    -> H(P1,P2,P3)
        -> ...
            -> ....
            Déplacer
        -> H ...
....

Remarque : La fonction correspond au meme étapes de déplacement pour une pyramide de 3 niv.
Dép-> Arr | temp
P1 -> P2  | P3
P1 -> P3  | P2
P2 -> P3  | P1
