#include "BmpLib.h"

typedef struct
{
	int hauteurImage;
	int largeurImage;
	short ** Bleu;
	short ** Vert;
	short ** Rouge;
} IMAGE;

IMAGE * creer3MatricesNegatif(DonneesImageRGB *image);

DonneesImageRGB * creerImage(IMAGE *image);

IMAGE * creer3MatricesNormal(DonneesImageRGB *image);

IMAGE * creer3MatricesNuancedegris(DonneesImageRGB *image);

IMAGE * creer3MatricesSeuillage(DonneesImageRGB *image);

IMAGE * creer3MatricesDamier(DonneesImageRGB *image);

IMAGE * creer3MatricesDegrade(DonneesImageRGB *image);

IMAGE * creerImageNoire(void);

IMAGE * creerVagueSinuosidaleHorizontale();

IMAGE * creerVagueSinuosidaleDiagonales();

IMAGE * creerVagueSinuosidaleVerticale();

IMAGE * creerFFT(IMAGE * matrices);
