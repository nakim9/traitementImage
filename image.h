#include "BmpLib.h"

typedef struct
{
	int hauteurImage;
	int largeurImage;
	unsigned short ** Bleu;
	unsigned short ** Vert;
	unsigned short ** Rouge;
} IMAGE;

IMAGE * creer3MatricesNegatif(DonneesImageRGB *image);

DonneesImageRGB * creerImage(IMAGE *image);

IMAGE * creer3MatricesNormal(DonneesImageRGB *image);

IMAGE * creer3MatricesNuancedegris(DonneesImageRGB *image);

IMAGE * creer3MatricesSeuillage(DonneesImageRGB *image);

IMAGE * creer3MatricesDamier(DonneesImageRGB *image);

IMAGE * creer3MatricesDegrade(DonneesImageRGB *image);

IMAGE * creerVagueSinuosidaleHorizontale();

IMAGE * creerVagueSinuosidaleDiagonales();

IMAGE * creerVagueSinuosidaleVerticale();

IMAGE * creerFFT(IMAGE * matrices);

IMAGE * creerImageVide(int hauteur, int largeur);
