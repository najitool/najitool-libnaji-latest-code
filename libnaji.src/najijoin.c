/* ---------- */
/* najijoin.c */
/* ---------- */

/* naji file spliting and joining functions */

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


void filechop(long copytil, char *namein, char *nameout, char *nameout2)
{
long i;
long fsize;

int a;

najin(namein);
najout(nameout);
najout2(nameout2);

    for (i=0; i<copytil; i++)
    {
    a = fgetc(naji_input);
    fputc(a, naji_output);
    }

    fsize = naji_filesize(naji_input);

    for (i=copytil; i<fsize; i++)
    {
    a = fgetc(naji_input);
    fputc(a, naji_output2);
    }

najinclose();
najoutclose();
najout2close();
}

void filejoin(char *namein, char *namein2, char *nameout)
{
int a=0;

najin(namein);
najin2(namein2);
najout(nameout);

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;
    fputc(a, naji_output);
    }

    loop
    {
    a = fgetc(naji_input2);
    if (a == EOF) endloop;
    fputc(a, naji_output);
    }

najinclose();
najin2close();
najoutclose();
}

/* todo: allow it to merge more than two files */

void mergline(char *namein, char *namein2, char *nameout, char *beforeline, char *afterline)
{
int a;

najin(namein);
najin2(namein2);
najout(nameout);

        loop
        {


        fprintf(naji_output, "%s ", beforeline);



        loop
        {
        a = fgetc(naji_input);

        if (a == '\n') endloop;
        if (a == EOF) endloop;


        fputc(a, naji_output);
        }



        fputc(' ', naji_output);


        loop
        {
        a = fgetc(naji_input2);

        if (a == '\n') endloop;
        if (a == EOF) endloop;
        fputc(a, naji_output);
        }



        fprintf(naji_output, " %s", afterline);

        fputc('\n', naji_output);


        if (a == EOF) endloop;

        }

najinclose();
najin2close();
najoutclose();
}


void putlines(char *namein, char *nameout, char *beforeline, char *afterline)
{
int a;

najin(namein);
najout(nameout);

        loop
        {

        fprintf(naji_output, "%s ", beforeline);


        loop
        {
        a = fgetc(naji_input);

        if (a == '\n') endloop;
        if (a == EOF) endloop;


        fputc(a, naji_output);
        }


        fprintf(naji_output, " %s", afterline);

        fputc('\n', naji_output);

        if (a == EOF) endloop;

        }

najinclose();
najoutclose();
}


void copyoffs(char *namein, long startpos, long endpos, char *nameout)
{
long filesize=0;
long i;

najin(namein);
najout(nameout);

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
  fputc(fgetc(naji_input), naji_output);


najinclose();
najoutclose();
}



void linesnip(int bytes, char *namein, char *nameout)
{
int i;
int a;

najin(namein);
najout(nameout);


   while(1)
   {

    a = fgetc(naji_input);

    if (a == '\n')
    {

      fputc(a, naji_output);
 
      for (i=0; i<bytes; i++)
      {
      a = fgetc(naji_input);

        if (a == EOF)
        {
        najinclose();
        najoutclose();
        return;
        }

      }


    }
    else if (a == EOF) break;
    else fputc(a, naji_output);
   }


najinclose();
najoutclose();
}


void mjoin(char *namein_original_filename, char *nameout_joined_output_file)
{
int a;
unsigned long peice;
char mjoin_filename_buffer[4096];

peice = 0;
najout(nameout_joined_output_file);


while (1)
{


sprintf(mjoin_filename_buffer, "%s.%lu", namein_original_filename, peice);
najin(mjoin_filename_buffer);


	while (1)
	{
	a = fgetc(naji_input);

	if (a == EOF)
	break;

	fputc(a, naji_output);
	}


najinclose();

peice++;
}


}




void bytsplit(char *namein, unsigned long peice_size)
{
int a;
char bytsplit_filename_buffer[4096];
unsigned long size_reached;
unsigned long peice;


size_reached = 0;
peice = 0;

najin(namein);



while (1)
{


sprintf(bytsplit_filename_buffer, "%s.%lu", namein, peice);
najout(bytsplit_filename_buffer);


	while (1)
	{


	a = fgetc(naji_input);

	if (a == EOF)
	break;

	fputc(a, naji_output);

	size_reached++;

	if (size_reached == peice_size)
	break;


	}


najoutclose();

if (a == EOF)
break;

peice++;
size_reached = 0;
}



}




void kbsplit(char *namein, unsigned long peice_size)
{
int a;
unsigned long i;
unsigned long size_reached;
unsigned long peice;
char kbsplit_filename_buffer[4096];


size_reached = 0;
peice = 0;

najin(namein);


while (1)
{


sprintf(kbsplit_filename_buffer, "%s.%lu", namein, peice);
najout(kbsplit_filename_buffer);


	while (1)
	{

	for (i=0; i<1024; i++)
	{

	a = fgetc(naji_input);

	if (a == EOF)
	break;

	fputc(a, naji_output);

	}
	
	if (a == EOF)
	break;

	size_reached++;

	if (size_reached == peice_size)
	break;


	}


najoutclose();

if (a == EOF)
break;

peice++;
size_reached = 0;
}



}




void mbsplit(char *namein, unsigned long peice_size)
{
int a;
unsigned long i;
unsigned long size_reached;
unsigned long peice;
char mbsplit_filename_buffer[4096];

size_reached = 0;
peice = 0;

najin(namein);

while (1)
{


sprintf(mbsplit_filename_buffer, "%s.%lu", namein, peice);
najout(mbsplit_filename_buffer);


	while (1)
	{

	for (i=0; i<1048576; i++)
	{

	a = fgetc(naji_input);

	if (a == EOF)
	break;

	fputc(a, naji_output);

	}
	
	if (a == EOF)
	break;

	size_reached++;

	if (size_reached == peice_size)
	break;


	}


najoutclose();

if (a == EOF)
break;

peice++;
size_reached = 0;
}



}




void gbsplit(char *namein, unsigned long peice_size)
{
int a;
unsigned long i;
unsigned long size_reached;
unsigned long peice;
char gbsplit_filename_buffer[4096];

size_reached = 0;
peice = 0;

najin(namein);

while (1)
{
sprintf(gbsplit_filename_buffer, "%s.%lu", namein, peice);
najout(gbsplit_filename_buffer);


	while (1)
	{

	for (i=0; i<1073741824; i++)
	{

	a = fgetc(naji_input);

	if (a == EOF)
	break;

	fputc(a, naji_output);

	}
	
	if (a == EOF)
	break;

	size_reached++;

	if (size_reached == peice_size)
	break;


	}


najoutclose();

if (a == EOF)
break;

peice++;
size_reached = 0;
}



}
