# Règle principale
main: main.o utils.o
	gcc -o main main.o utils.o

# Règle pour compiler main.c en main.o
main.o: main.c utils.h
	gcc -c main.c

# Règle pour compiler utils.c en utils.o
utils.o: utils.c utils.h
	gcc -c utils.c


# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f main.o utils.o main