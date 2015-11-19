main : tp3.o liste_ptr.o
	gcc -o main tp3.o liste_ptr.o -lm
tp3.o : tp3.c liste.h
	gcc -c tp3.c liste.h -g -Wall
liste.o : liste_ptr.c
	gcc -c liste_ptr.c -g -Wall
