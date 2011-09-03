/* ---------- */
/* najicomp.c */
/* ---------- */

/* naji compression/decompression functions */

/* this  .c  file is a part */
/* of libnaji version 0.6.4 */

/* libnaji is based on   */
/* the original najitool */

/* both najitool and libnaji */
/* are public domain and are */
/* made by the same author   */
/* please read license.txt   */

/* made by NECDET COKYAZICI  */

#include "libnaji.h"


void najirle(char *namein, char *nameout)
{
int i;
int a;
int b;
unsigned char repeats=0;


najin(namein);
najout(nameout);

	while (1)
	{

	repeats=0;

	a = fgetc(naji_input);

	if (a == EOF)
	break;

		while (1)
		{
		b = fgetc(naji_input);

		if (b == EOF)
		break;

			if (a != b)
			{
			fseek(naji_input, -1, SEEK_CUR);
			break;
			}
		
		repeats++;

		if (repeats == 255)
		break;	
		}


		if (a == 255)
		{

			for (i=0; i<=repeats; i++)
			{
			fputc(255, naji_output);
			fputc(255, naji_output);
			}

		}
		else
		{

			if (repeats > 2)
			fprintf(naji_output, "%c%c%c", 255, a, repeats);

			else
			{
			for (i=0; i<=repeats; i++)
			fputc(a, naji_output);
			}


		}



	}



najinclose();
najoutclose();
}



void unajirle(char *namein, char *nameout)
{
int a;
int b;
int i=0;


najin(namein);
najout(nameout);


        while (1)
        {

		a = fgetc(naji_input);

		if (a == EOF)
		break;

		if (a != 255)
		{
		fputc(a, naji_output);
		}
		else
		{

		b = fgetc(naji_input);

			if (b == EOF)
			{
			fputc(a, naji_output);
			break;
			}

			if (b == 255)
			{
			fputc(255, naji_output);
			}
			else
			{
			a = b;

			b = fgetc(naji_input);

			 	if (b == EOF)
				{
				fputc(a, naji_output);
				break;
				}
				else
				{
				for (i=0; i<=b; i++)
				fputc(a, naji_output);
				}

			}




		}




        }

najinclose();
najoutclose();
}
