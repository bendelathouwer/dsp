#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//#define _USE_MATH_DEFINE
#ifdef M_PI
#define pi M_PI
#else
#define pi 3.14
#endif

void generatesinewave(double, double, double, double, int, double *);
void generatesinewave2(double, double, double, double, int, double *);

int main(int argc, char* argv[])
{
	// definieren van de variable voor amplithude, frequentie , sampelfrequentie,fase en aantal sampels 
	double A = 1.0;
	double f = 1000.0;
	double fs = 8000.0;
	double phi = 0.0;// naderhand te testen met 3*3.14/4
	int n = 8;

	double A2 = 0.5;
	double f2 = 2000.0;
	double fs2 = 8000.0;
	double phi2 = 3 * pi / 4;// naderhand te testen met 3*3.14/4
	int n2 = 8;
	//double uitkomst[];
	double *x1          = (double*)calloc(n, sizeof(double));
	double *x2          = (double*)calloc(n, sizeof(double));
	double *X           = (double*)calloc(n, sizeof(double));
	double *Xreel       = (double*)calloc(n, sizeof(double));
	double *Ximaginair  = (double*)calloc(n, sizeof(double));
	double *Xmagintuude = (double*)calloc(n, sizeof(double));
	double *Xfase       = (double*)calloc(n, sizeof(double));

	generatesinewave(A, f, fs, phi, n, x);
	generatesinewave2(A2, f2, fs2, phi2, n2, x2);
	printf("sinus1\n");
	for (int m = 0; m < n; m++)
	{

		printf("%lf\n", x[m]);

	}
	printf("sinus2\n");
	for (int m2 = 0; m2 < n2; m2++)
	{

		printf("%lf\n", x2[m2]);

	}
	printf("som ");
	for (int m2 = 0; m2 < n2; m2++)
	{

		printf("%lf\n", x2[m2] + x[m2]);

	}
}


//functie om de sinus te genereren 
void generatesinewave(double A, double f, double fs, double phi, int n, double * x)
{

	for (int e = 0; e < n; e++)
	{
		x[e] = A*sin(2 * pi*f / fs*(double)n + phi);


	}
}

void generatesinewave2(double A2, double f2, double fs2, double phi2, int n2, double * x2)
{

	for (int e2 = 0; e2 < n2; e2++)
	{
		x2[e2] = A2*sin(2 * pi*f2 / fs2*(double)n2 + phi2);


	}

}
