/* --------- */
/* naji_uu.c */
/* --------- */

/* naji uuencode/uudecode functions */

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


#define UUENC(c)  ( ((c) & 077) + ' ' )
#define UUDEC(c)  (char) ( ((c) - ' ') & 077)


void uuencode(char *namein, char *nameout)
{
char buffer[100];
int i;
int a;
int b;
int x1;
int x2;
int x3;
int x4;
int reached_eof = NAJI_FALSE;


      najin(namein);
      najout(nameout);

      loop 
      {


      for (i=0; i<45; i++)
      {
      b = fgetc(naji_input);

      if (b == EOF)
      {
      a = i;
      reached_eof = NAJI_TRUE;
      break;
      }

      buffer[i] = (char) b;
      }

      if (reached_eof == NAJI_FALSE)
      a = 45;


      fputc(UUENC(a), naji_output);

      for (i=0; i<a; i+=3)
      {
      x1 = buffer[i] >> 2;

      x2 = ( (buffer[0+i] << 4) & 060) | ( (buffer[1+i] >> 4) & 017);
      x3 = ( (buffer[1+i] << 2) & 074) | ( (buffer[2+i] >> 6) & 03);

      x4 = buffer[2+i] & 077;

      fputc(UUENC(x1), naji_output);
      fputc(UUENC(x2), naji_output);
      fputc(UUENC(x3), naji_output);
      fputc(UUENC(x4), naji_output);
      }

      putc('\n', naji_output);

      if (a <= 0)
      endloop;
      }

najinclose();
najoutclose();
}



void uudecode(char *namein, char *nameout)
{
int i;
char a;
char b;
char c;
char d;

      najin(namein);
      najout(nameout);

      while ((i = fgetc(naji_input)) != EOF && ((i = UUDEC(i)) != 0))
      {

        while (i > 0)
        {
        a = UUDEC(fgetc(naji_input));
        b = UUDEC(fgetc(naji_input));
        c = UUDEC(fgetc(naji_input));
        d = UUDEC(fgetc(naji_input));

        if (i-- > 0) fputc((a<<2) | (b>>4), naji_output);
        if (i-- > 0) fputc((b<<4) | (c>>2), naji_output);
        if (i-- > 0) fputc((c<<6) | d, naji_output);
        }

        i = fgetc(naji_input);

      }

najinclose();
najoutclose();
}

