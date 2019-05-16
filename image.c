#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "image.h"
#include "fft.h"

IMAGE * creer3MatricesNegatif(DonneesImageRGB *image)
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

			bleu[i][j] = 255-image->donneesRGB[i*largeurImage*3 + j*3 + posB];
			vert[i][j] = 255-image->donneesRGB[i*largeurImage*3 + j*3 + posV];
			rouge[i][j] = 255-image->donneesRGB[i*largeurImage*3 + j*3 + posR];

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
			gris[i][j] = (0.0721*bleu[i][j]+0.7154*vert[i][j]+0.2125*rouge[i][j]);
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

IMAGE * creerVagueSinuosidaleHorizontale()
{
	IMAGE * image = creerImageNoire();
	const double PI = atan(1)*4;
	short res ;
	for (int i = 0; i < image->hauteurImage; i++) {
		res = (sin(i*6*PI/256)+1)*255/2;
		for (int j = 0; j < image->largeurImage; j++) {
			image->Bleu[i][j] = res;
			image->Vert[i][j] = res;
			image->Rouge[i][j] = res;
		}
	}

	return image;
}

short * decalage(short * buf, int sizeBuf, int decallage)
{
	short * cpy = malloc(sizeof(short)*sizeBuf);
	for(int i = 0; i < sizeBuf ; i++){
		cpy[i] = buf[i];
	}

	for (int i = 0; i < sizeBuf; i++) {
		buf[i] = cpy[(i+decallage)%sizeBuf];
	}
	return buf;
}

IMAGE * creerVagueSinuosidaleDiagonales()
{
	IMAGE * image = creerImageNoire();
	const double PI = atan(1)*4;
	short res ;
	for (int i = 0; i < image->hauteurImage; i++) {
		res = (sin(i*6*PI/256)+1)*255/2;
		for (int j = 0; j < image->largeurImage; j++) {
			image->Bleu[j][i] = res;
			image->Vert[j][i] = res;
			image->Rouge[j][i] = res;
		}
	}

	for (int i = 0; i < image->hauteurImage; i++) {
		image->Bleu[i] = decalage(image->Bleu[i],256,i);
		image->Vert[i] = decalage(image->Vert[i],256,i);
		image->Rouge[i] = decalage(image->Rouge[i],256,i);
	}

	return image;
}

IMAGE * creerVagueSinuosidaleVerticale()
{
	IMAGE * image = creerImageNoire();
	const double PI = atan(1)*4;
	short res ;
	for (int i = 0; i < image->hauteurImage; i++) {
		res = (sin(i*6*PI/256)+1)*255/2;
		for (int j = 0; j < image->largeurImage; j++) {
			image->Bleu[j][i] = res;
			image->Vert[j][i] = res;
			image->Rouge[j][i] = res;
		}
	}

	return image;
}

IMAGE * creerImageNoire(void){
	/* ---Variables--- */
	int hauteurImage = 256;
	int largeurImage = 256;
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
			bleu[i][j] = 0;
			vert[i][j] = 0;
			rouge[i][j] = 0;
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


IMAGE * creerFFT(IMAGE * matrices){
	int hauteur = matrices->hauteurImage;
	int largeur = matrices->largeurImage;
	int valNb = hauteur*largeur;

	IMAGE * tmp = matrices;

	COMPLEX * data = NULL;
	data = malloc(sizeof(COMPLEX)*valNb);
	if(data == NULL) return NULL;

	for (int i = 0; i < hauteur; i++) {
		for (int j = 0; j < largeur; j++) {
			data[i*largeur+j].Re = matrices->Bleu[i][j];
			data[i*largeur+j].Im = 0;
		}
	}
	fft2D(data,hauteur,largeur,1);
	short value = data[0].Re;
	short max = value;
	short min = value;

	for (int i = 0; i < hauteur; i++) {
		for (int j = 0; j < largeur; j++) {
			value = data[i*largeur+j].Re;
			if(value < 0)
				value = 0;
			if(max < value)
				max = value;
			if(min > value)
				min = value;

			tmp->Bleu[i][j] 	= value;
			tmp->Vert[i][j]		= value;
			tmp->Rouge[i][j]	= value;
		}
	}
	for (int i = 0; i < hauteur; i++) {
		for (int j = 0; j < largeur; j++) {
			value = (((tmp->Bleu[i][j])-min)*255)/(max-min);

			tmp->Bleu[i][j] 	= value;
			tmp->Vert[i][j]		= value;
			tmp->Rouge[i][j]	= value;
		}
	}
	return tmp;

}
