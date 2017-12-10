#include "C:\Users\Ecto1\Documents\GitHub\dsp\used_libaries\qdbmp_1.0.0\qdbmp.h"

#include <stdio.h>
#include <stdlib.h>

void BMP_Invertindex(BMP* target, BMP* source);
void BMP_ToGray     (BMP* target, BMP* source);
void BMP_InvertRGB  (BMP* target, BMP* source);
void BMP_RotateRGB  (BMP* target, BMP* source);

int main(int argc, char* argv[])
{
	BMP*    bmp;
	BMP*    bmp2;

	/* Read an image file */
	bmp  = BMP_ReadFile("Mandrill.bmp");
	bmp2 = BMP_Create(BMP_GetWidth(bmp),
					  BMP_GetHeight(bmp),
					  BMP_GetDepth(bmp));

	if (BMP_GetDepth(bmp) == 8)
	{
		BMP_Invertindex(bmp2, bmp);
	}
	else
	{
		BMP_RotateRGB(bmp2, bmp);
	}

	/* Save result */
	BMP_WriteFile(bmp2, "result.bmp");

	/* Free all memory allocated for the image */
	BMP_Free(bmp); 
	BMP_Free(bmp2);

	return 0;
}

void BMP_Invertindex(BMP* target, BMP* source)
{
	UCHAR   g;

	for (UINT x = 0; x < BMP_GetWidth(source); x++)
	{
		for (UINT y = 0; y < BMP_GetHeight(source); y++)
		{
			/* Get pixel's RGB values */
			BMP_GetPixelIndex(source, x, y, &g);
			if (BMP_GetError() != BMP_OK)
			{
			}

			/* Invert RGB values */
			BMP_SetPixelIndex(target, x, y, 255 - g);
			if (BMP_GetError() != BMP_OK)
			{
			}
		}
	}
}

void BMP_InvertRGB(BMP* target, BMP* source)
{
	UCHAR   r, g, b;

	for (UINT x = 0; x < BMP_GetWidth(source); x++)
	{
		for (UINT y = 0; y <  BMP_GetHeight(source); y++)
		{
			/* Get pixel's RGB values */
			BMP_GetPixelRGB(source, x, y, &r, &g, &b);

			/* Invert RGB values */
			BMP_SetPixelRGB(target, x, y, 255 - r, 255 - g, 255 - b);
		}
	}
}

void BMP_ToGray(BMP* target, BMP* source)
{
	UCHAR   r, g, b;

	for (UINT x = 0; x < BMP_GetWidth(source); x++)
	{
		for (UINT y = 0; y < BMP_GetHeight(source); y++)
		{
			/* Get pixel's RGB values */
			BMP_GetPixelRGB(source, x, y, &r, &g, &b);

			/* Invert RGB values */
			UCHAR gray = (UCHAR)(0.299*r + 0.587*g + 0.114*b);
			BMP_SetPixelRGB(target, x, y, gray, gray, gray);
		}
	}
}

void BMP_RotateRGB(BMP* target, BMP* source)
{
	UCHAR   r, g, b;

	const UINT height = BMP_GetHeight(source);
	const UINT width  = BMP_GetWidth(source);

	// werkt alleen met een vierkant prentje

	for (UINT x = 0; x < width; x++)
	{
		for (UINT y = 0; y < height; y++)
		{
			/* Get pixel's RGB values */
			BMP_GetPixelRGB(source, x, y, &r, &g, &b);
			
			/* rotate  RGB values */
			BMP_SetPixelRGB(target, 
							height - y - 1, x,  // -1 omdat column 0 based
							r, g, b);
		}
	}
}