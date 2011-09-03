/* ---------- */
/* naji_bit.c */
/* ---------- */

/* naji bitwise operation functions */

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

void show_16_bit_bin(int num)
{
int show;
int i;

        for (i=0; i<16; i++)
        {

        show = num & 0x8000 ? '1' : '0';

        fputc(show, stdout);

        num <<= 1;

        }

}


void show_8_bit_bin(char num)
{
char show;
int i;

        for (i=0; i<8; i++)
        {

        show = num & 0x8000 ? '1' : '0';

        fputc(show, stdout);

        num <<= 1;

        }

}




void fprint_16_bit_bin(FILE *out, int num)
{
int print;
int i;

        for (i=0; i<16; i++)
        {

        print = num & 0x8000 ? '1' : '0';

        fputc(print, out);

        num <<= 1;

        }

}




void fprint_8_bit_bin(FILE *out, char num)
{
char print;
int i;

        for (i=0; i<8; i++)
        {

        print = num & 0x8000 ? '1' : '0';

        fputc(print, out);

        num <<= 1;

        }

}
