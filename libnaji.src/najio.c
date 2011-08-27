/* ------- */
/* najio.c */
/* ------- */

/* naji input/output functions  */
/* used by najitool and libnaji */

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
int a;

    naji_input = fopen(namein, "rb");

    if (naji_input == NULL)
    {
    fprintf(stderr, "\n\nError, cannot open input file: %s", namein);
    perror(" "); fprintf(stderr, "\n\n");
    exit(2);
    }

	
	a = fgetc(naji_input);
	
	if (a == EOF)
    {
    fprintf(stderr, "\n\nError, empty file.\n\n");
    exit(1);
    }
	else
	{
		najinclose();
		
		naji_input = fopen(namein, "rb");

		if (naji_input == NULL)
		{
		fprintf(stderr, "\n\nError, cannot open input file: %s", namein);
		perror(" "); fprintf(stderr, "\n\n");
		exit(2);
		}
	
	}

	
	
	
}


void najintext(char *namein)
{
int a;

    naji_input = fopen(namein, "rt");

    if (naji_input == NULL)
    {
    fprintf(stderr, "\n\nError, cannot open input file: %s", namein);
    perror(" "); fprintf(stderr, "\n\n");
    exit(2);
    }

	
	a = fgetc(naji_input);
	if (a == EOF)
    {
    fprintf(stderr, "\n\nError, empty file.\n\n");
    exit(1);
    }
	else
	{
		najinclose();
		
		naji_input = fopen(namein, "rb");

		if (naji_input == NULL)
		{
		fprintf(stderr, "\n\nError, cannot open input file: %s", namein);
		perror(" "); fprintf(stderr, "\n\n");
		exit(2);
		}
	
	}

	
	
	
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
int a;

    naji_input2 = fopen(namein2, "rb");

    if (naji_input2 == NULL)
    {
    fprintf(stderr, "\n\nError, cannot open second input file: %s", namein2);
    perror(" "); fprintf(stderr, "\n\n");
    exit(2);
    }

	
	a = fgetc(naji_input2);
	if (a == EOF)
    {
    fprintf(stderr, "\n\nError, empty file.\n\n");
    exit(1);
    }
	else
	{
		najinclose();
		
		naji_input2 = fopen(namein2, "rb");

		if (naji_input2 == NULL)
		{
		fprintf(stderr, "\n\nError, cannot open second input file: %s", namein2);
		perror(" "); fprintf(stderr, "\n\n");
		exit(2);
		}
	
	}

	
	
	
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


/* finds the longest line in a text file and returns the result */

unsigned long longl(char *namein)
{
int a;

unsigned long length = 0;
unsigned long longest = 0;

najin(namein);

	while (1)
	{
	
		a = getc(naji_input);

		if (a == EOF)
		break;

		if (a == '\n')
		{
			if (length > longest)
			longest = length;
		
		length=0;
		}
		else length++;

	}

najinclose();

return longest;
}


void longline(char *namein)
{
printf("\n\nLongest line is: %lu\n\n", longl(namein));
}


/* counts how many lines there are in a text file and returns the result */

unsigned long howl(char *namein)
{
int a;

unsigned long lines = 0;

najin(namein);

	while (1)
	{
	
		a = getc(naji_input);

		if (a == EOF)
		break;

		if (a == '\n')
		lines++;

	}

najinclose();

return lines;
}


void howline(char *namein)
{
printf("\n\nTotal number of lines is: %lu\n\n", howl(namein));
}


char **naji_lines_alloc(unsigned long howmany, unsigned long howlong)
{
char **buffer = NULL;
unsigned long i;

	buffer = (char **) malloc(howmany * sizeof(char *));

	exitnull(buffer);

	for (i=0; i<howmany; i++)
	{
	buffer[i] = (char *) malloc(howlong * sizeof(char) + 3);
	exitnull(buffer[i]);
	}

return buffer;
}


void naji_lines_free(char **buffer, unsigned long howmany)
{
unsigned long i;

	for (i=0; i<howmany; i++)
	free(buffer[i]);

	free(buffer);
	
	buffer = NULL;
}


void naji_lines_load(char *namein, char **buffer, unsigned long howmany, unsigned long howlong)
{
int a;
unsigned long i = 0;
unsigned long c = 0;

	najintext(namein);

	while (1)
	{
		a = fgetc(naji_input);
	
		if (a == EOF)
		{
		buffer[i][c] = '\0';
		break;
		}

		else if (a == '\n')
		{
		buffer[i][c] = '\n';
		c++;
		
		buffer[i][c] = '\0';
		c++;
		
		i++;
	    
		c = 0;
		
		if (i >= howmany)
		break;
		}
	
		else if (a == '\r')
		;

		else
		{
		buffer[i][c] = a;
		c++;
		
		if (c == howlong)
		{
		buffer[i][c] = '\0';
		break;
		}
		
		
		}
	
	}
	

	najinclose();

}


void naji_lines_backwards_print(char **buffer, unsigned long howmany)
{
signed long backwards_howmany = 0;
signed long backwards_i = 0;

	backwards_howmany = (signed long) howmany;

	backwards_howmany--;

	if (strlen(buffer[backwards_howmany]) > 0)
	if (strchr(buffer[backwards_howmany], '\n') == NULL)
	{
	printf("%s\n", buffer[backwards_howmany]);
	backwards_howmany--;
	}
  
	for (backwards_i = backwards_howmany; backwards_i >= 0; backwards_i--)
	printf("%s", buffer[backwards_i]);

}


void naji_lines_print(char **buffer, unsigned long howmany)
{
unsigned long i;

	for (i=0; i<howmany; i++)
	printf("%s", buffer[i]);

}


void lineback(char *namein)
{
char **buffer = NULL;
unsigned long howmany;
unsigned long howlong;

	howmany = howl(namein);
	howlong = longl(namein);
	
	howlong += 3;
	howmany ++;
	
	buffer = naji_lines_alloc(howmany, howlong);

	naji_lines_load(namein, buffer, howmany, howlong);

	naji_lines_backwards_print(buffer, howmany);

	naji_lines_free(buffer, howmany);
}



int return_random(int max)
{
int random_number;
int limit;

	limit = RAND_MAX - RAND_MAX % max;
	do random_number = rand(); while (random_number >= limit);

return random_number % max;
}


void shuffle_int_array(int *array, int size)
{
int a;
int b;
int c;

  size--;
  
  srand(time(NULL));
  
  for (a=size; a>0; a--)
  {
    b = return_random(a + 1);
    c = array[b];
    array[b] = array[a];
    array[a] = c;
  }

}


void naji_lines_random_print(char **buffer, int howmany)
{
unsigned long i = 0; 
int *vektor = NULL;

vektor = (int *) malloc(howmany * sizeof (int));
exitnull(vektor)

for (i=0; i<howmany; i++)
vektor[i] = i;

shuffle_int_array(vektor, howmany);

for (i=0; i<howmany; i++)
printf("%s", buffer[vektor[i]]);

free(vektor);
vektor = NULL;
}


void rndlines(char *namein)
{
char **buffer = NULL;
unsigned long howmany;
unsigned long howlong;

	howmany = howl(namein);
	howlong = longl(namein);
	
	howlong += 3;
	howmany ++;
	
	buffer = naji_lines_alloc(howmany, howlong);

	naji_lines_load(namein, buffer, howmany, howlong);

	naji_lines_random_print(buffer, howmany);

	naji_lines_free(buffer, howmany);
}


void najifgets(char *buf, int size, FILE *input)
{
int a;
int i=0;

    while(1)
    {
    
        a = fgetc(naji_input);

        if (a == EOF)
		{
		buf[i] = '\0';
		return;
		}
		
		if (i == size)
        {
		buf[i+1] = '\0';
		return;
		}

        if (a == '\n')
        {
		buf[i]   = '\n';
		buf[i+1] = '\0';
        return;
        }
        else
		{
        buf[i] = a;
		buf[i+1] = '\0';
        }
		
		i++;
    
    }

}
