#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "dict.h"
#include <ctype.h>
#include <string.h>


void afficher_resultat(const char *secret,const char *prop){
	for (int i = 0; i < 5 ; i++){
		if (prop[i] == secret[i]){
			printf("v");}
		else if (strchr(secret,prop[i])){
			printf("o");}
		else { printf("x");}
	}

	printf("\n");
}

int main(){
	char mots[MAX_MOTS][LEN_MOT];
	int nb = charger_dict(mots,"resource/bdd_wordle.txt");

	srand(time(NULL));
	char *secret = mots[rand() % nb];

	int essais = 0;
	int gagne = 0;
	char rejouer;

	do{

		while (essais < 6 && !gagne){
			char prop[LEN_MOT];

			do {
				printf("Proposer un mot :");
				scanf("%5s",prop);

				// met le mot en minuscules

				for (int i = 0; prop[i]; i++) {
					prop[i] = tolower(prop[i]);
				}
			} while (!mot_valide(mots,nb,prop));

			essais++;
			afficher_resultat(secret,prop);

			if (strcmp(prop,secret) == 0){ gagne = 1;}
		}

		if (gagne)
			printf("Bravo, vous avez gagne en %d coups!\n", essais);
		else
			printf("Perdu! Le mot etait : %s\n",secret);

	printf("Rejouer ?  (o/n) : ");
	scanf("%c", &rejouer);
	}while(rejouer == 'o' || rejouer == 'O');
}

