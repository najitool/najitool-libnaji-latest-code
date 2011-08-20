/* ---------- */
/* najstdin.c */
/* ---------- */

/* naji standard input functions */

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


void kitten_stdin(void)
{
int a=0;

    loop
    {
    a = fgetc(stdin);
    if (a == EOF) endloop;
    fputc(a, stdout);
    }

}

void cat_text_stdin(void)
{
int a=0;

    loop
    {
    a = fgetc(stdin);
    if (a == EOF) endloop;
    if ( ( (a > 31) && (a < 127) ) ||
         ( (a == '\n') ) ||
         ( (a == '\r') ) ||
         ( (a == '\t') )
        )
    
    
    fputc(a, stdout);
    }

}

/* this is better for unix because you don't really need \r on unix do you */
void cat_text_faster_stdin(void)
{
int a=0;

    loop
    {
    a = fgetc(stdin);
    if (a == EOF) endloop;
    if ( ( (a > 31) && (a < 127) ) ||
         ( (a == '\n') ) ||
         ( (a == '\t') )
        )
    
    
    fputc(a, stdout);
    }

}

/* this is the fastest but doesn't include newlines or   */
/* tabs because the ascii people didn't do them close by */
void cat_text_fastest_stdin(void)
{
int a=0;

    loop
    {
    a = fgetc(stdin);
    if (a == EOF) endloop;
    if ( ( (a > 31) && (a < 127) ) )
    fputc(a, stdout);
    }

}

