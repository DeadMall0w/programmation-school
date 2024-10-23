Exercice : Calcul de somme
**Fonction récursive**
fonction CalculSomme(n)
    si n=1 alors
        return 1
    sinon
        return CalculSomme(n-1) + 1/(n*n) 


**Fonction itérative**
```
Fonction sommeCarre(precision, n)
    n <- 2
    somme <- 1
    tantque (1/n*n > precision)
        somme <- somme + 1/(n*n)
        n <- n+1
    fintantque
    retourner somme
    fin
        

```
