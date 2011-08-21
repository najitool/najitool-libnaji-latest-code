/* --------- */
/* najicat.c */
/* --------- */

/* naji standard output (usually screen) functions */

/* this  .c  file is a part */
/* of libnaji version 0.6.4 */

/* libnaji is based on   */
/* the original najitool */

/* both najitool and libnaji */
/* are public domain and are */
/* made by the same author   */
/* please read license.txt   */

/* made by NECDET COKYAZICI  */

/* cat_tail, cat_head, showline */
/*     made by SACHIN MANE      */

#include "libnaji.h"

void naji_license(void)
{
printf("\nTHIS PROGRAM IS NON-COPYRIGHTED PUBLIC DOMAIN AND DISTRIBUTED IN THE\n");
printf("HOPE THAT IT WILL BE USEFUL BUT THERE IS NO WARRANTY FOR THE PROGRAM,\n");
printf("THE PROGRAM IS PROVIDED \"AS IS\" WITHOUT WARRANTY OF ANY KIND, EITHER\n");
printf("EXPRESSED  OR  IMPLIED, INCLUDING, BUT  NOT  LIMITED TO, THE IMPLIED\n");
printf("WARRANTIES  OF  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.\n");
printf("THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM  IS\n");
printf("WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF\n");
printf("ALL NECESSARY SERVICING, REPAIR OR CORRECTION.\n\n");
return;
}


void naji_credits(void)
{
printf("\n");
printf("  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
printf("  najitool 0.8.4 and libnaji 0.6.4 Credits\n");
printf("  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
printf("  in order of joining the project najitool\n");
printf("\n");
printf("NECDET COKYAZICI - England, London - cokyazici@yahoo.co.uk\n");
printf("Main author, programmer, planner, designer, tester, debugger,\n");
printf("and project manager. Wrote everything that someone else didn't write.\n");
printf("\n");
printf("SELCUK OZDOGAN - Turkey, Istanbul - selcuk198@yahoo.com\n");
printf("Programmer. Wrote charbefr, charaftr.\n");
printf("\n");
printf("POLIKARP - Poland - polikarp@users.sourceforge.net\n");
printf("Programmer. Wrote strbline, streline, chchar.\n");
printf("\n");
printf("SAMUEL CHANG - Australia - badp1ayer@hotmail.com\n");
printf("Programmer. Wrote ttt, the fun Tic-Tac-Toe game with clever AI.\n");
nextpage();
printf("ARKAINO (YEHRCL) - Argentina - arkaino@gmail.com\n");
printf("Programmer. Wrote getlinks, find_basis,\n");
printf("findi_line, chstr, skipstr, naji_mp3.c\n");
printf("\n");
printf("SACHIN MANE - America, Arizona - sachin.mane@gmail.com\n");
printf("Programmer. Wrote cat_tail, cat_head, showline, bremline, eremline.\n");
printf("\n");
printf("MANUEL LE BOETTE - France - askoan@yahoo.fr\n");
printf("Programmer. Wrote lensorts, lensortl.\n");
printf("\n");
}




void kitten(char *namein)
{
int a=0;

najin(namein);

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;
    fputc(a, stdout);
    }

najinclose();
}

void cat_text(char *namein)
{
int a=0;

najin(namein);

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;
    if ( ( (a > 31) && (a < 127) ) ||
         ( (a == '\n') ) ||
         ( (a == '\r') ) ||
         ( (a == '\t') )
        )
    
    
    fputc(a, stdout);
    }

najinclose();
}

/* this is better for unix because you don't really need \r on unix do you */
void cat_text_faster(char *namein)
{
int a=0;

najin(namein);

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;
    if ( ( (a > 31) && (a < 127) ) ||
         ( (a == '\n') ) ||
         ( (a == '\t') )
        )
    
    
    fputc(a, stdout);
    }

najinclose();
}

/* this is the fastest but doesn't include newlines or tabs */
/* because the ascii people didn't do them close by */
void cat_text_fastest(char *namein)
{
int a=0;

najin(namein);

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;
    if ( ( (a > 31) && (a < 127) ) )
    fputc(a, stdout);
    }

najinclose();
}

void repcat(char *namein, unsigned int repeat)
{
int a=0;
unsigned int i=0;

najin(namein);

repeat++;

    loop
    {
    a = fgetc(naji_input);

    if (a == EOF)
    endloop;

    for (i=0; i<repeat; i++)
    fputc(a, stdout);
    }

najinclose();
}

void repcatpp(char *namein, unsigned int start)
{
int a=0;
unsigned int i=0;

najin(namein);

start++;

    loop
    {
    a = fgetc(naji_input);

    if (a == EOF)
    endloop;

    for (i=0; i<start; i++)
    fputc(a, stdout);

    start++;
    }

najinclose();
}



void skipcat(char *namein, char *toskip)
{
int skip = NAJI_FALSE;
int a=0;
int i=0;
int l=0;

    l = strlen(toskip);

najin(namein);

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;
    skip = NAJI_FALSE;

    for (i=0; i<l; i++)
    if (a == toskip[i])
    skip = NAJI_TRUE;

    if (skip == NAJI_FALSE)
    fputc(a, stdout);
    }

najinclose();
}

void onlycat(char *namein, char *toshow)
{
int show = NAJI_TRUE;
int a=0;
int i=0;
int l=0;


najin(namein);

    l = strlen(toshow);

        loop
        {
        a = fgetc(naji_input);
        if (a == EOF) endloop;

        show = NAJI_FALSE;

        for (i=0; i<l; i++)
        if (a == toshow[i])
        show = NAJI_TRUE;

        if (show == NAJI_TRUE)
        fputc(a, stdout);
        }

najinclose();
}


void rndbsout(unsigned long int size)
{
unsigned long int i=0;

srand(time(NULL));
for (i=0; i<size; i++)
fputc((rand() % 255), stdout);
}


void rndtsout(unsigned long int size)
{
unsigned long int i=0;

srand(time(NULL));
for (i=0; i<size; i++)
fputc(((rand() % 95)+' '), stdout);
}


void hexicat(char *namein)
{
int counter = 0; 
int hexbuf[20];

unsigned int offset = 0;

int a;
int i;


najin(namein);


	while (1)
	{

		a = fgetc(naji_input);

		if (a == EOF)
		{

			if (counter == 1)
			fprintf(stdout, "                                                 ");

			if (counter == 2)
			fprintf(stdout, "                                              ");

			if (counter == 3)
			fprintf(stdout, "                                           ");

			if (counter == 4)
			fprintf(stdout, "                                       ");

			if (counter == 5)
			fprintf(stdout, "                                    ");

			if (counter == 6)
			fprintf(stdout, "                                 ");

			if (counter == 7)
			fprintf(stdout, "                              ");

			if (counter == 8)
			fprintf(stdout, "                          ");

			if (counter == 9)
			fprintf(stdout, "                       ");

			if (counter == 10)
			fprintf(stdout, "                    ");

			if (counter == 11)
			fprintf(stdout, "                 ");

			if (counter == 12)
			fprintf(stdout, "             ");

			if (counter == 13)
			fprintf(stdout, "          ");

			if (counter == 14)
			fprintf(stdout, "       ");

			if (counter == 15)
			fprintf(stdout, "    ");

	


			for (i=0; i<counter; i++)
			{
				if ((hexbuf[i] >= 32) && (hexbuf[i] <= 126))
				fputc(hexbuf[i], stdout);
		
				else
				fputc('.', stdout);
			}

			fputc('\n', stdout);



			break;

		}

	
		if (counter == 0 || counter == 16)
		{

			if (offset == 0xFFFFFFF0)
			{
			fprintf(stdout, "OFFLIMIT:  ");
			}

			else
			{
			fprintf(stdout, "%08X:  ", offset);
			}

		}
	
		hexbuf[counter]=a;


		fprintf(stdout, "%02X ", a);

		if (counter == 3  ||
        	    counter == 7  ||
	            counter == 11 ||
	            counter == 15
		)

		fputc(' ', stdout);


		counter++;


		if (counter == 16)
		{



			if (offset != 0xFFFFFFF0)
			offset += 16;

	
			for (i=0; i<16; i++)
			{
				if ((hexbuf[i] >= 32) && (hexbuf[i] <= 126))
				fputc(hexbuf[i], stdout);

				else
				fputc('.', stdout);

			}

			fputc('\n', stdout);


			counter = 0;


		}



	}


najinclose();
}




void coffset(char *namein, long startpos, long endpos)
{
long filesize=0;
long i;

najin(namein);

filesize=najinsize();


  if (startpos > endpos)
  {
  fprintf(stderr,
  "Error, start position cannot be greater than end possition.\n\n");
  exit(15);
  }

  if (startpos > filesize)
  {
  fprintf(stderr,
  "Error, start position is greater than the file size.\n\n");
  exit(16);
  }

  if (endpos > filesize)
  {
  fprintf(stderr,
  "Error, end position is greater than the file size.\n\n");
  exit(17);
  }


  fseek(naji_input, startpos, SEEK_SET);

  for (i=startpos; i<endpos; i++)
  fputc(fgetc(naji_input), stdout);


najinclose();
}



void dumpoffs(char *namein, long startpos, long endpos)
{
long filesize=0;
long i;

najin(namein);

filesize=najinsize();


  if (startpos > endpos)
  {
  fprintf(stderr,
  "Error, start position cannot be greater than end possition.\n\n");
  exit(15);
  }

  if (startpos > filesize)
  {
  fprintf(stderr,
  "Error, start position is greater than the file size.\n\n");
  exit(16);
  }

  if (endpos > filesize)
  {
  fprintf(stderr,
  "Error, end position is greater than the file size.\n\n");
  exit(17);
  }


  fseek(naji_input, startpos, SEEK_SET);

  for (i=startpos; i<endpos; i++)
  printf("%02X ", fgetc(naji_input));

najinclose();
}


void revcat(char *namein)
{
int a=0;
long pos;

najin(namein);

    pos = najinsize();

    loop
    {
    pos--;
    if (pos < 0) endloop;

    fseek(naji_input, pos, SEEK_SET);

    a = fgetc(naji_input);
    fputc(a, stdout);
    }

najinclose();
}


void cat_head(char *namein, int n_lines)
{
int a;
int cnt=0;

    if (n_lines <= 0)
    return;

    najin(namein);

    printf("\n");
	
    while (cnt < n_lines)
	{

        a = fgetc(naji_input);

        if (a == EOF)
        break;

		if (a == '\n')
		{
            cnt++;
            putchar(a);
 		}

        else if (cnt <= n_lines)
        putchar(a);

    }

najinclose();
}


void cat_tail(char *namein, int n_lines)
{
int a;
int i=0;

long *fpos = NULL;

    if (n_lines <= 0)
    return;

    fpos = (long *) malloc(sizeof (long) * n_lines);

    if (fpos == NULL)
	{
	    fprintf(stderr, "\n\nError, cannot allocate memory");
		perror(" "); fprintf(stderr, "\n\n");
        exit(2);
	}
	

    najin(namein);

    fpos[i % n_lines] = 0;
    i++;

	while (1)
	{

		a = fgetc (naji_input);
		if (a == EOF) break;

		if (a == '\n')
		{
           fpos[i % n_lines] = ftell (naji_input);
           i++;
		}

	}


    if (i < n_lines)
    fseek(naji_input, 0, SEEK_SET);

    else fseek(naji_input, fpos[i % n_lines], SEEK_SET);


	while (1)
	{
        a = fgetc(naji_input);

        if (a == EOF)
        break;

        putchar(a);
    }


free(fpos);
najinclose();
}


void showline(char *namein, unsigned long line)
{
int a;
unsigned long cnt = 0;

    if (line <= 0)
    return;

    line -= 1;

	najin(namein);

    while (cnt != line)
	{
        a = fgetc(naji_input);
        if (a == EOF)
        break;

        if (a == '\n')
        cnt++;
  	}
	
    if (cnt == line)
	{
            while (1)
            {
                a = fgetc (naji_input);

                if (a == EOF || a == '\n')
                break;

                putchar(a);
            }

	}

najinclose();
}



void catrandl(char *namein)
{
int a;
unsigned long number_of_lines = 0;
unsigned long random_line = 0;

rndinit();

  najin(namein);

     while (1)
     {
     a = fgetc(naji_input);

     if (a == EOF)
     break;

     if (a == '\n')
     number_of_lines++;
     }

  najinclose();


  random_line = rand() % number_of_lines;
  random_line++;

  showline(namein, random_line);

}

