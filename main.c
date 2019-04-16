#include <stdio.h>
#include <stdlib.h>
#include "BmpLib.h"
#include "image.h"

int main(void)
{
	DonneesImageRGB *image = NULL;
	image = lisBMPRGB("hibou.bmp");

	IMAGE * matrices = creer3Matrices(image);

	image = creerImage(matrices);

	ecrisBMPRGB_Dans(image,"copie.bmp");

	return 0;
}
