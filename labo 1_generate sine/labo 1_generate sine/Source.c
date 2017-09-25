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
int main(int argc, char* argv[])
{
	// definieren van de variable voor amplithude, freuentie , sampelfrequentie,fase en aantal sampels 
	double A =1.0;
	double f= 1000.0;
	double fs = 8000.0;
	double phi = 0.0;// naderhand te testen met 3*3.14/4
	int n = 8;
	//double uitkomst[];
	double *x = (double*)calloc(n,sizeof(double));
	generatesinewave(A,f,fs,phi,n, x);
	for (int m = 0; m < n; m++)
	{
		printf("%lf\n",x[m]);
	}
}


//functie om de sinus te genereren 
void generatesinewave(double A, double f, double fs, double phi, int n, double * x)
{

	for (int e = 0; e < n; e++)
	{
		//x[e]= A*sin(2 * pi*f/fs*(double)n+phi);
		x[e] = sin(45.0);
	
	}

}