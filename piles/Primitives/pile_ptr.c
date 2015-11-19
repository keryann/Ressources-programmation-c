#include <stdio.h>
#include <stdlib.h>

typedef struct element{char c; struct element * suivant;}t_element;
t_element * pile;


void initpile(void) {
	pile = NULL;
}

int pilevide(void) {
	return(pile==NULL);
}

void empiler(int caract){
	t_element * nouv;
	
	nouv = (t_element*)malloc(sizeof(t_element));
	nouv -> c = caract;
	nouv -> suivant = pile;
	pile = nouv;
}

void depiler(int * caract) {
	t_element * sommet;

	if (pile!=NULL){
		*caract = pile -> c;
		sommet = pile;
		pile = sommet -> suivant;
		free(sommet);
    }
}

