#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BmpLib.h"
#include "image.h"

void menufft(void);

int main(void)
{
    int choix;
	DonneesImageRGB *image = NULL;
	image = lisBMPRGB("hibou.bmp");
	IMAGE * matrices=NULL;

	while(choix)
    {

	printf("Traitement d'images\n");
	printf("1 - Negatif d'une image\n");
	printf("2 - Transformation en niveaux de gris d'un image couleur\n");
	printf("3 - Seuillage\n");
	printf("4 - Afficher image originale\n");
	printf("5 - Afficher image damier\n");
	printf("6 - Afficher image degrade\n");
  printf("7 - FFT\n");
	printf("0 - Quitter\n");
	scanf("%d",&choix);

	switch(choix)
	{
        case 1:
            matrices = creer3MatricesNegatif(image);
            image = creerImage(matrices);
            ecrisBMPRGB_Dans(image,"Negatif.bmp");
            printf("Fichier copie sous le nom de Negatif\n");
            break;
        case 4:
            matrices = creer3MatricesNormal(image);
            image = creerImage(matrices);
            ecrisBMPRGB_Dans(image,"Hibou copie.bmp");
            printf("Fichier copie sous le nom de Hibou copie\n");
            break;
        case 2:
            matrices = creer3MatricesNuancedegris(image);
            image = creerImage(matrices);
            ecrisBMPRGB_Dans(image,"Nuance de gris.bmp");
            printf("Fichier copie sous le nom de Nuance de gris\n");
            break;
        case 3:
            matrices = creer3MatricesSeuillage(image);
            image = creerImage(matrices);
            ecrisBMPRGB_Dans(image,"Seuillage.bmp");
            printf("Fichier copie sous le nom de Seuillage\n");
            break;
        case 5:
            matrices = creer3MatricesDamier(image);
            image = creerImage(matrices);
            ecrisBMPRGB_Dans(image,"Damier.bmp");
            printf("Fichier copie sous le nom de Damier\n");
            break;
         case 6:
            matrices = creer3MatricesDegrade(image);
            image = creerImage(matrices);
            ecrisBMPRGB_Dans(image,"Degrade.bmp");
            printf("Fichier copie sous le nom de Degrade\n");
            break;
        case 7:
            menufft();
            break;
        case 0:
            printf("Bye Bye \n");
            return 0;
            break;
	}
    }


	return 0;
}

void menufft(void){
  int choix;
  DonneesImageRGB * rgb = NULL;
  IMAGE * matrice = NULL;
  while(choix){
    puts("  - Sur quel type d'image voulez vous faire une transformée ?\n");
    puts("  - 1 Sinusoïde verticale");
    puts("  - 2 Sinusoïde horizontale");
    puts("  - 3 Sinusoïde diagonale");
    puts("  - 4 Une image de chouette");
    puts("  - 5 Un damier");
    puts("  - 6 Un dégradé");
    puts("  - 0 Aucune");
    scanf("%d",&choix);
    char nomfori[32];
    char nomffft[32];
    switch (choix) {
      case 1:
      strcpy(nomfori,"sinv.bmp");
      strcpy(nomffft,"fftv.bmp");
      matrice = creerVagueSinuosidaleVerticale();
      rgb = creerImage(matrice);
      ecrisBMPRGB_Dans(rgb, nomfori);

      matrice = creerFFT(matrice);
      rgb = creerImage(matrice);
      ecrisBMPRGB_Dans(rgb, nomffft);
      printf("    Image originale créée : %s\n    Image transformée créée : %s\n", nomfori, nomffft);
      break;

      case 2:
      strcpy(nomfori,"sinh.bmp");
      strcpy(nomffft,"ffth.bmp");
      matrice = creerVagueSinuosidaleHorizontale();
      rgb = creerImage(matrice);
      ecrisBMPRGB_Dans(rgb, nomfori);

      matrice = creerFFT(matrice);
      rgb = creerImage(matrice);
      ecrisBMPRGB_Dans(rgb, nomffft);
      printf("    Image originale créée : %s\n    Image transformée créée : %s\n", nomfori, nomffft);
      break;

      case 3:
      strcpy(nomfori,"sind.bmp");
      strcpy(nomffft,"fftd.bmp");
      matrice = creerVagueSinuosidaleDiagonales();
      rgb = creerImage(matrice);
      ecrisBMPRGB_Dans(rgb, nomfori);

      matrice = creerFFT(matrice);
      rgb = creerImage(matrice);
      ecrisBMPRGB_Dans(rgb, nomffft);
      printf("    Image originale créée : %s\n    Image transformée créée : %s\n", nomfori, nomffft);
      break;

      case 4:
      strcpy(nomfori,"hibou.bmp");
      strcpy(nomffft,"ffthibou.bmp");

      matrice = creer3MatricesNormal(lisBMPRGB(nomfori));
      matrice = creerFFT(matrice);
      rgb = creerImage(matrice);
      ecrisBMPRGB_Dans(rgb, nomffft);
      printf("    Image originale créée : %s\n    Image transformée créée : %s\n", nomfori, nomffft);
      break;

      case 5:
      strcpy(nomfori,"damier.bmp");
      strcpy(nomffft,"fftdamier.bmp");

      matrice = creer3MatricesDamier(creerImage(creerImageNoire()));
      rgb = creerImage(matrice);
      ecrisBMPRGB_Dans(rgb,nomfori);

      matrice = creerFFT(matrice);
      rgb = creerImage(matrice);
      ecrisBMPRGB_Dans(rgb, nomffft);
      printf("    Image originale créée : %s\n    Image transformée créée : %s\n", nomfori, nomffft);
      break;

      case 6:
      strcpy(nomfori,"degrade.bmp");
      strcpy(nomffft,"fftdegrade.bmp");

      matrice = creer3MatricesDegrade(creerImage(creerImageNoire()));
      rgb = creerImage(matrice);
      ecrisBMPRGB_Dans(rgb,nomfori);

      matrice = creerFFT(matrice);
      rgb = creerImage(matrice);
      ecrisBMPRGB_Dans(rgb, nomffft);
      printf("    Image originale créée : %s\n    Image transformée créée : %s\n", nomfori, nomffft);
      break;

      case 0:
      puts("Retour au menu principal\n");
      break;
    }
  }
}
