/* ---------- */
/* najistat.c */
/* ---------- */

/* naji file statistics functions */

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


int wrdcount(char *namein)
{
int x=1;
int c=0;

int a;

najin(namein);

    loop
    {
    
        a = fgetc(naji_input);
        if (a == EOF)
        {
        najinclose();
        return c;
        }

        if ( (a > 32) && (a < 127) )
        {
            if (x)
            {
            ++c;
            x=0;
            }
        }
        else x=1;
    }

najinclose();
return c;
}


void najisum(char *namein)
{
unsigned long int najisum[256];
unsigned long int chksum=0;
unsigned long int filesize=0;
unsigned long int i=0;

int a=0;
int b=0;

        for (a=0; a<256; a++)
        najisum[a] = 0;


        
        najin(namein);


        printf("Looking at file...\n\n\n");

        while (!(feof(naji_input)))
        {
        i = fgetc(naji_input);
        najisum[i]++;
        chksum = (chksum + (i + 1) );
        filesize++;
        }

        
        for (a=0; a<256; a++)
        {
        if ((a > 33) && (a < 127))
        printf("%c ", a);

        printf("%03d: %lu\n", a, najisum[a]);
        }

        printf("\n\n\n");


        for (a=0; a<256; a++)
        {
        if ((a > 33) && (a < 127) && (najisum[a] != 0))
        printf ("%c ", a);

        if (najisum[a] != 0)
        printf ("%03d: %lu\n", a, najisum[a]);
        }

printf("\n\nnaji checksum (najisum) is the above and the following: ");
printf("%lu:%lu...\n\n", chksum, filesize);
printf("Later versions of najisum should allow you to\n");
printf("recreate the file with the checksum.\n");

fgetc(stdin);


/* todo: make the bbb checksum do a cleverer minus and/or plus system,
   for example instead of -1 -2 -3 -4 -5 it should do -1_5  */


najinclose();

printf("\n\n\n");
printf("<najisum>\n");
b=0;

for (a=0; a<256; a++)
{
        
        if (najisum[a] != 0)
        {
        printf ("%d*%lu + ", a, najisum[a]);
        b++;

                if (b == 8)
                {
                printf("\n");

                b=0;
                }

        }

}



printf("=\n%lu:%lu\n", chksum, filesize);

printf("</najisum>\n");
printf("\n\n\n");

fgetc(stdin);
}

