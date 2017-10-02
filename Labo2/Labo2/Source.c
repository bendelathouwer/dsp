#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//#define _USE_MATH_DEFINE
#ifdef M_PI
#define pi M_PI
#else
#define pi 3.14
#endif

void convolution_1d(int,int,int ,double*, double , double );//int L,  int m , int p, int q , double * y, double h , double x
int main(int argc, char* argv[])
{
	
	double h[] = { 1 , 2 };
	double x[] = { 1 , 2 , 3 };
	int p = sizeof(h) / sizeof(h[0]);
	int q = sizeof(x) / sizeof(x[0]);
	printf("p\n");
	printf("%d\n", p);
	printf("q\n");
	printf("%d\n", q);
	int L = q + p - 2;// berekenen van de lengte van de output array + rekening houdendede met indexing 
	printf("L is \n");
	printf("%d\n", L);
	double *y = calloc(L, sizeof(double));
	convolution_1d( L,    p,  q,   y,  h[p],  x[q]);


}

void convolution_1d(int L, int p, int q, double * y, double h, double x)
{

	for (int n = 0; n < L; n++)
	{
		if (n>q-1)
		{	
			q = q;
		}
		else
		{
			q = 0;
		}
		if (p>p-1)
		{
			p = p;
		}
		else
		{
			p = 0;
		}
	}


}

