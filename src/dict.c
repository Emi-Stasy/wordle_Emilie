#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dict.h"

int charger_dict(char mots[][LEN_MOT], const char *chemin){

	FILE *f = fopen(chemin,"r");

	if (!f) {
	perror("Erreur ouverture fichier");
	return 0;
	}

	char ligne[64]
	int nb = 0;

	while(fgets(ligne, sizeof(ligne),f) && nb < MAX_MOTS) {

		ligne[strcspn(ligne,"\n\")] = '\0';

		if (strlen(ligne) == 5 {
			int ok = 1;
			for (int i = 0; i < 5; i++)
				if(!isalpha(ligne[i])) { ok = 0; break;}
			if (ok) strcpy(mots[nb++],ligne);
		}
	}
	fclose(f);
	return nb;

}

int mot_valide(char mots[][LEN_MOT],int nb, const char *mot){
	for (int i = 0 ; i < nb; i++)
		if (strcmp(mots[i], mot) == 0 return 1;
	return 0;
}
