typedef double real;                 /* can be long double, double, or float */
typedef struct {
	real Re;
	real Im;
} COMPLEX;         /* for complex number */

/*
	Algorithms by Wang Jian-Sheng
	physics.nus.edu.sg/~phywjs/CZ510/fft.c
*/
/* x[] tableau à une dimension contenant les valeurs complexes
		n taille tableau, n2 taille d'une ligne
		flag = 1 pour fft ; flage = -1 pour une fft inverse
*/
void cooley_tukey(COMPLEX x[], int n, int flag, int n2);
/* x[] tableau à une dimension contenant les valeurs complexes
		n1 hauteur du tableau, n2 largeur d'une ligne
		flag = 1 pour fft ; flage = -1 pour une fft inverse
*/
void fft2D(COMPLEX x[], int n1, int n2, int flag);
