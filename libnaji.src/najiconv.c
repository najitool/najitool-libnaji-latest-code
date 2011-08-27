/* ---------- */
/* najiconv.c */
/* ---------- */

/* naji conversion functions */

/* this  .c  file is a part */
/* of libnaji version 0.6.4 */

/* libnaji is based on   */
/* the original najitool */

/* both najitool and libnaji */
/* are public domain and are */
/* made by the same author   */
/* please read license.txt   */

/* made by NECDET COKYAZICI  */

/* chchar made by POLIKARP */


#include "libnaji.h"


unsigned char ascii_to_ebcdic_array[256] = {
          0,  1,  2,  3, 55, 45, 46, 47, 22,  5, 37, 11, 12, 13, 14, 15,
         16, 17, 18, 19, 60, 61, 50, 38, 24, 25, 63, 39, 28, 29, 30, 31,
         64, 79,127,123, 91,108, 80,125, 77, 93, 92, 78,107, 96, 75, 97,
        240,241,242,243,244,245,246,247,248,249,122, 94, 76,126,110,111,
        124,193,194,195,196,197,198,199,200,201,209,210,211,212,213,214,
        215,216,217,226,227,228,229,230,231,232,233, 74,224, 90, 95,109,
        121,129,130,131,132,133,134,135,136,137,145,146,147,148,149,150,
        151,152,153,162,163,164,165,166,167,168,169,192,106,208,161,  7,
         32, 33, 34, 35, 36, 21,  6, 23, 40, 41, 42, 43, 44,  9, 10, 27,
         48, 49, 26, 51, 52, 53, 54,  8, 56, 57, 58, 59,  4, 20, 62,225,
         65, 66, 67, 68, 69, 70, 71, 72, 73, 81, 82, 83, 84, 85, 86, 87,
         88, 89, 98, 99,100,101,102,103,104,105,112,113,114,115,116,117,
        118,119,120,128,138,139,140,141,142,143,144,154,155,156,157,158,
        159,160,170,171,172,173,174,175,176,177,178,179,180,181,182,183,
        184,185,186,187,188,189,190,191,202,203,204,205,206,207,218,219,
        220,221,222,223,234,235,236,237,238,239,250,251,252,253,254,255
};

unsigned char ebcdic_to_ascii_array[256] = {
          0,  1,  2,  3,156,  9,134,127,151,141,142, 11, 12, 13, 14, 15,
         16, 17, 18, 19,157,133,  8,135, 24, 25,146,143, 28, 29, 30, 31,
        128,129,130,131,132, 10, 23, 27,136,137,138,139,140,  5,  6,  7,
        144,145, 22,147,148,149,150,  4,152,153,154,155, 20, 21,158, 26,
         32,160,161,162,163,164,165,166,167,168, 91, 46, 60, 40, 43, 33,
         38,169,170,171,172,173,174,175,176,177, 93, 36, 42, 41, 59, 94,
         45, 47,178,179,180,181,182,183,184,185,124, 44, 37, 95, 62, 63,
        186,187,188,189,190,191,192,193,194, 96, 58, 35, 64, 39, 61, 34,
        195, 97, 98, 99,100,101,102,103,104,105,196,197,198,199,200,201,
        202,106,107,108,109,110,111,112,113,114,203,204,205,206,207,208,
        209,126,115,116,117,118,119,120,121,122,210,211,212,213,214,215,
        216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,
        123, 65, 66, 67, 68, 69, 70, 71, 72, 73,232,233,234,235,236,237,
        125, 74, 75, 76, 77, 78, 79, 80, 81, 82,238,239,240,241,242,243,
         92,159, 83, 84, 85, 86, 87, 88, 89, 90,244,245,246,247,248,249,
         48, 49, 50, 51, 52, 53, 54, 55, 56, 57,250,251,252,253,254,255
};

unsigned char ascii_to_ebcdic_char(const unsigned char a)
{
return ascii_to_ebcdic_array[a];
}

unsigned char ebcdic_to_ascii_char(const unsigned char a)
{
return ebcdic_to_ascii_array[a];
}


void asc2ebc(char *namein, char *nameout)
{
int a=0;

najin(namein);
najout(nameout);

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;
    fputc(ascii_to_ebcdic_char(a), naji_output);
    }

najinclose();
najoutclose();
}


void ebc2asc(char *namein, char *nameout)
{
int a=0;

najin(namein);
najout(nameout);

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;
    fputc(ebcdic_to_ascii_char(a), naji_output);
    }

najinclose();
najoutclose();
}


void bin2text(char *namein, char *nameout)
{
int a=0;

najin(namein);
najout(nameout);

        loop
        {
        a = fgetc(naji_input);
        if (a == EOF) endloop;

    if ( ( (a > 31) && (a < 127) ) ||
         ( (a == '\n') ) ||
         ( (a == '\r') ) ||
         ( (a == '\t') )
        )
    
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


/* does the opposite thing that skipchar does */
void onlychar(char *namein, char *nameout, char *toshow)
{
int show = NAJI_TRUE;
int a=0;
int i=0;
int l=0;


najin(namein);
najout(nameout);

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
        fputc(a, naji_output);

        }
najinclose();
najoutclose();
}



void repchar(char *namein, char *nameout, unsigned int repeat)
{
int a=0;
unsigned int i=0;

najin(namein);
najout(nameout);

repeat++;

        loop
        {
        a = fgetc(naji_input);
        if (a == EOF) endloop;

        for (i=0; i<repeat; i++)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}




void repcharp(char *namein, char *nameout, unsigned int start)
{
int a=0;
unsigned int i=0;

najin(namein);
najout(nameout);

start++;

        loop
        {
        a = fgetc(naji_input);
        if (a == EOF) endloop;

        for (i=0; i<start; i++)
        fputc(a, naji_output);

        start++;
        }

najinclose();
najoutclose();
}


void rrrchars(char *namein, char *nameout, int start, int end)
{
int a;
int i=0;

rndinit();

najin(namein);
najout(nameout);

        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        for (i=0; i<rndrange(start, end); i++)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}



void skipchar(char *namein, char *nameout, char *toskip)
{
int skip = NAJI_FALSE;
int a=0;
int i=0;
int l=0;


najin(namein);
najout(nameout);

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
        fputc(a, naji_output);
        }
najinclose();
najoutclose();
}


void chchar(char *namein, char *nameout, char original, char changed)
{
char a;

najin(namein);
najout(nameout);


    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;

    if (a == original)
    a = changed;

    fputc(a, naji_output);
    }

najinclose();
najoutclose();
}

void chchars(char *namein, char *nameout, char *original_chars, char *changed_chars)
{
int a;
int i;

int len_original_chars;
int len_changed_chars;

len_original_chars = strlen(original_chars);
len_changed_chars  = strlen(changed_chars);


if (len_original_chars != len_changed_chars)
{
fprintf(stderr, "\n\nchchars: Error, both strings need to be the same length.\n\n");
exit(1);
}




najin(namein);
najout(nameout);


     while(1)
     {

        a = fgetc(naji_input);

        if (a == EOF)
        break;

           for (i=0; i<len_original_chars; i++)
           {

               if (a == original_chars[i])
               {
               a = changed_chars[i];
               break;
               }
  
           }

        fputc(a, naji_output);

      }



najinclose();
najoutclose();
}



/* reverses the file, note: this is usually not needed for */
/* right to left languages like arabic, its stored the same way as */
/* normal ascii but the software just displays it differently */
/* you might want to use this function for your own graphics or */
/* or encryption format */
void freverse(char *namein, char *nameout)
{
int a=0;
long pos;

najin(namein);
najout(nameout);

    pos = najinsize();

    loop
    {
    pos--;
    if (pos < 0) endloop;

    fseek(naji_input, pos, SEEK_SET);

    a = fgetc(naji_input);
    fputc(a, naji_output);
    }

najinclose();
najoutclose();
}


void revlines(char *namein, char *nameout)
{
unsigned long int longest_line;
char *buffer = NULL;

longest_line = longl(namein);

buffer = (char *) malloc(longest_line * sizeof (char) + 2);
exitnull(buffer);

najin(namein);
najout(nameout);

longest_line++;

  while (1)
  {
  if (feof(naji_input))
  break;
  

  najifgets(buffer, longest_line, naji_input);
  
  sreverse(buffer);

  fprintf(naji_output, "%s", buffer);
  }

free(buffer);
buffer = NULL;
 
najinclose();
najoutclose();
}




/* very useful function, especially for source code. */
/* converts dos format text files to unix format text files */
void dos2unix(char *namein, char *nameout)
{
int a=0;

najin(namein);
najout(nameout);

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;
    
    if (a != '\r')
    fputc(a, naji_output);
    }

najinclose();
najoutclose();
}

/* very useful function, especially for source code. */
/* converts unix format text files to dos format text files */
void unix2dos(char *namein, char *nameout)
{
int a;

najin(namein);
najout(nameout);

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;

    if (a != '\n')
    fputc(a, naji_output);
    
    if (a == '\n')
    {
    fputc('\r', naji_output);
    fputc('\n', naji_output);
    }
    
    }

najinclose();
najoutclose();
}


void tabspace(int spaces, char *namein, char *nameout)
{
int a;
int i;

najin(namein);
najout(nameout);

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;

    if (a != '\t')
    fputc(a, naji_output);
    
    if (a == '\t')
    {
    for (i=0; i<spaces; i++)
    fputc(' ', naji_output);
    }
    
    }

najinclose();
najoutclose();
}


void file2dec(char *namein, char *nameout)
{
int a;


 najin(namein);
 najout(nameout);

  loop
  {
  a = fgetc(naji_input);

  if (a == EOF)
  endloop;

  fprintf(naji_output, "%i\n", a);
  }

 najinclose();
 najoutclose();

}


void file2hex(char *namein, char *nameout)
{
int a;


 najin(namein);
 najout(nameout);

  loop
  {
  a = fgetc(naji_input);

  if (a == EOF)
  endloop;

  fprintf(naji_output, "%02X\n", a);
  }

 najinclose();
 najoutclose();

}


void file2bin(char *namein, char *nameout)
{
char a;

 najin(namein);
 najout(nameout);

  loop
  {
  a = fgetc(naji_input);

  if (a == EOF)
  endloop;

  fprint_8_bit_bin(naji_output, a);
  fputc('\n', naji_output);
  }

 najinclose();
 najoutclose();
}


void f2lower(char *namein, char *nameout)
{
int a;
int i;

najin(namein);
najout(nameout);


    while(1)
    {

    a = fgetc(naji_input);

    if (a == EOF)
    break;


       for (i=0; i<26; i++)
       {

          if (a == ('A' + i) )
          {
          a += 32;
          break;
          }

       }


     fputc(a, naji_output);

    }





najinclose();
najoutclose();
}


void f2upper(char *namein, char *nameout)
{
int a;
int i;

najin(namein);
najout(nameout);


    while(1)
    {

    a = fgetc(naji_input);

    if (a == EOF)
    break;


       for (i=0; i<26; i++)
       {

          if (a == ('a' + i) )
          {
          a -= 32;
          break;
          }

       }


     fputc(a, naji_output);

    }





najinclose();
najoutclose();
}


void fswpcase(char *namein, char *nameout)
{
int a;
int i;

najin(namein);
najout(nameout);


    while(1)
    {

    a = fgetc(naji_input);

    if (a == EOF)
    break;


       for (i=0; i<26; i++)
       {

          if (a == ('a' + i) )
          {
          a -= 32;
          break;
          }

          if (a == ('A' + i) )
          {
          a += 32;
          break;
          }

       }


     fputc(a, naji_output);

    }





najinclose();
najoutclose();
}


void blanka(char *namein, char *nameout)
{
int a;
int i;

najin(namein);
najout(nameout);

	while(1)
	{
	a = fgetc(naji_input);

	if (a == EOF)
	break;

	for (i=0; i<=a; i++)
	fputc(' ', naji_output);

	fputc('\n', naji_output);
	}

najinclose();
najoutclose();
}


void unblanka(char *namein, char *nameout)
{
int a;
int i=0;


najin(namein);
najout(nameout);


	while(1)
	{
	a = fgetc(naji_input);

	if (a == EOF)
	break;

	if (a == ' ')
	i++;

		if ((a == '\n') && (i != 0))
		{
		fputc((i-1), naji_output);
		i = 0;
		}

	}


najinclose();
najoutclose();
}


void n2ch(char ch, char *namein, char *nameout)
{
int a;

najin(namein);
najout(nameout);

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;

    if (a != '\n' && a != '\r')
    fputc(a, naji_output);
    
    if (a == '\n')
    fputc(ch, naji_output);
    
    }

najinclose();
najoutclose();
}


void n2str(char *str, char *namein, char *nameout)
{
int a;

najin(namein);
najout(nameout);

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;

    if (a != '\n' && a != '\r')
    fputc(a, naji_output);
    
    if (a == '\n')
    fputs(str, naji_output);
    
    }

najinclose();
najoutclose();
}

void gigabyte(unsigned long i)
{
unsigned long gb2bytes = 1073741824;
unsigned long gb2kb    = 1048576;
unsigned long gb2mb    = 1024;
unsigned long gb2gb    = 1;


  if ( (i >= 1UL) && (i <= 4294967295UL) ) /* variable overflow prevention */
  printf("GB    : %lu\n", ( (gb2gb)    * (i) ) );
  else printf("gigabyte calculation error\n");

  if ( (i >= 1UL) && (i <= 4194303) ) /* variable overflow prevention */
  printf("MB    : %lu\n", ( (gb2mb)    * (i) ) );

  if ( (i >= 1UL) && (i <= 4095) ) /* variable overflow prevention */
  printf("KB    : %lu\n", ( (gb2kb)    * (i) ) );

  if ( (i >= 1UL) && (i <= 3) ) /* variable overflow prevention */
  printf("Bytes : %lu\n", ( (gb2bytes) * (i) ) );

}

void sp2ce2sp(char c, char *namein, char *nameout)
{
int a;

najin(namein);
najout(nameout);

  while (1)
  {
  a = fgetc(naji_input);

  if (a == EOF)
  break;
  
  if (a == ' ')
  fputc(c, naji_output);

  else if (a == '\n')
  fputc('\n', naji_output);

  else if (a == '\r')
  fputc('\r', naji_output);

  else
  fputc(' ', naji_output);
  }


najinclose();
najoutclose();
}

void sp2re2sp(char *namein, char *nameout)
{
int a;

najin(namein);
najout(nameout);

rndinit();

  while (1)
  {
  a = fgetc(naji_input);

  if (a == EOF)
  break;
  
  if (a == ' ')
  fputc( ( (rand() % 94) + '!'), naji_output);

  else if (a == '\n')
  fputc('\n', naji_output);

  else if (a == '\r')
  fputc('\r', naji_output);

  else
  fputc(' ', naji_output);
  }


najinclose();
najoutclose();
}
