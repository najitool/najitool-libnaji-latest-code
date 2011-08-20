/* ---------- */
/* najihexi.c */
/* ---------- */

/* naji hexidecimal functions */

/* this  .c  file is a part */
/* of libnaji version 0.6.3 */

/* libnaji is based on   */
/* the original najitool */

/* both najitool and libnaji */
/* are public domain and are */
/* made by the same author   */
/* please read license.txt   */

/* made by NECDET COKYAZICI  */

#include "libnaji.h"

void bin2hexi(char *namein, char *nameout)
{
int a;
int b;
int counter = 0; 
unsigned int offset = 0;


najin(namein);
najout(nameout);


	while (1)
	{

		a = fgetc(naji_input);

		if (a == EOF)
		{
		fputc('\n', naji_output);
		break;
		}

	
		if (counter == 0 || counter == 16)
		{

			if (offset == 0xFFFFFFF0)
			{
			fprintf(naji_output, "OFFLIMIT:  ");
			}

			else
			{
			fprintf(naji_output, "%08X:  ", offset);
			}

		}


		b = fgetc(naji_input);

		if (b == EOF)
		{
			fprintf(naji_output, "%02X", a);
			break;
		}

		else
		{
			fseek(naji_input, -1, SEEK_CUR);
		}


		if (counter != 15)
			fprintf(naji_output, "%02X ", a);
		else
			fprintf(naji_output, "%02X", a);
		

		if (counter == 3  ||
        	    counter == 7  ||
	            counter == 11
		)

		fputc(' ', naji_output);


		counter++;


		if (counter == 16)
		{



			if (offset != 0xFFFFFFF0)
			offset += 16;

	
			fputc('\n', naji_output);


			counter = 0;


		}





	}



najinclose();
najoutclose();
}
