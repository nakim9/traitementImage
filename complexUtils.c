#include <stdio.h>
#include <stdlib.h>
#include "complexUtils.h"


cplx ** creerTabCplx(int hauteur, int largeur){
  cplx ** tmp 	= NULL;

	/* ---Allocation--- */
	tmp	= (cplx **)malloc(sizeof(cplx *) * hauteur);

	if(tmp == NULL)
	{
		printf("Error malloc\n");
		return NULL;
	}

	for(int i=0 ; i < hauteur ; i++)
	{
		tmp[i]	= NULL;
		tmp[i]	= (cplx *) malloc(sizeof(cplx) * largeur);
		if(tmp[i] == NULL)
		{
			printf("Error malloc\n");
			return NULL;
		}
	}

  return tmp;
}

void transposee(cplx ** tab, int hauteur, int largeur){
  cplx ** cpy = creerTabCplx(hauteur,largeur);

	for (int i = 0; i < hauteur; i++) {
		for (int j = 0; j < largeur; j++) {
			cpy[i][j] = tab[i][j];
		}
	}

	for (int i = 0; i < hauteur; i++) {
		for (int j = 0; j < largeur; j++) {
			tab[i][j] = cpy[j][i];
		}
	}
  free(cpy);
}
