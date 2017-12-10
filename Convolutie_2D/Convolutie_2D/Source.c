#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//#define _USE_MATH_DEFINE
#ifdef M_PI
#define pi M_PI
#else
#define pi 3.14
#endif

void convolutie_2D(const int x[8][8], const int h[3][3], int* y);

int main(int argc, char* argv[])
{
	int sourceImage[8][8];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			sourceImage[i][j] = rand() % 100; // random tussen 0 en 99

	int mask[3][3] = { {0,0,0},{ 0,1,0 }, { 0,0,0 } };

	int** destinationImage = (int**)calloc(8 * 8, sizeof(int*));

	convolutie_2D(sourceImage, mask, (int*)&destinationImage[0]);
}

void convolutie_2D(const int x[8][8], const int h[3][3], int* y)
{
	for (int m = 1; m <= 6; m++)
	{
		for (int n = 1; n <= 6; n++)
		{
			int sum = 0;

			// h (mask) is 3 op 3, de index van het midden is 0,0, dus het eerste element is -1,-1
			// voor een mask van 5x5, is de index: -2, van een matrix van 7: -3
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					sum += h[i + 1][j + 1] * x[m - i][n - j];
				}
			}

			// van [m,n] notatie naar een []notatie (in c bestaan geen 2 dimensionale arrays, enkel 1 dimensionaal)
			// de 8 verwijst naar het aantal rijen in de matrix, m is het rij nummer, n de kolom
			y[m * 8 + n] = sum;
		}
	}
}


