#include <stdlib.h>
#include <stdio.h>
#include "image.h"



IMAGE * creer3MatricesDegrade(DonneesImageRGB *image)
{
	/* ---Variables--- */
	int hauteurImage = image->hauteurImage;
	int largeurImage = image->largeurImage;
	short ** bleu 	= NULL;
	short ** vert 	= NULL;
	short ** rouge 	= NULL;
	int r=0;

	/* ---Allocation--- */
	bleu	= (short **)malloc(sizeof(short *) * hauteurImage);
	vert	= (short **)malloc(sizeof(short *) * hauteurImage);
	rouge	= (short **)malloc(sizeof(short *) * hauteurImage);

	if(bleu == NULL || vert == NULL || rouge == NULL)
	{
		printf("Error malloc\n");
		return NULL;
	}

	for(int i=0 ; i < hauteurImage ; i++)
	{
		bleu[i]	= NULL;
		vert[i]	= NULL;
		rouge[i]	= NULL;

		bleu[i]	= (short *)malloc(sizeof(short) * largeurImage);
		vert[i]	= (short *)malloc(sizeof(short) * largeurImage);
		rouge[i]	= (short *)malloc(sizeof(short) * largeurImage);

		if(bleu[i] == NULL || vert[i] == NULL || rouge[i] == NULL)
		{
			printf("Error malloc\n");
			return NULL;
		}
	}

	/* ---Insertion dans les matrices--- */
	for(int i=0 ; i < hauteurImage ; i++)
	{
		for(int j=0 ; j < largeurImage ; j++)
		{
			short posB = 0;
			short posV = 1;
			short posR = 2;

			bleu[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posB];
			vert[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posV];
			rouge[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posR];

			if(j!=255)
            {
                bleu[i][j]=255-r;
                rouge[i][j]=255-r;
                vert[i][j]=255-r;
            }
            else
            {
                bleu[i][j]=255-r;
                rouge[i][j]=255-r;
                vert[i][j]=255-r;
                r++;
            }


		}
	}

	IMAGE * couleur = NULL;
	couleur = malloc(sizeof(IMAGE));

	couleur->hauteurImage = hauteurImage;
	couleur->largeurImage = largeurImage;
	couleur->Bleu = bleu;
	couleur->Vert = vert;
	couleur->Rouge = rouge;

	return couleur;
}


IMAGE * creer3MatricesDamier(DonneesImageRGB *image)
{
	/* ---Variables--- */
	int hauteurImage = image->hauteurImage;
	int largeurImage = image->largeurImage;
	short ** bleu 	= NULL;
	short ** vert 	= NULL;
	short ** rouge 	= NULL;
	short ** nb = NULL;

	/* ---Allocation--- */
	bleu	= (short **)malloc(sizeof(short *) * hauteurImage);
	vert	= (short **)malloc(sizeof(short *) * hauteurImage);
	rouge	= (short **)malloc(sizeof(short *) * hauteurImage);

	if(bleu == NULL || vert == NULL || rouge == NULL)
	{
		printf("Error malloc\n");
		return NULL;
	}

	for(int i=0 ; i < hauteurImage ; i++)
	{
		bleu[i]	= NULL;
		vert[i]	= NULL;
		rouge[i]	= NULL;

		bleu[i]	= (short *)malloc(sizeof(short) * largeurImage);
		vert[i]	= (short *)malloc(sizeof(short) * largeurImage);
		rouge[i]	= (short *)malloc(sizeof(short) * largeurImage);

		if(bleu[i] == NULL || vert[i] == NULL || rouge[i] == NULL)
		{
			printf("Error malloc\n");
			return NULL;
		}
	}

	/* ---Insertion dans les matrices--- */
	for(int i=0 ; i < hauteurImage ; i++)
	{
		for(int j=0 ; j < largeurImage ; j++)
		{
			short posB = 0;
			short posV = 1;
			short posR = 2;

			bleu[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posB];
			vert[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posV];
			rouge[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posR];

			if(((i/64)+(j/64))%2)
            {
                bleu[i][j]=255;
                rouge[i][j]=255;
                vert[i][j]=255;
            }
            else
            {
               bleu[i][j]=0;
                rouge[i][j]=0;
                vert[i][j]=0;
            }


		}
	}

	IMAGE * couleur = NULL;
	couleur = malloc(sizeof(IMAGE));

	couleur->hauteurImage = hauteurImage;
	couleur->largeurImage = largeurImage;
	couleur->Bleu = bleu;
	couleur->Vert = vert;
	couleur->Rouge = rouge;

	return couleur;
}



IMAGE * creer3MatricesSeuillage(DonneesImageRGB *image)
{
	/* ---Variables--- */
	int hauteurImage = image->hauteurImage;
	int largeurImage = image->largeurImage;
	short ** bleu 	= NULL;
	short ** vert 	= NULL;
	short ** rouge 	= NULL;
	short ** gris   = NULL;

	/* ---Allocation--- */
	bleu	= (short **)malloc(sizeof(short *) * hauteurImage);
	vert	= (short **)malloc(sizeof(short *) * hauteurImage);
	rouge	= (short **)malloc(sizeof(short *) * hauteurImage);
	gris	= (short **)malloc(sizeof(short *) * hauteurImage);

	if(bleu == NULL || vert == NULL || rouge == NULL || gris == NULL)
	{
		printf("Error malloc\n");
		return NULL;
	}

	for(int i=0 ; i < hauteurImage ; i++)
	{
		bleu[i]	= NULL;
		vert[i]	= NULL;
		rouge[i]	= NULL;
		gris[i]	= NULL;

		bleu[i]	= (short *)malloc(sizeof(short) * largeurImage);
		vert[i]	= (short *)malloc(sizeof(short) * largeurImage);
		rouge[i]	= (short *)malloc(sizeof(short) * largeurImage);
		gris[i]	= (short *)malloc(sizeof(short) * largeurImage);

		if(bleu[i] == NULL || vert[i] == NULL || rouge[i] == NULL || gris[i] == NULL)
		{
			printf("Error malloc\n");
			return NULL;
		}
	}

	/* ---Insertion dans les matrices--- */
	for(int i=0 ; i < hauteurImage ; i++)
	{
		for(int j=0 ; j < largeurImage ; j++)
		{
			short posB = 0;
			short posV = 1;
			short posR = 2;

			bleu[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posB];
			vert[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posV];
			rouge[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posR];
			gris[i][j] = (rouge[i][j]+vert[i][j]+rouge[i][j])/3;

			if(gris[i][j] <= 128)
            {
                gris[i][j]=0;
            }
            else
            {
                gris[i][j]=255;
            }
		}
	}

	IMAGE * couleur = NULL;
	couleur = malloc(sizeof(IMAGE));

	couleur->hauteurImage = hauteurImage;
	couleur->largeurImage = largeurImage;
	couleur->Bleu = gris;
	couleur->Vert = gris;
	couleur->Rouge = gris;

	return couleur;
}





IMAGE * creer3MatricesNuancedegris(DonneesImageRGB *image)
{
	/* ---Variables--- */
	int hauteurImage = image->hauteurImage;
	int largeurImage = image->largeurImage;
	short ** bleu 	= NULL;
	short ** vert 	= NULL;
	short ** rouge 	= NULL;
	short ** gris   = NULL;

	/* ---Allocation--- */
	bleu	= (short **)malloc(sizeof(short *) * hauteurImage);
	vert	= (short **)malloc(sizeof(short *) * hauteurImage);
	rouge	= (short **)malloc(sizeof(short *) * hauteurImage);
	gris	= (short **)malloc(sizeof(short *) * hauteurImage);

	if(bleu == NULL || vert == NULL || rouge == NULL || gris == NULL)
	{
		printf("Error malloc\n");
		return NULL;
	}

	for(int i=0 ; i < hauteurImage ; i++)
	{
		bleu[i]	= NULL;
		vert[i]	= NULL;
		rouge[i]	= NULL;
		gris[i]	= NULL;

		bleu[i]	= (short *)malloc(sizeof(short) * largeurImage);
		vert[i]	= (short *)malloc(sizeof(short) * largeurImage);
		rouge[i]	= (short *)malloc(sizeof(short) * largeurImage);
		gris[i]	= (short *)malloc(sizeof(short) * largeurImage);

		if(bleu[i] == NULL || vert[i] == NULL || rouge[i] == NULL || gris[i] == NULL)
		{
			printf("Error malloc\n");
			return NULL;
		}
	}

	/* ---Insertion dans les matrices--- */
	for(int i=0 ; i < hauteurImage ; i++)
	{
		for(int j=0 ; j < largeurImage ; j++)
		{
			short posB = 0;
			short posV = 1;
			short posR = 2;

			bleu[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posB];
			vert[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posV];
			rouge[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posR];
			gris[i][j] = (rouge[i][j]+vert[i][j]+rouge[i][j])/3;
		}
	}

	IMAGE * couleur = NULL;
	couleur = malloc(sizeof(IMAGE));

	couleur->hauteurImage = hauteurImage;
	couleur->largeurImage = largeurImage;
	couleur->Bleu = gris;
	couleur->Vert = gris;
	couleur->Rouge = gris;

	return couleur;
}




IMAGE * creer3MatricesNormal(DonneesImageRGB *image)
{
	/* ---Variables--- */
	int hauteurImage = image->hauteurImage;
	int largeurImage = image->largeurImage;
	short ** bleu 	= NULL;
	short ** vert 	= NULL;
	short ** rouge 	= NULL;

	/* ---Allocation--- */
	bleu	= (short **)malloc(sizeof(short *) * hauteurImage);
	vert	= (short **)malloc(sizeof(short *) * hauteurImage);
	rouge	= (short **)malloc(sizeof(short *) * hauteurImage);

	if(bleu == NULL || vert == NULL || rouge == NULL)
	{
		printf("Error malloc\n");
		return NULL;
	}

	for(int i=0 ; i < hauteurImage ; i++)
	{
		bleu[i]	= NULL;
		vert[i]	= NULL;
		rouge[i]	= NULL;

		bleu[i]	= (short *)malloc(sizeof(short) * largeurImage);
		vert[i]	= (short *)malloc(sizeof(short) * largeurImage);
		rouge[i]	= (short *)malloc(sizeof(short) * largeurImage);

		if(bleu[i] == NULL || vert[i] == NULL || rouge[i] == NULL)
		{
			printf("Error malloc\n");
			return NULL;
		}
	}

	/* ---Insertion dans les matrices--- */
	for(int i=0 ; i < hauteurImage ; i++)
	{
		for(int j=0 ; j < largeurImage ; j++)
		{
			short posB = 0;
			short posV = 1;
			short posR = 2;

			bleu[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posB];
			vert[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posV];
			rouge[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posR];

		}
	}

	IMAGE * couleur = NULL;
	couleur = malloc(sizeof(IMAGE));

	couleur->hauteurImage = hauteurImage;
	couleur->largeurImage = largeurImage;
	couleur->Bleu = bleu;
	couleur->Vert = vert;
	couleur->Rouge = rouge;

	return couleur;
}


IMAGE * creer3Matrices(DonneesImageRGB *image)
{
	/* ---Variables--- */
	int hauteurImage = image->hauteurImage;
	int largeurImage = image->largeurImage;
	short ** bleu 	= NULL;
	short ** vert 	= NULL;
	short ** rouge 	= NULL;

	/* ---Allocation--- */
	bleu	= (short **)malloc(sizeof(short *) * hauteurImage);
	vert	= (short **)malloc(sizeof(short *) * hauteurImage);
	rouge	= (short **)malloc(sizeof(short *) * hauteurImage);

	if(bleu == NULL || vert == NULL || rouge == NULL)
	{
		printf("Error malloc\n");
		return NULL;
	}

	for(int i=0 ; i < hauteurImage ; i++)
	{
		bleu[i]	= NULL;
		vert[i]	= NULL;
		rouge[i]	= NULL;

		bleu[i]	= (short *)malloc(sizeof(short) * largeurImage);
		vert[i]	= (short *)malloc(sizeof(short) * largeurImage);
		rouge[i]	= (short *)malloc(sizeof(short) * largeurImage);

		if(bleu[i] == NULL || vert[i] == NULL || rouge[i] == NULL)
		{
			printf("Error malloc\n");
			return NULL;
		}
	}

	/* ---Insertion dans les matrices--- */
	for(int i=0 ; i < hauteurImage ; i++)
	{
		for(int j=0 ; j < largeurImage ; j++)
		{
			short posB = 0;
			short posV = 1;
			short posR = 2;

			bleu[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posB];
			vert[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posV];
			rouge[i][j] = image->donneesRGB[i*largeurImage*3 + j*3 + posR];
			bleu[i][j]=255-bleu[i][j];
			vert[i][j]=255-vert[i][j];
			rouge[i][j]=255-rouge[i][j];
		}
	}

	IMAGE * couleur = NULL;
	couleur = malloc(sizeof(IMAGE));

	couleur->hauteurImage = hauteurImage;
	couleur->largeurImage = largeurImage;
	couleur->Bleu = bleu;
	couleur->Vert = vert;
	couleur->Rouge = rouge;

	return couleur;
}

DonneesImageRGB * creerImage(IMAGE *image)
{
	/* ---Variables--- */
	int hauteur = image->hauteurImage;
	int largeur = image->largeurImage;

	unsigned char *tab = NULL;;
	tab = malloc(sizeof(char) * hauteur * largeur * 3);

	if (tab == NULL)
	{
		return NULL;
	}

	for(int i = 0 ; i < hauteur ; i++)
	{
		for(int j = 0 ; j < largeur ; j++)
		{
			short posB = 0;
			short posV = 1;
			short posR = 2;

			tab[i*largeur*3 + j*3 + posB] = image->Bleu[i][j]  ;
			tab[i*largeur*3 + j*3 + posV] = image->Vert[i][j]  ;
			tab[i*largeur*3 + j*3 + posR] = image->Rouge[i][j] ;
		}
	}

	DonneesImageRGB *donnees = NULL;
	donnees = (DonneesImageRGB *)malloc(sizeof (DonneesImageRGB));
	if (donnees == NULL)
	{
		return NULL;
	}
	donnees->hauteurImage 	= hauteur ;
	donnees->largeurImage 	= largeur ;
	donnees->donneesRGB 	= tab ;

return donnees ;


}
