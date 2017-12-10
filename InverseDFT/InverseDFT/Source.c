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
void addSine(int, double*, double*, double*);
void DFT(int, int, double*, double*, double*, double*, double*);

int main(int argc, char* argv[])
{
	// definieren van de variable voor amplithude, frequentie , sampelfrequentie,fase en aantal sampels 
	double A = 1.0;
	double f = 10000;
	double fs = 8000.0;
	double phi = 0.0;// naderhand te testen met 3*3.14/4
	int n = 8;

	double A2 = 0.5;
	double f2 = 2000.0;
	//double fs2 = 8000.0;
	double phi2 = 3 * 3.14/ 4;// naderhand te testen met 3*3.14/4
	int n2 = 8;
	// DFT variable
	int numberOfPoints = 8 ;
	//geheugen alocatie 
	double *x1          = (double*)calloc(n, sizeof(double));
	double *x2          = (double*)calloc(n, sizeof(double));
	double *Out         = (double*)calloc(n, sizeof(double));
	double *X_reel      = (double*)calloc(n, sizeof(double));
	double *X_Imaginair = (double*)calloc(n, sizeof(double));
	double *X_Magnitude = (double*)calloc(n, sizeof(double));
	double *X_Fase      = (double*)calloc(n, sizeof(double));
	
	generatesinewave(A, f, fs, phi, n, x1);
	generatesinewave(A2, f2, fs, phi2, n2, x2);
	addSine(n2, x1, x2, Out);
	
	printf("sinus1\n");
	for (int m = 0; m < n; m++)
		printf("%lf\n", x1[m]);

	
	printf("sinus2\n");
	for (int m2 = 0; m2 < n2; m2++)
		printf("%lf\n", x2[m2]);

	printf("Som\n");
	for (int m2 = 0; m2 < n2; m2++)
		printf("%lf\n", Out[m2]);
	


}


//functie om de sinus te genereren 
void generatesinewave(double A, double f, double fs, double phi, int n, double * x1)
{

	for (int e = 0; e < n; e++)
		x1[e] = A*sin(2 * pi*f / fs*(double)n + phi);


	
}

// functie om de generate sine uitkomsten op te tellen 
void addSine(int n2, double *x1, double *x2, double* Out)
{
	for (int m2 = 0; m2 < n2; m2++)
		Out[m2] = x2[m2] + x1[m2];

	
}

void DFT(int fs, int N, double *Out ,double *X_reel, double *X_Imaginair, double *X_Magnitude, double *X_Fase)
{

}