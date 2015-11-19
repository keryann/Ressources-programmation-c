// auteur : Keryann Bussereau

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "liste_ptr.h"


void afficher() {
/* Affiche les valeurs de la liste */
	int val, pui;

	if(liste_vide())
		printf("La liste est vide\n");
	else {
		printf("\nLe polynome est ");
		en_tete();
		valeur_elt(&val, &pui);
        printf("%ix%i",val, pui);
        suivant();

		while(!hors_liste()) {
			valeur_elt(&val, &pui);
			if(pui==0) // pas de x puisque x^0=1
                printf(" + %i", val);
            else if (pui==1) //pas de puissance à afficher x^1=x
                printf(" + %ix", val);
            else
                printf(" + %ix%i",val, pui);
			suivant();
		}
		printf("\n");
	}
}

void saisie() {
    /* Crée une liste */
    int val, pui;

    init_liste();
    printf("\nSaisir une suite de valeur tel que : valeur puissanece valeur puissance terminée par deux 0 : ");
    scanf("%i%i", &val, &pui);

    while(val!=0 || pui!=0) {
        ajout_droit(val, pui);
        scanf("%i%i", &val, &pui);
    }
}

void parite() {
    /* On calcule si le polynome est pair ou impair*/
    int resa, resb, val, pui, i;

    en_tete();
    valeur_elt(&val, &pui);
    suivant();

    resa=val*pow(2, pui);
    resb=val*pow(-2, pui);

    while(!hors_liste()) {
	    valeur_elt(&val, &pui);
        suivant();
        resa+=val*pow(2, pui);
        resb+=val*pow(-2, pui);
    }
    if (resa==0) {
        for(i=0;resa==0;i++){
            resa=val*pow(2+i, pui);
            resb=val*pow(-2-i, pui);
            while(!hors_liste()) {
                valeur_elt(&val, &pui);
                suivant();
                resa+=val*pow(2+i, pui);
                resb+=val*pow(-2-i, pui);
            }
        }
    }
    else if (resa-resb==0)
        printf("\nIl s'agit d'un polynome pair\n");
    else
        printf("\nIl s'agit d'un polynome impair\n");
}

void derivee() {
    int val, pui;

    en_tete();

    while(!hors_liste()){
        valeur_elt(&val, &pui);
        if(pui==0)
            oter_elt();
        else
            modif_elt(val*pui, pui-1);
        suivant();
    }
}

/* Programme principal */
int main(void) {
    int choix;

    /* Initialisation de la liste*/
    init_liste();

    /* Affichage du menu et saisie du choix */
    do {
        printf("\nMenu : \n");
        printf(" 1 - Entrer un polynome\n");
        printf(" 2 - Tester la parite\n");
        printf(" 3 - Calculer la derivee\n");
        printf(" 4 - Quitter \n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        /* Traitement du choix de l'utilisateur */
        switch (choix) {
            case 1 : saisie(); afficher(); break;
            case 2 : parite(); afficher(); break;
            case 3 : derivee(); afficher(); break;
            case 4 : break;
            default : printf("Erreur : votre choix doit être compris entre 1 et 4\n");
        }
    }
    while(choix!=4);
    printf("Au revoir !\n");
}
