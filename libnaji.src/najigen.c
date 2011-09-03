/* --------- */
/* najigen.c */
/* --------- */

/* naji file generators */

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

void naji_genlic()
{
najout("LICENSE");
fprintf(naji_output, "\nTHIS PROGRAM IS NON-COPYRIGHTED PUBLIC DOMAIN AND DISTRIBUTED IN THE\n");
fprintf(naji_output, "HOPE THAT IT WILL BE USEFUL BUT THERE IS NO WARRANTY FOR THE PROGRAM,\n");
fprintf(naji_output, "THE PROGRAM IS PROVIDED \"AS IS\" WITHOUT WARRANTY OF ANY KIND, EITHER\n");
fprintf(naji_output, "EXPRESSED  OR  IMPLIED, INCLUDING, BUT  NOT  LIMITED TO, THE IMPLIED\n");
fprintf(naji_output, "WARRANTIES  OF  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.\n");
fprintf(naji_output, "THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM  IS\n");
fprintf(naji_output, "WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF\n");
fprintf(naji_output, "ALL NECESSARY SERVICING, REPAIR OR CORRECTION.\n\n");
najoutclose();

unix2dos("LICENSE", "license.txt");
}


void rndbfile(char *nameout, unsigned long int size)
{
unsigned long int i=0;

najout(nameout);

rand_init();
for (i=0; i<size; i++)
fputc((rand() % 255), naji_output);

najoutclose();
}

void rndtfile(char *nameout, unsigned long int size)
{
unsigned long int i=0;

najout(nameout);

rand_init();
for (i=0; i<size; i++)
fputc(((rand() % 95)+' '), naji_output);

najoutclose();
}

void charfile(char *nameout, unsigned long int size, int c)
{
unsigned long int i=0;

najout(nameout);

for (i=0; i<size; i++)
fputc(c, naji_output);

najoutclose();
}


void strfile(char *nameout, unsigned long int howmany, char *string)
{
unsigned long int i=0;

najout(nameout);

 for (i=0; i<howmany; i++)
 fprintf(naji_output, "%s", string);

najoutclose();
}


/* todo */

/*

void sstrfile(unsigned long int strictsize, char *string)
{
unsigned long int i=0;
unsigned long int bytes_written_so_far=0;
long fsize;
int len=0;


if (bytes_written_so_far == (fsize - len))
return;


}
*/


void _8bit256(char *nameout, unsigned long rep)
{
int i;
int ii;

najout(nameout);

    for (ii=0; ii<=rep; ii++)
    for (i=0; i<=255; i++)
    fputc(i, naji_output);

najoutclose();
}

void asctable(void)
{
int i;

    for (i=' '; i<='~'; i++)
    {
    printf("%i\t0x%02X\t%c\t", i, i, i);
    show_16_bit_bin(i);
    printf("\n");
    }

}
