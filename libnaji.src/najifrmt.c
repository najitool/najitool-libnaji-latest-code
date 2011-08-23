/* ---------- */
/* najifrmt.c */
/* ---------- */

/* naji file format functions */

/* this  .c  file is a part */
/* of libnaji version 0.6.4 */

/* libnaji is based on   */
/* the original najitool */

/* both najitool and libnaji */
/* are public domain and are */
/* made by the same author   */
/* please read license.txt   */

/* made by NECDET COKYAZICI  */

/* charaftr and charbefr  */
/* made by SELCUK OZDOGAN */

/* strbline and streline */
/*   made by POLIKARP    */

/* bremline, eremline  */
/* made by SACHIN MANE */


#include "libnaji.h"


void charwrap(int w, char *namein, char *nameout)
{
int a;
int b;

najin(namein);
najout(nameout);


       b=0;

       loop
       {

       a = fgetc(naji_input);
       if (a == EOF)
       endloop;

       b++;

       if (b == w || a == '\n')
       {
       fputc('\n', naji_output);
       b=0;
       }

       fputc(a, naji_output);

       }




najinclose();
najoutclose();
}



void wordwrap(char *namein, char *nameout)
{
int i;
int a;
int b;

najin(namein);
najout(nameout);


       b=0;

       loop
       {

       a = fgetc(naji_input);
       if (a == EOF)
       endloop;

       b++;

       if (a == '\n') b=0;


       for (i=0; i<14; i++)
       if ( (b == 65+i) &&

            (  a == ' ' ||
               a == '-' ||
               a == '+' ||
               a == '_' ||
               a == '/' ||
               a == '\\'

             )
          )

       {
       fputc('\n', naji_output);
       b=0;
       break;
       }

       fputc(a, naji_output);

       }




najinclose();
najoutclose();
}


void numlines(char *namein, char *nameout)
{
int a;
unsigned long line = 1;


najin(namein);
najout(nameout);


fprintf(naji_output, "%lu ", line);


   loop
   {

   a = fgetc(naji_input);

   if (a == EOF)
   endloop;

   if (a == '\n')
   {
   line++;
   fprintf(naji_output, "\n%lu ", line);
   }
   else
   fputc(a, naji_output);

   }


najinclose();
najoutclose();
}



void charaftr(char *namein, char *nameout, char ch)
{
int a;

najin(namein);
najout(nameout);

    loop
    {
    a = fgetc(naji_input);
    
    if (a == EOF)
    endloop;
    
    fputc(a, naji_output);
    fputc(ch, naji_output);
    }

najinclose();
najoutclose();
}


void charbefr(char *namein, char *nameout, char ch)
{
int a;

najin(namein);
najout(nameout);

    loop
    {
    a = fgetc(naji_input);

    if (a == EOF)
    endloop;

    fputc(ch, naji_output);
    fputc(a, naji_output);
    }

najinclose();
najoutclose();
}




void rbcafter(char *namein, char *nameout)
{
int a;

rand_init();

najin(namein);
najout(nameout);

    loop
    {
    a = fgetc(naji_input);
    
    if (a == EOF)
    endloop;
    
    fputc(a, naji_output);
    fputc(rand() % 255, naji_output);
    }

najinclose();
najoutclose();
}


void rbcbefor(char *namein, char *nameout)
{
int a;

rand_init();

najin(namein);
najout(nameout);

    loop
    {
    a = fgetc(naji_input);

    if (a == EOF)
    endloop;

    fputc(rand() % 255, naji_output);
    fputc(a, naji_output);
    }

najinclose();
najoutclose();
}




void rtcafter(char *namein, char *nameout)
{
int a;

rand_init();

najin(namein);
najout(nameout);

    loop
    {
    a = fgetc(naji_input);
    
    if (a == EOF)
    endloop;
    
    fputc(a, naji_output);
    fputc( ( (rand() % 95)+' ' ), naji_output);
    }

najinclose();
najoutclose();
}


void rtcbefor(char *namein, char *nameout)
{
int a;

rand_init();

najin(namein);
najout(nameout);

    loop
    {
    a = fgetc(naji_input);

    if (a == EOF)
    endloop;

    fputc( ( (rand() % 95)+' ' ), naji_output);
    fputc(a, naji_output);
    }

najinclose();
najoutclose();
}



void strbline(char *namein, char *nameout, char *str)
{
char buffer[4096];
   
najin(namein);
najout(nameout);


   *buffer = '\0';

   while(fgets(buffer, sizeof(buffer), naji_input))
   {
   fprintf(naji_output, "%s%s", str, buffer);
   *buffer = '\0';
   }


najinclose();
najoutclose();
}


void streline(char *namein, char *nameout, char *str)
{
char buffer[4096];
char lastchar=0;
   
najin(namein);
najout(nameout);


   *buffer = '\0';

   while(fgets(buffer, sizeof(buffer), naji_input))
   {
   lastchar = buffer[strlen(buffer)-1];
   buffer[strlen(buffer)-1] ='\0';

   fprintf(naji_output, "%s%s%c",  buffer, str, lastchar);
   *buffer = '\0';
   }


najinclose();
najoutclose();
}


void swapfeb(char *namein, char *namein2, char *nameout)
{
int a;
int b;

  najin(namein);
  najin2(namein2);
  najout(nameout);


   while(1)
   {

   a = fgetc(naji_input);
   fgetc(naji_input2);
   b = fgetc(naji_input2);
   fgetc(naji_input);


   if (a == EOF)
   break;

   if (b == EOF)
   break;

   fputc(a, naji_output);
   fputc(b, naji_output);

   }


  najinclose();
  najin2close();
  najoutclose();
}


void filbreed(char *namein, char *namein2, char *nameout)
{
int a;
int b;

  najin(namein);
  najin2(namein2);
  najout(nameout);


   while(1)
   {

   a = fgetc(naji_input);
   b = fgetc(naji_input2);


   if (a == EOF)
   break;

   if (b == EOF)
   break;

   fputc(a, naji_output);
   fputc(b, naji_output);

   }


  najinclose();
  najin2close();
  najoutclose();
}



void wordline(char *namein, char *nameout)
{
int a;

najin(namein);
najout(nameout);


    loop
    {
    a = fgetc(naji_input);

    if (a == EOF)
    endloop;

    if (a == ' ')
    a = '\n';

    fputc(a, naji_output);
    }


najinclose();
najoutclose();
}



void bremline(char *str, char *namein, char *nameout)
{
char *tempbuf = NULL;

int len;
int a = 0;
int i = 0;
int cnt = 0;
int pos = 0;

    len = strlen(str);

    tempbuf = (char *) calloc(len + 1, sizeof (char));

    if (tempbuf == NULL)
	{
		fprintf(stderr, "\n\nError, cannot allocate memory");
		perror(" "); fprintf(stderr, "\n\n");
        exit(2);
	}

	najin(namein);
	najout(nameout);

	while (1)
	{

        a = fgetc(naji_input);

		if (a == EOF)
		{
            for (i=0; i<cnt ; i++)
            fputc(tempbuf[i], naji_output);

			fputc('\n', naji_output);
			break;
		}

		if (a == '\n')
		{
			/* Print the temp buffer */
            for (i=0; i<cnt; i++)
            fputc(tempbuf[i], naji_output);
			
			fputc('\n', naji_output);

			pos = 0;
			cnt = 0;

			continue;
		}

        tempbuf[pos % len] = a;
        pos++;
        cnt++;

		if (cnt == len)
		{

            if (!isequal(str, tempbuf, len, pos % len))
			{

                for (i=0; i<cnt; i++)
                fputc(tempbuf[i], naji_output);

				/* Print remaing line */
				while (1)
				{
                    a = fgetc(naji_input);

					if (a == EOF || a == '\n')
                    break;

                    fputc(a, naji_output);
				}

                fputc('\n', naji_output);
			}


    		else
			{

				/* Skip this line */
				while (1)
				{

                    a = fgetc(naji_input);

                    if (a == EOF || a == '\n')
                    break;


                }


			}


			pos = 0;
			cnt = 0;

		}



	}


najinclose();
najoutclose();
}



/*
   Memory will be allocated for the line buffer as a block size of 100.
   The number 100 is taken because normally the line size is 80 characters.
   In best case scenario this function will not have to reallocate memory
   for the line. In other cases this function keeps on increasing
   the buffer size by BLOCK_SIZE as and when required.
*/

void eremline(char *str, char *namein, char *nameout)
{
const int BLOCK_SIZE = 100;
char *line_buf = NULL;

int cur_buf_size = 0;

int a;
int x;
int i = 0;
int j = 0;
int len = 0;
int buf_len;



    len = strlen(str);

    /*
       Allocate a block of memory for the line buffer.
       This buffer can grow as and when required.
    */

    line_buf = (char *) calloc(BLOCK_SIZE, sizeof(char));

    if (line_buf == NULL)
	{
		fprintf(stderr, "\n\nError, cannot allocate memory");
		perror(" "); fprintf(stderr, "\n\n");
        exit(2);
	}

    cur_buf_size = BLOCK_SIZE;

	najin(namein);
	najout(nameout);

    while (1)
    {
        a = fgetc(naji_input);

        if (a == '\r')
        a = fgetc(naji_input);
        
        if (a == '\n' || a == EOF)
		{
            line_buf =
            addtolinebuf('\0', line_buf, i, &cur_buf_size, BLOCK_SIZE);

            if (line_buf == NULL)
            break;

            if (strlen(line_buf) < len)
			{
                fputs(line_buf, naji_output);

                if (a != EOF)
                fputc('\n', naji_output);
			}

			else
			{
                buf_len = strlen(line_buf);

                j = 0;

                for (x = (buf_len - len); x < buf_len; x++)
				{
                    if (line_buf[x] != str[j])
                    break;

                    j++;
				}

                if (x == buf_len) { }

            	else
				{
                    fputs(line_buf, naji_output);

                    if (a != EOF)
                    fputc('\n', naji_output);
				}
			}

            line_buf[0] = '\0';

            i = 0;

            if (a == EOF)
            break;

            else continue;
        }

		else
		{
            line_buf =
            addtolinebuf(a, line_buf, i, &cur_buf_size, BLOCK_SIZE);

            if (line_buf == NULL)
            break;

            i++;
		}
	}


free(line_buf);
najinclose();
najoutclose();
}


void remline(char *str, char *namein, char *nameout)
{
long pos;
int i;
int c;
char *line;


        najin(namein);
        najout(nameout);

        pos = ftell(naji_input);
        c = fgetc(naji_input);
        
        /* line by line */
        while (c != EOF)
        {
        
            for (i=0; (c != EOF) && (c != '\n') && (c != '\0'); i++)
            c = fgetc(naji_input);

            if (i > 0)
            {
            line = (char*) malloc (sizeof(char)*i+1);

            fseek(naji_input, pos, SEEK_SET);
            fgets(line, (i+1), naji_input);

            if (strstr(line, str) == NULL)
            fprintf(naji_output, "%s\n", line);
        
            free(line);
            }
                
            pos = ftell(naji_input);
            c = fgetc(naji_input);
        }



najinclose();
najoutclose();
}



void skpalnum(char *namein, char *nameout)
{
int skip = NAJI_FALSE;
int a=0;


najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        skip = NAJI_FALSE;

        if (isalnum(a))
        skip = NAJI_TRUE;

        if (skip == NAJI_FALSE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void skpalpha(char *namein, char *nameout)
{
int skip = NAJI_FALSE;
int a=0;


najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        skip = NAJI_FALSE;

        if (isalpha(a))
        skip = NAJI_TRUE;

        if (skip == NAJI_FALSE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void skpcntrl(char *namein, char *nameout)
{
int skip = NAJI_FALSE;
int a=0;


najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        skip = NAJI_FALSE;

        if (iscntrl(a))
        skip = NAJI_TRUE;

        if (skip == NAJI_FALSE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void skpdigit(char *namein, char *nameout)
{
int skip = NAJI_FALSE;
int a=0;


najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        skip = NAJI_FALSE;

        if (isdigit(a))
        skip = NAJI_TRUE;

        if (skip == NAJI_FALSE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void skpgraph(char *namein, char *nameout)
{
int skip = NAJI_FALSE;
int a=0;


najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        skip = NAJI_FALSE;

        if (isgraph(a))
        skip = NAJI_TRUE;

        if (skip == NAJI_FALSE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void skplower(char *namein, char *nameout)
{
int skip = NAJI_FALSE;
int a=0;


najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        skip = NAJI_FALSE;

        if (islower(a))
        skip = NAJI_TRUE;

        if (skip == NAJI_FALSE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void skpprint(char *namein, char *nameout)
{
int skip = NAJI_FALSE;
int a=0;


najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        skip = NAJI_FALSE;

        if (isprint(a))
        skip = NAJI_TRUE;

        if (skip == NAJI_FALSE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void skppunct(char *namein, char *nameout)
{
int skip = NAJI_FALSE;
int a=0;


najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        skip = NAJI_FALSE;

        if (ispunct(a))
        skip = NAJI_TRUE;

        if (skip == NAJI_FALSE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void skpspace(char *namein, char *nameout)
{
int skip = NAJI_FALSE;
int a=0;


najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        skip = NAJI_FALSE;

        if (isspace(a))
        skip = NAJI_TRUE;

        if (skip == NAJI_FALSE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void skpupper(char *namein, char *nameout)
{
int skip = NAJI_FALSE;
int a=0;


najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        skip = NAJI_FALSE;

        if (isupper(a))
        skip = NAJI_TRUE;

        if (skip == NAJI_FALSE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void skpxdigt(char *namein, char *nameout)
{
int skip = NAJI_FALSE;
int a=0;


najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        skip = NAJI_FALSE;

        if (isxdigit(a))
        skip = NAJI_TRUE;

        if (skip == NAJI_FALSE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void onlalnum(char *namein, char *nameout)
{
int show = NAJI_TRUE;
int a=0;

najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        show = NAJI_FALSE;

        if (isalnum(a))
        show = NAJI_TRUE;

        if (show == NAJI_TRUE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void onlalpha(char *namein, char *nameout)
{
int show = NAJI_TRUE;
int a=0;

najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        show = NAJI_FALSE;

        if (isalpha(a))
        show = NAJI_TRUE;

        if (show == NAJI_TRUE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void onlcntrl(char *namein, char *nameout)
{
int show = NAJI_TRUE;
int a=0;

najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        show = NAJI_FALSE;

        if (iscntrl(a))
        show = NAJI_TRUE;

        if (show == NAJI_TRUE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void onldigit(char *namein, char *nameout)
{
int show = NAJI_TRUE;
int a=0;

najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        show = NAJI_FALSE;

        if (isdigit(a))
        show = NAJI_TRUE;

        if (show == NAJI_TRUE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void onlgraph(char *namein, char *nameout)
{
int show = NAJI_TRUE;
int a=0;

najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        show = NAJI_FALSE;

        if (isgraph(a))
        show = NAJI_TRUE;

        if (show == NAJI_TRUE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void onllower(char *namein, char *nameout)
{
int show = NAJI_TRUE;
int a=0;

najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        show = NAJI_FALSE;

        if (islower(a))
        show = NAJI_TRUE;

        if (show == NAJI_TRUE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void onlprint(char *namein, char *nameout)
{
int show = NAJI_TRUE;
int a=0;

najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        show = NAJI_FALSE;

        if (isprint(a))
        show = NAJI_TRUE;

        if (show == NAJI_TRUE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void onlpunct(char *namein, char *nameout)
{
int show = NAJI_TRUE;
int a=0;

najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        show = NAJI_FALSE;

        if (ispunct(a))
        show = NAJI_TRUE;

        if (show == NAJI_TRUE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void onlspace(char *namein, char *nameout)
{
int show = NAJI_TRUE;
int a=0;

najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        show = NAJI_FALSE;

        if (isspace(a))
        show = NAJI_TRUE;

        if (show == NAJI_TRUE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void onlupper(char *namein, char *nameout)
{
int show = NAJI_TRUE;
int a=0;

najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        show = NAJI_FALSE;

        if (isupper(a))
        show = NAJI_TRUE;

        if (show == NAJI_TRUE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void onlxdigt(char *namein, char *nameout)
{
int show = NAJI_TRUE;
int a=0;

najin(namein);
najout(nameout);


        loop
        {
        a = fgetc(naji_input);

        if (a == EOF)
        endloop;

        show = NAJI_FALSE;

        if (isxdigit(a))
        show = NAJI_TRUE;

        if (show == NAJI_TRUE)
        fputc(a, naji_output);
        }

najinclose();
najoutclose();
}


void tothe(char *str)
{
int i;
int l;

l = strlen(str);
  
       for (i=0; i<(l-1); i++)
       {
       printf("%c to the", str[i]);

       if (i == (l-1) )
       break;

       putchar(' ');

       }

       putchar(str[l-1]);

}


void ftothe(char *namein, char *nameout)
{
int a;

int i;
long l;

najin(namein);
najout(nameout);

l = najinsize();
  
       for (i=0; i<(l-1); i++)
       {

       a = fgetc(naji_input);

       fprintf(naji_output, "%c to the", a);

       if (i == (l-1))
       break;

       fputc(' ', naji_output);
       }

       a = fgetc(naji_input);
       fputc(a, naji_output);

najinclose();
najoutclose();
}


void strachar(char *str, char *namein, char *nameout)
{
int a;

najin(namein);
najout(nameout);

    while(1)
    {
    a = fgetc(naji_input);

    if (a == EOF)
    break;

    fputc(a, naji_output);

    fprintf(naji_output, str);
    }

najinclose();
najoutclose();
}


void strbchar(char *str, char *namein, char *nameout)
{
int a;

najin(namein);
najout(nameout);

    while(1)
    {
    a = fgetc(naji_input);

    if (a == EOF)
    break;

    fprintf(naji_output, str);

    fputc(a, naji_output);
    }

najinclose();
najoutclose();
}


void rstrach(int len, char *namein, char *nameout)
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

    fputc(a, naji_output);

    for (i=0; i<len; i++)
    fputc(((rand() % 95)+' '), naji_output);
    }

najinclose();
najoutclose();
}


void rstrbch(int len, char *namein, char *nameout)
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

    for (i=0; i<len; i++)
    fputc(((rand() % 95)+' '), naji_output);

    fputc(a, naji_output);
    }

najinclose();
najoutclose();
}


void cpfroml(unsigned long line, char *namein, char *nameout)
{
int a;
unsigned long cnt = 0;

    if (line <= 0)
    return;

    line -= 1;

najin(namein);
najout(nameout);

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

	a = fgetc(naji_input);

	if (a == EOF)
	{
	najinclose();
	najoutclose();
	return;
	}

	if (a != '\r')
	fputc(a, naji_output);

            while (1)
            {
                a = fgetc(naji_input);

                if (a == EOF)
                break;

		fputc(a, naji_output);
            }

	}


najinclose();
najoutclose();
}


void cptiline(unsigned long line, char *namein, char *nameout)
{
int a;
unsigned long cnt = 0;

    if (line <= 0)
    return;

najin(namein);
najout(nameout);

	while (1)
	{
        a = fgetc(naji_input);

        if (a == EOF)
        break;

        if (a == '\n')
        cnt++;

		if (cnt == line)
		{
		a = fgetc(naji_input);

			if (a == EOF)
			break;

			if (a == '\r')
			fputc(a, naji_output);

			break;
		}

	fputc(a, naji_output);

  	}
	



najinclose();
najoutclose();
}


void istrael(char *str, int pos, char *namein, char *nameout)
{
int a;
int b;
int isdos = NAJI_FALSE;
int i = 0;

najin(namein);
najout(nameout);


if (pos == 0)
{

	while (1)
	{
	a = fgetc(naji_input);
	if (a == EOF)
	break;

	if (a == '\r')
	{
	isdos = NAJI_TRUE;
	break;
	}

	}

	najinclose();
	najin(namein);

	a = fgetc(naji_input);

	if (a != EOF)
	{

		if (a == '\n')
		{
		if (isdos == NAJI_TRUE)
		fprintf(naji_output, "%s\n\r", str);
	
		else 
		fprintf(naji_output, "%s\n", str);
		}

	}
	else
	{
	najinclose();
	najoutclose();
	return;
	}


	b = fgetc(naji_input);

	if (b != EOF)
	{

		if (b == '\n')
		{
		if (isdos == NAJI_TRUE)
		fprintf(naji_output, "%s\n\r", str);
	
		else 
		fprintf(naji_output, "%s\n", str);
		}

	}
	else
	{
	najinclose();
	najoutclose();
	return;
	}

najinclose();
najin(namein);
}


  while (1)
  {
  a = fgetc(naji_input);

  if (a == EOF)
  break;
  
  fputc(a, naji_output);

  i++;

  if (a == '\n')
  i=0;
   
  if (i == pos)
  fputs(str, naji_output);
  }

najinclose();
najoutclose();
}


void istreml(char *str, char *namein, char *nameout)
{
int a;
int b;
int isdos = NAJI_FALSE;

najin(namein);
najout(nameout);


while (1)
{
a = fgetc(naji_input);
if (a == EOF)
break;

if (a == '\r')
{
isdos = NAJI_TRUE;
break;
}

}

najinclose();
najin(namein);

a = fgetc(naji_input);

if (a != EOF)
{

if (a == '\n')
{
	if (isdos == NAJI_TRUE)
	fprintf(naji_output, "\n\r%s\n\r", str);
	
	else 
	fprintf(naji_output, "\n%s\n", str);
}

}
else
{
najinclose();
najoutclose();
return;
}


b = fgetc(naji_input);

if (b != EOF)
{

if (b == '\n')
{
	if (isdos == NAJI_TRUE)
	fprintf(naji_output, "\n\r%s\n\r", str);
	
	else 
	fprintf(naji_output, "\n%s\n", str);
}

}
else
{
najinclose();
najoutclose();
return;
}

najinclose();
najin(namein);


	while (1)
	{
	a = fgetc(naji_input);

	if (a == EOF)
	break;
  
		if (a == '\n')
		{
			b = fgetc(naji_input);

			if (b == '\r')
			fprintf(naji_output, "\n\r%s\n\r", str);

			else if (b == '\n')
			fprintf(naji_output, "\n%s\n", str);
 
			else if (b == EOF)
			{
			fputc(a, naji_output);

				if (isdos == NAJI_TRUE)
				fprintf(naji_output, "\n\r%s\n\r", str);
	
				else 
				fprintf(naji_output, "\n%s\n", str);

			break;
			}
 
			else
			{
			fputc(a, naji_output);
			fputc(b, naji_output);
			}

		}
		
		else
		fputc(a, naji_output);

  }





najinclose();
najoutclose();
}
