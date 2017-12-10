//mediaan filter moet gedaan worden met grijswaarden mask moet 3x3 zijn , als alles werkt met kleur en 5x5 of 7x7 en met ruis precentage 5,10 en 20 en het aantalm passes tellen (1 2 of 3)
// eens alles werkt het probleem van de randen moetnen maken (canvas grroter maken 3x3 1 rij er bij, 5x5 2 rijen er bij en 

#include "C:\Users\Ecto1\Documents\GitHub\dsp\used_libaries\qdbmp_1.0.0\qdbmp.h"

#include <stdio.h>
#include <stdlib.h>

void medianCalculationIndex(BMP*, BMP*);
void medianCalculationRGB(BMP*, BMP*);
void bubbleSort(UCHAR arr[], int n);

int main(int argc, char* argv[])
{
	BMP*    source;
	BMP*    destination;
	source = BMP_ReadFile("lena_24bit_256_20%.bmp");
	
	//handige variable 
	USHORT depth = BMP_GetDepth(source);
	UINT width = BMP_GetWidth(source);
	UINT height = BMP_GetHeight(source);

	// het aanmaken van een 2de output BMP
	destination = BMP_ReadFile("lena_24bit_256_20%.bmp"); // BMP_Create(width, height, depth);

	medianCalculationRGB(source, destination);

	BMP_WriteFile(destination, "bla.bmp");

	/* Free all memory allocated for the image */
	BMP_Free(source);
	BMP_Free(destination);
	return 0;
}

void medianCalculationIndex(BMP* source, BMP* destination)
{
	UCHAR mask[9];
	int x = 0;

	for (UINT m = 1; m <= BMP_GetWidth(source)-2; m++)
	{
		for (UINT n = 1; n <= BMP_GetHeight(source)-2; n++)
		{
			// h (mask) is 3 op 3, de index van het midden is 0,0, dus het eerste element is -1,-1
			// voor een mask van 5x5, is de index: -2, van een matrix van 7: -3
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					UCHAR pixel;
					BMP_GetPixelIndex(source, m-i,n-j, &pixel);

					mask[x++] = pixel;
				}
			}

			bubbleSort(mask, 9);

			BMP_SetPixelIndex(destination, m,n, mask[4]);

			x = 0;
		}
	}
}

void medianCalculationRGB(BMP* source, BMP* destination)
{
	UCHAR ar[9];
	UCHAR ag[9];
	UCHAR ab[9];

	int x = 0;

	for (UINT m = 1; m <= BMP_GetWidth(source) - 2; m++)
	{
		for (UINT n = 1; n <= BMP_GetHeight(source) - 2; n++)
		{
			// h (mask) is 3 op 3, de index van het midden is 0,0, dus het eerste element is -1,-1
			// voor een mask van 5x5, is de index: -2, van een matrix van 7: -3
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					UCHAR r,g,b;
					BMP_GetPixelRGB(source, m - i, n - j, &r, &g, &b);

					ar[x] = r;
					ag[x] = g;
					ab[x] = b;
					x++;
				}
			}

			bubbleSort(ar, 9);
			bubbleSort(ag, 9);
			bubbleSort(ab, 9);

			BMP_SetPixelRGB(destination, m, n, ar[4], ag[4], ab[4]);

			x = 0;
		}
	}
}

void bubbleSort(UCHAR arr[], int n) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n - i - 1; j++) 
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}