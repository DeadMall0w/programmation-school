all : annuaire


annuaire : libannu.o
	gcc annuaire.o libannu.o -o annuaire

libannu.o : 
	gcc -c libannu.c


.PHONY : clean
clean:
	rm libannu.o annuaire