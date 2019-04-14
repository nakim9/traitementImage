#include "BmpLib.h"

typedef struct 
{
	int hauteurImage;
	int largeurImage;
	short ** Bleu;
	short ** Vert;
	short ** Rouge;
} IMAGE;

IMAGE * creer3Matrices(DonneesImageRGB *image);

DonneesImageRGB * creerImage(IMAGE *image);
 
