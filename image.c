#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "image.h"


IMAGE * creer3Matrices(DonneesImageRGB * image){
  /*  Partie Déclarative  */
  int hauteurImage = image->hauteurImage;
  int largeurImage = image->largeurImage;
  short ** bleu = NULL;
  short ** vert = NULL;
  short ** rouge = NULL;

  bleu  = (short **) malloc(sizeof(short *) * hauteurImage);
  vert  = (short **) malloc(sizeof(short *) * hauteurImage);
  rouge = (short **) malloc(sizeof(short *) * hauteurImage);
  if(bleu == NULL || vert == NULL || rouge == NULL) return NULL;

  for(int i = 0 ; i < hauteurImage ; i++){
    bleu[i]   = NULL;
    vert[i]   = NULL;
    rouge[i]  = NULL;
    bleu[i]   = (short *) malloc(sizeof(short) * largeurImage);
    vert[i]   = (short *) malloc(sizeof(short) * largeurImage);
    rouge[i]  = (short *) malloc(sizeof(short) * largeurImage);
    if(bleu[i] == NULL || vert[i] == NULL || rouge[i] == NULL) return NULL;
  }

  /*
    * Insertion dans les matrices
    * i index de ligne des matrices (hauteur)
    * j index de colonne des matrices (largeur)
    * matrice[ligne][colonne] = Liste[
    *       ligne*hauteur*3 (decalage de ligne multiplié par 3 car on a des des paquets de 3 informations à chaque fois)
    *       + colonne*largeurImage (decalage de colonne)
    *       + pos (position de l'élément recherche, prendre les valeurs {1,2,3})
    *     ]
    * EXEMPLE
    * Liste : [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27]
    * Matrices :    ⎡ 1  4  7⎤      ⎡ 2  5  8⎤      ⎡ 3  6  9⎤
    *           B = ⎢10 13 16⎢  V = ⎢11 14 17⎢  R = ⎢12 15 18⎥
    *               ⎣19 22 25⎦      ⎣20 23 26⎦      ⎣21 24 27⎦
  */
  for(int i = 0 ; i < hauteurImage ; i++){
    for (int j = 0 ; j < largeurImage ; j++) {
      short posB = 0;
      short posV = 1;
      short posR = 2;

      bleu[i][j]  = image->donneesRGB[i*hauteurImage*3 + j*3 + posB];
      vert[i][j]  = image->donneesRGB[i*hauteurImage*3 + j*3 + posV];
      rouge[i][j] = image->donneesRGB[i*hauteurImage*3 + j*3 + posR];


    }
  }
  IMAGE * couleur = NULL;
  couleur = malloc(sizeof(IMAGE));

  couleur->rouge = rouge;
  couleur->vert = vert;
  couleur->bleu = bleu;

  return couleur;
}

int creerImage(DonneesImageRGB * donnees, IMAGE * image){
  puts("creerImage\n");
  return 0;
}

int main(int argc, char const *argv[]) {
  DonneesImageRGB * data = malloc(sizeof(DonneesImageRGB));
  data->largeurImage = 3;
  data->hauteurImage = 3;
  data->donneesRGB = malloc(sizeof(char)*27);
  for (int i = 0; i < 27; i++) {
    *(data->donneesRGB+i) = i+1;
  }
  IMAGE * image = creer3Matrices(data);
  for(int i = 0 ; i < 3 ; i++){
    printf("%2d %2d %2d  %2d %2d %2d  %2d %2d %2d\n", image->bleu[i][0], image->bleu[i][1], image->bleu[i][2], image->vert[i][0], image->vert[i][1], image->vert[i][2], image->rouge[i][0], image->rouge[i][1], image->rouge[i][2]);
  }
  return 0;
}
