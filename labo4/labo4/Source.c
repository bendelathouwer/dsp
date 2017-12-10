#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])

void convolution_1d(int[], int, int[], int, int*, int);
void blockConv(int x[], int xlen, int h[], int hlen, int* y, int ylen, int blocksize);

int main(int argc, char* argv[])
{
	int h[6] = { 1,2,3,4,3,2 }; // input stream
	int x[3] = { 1,2,3 }; // convolutie filter

	const int hlen = ARRAY_SIZE(h); // lengte input array (P)
	const int xlen = ARRAY_SIZE(x);	// lengte convolutie filter array (Q)

	// lengte output array
	const int ylen = hlen + xlen - 1; // L = P + Q - 1

	// grootte van de blockconvolutie 
	const int blocksize = 3;

	printf("lengte k =%d \n", xlen);
	printf("lengte h =%d \n", hlen);
	printf("Lengte van y(L) =%d \n\n", ylen);

	int *y = calloc(ylen, sizeof(int));

	blockConv(h, hlen, x, xlen, y, ylen, blocksize);

	for (int i = 0; i < ylen; i++)
	{
	printf("%d\n", y[i]);
	}
}

void blockConv(int x[], int xlen, int h[], int hlen, int* y, int ylen, int blocksize)
{
	const int m = hlen - 1;

	int j = hlen / blocksize;

	for (int i = 0; i < j; i++)
	{
		convolution_1d(x, blocksize, h, hlen, y, ylen);
	}
}

void convolution_1d(int x[], int xlen, int h[], int hlen, int* y, int ylen)
{
	int kmin = 0;
	int kmax = 0;

	for (int n = 0; n < ylen; n++)
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

		for (int k = kmin; k <= kmax; k++)
		{
			y[n] += x[k] * h[n - k];
		}
	}
}