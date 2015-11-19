// auteur : Keryann Bussereau

#include <stdio.h>
#include <stdlib.h>
#define N 10
int pile[N];
int sommet;

void initpile(void) {
	sommet=-1;
}

void empiler(int c) {
	if(sommet<N-1) {
		sommet++;
		pile[sommet]=c;
	}
}

void depiler(int * v) {
	if(sommet>-1) {
		*v=pile[sommet];
		sommet--;
	}
}

int pilevide(void) {
	return(sommet==-1);
}
