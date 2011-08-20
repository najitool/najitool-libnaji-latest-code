/* ------- */
/* najio.c */
/* ------- */

/* naji input/output functions  */
/* used by najitool and libnaji */

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

FILE *naji_input;
FILE *naji_input2;

FILE *naji_output;
FILE *naji_output2;

FILE *naji_edit;

long naji_filesize(FILE *file)
{
long savepos=0;
long size=0;

savepos = ftell(file);

fseek(file, 0 , SEEK_END);
size = ftell(file);

fseek(file, savepos, SEEK_SET);

return size;
}


/* you might want to make your own najin and najout functions */
/* depending on what you need, for example it will probably   */
/* be better to change these functions for your GUI programs  */

void najin(char *namein)
{
/* long filesize = 0; */

    naji_input = fopen(namein, "rb");

    if (naji_input == NULL)
    {
    fprintf(stderr, "\n\nError, cannot open input file: %s", namein);
    perror(" "); fprintf(stderr, "\n\n");
    exit(2);
    }


/*
    filesize = najinsize();


    if (filesize == 0)
    {
    fprintf(stderr, "\n\nError, empty file.\n\n");
    exit(1);
    }

*/


/* NOTE: empty file checks have been disabled in this version
         because it falsely reports large files as being empty
*/
}


void najed(char *named)
{
naji_edit = fopen(named, "r+b");

        if (naji_edit == NULL)
        {
        fprintf(stderr, "\n\nError, cannot open edit file: %s", named);
        perror(" "); fprintf(stderr, "\n\n");
        exit(6);
        }

}


void najin2(char *namein2)
{
/* long filesize = 0; */


    naji_input2 = fopen(namein2, "rb");

    if (naji_input2 == NULL)
    {
    fprintf(stderr, "\n\nError, cannot open second input file: %s", namein2);
    perror(" ");
    fprintf(stderr, "\n\n");
    exit(5);
    }

/*
    filesize = najinsize();


    if (filesize == 0)
    {
    fprintf(stderr, "\n\nError, empty file.\n\n");
    exit(1);
    }

*/

/* NOTE: empty file checks have been disabled in this version
         because it falsely reports large files as being empty
*/
}


void najout(char *nameout)
{
int choice;
char buffer[1050];

naji_output = fopen(nameout, "rb");


    if (naji_output != NULL)
    {
    fprintf(stderr, "\n\nError, output file already exists: %s\n\n", nameout);

        while (1)
        {

            fprintf(stderr, "[Q]uit - [R]ename - [O]verwrite ?\n\n");
            choice = fgetc(stdin);

            if (choice == 'q' || choice == 'Q')
            {
            fclose(naji_output);
            exit(3);
            }


            else if (choice == 'r' || choice == 'R')
            {

            fprintf(stderr, "\nType new name for output file: ");

            fgetc(stdin);
            safegets(buffer, 1024);

                fclose(naji_output);

                if (rename(nameout, buffer) != 0)
                {
                perror("\n\nError renaming output file");
                fclose(naji_output);
                exit(3);
                }

                else break;

            }

          else if (choice == 'o' || choice == 'O')
          {
          fclose(naji_output);
          break;
          }

          else continue;

        }


    }

    naji_output = fopen(nameout, "wb");
    if (naji_output == NULL)
    {
    fprintf(stderr, "\n\nError, cannot open output file: %s", nameout);
    perror(" "); fprintf(stderr, "\n\n");
    exit(4);
    }

}



void najout2(char *nameout2)
{
int choice;
char buffer[1050];

naji_output2 = fopen(nameout2, "rb");

    if (naji_output2 != NULL)
    {
    fprintf(stderr, "\n\nError, second output file already exists: %s\n\n",
    nameout2);

        while (1)
        {

            fprintf(stderr, "[Q]uit - [R]ename - [O]verwrite ?\n\n");
            choice = fgetc(stdin);

            if (choice == 'q' || choice == 'Q')
            {
            fclose(naji_output2);
            exit(3);
            }


            else if (choice == 'r' || choice == 'R')
            {

            fprintf(stderr, "\nType new name for second output file: ");

            fgetc(stdin);
            safegets(buffer, 1024);

                fclose(naji_output2);

                if (rename(nameout2, buffer) != 0)
                {
                perror("\n\nError renaming second output file");
                fclose(naji_output2);
                exit(3);
                }

                else break;

            }

          else if (choice == 'o' || choice == 'O')
          {
          fclose(naji_output2);
          break;
          }

          else continue;

        }

    }

    naji_output2 = fopen(nameout2, "wb");
    if (naji_output2 == NULL)
    {
    fprintf(stderr, "\n\nError, cannot open output file: %s", nameout2);
    perror(" "); fprintf(stderr, "\n\n");
    exit(4);
    }

}

long najinsize(void)    { return naji_filesize(naji_input);   }
long najin2size(void)   { return naji_filesize(naji_input2);  }
long najoutsize(void)   { return naji_filesize(naji_output);  }
long najout2size(void)  { return naji_filesize(naji_output2); }
long najedsize(void)    { return naji_filesize(naji_edit);    }

void najinclose(void)   { fclose(naji_input);   }
void najin2close(void)  { fclose(naji_input2);  }
void najoutclose(void)  { fclose(naji_output);  }
void najout2close(void) { fclose(naji_output2); }
void najedclose(void)   { fclose(naji_edit);    }

/* I should probably move these to another  */
/* .c file, because it's getting big again  */
void copyfile(char *namein, char *nameout)
{
int a=0;

najin(namein);
najout(nameout);

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;
    fputc(a, naji_output);
    }

najinclose();
najoutclose();
}


/* todo: allow it to copy unlimited
number of files file not opening them
all at the same time, open them one by one */

/* append files */

/*
void apfiles(...)
{
}
*/


/* copies while flipping the bits of each byte, for example

11110000 becomes
00001111

and

01010101 becomes
10101010 etc
*/

void flipcopy(char *namein, char *nameout)
{
int a=0;

najin(namein);
najout(nameout);

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;
    fputc((~a), naji_output);
    }

najinclose();
najoutclose();
}


/*
void copyrep(unsigned long int howmany)
{
unsigned long int i=0;
int a=0;

    howmany++;

    for (i=0; i < howmany; i++)
    {
        loop
        {
        a = fgetc(naji_input);
        if (a == EOF) endloop;
        fputc(a, naji_output);
        }
    }

}
*/


void safegets(char *buf, int size)
{
int a;
int i=0;

    while(1)
    {
    
        a = fgetc(stdin);

        if (i == size)
        {
        buf[size] = '\0';
        if ( (a == '\n') || (a == '\r') ) return;
        }

        if (i < size)
        {
    
            if ( (a == '\n') || (a == '\r') )
            {
            buf[i]='\0';
    
            return;
            }
    
            if ( (a > 31) && (a < 127) )
            {
            buf[i]=a;
            i++;
            }

        }    
    
    }

}


void nextpage(void)
{
printf("\n- Press ENTER for the next page...\n");
getchar();
}
