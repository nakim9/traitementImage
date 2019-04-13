#include "BmpLib.h"

typedef struct image{
  short ** rouge;
  short ** vert;
  short ** bleu;
}IMAGE;

IMAGE * creer3Matrices(DonneesImageRGB * image);

int creerImage(DonneesImageRGB * donnees, IMAGE * image);
