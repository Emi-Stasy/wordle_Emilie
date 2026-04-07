#ifndef dict_h

#define dict_h

#define MAX_MOTS 10000

#define LEN_MOT 6 // 5 lettres + '\0'

int charger_dict(char mot[][LEN_MOT],const char *chemin);
int mot_valide(char mots[][LEN_MOT],int nb, const char *mot);

#endif
