/* ---------- */
/* najiedit.c */
/* ---------- */

/* naji file edit functions */

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


void fillfile(char *named, char c)
{
long size=0;
long i=0;

najed(named);

        size = najedsize();

        fseek(naji_edit, 0, SEEK_SET);

        for (i=0; i<size; i++)
        fputc(c, naji_edit);

najedclose();
}


void rndffill(char *named)
{
long size=0;
long i=0;

najed(named);

        size = najedsize();

        rand_init();

        fseek(naji_edit, 0, SEEK_SET);

        for (i=0; i<size; i++)
        fputc(rand() % 255, naji_edit);

najedclose();
}


int zerokill(char *name)
{
fillfile(name, '\0');
return remove(name);
}


int randkill(char *name)
{
rndffill(name);
return remove(name);
}


