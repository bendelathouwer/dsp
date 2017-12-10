#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//#define _USE_MATH_DEFINE
#ifdef M_PI
#define pi M_PI
#else
#define pi 3.14
#endif


#define aantal(x) sizeof(x)/sizeof(x[0])


void convolution_1d(double[], int, double[], int, double*, int);


int main(int argc, char* argv[])
{

	double h[2] = { 1,2 };
	double k[3] = { 1,2,3 };
	int hlen = aantal(h);
	int xlen = aantal(k);
	int L;

	L = hlen + xlen - 1;
	double *y = calloc(L, sizeof(double));
	printf("lengte x =%d \n", xlen);
	printf("lengte h =%d \n", hlen);
	printf("Lengte van y(L) =%d \n\n", L);

	convolution_1d(k, xlen, h, hlen, y, L);

	for (int i = 0; i < L; i++)
	{
		printf("%lf\n", y[i]);
	}

	//return 0;

}



void convolution_1d(double x[], int xlen, double h[], int hlen, double* y, int L)
{
	int kmin = 0;
	int kmax = 0;
	int n;
	int k = 0;


	for (n = 0; n < L; n++)
	{

		if (n >= xlen - 1)
		{
			kmax = xlen - 1;
		}
		else
			kmax = n;

		if (n <= hlen - 1)
		{
			kmin = 0;
		}
		else
		{
			kmin = n - (hlen - 1);
		}

		printf("n = %d\t kmin = %d\t kmax = %d\n", n, kmin, kmax);


		for (k = kmin; k <= kmax; k++)
		{
			y[n] += x[k] * h[n - k];
		}



	}
}