#include <stdio.h>
#include <stdlib.h>
#include "BmpLib.h"
#include "image.h"

int main(void)
{
    int choix;
	DonneesImageRGB *image = NULL;
	DonneesImageRGB *seuillage = NULL;
	image = lisBMPRGB("hibou.bmp");
	seuillage = lisBMPRGB("Seuillage.bmp");
	IMAGE * matrices=NULL;

	while(choix=!0)
    {

	printf("Traitement d'images\n");
	printf("1 - Negatif d'une image\n");
	printf("2 - Transformation en niveaux de gris d'un image couleur\n");
	printf("3 - Seuillage\n");
	printf("4 - Afficher image originale\n");
	printf("5 - Afficher image damier\n");
	printf("6 - Afficher image degrade\n");
	printf("0 - Quitter\n");
	scanf("%d",&choix);

	switch(choix)
	{
        case 1:
            matrices = creer3Matrices(image);
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
        case 0:
            printf("Bye Bye \n");
            return 0;
            break;



	}
    }


	return 0;
}

