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
