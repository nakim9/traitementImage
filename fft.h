typedef double real;                 /* can be long double, double, or float */
typedef struct {
	real Re;
	real Im;
} COMPLEX;         /* for complex number */
//typedef double complex cplx;

// void _fft(cplx buf[], cplx out[], int n, int step);

// void fft(cplx buf[], int n);

//  void show(const char * s, cplx buf[]);


void cooley_tukey(COMPLEX x[], int n, int flag, int n2);

void fft2D(COMPLEX x[], int n1, int n2, int flag);
