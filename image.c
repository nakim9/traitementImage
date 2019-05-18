#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "image.h"
#include "fft.h"
#include "complexUtils.h"

IMAGE * creer3MatricesNegatif(DonneesImageRGB *image)
{
	/* ---Variables--- */
	int hauteurImage = image->hauteurImage;
	int largeurImage = image->largeurImage;
	unsigned short ** bleu 	= NULL;
	unsigned short ** vert 	= NULL;
	unsigned short ** rouge 	= NULL;

	/* ---Allocation--- */
	bleu	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);
	vert	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);
	rouge	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);

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

		bleu[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);
		vert[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);
		rouge[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);

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
			unsigned short posB = 0;
			unsigned short posV = 1;
			unsigned short posR = 2;

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
	unsigned short ** bleu 	= NULL;
	unsigned short ** vert 	= NULL;
	unsigned short ** rouge 	= NULL;

	/* ---Allocation--- */
	bleu	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);
	vert	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);
	rouge	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);

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

		bleu[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);
		vert[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);
		rouge[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);

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
			unsigned short posB = 0;
			unsigned short posV = 1;
			unsigned short posR = 2;

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
			unsigned short posB = 0;
			unsigned short posV = 1;
			unsigned short posR = 2;

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

	return donnees;
}

IMAGE * creer3MatricesDegrade(DonneesImageRGB *image)
{
	/* ---Variables--- */
	int hauteurImage = image->hauteurImage;
	int largeurImage = image->largeurImage;
	unsigned short ** bleu 	= NULL;
	unsigned short ** vert 	= NULL;
	unsigned short ** rouge 	= NULL;
	int r=0;

	/* ---Allocation--- */
	bleu	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);
	vert	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);
	rouge	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);

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

		bleu[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);
		vert[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);
		rouge[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);

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
			unsigned short posB = 0;
			unsigned short posV = 1;
			unsigned short posR = 2;

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
	unsigned short ** bleu 	= NULL;
	unsigned short ** vert 	= NULL;
	unsigned short ** rouge 	= NULL;

	/* ---Allocation--- */
	bleu	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);
	vert	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);
	rouge	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);

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

		bleu[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);
		vert[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);
		rouge[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);

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
			unsigned short posB = 0;
			unsigned short posV = 1;
			unsigned short posR = 2;

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
	unsigned short ** bleu 	= NULL;
	unsigned short ** vert 	= NULL;
	unsigned short ** rouge 	= NULL;
	unsigned short ** gris   = NULL;

	/* ---Allocation--- */
	bleu	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);
	vert	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);
	rouge	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);
	gris	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);

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

		bleu[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);
		vert[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);
		rouge[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);
		gris[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);

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
			unsigned short posB = 0;
			unsigned short posV = 1;
			unsigned short posR = 2;

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
	unsigned short ** bleu 	= NULL;
	unsigned short ** vert 	= NULL;
	unsigned short ** rouge 	= NULL;
	unsigned short ** gris   = NULL;

	/* ---Allocation--- */
	bleu	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);
	vert	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);
	rouge	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);
	gris	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteurImage);

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

		bleu[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);
		vert[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);
		rouge[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);
		gris[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeurImage);

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
			unsigned short posB = 0;
			unsigned short posV = 1;
			unsigned short posR = 2;

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

unsigned short * decalage(unsigned short * buf, int sizeBuf, int decallage)
{
	unsigned short * cpy = malloc(sizeof(unsigned short)*sizeBuf);
	for(int i = 0; i < sizeBuf ; i++){
		cpy[i] = buf[i];
	}

	for (int i = 0; i < sizeBuf; i++) {
		buf[i] = cpy[(i+decallage)%sizeBuf];
	}
	return buf;
}

IMAGE * creerVagueSinuosidaleHorizontale()
{
	IMAGE * image = creerImageVide(256,256);
	const double PI = atan(1)*4;
	unsigned short res ;
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

IMAGE * creerVagueSinuosidaleDiagonales()
{
	IMAGE * image = creerImageVide(256,256);
	const double PI = atan(1)*4;
	unsigned short res ;
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
	IMAGE * image = creerImageVide(256,256);
	const double PI = atan(1)*4;
	unsigned short res ;
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

IMAGE * creerFFT(IMAGE * img)
{
	int hauteurImage = img->hauteurImage;
	int largeurImage = img->largeurImage;

	cplx ** tmp = creerTabCplx(hauteurImage,largeurImage);

	for (int i = 0; i < hauteurImage; i++) {
		for (int j = 0; j < largeurImage; j++) {
			tmp[i][j] = img->Bleu[i][j] + I*0;
		}
		fft(tmp[i],largeurImage);
	}

	cplx ** cpy = creerTabCplx(hauteurImage,largeurImage);

	for (int i = 0; i < hauteurImage; i++) {
		for (int j = 0; j < largeurImage; j++) {
			cpy[i][j] = tmp[i][j];
		}
	}

	for (int i = 0; i < hauteurImage; i++) {
		for (int j = 0; j < largeurImage; j++) {
			tmp[i][j] = cpy[j][i];
		}
		fft(tmp[i],largeurImage);
	}

	/* Transposée */
	for (int i = 0; i < hauteurImage; i++) {
		for (int j = 0; j < largeurImage; j++) {
			cpy[i][j] = tmp[i][j];
		}
	}

	for (int i = 0; i < hauteurImage; i++) {
		for (int j = 0; j < largeurImage; j++) {
			tmp[i][j] = cpy[j][i];
		}
	}
	/* Fin Transposée */

	IMAGE * image = NULL;
	image = creerImageVide(256,256);
	if(image == NULL) return NULL;

	unsigned short val = 0;
	double realvar = 0.0;
	double imagvar = 0.0;
	unsigned short min = sizeof(unsigned short);
	unsigned short max = 0;

	for (int i = 0; i < hauteurImage; i++) {
		for (int j = 0; j < largeurImage; j++) {
			realvar = creal(tmp[i][j]);
			imagvar = cimag(tmp[i][j]);
			val = sqrt((realvar*realvar) + (imagvar*imagvar));
			if(val < min)
				min = val;
			if(val > max)
				max = val;
			image->Bleu[i][j] = val;
			image->Rouge[i][j] = val;
			image->Vert[i][j] = val;
		}
	}

	for (int i = 0; i < hauteurImage; i++) {
		for (int j = 0; j < largeurImage; j++) {
			val =image->Bleu[i][j];
			image->Bleu[i][j] = 255*((val-min)/(max-min));
			image->Rouge[i][j] = 255*((val-min)/(max-min));
			image->Vert[i][j] = 255*((val-min)/(max-min));
		}
	}

	int hauteurOut = 256*2;
	int largeurOut = 256*2;

	IMAGE * imageOut = NULL;
	imageOut = creerImageVide(hauteurOut,largeurOut);
	if(imageOut == NULL) return NULL;
	/* Quart inferieur gauche */
	for (int i = 0; i < hauteurOut/2; i++) {
		for (int j = 0; j < largeurOut/2; j++) {
			imageOut->Bleu[i][j] = image->Bleu[image->largeurImage-1-i][image->hauteurImage-1-j];
			imageOut->Vert[i][j] = image->Vert[image->largeurImage-1-i][image->hauteurImage-1-j];
			imageOut->Rouge[i][j] = image->Rouge[image->largeurImage-1-i][image->hauteurImage-1-j];
		}
	}
	/* Quart inferieur droit */
	for (int i = 0; i < hauteurOut/2; i++) {
		for (int j = largeurOut/2; j < largeurOut; j++) {
			imageOut->Bleu[i][j] = image->Bleu[image->largeurImage-1-i][j%image->hauteurImage];
			imageOut->Vert[i][j] = image->Vert[image->largeurImage-1-i][j%image->hauteurImage];
			imageOut->Rouge[i][j] = image->Rouge[image->largeurImage-1-i][j%image->hauteurImage];
		}
	}
	/* Quart superieur gauche */
	for (int i = hauteurOut/2; i < hauteurOut; i++) {
		for (int j = 0; j < largeurOut/2; j++) {
			imageOut->Bleu[i][j] = image->Bleu[i%image->largeurImage][image->largeurImage-1-j];
			imageOut->Vert[i][j] = image->Vert[i%image->largeurImage][image->largeurImage-1-j];
			imageOut->Rouge[i][j] = image->Rouge[i%image->largeurImage][image->largeurImage-1-j];
		}
	}
	/* Quart superieur droit */
	for (int i = hauteurOut/2; i < hauteurOut; i++) {
		for (int j = largeurOut/2; j < largeurOut; j++) {
			imageOut->Bleu[i][j] = image->Bleu[i%image->largeurImage][j%image->largeurImage];
			imageOut->Vert[i][j] = image->Vert[i%image->largeurImage][j%image->largeurImage];
			imageOut->Rouge[i][j] = image->Rouge[i%image->largeurImage][j%image->largeurImage];
		}
	}

	return imageOut;
}

IMAGE * creerImageVide(int hauteur, int largeur){
	/* ---Variables--- */

	IMAGE * image = malloc(sizeof(IMAGE));
	image->largeurImage = largeur;
	image->hauteurImage = hauteur;

	/* ---Allocation--- */
	image->Bleu	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteur);
	image->Vert	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteur);
	image->Rouge	= (unsigned short **)malloc(sizeof(unsigned short *) * hauteur);

	if(image->Bleu == NULL || image->Vert == NULL || image->Rouge == NULL)
	{
		printf("Error malloc\n");
		return NULL;
	}

	for(int i=0 ; i < hauteur ; i++)
	{
		image->Bleu[i]	= NULL;
		image->Vert[i]	= NULL;
		image->Rouge[i]	= NULL;

		image->Bleu[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeur);
		image->Vert[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeur);
		image->Rouge[i]	= (unsigned short *)malloc(sizeof(unsigned short) * largeur);

		if(image->Bleu[i] == NULL || image->Vert[i] == NULL || image->Rouge[i] == NULL)
		{
			printf("Error malloc\n");
			return NULL;
		}
	}

	return image;
}
