/* --------- */
/* najierr.c */
/* --------- */

/* naji standard error output functions */
/* like cat_text for example but its called errtext */
/* which outputs to standard error instead of standard */
/* output. */

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


/* note: I probably wont add every stderr version of */
/* every najicat.c function, just simple stuff until */
/* I figure out a way to use one function for */
/* displaying to stderr, stdout, or a normal */
/* file. */


void errtext(void)
{
int a=0;

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;

     if ( ( (a > 31) && (a < 127) ) ||
         ( (a == '\n') ) ||
         ( (a == '\r') ) ||
         ( (a == '\t') )
        )
        
    fputc(a, stderr);
    }

}


void kiterr(void)
{
int a=0;

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;
    fputc(a, stderr);
    }
}

void reperr(unsigned int repeat)
{
int a=0;
unsigned int i=0;

repeat++;

        loop
        {
        a = fgetc(naji_input);
        if (a == EOF) endloop;
        for (i=0; i<repeat; i++)
        fputc(a, stderr);
        }

}


void skiperr(char *toskip)
{
int skip = NAJI_FALSE;
int a=0;
int i=0;
int l=0;

l = strlen(toskip);

        loop
        {
        a = fgetc(naji_input);
        if (a == EOF) endloop;
        skip = NAJI_FALSE;

        for (i=0; i<l; i++)
        if (a == toskip[i])
        skip = NAJI_TRUE;

        if (skip == NAJI_FALSE)
        fputc(a, stderr);
        }

}

void hexierr(void)
{
int offset=0;
int a;
int i;
int ii;
int x;

a = fgetc(naji_input);

    loop
    {

        if (a == EOF) endloop;

        printf("%08X: ", offset);

        for (ii=0; ii<4; ii++)
        {
            for (i=0; i<4; i++)
            {
            a = fgetc(naji_input);
            offset++;
            if (a != EOF) printf(" %02X", a);
            }

        fputc(' ', stderr);
        }

    fseek(naji_input, (-16), SEEK_CUR);

    for (x=0; x<16; x++)
    {
    a = fgetc(naji_input);

    if ( (a >= ' ') && (a <= '~') )
    fputc(a, stderr);
    else if (a == EOF) endloop;
    else fputc('.', stderr);
    }

    fputc('\n', stderr);
    fseek(naji_input, (+16), SEEK_CUR);
    }

}

