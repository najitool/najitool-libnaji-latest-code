/* ---------- */
/* naji_str.c */
/* ---------- */

/* naji string functions */

/* this  .c  file is a part */
/* of libnaji version 0.6.3 */

/* libnaji is based on   */
/* the original najitool */

/* both najitool and libnaji */
/* are public domain and are */
/* made by the same author   */
/* please read license.txt   */

/* made by NECDET COKYAZICI  */


/* chstr          */
/* chstr_line     */

/* skipstr        */
/* skipstr_line   */

/* touppersn      */
/* touppers       */

/* str_move_left  */

/* made by YEHRCL */


/* addtolinebuf, isequal */
/* made by SACHIN MANE   */



#include "libnaji.h"


int swrdcoun(const char *string)
{
int i=0;
int x=1;
int c=0;

        for (i=0; string[i] != '\0'; ++i)
        if ( (string[i] > 32) && (string[i] < 127) )
        {
                if (x)
                {
                ++c;
                x=0;
                }
        }
        else x=1;

return c;
}

void sreverse(char *str)
{
int i;
int len=strlen(str);
char *strbackup=newchar(len);
exitnull(strbackup);

strcpy(strbackup, str);

   for (i=0; i<len; i++)
   str[i] = '\0';

   for (i=0; i<len; i++)
   str[len-i-1] = strbackup[i];

}




void sflpcase(char *str)
{
int i;
int len=strlen(str);

     for (i=0; i<len; i++)
     {
     if (str[i] == 'A') { str[i] = 'a'; continue; }
     if (str[i] == 'B') { str[i] = 'b'; continue; }
     if (str[i] == 'C') { str[i] = 'c'; continue; }
     if (str[i] == 'D') { str[i] = 'd'; continue; }
     if (str[i] == 'E') { str[i] = 'e'; continue; }
     if (str[i] == 'F') { str[i] = 'f'; continue; }
     if (str[i] == 'G') { str[i] = 'g'; continue; }
     if (str[i] == 'H') { str[i] = 'h'; continue; }
     if (str[i] == 'I') { str[i] = 'i'; continue; }
     if (str[i] == 'J') { str[i] = 'j'; continue; }
     if (str[i] == 'K') { str[i] = 'k'; continue; }
     if (str[i] == 'L') { str[i] = 'l'; continue; }
     if (str[i] == 'M') { str[i] = 'm'; continue; }
     if (str[i] == 'N') { str[i] = 'n'; continue; }
     if (str[i] == 'O') { str[i] = 'o'; continue; }
     if (str[i] == 'P') { str[i] = 'p'; continue; }
     if (str[i] == 'Q') { str[i] = 'q'; continue; }
     if (str[i] == 'R') { str[i] = 'r'; continue; }
     if (str[i] == 'S') { str[i] = 's'; continue; }
     if (str[i] == 'T') { str[i] = 't'; continue; }
     if (str[i] == 'U') { str[i] = 'u'; continue; }
     if (str[i] == 'V') { str[i] = 'v'; continue; }
     if (str[i] == 'W') { str[i] = 'w'; continue; }
     if (str[i] == 'X') { str[i] = 'x'; continue; }
     if (str[i] == 'Y') { str[i] = 'y'; continue; }
     if (str[i] == 'Z') { str[i] = 'z'; continue; }

     if (str[i] == 'a') { str[i] = 'A'; continue; }
     if (str[i] == 'b') { str[i] = 'B'; continue; }
     if (str[i] == 'c') { str[i] = 'C'; continue; }
     if (str[i] == 'd') { str[i] = 'D'; continue; }
     if (str[i] == 'e') { str[i] = 'E'; continue; }
     if (str[i] == 'f') { str[i] = 'F'; continue; }
     if (str[i] == 'g') { str[i] = 'G'; continue; }
     if (str[i] == 'h') { str[i] = 'H'; continue; }
     if (str[i] == 'i') { str[i] = 'I'; continue; }
     if (str[i] == 'j') { str[i] = 'J'; continue; }
     if (str[i] == 'k') { str[i] = 'K'; continue; }
     if (str[i] == 'l') { str[i] = 'L'; continue; }
     if (str[i] == 'm') { str[i] = 'M'; continue; }
     if (str[i] == 'n') { str[i] = 'N'; continue; }
     if (str[i] == 'o') { str[i] = 'O'; continue; }
     if (str[i] == 'p') { str[i] = 'P'; continue; }
     if (str[i] == 'q') { str[i] = 'Q'; continue; }
     if (str[i] == 'r') { str[i] = 'R'; continue; }
     if (str[i] == 's') { str[i] = 'S'; continue; }
     if (str[i] == 't') { str[i] = 'T'; continue; }
     if (str[i] == 'u') { str[i] = 'U'; continue; }
     if (str[i] == 'v') { str[i] = 'V'; continue; }
     if (str[i] == 'w') { str[i] = 'W'; continue; }
     if (str[i] == 'x') { str[i] = 'X'; continue; }
     if (str[i] == 'y') { str[i] = 'Y'; continue; }
     if (str[i] == 'z') { str[i] = 'Z'; continue; }
     }

}


void stoupper(char *str)
{
int i;
int len=strlen(str);

     for (i=0; i<len; i++)
     {
     if (str[i] == 'a') { str[i] = 'A'; continue; }
     if (str[i] == 'b') { str[i] = 'B'; continue; }
     if (str[i] == 'c') { str[i] = 'C'; continue; }
     if (str[i] == 'd') { str[i] = 'D'; continue; }
     if (str[i] == 'e') { str[i] = 'E'; continue; }
     if (str[i] == 'f') { str[i] = 'F'; continue; }
     if (str[i] == 'g') { str[i] = 'G'; continue; }
     if (str[i] == 'h') { str[i] = 'H'; continue; }
     if (str[i] == 'i') { str[i] = 'I'; continue; }
     if (str[i] == 'j') { str[i] = 'J'; continue; }
     if (str[i] == 'k') { str[i] = 'K'; continue; }
     if (str[i] == 'l') { str[i] = 'L'; continue; }
     if (str[i] == 'm') { str[i] = 'M'; continue; }
     if (str[i] == 'n') { str[i] = 'N'; continue; }
     if (str[i] == 'o') { str[i] = 'O'; continue; }
     if (str[i] == 'p') { str[i] = 'P'; continue; }
     if (str[i] == 'q') { str[i] = 'Q'; continue; }
     if (str[i] == 'r') { str[i] = 'R'; continue; }
     if (str[i] == 's') { str[i] = 'S'; continue; }
     if (str[i] == 't') { str[i] = 'T'; continue; }
     if (str[i] == 'u') { str[i] = 'U'; continue; }
     if (str[i] == 'v') { str[i] = 'V'; continue; }
     if (str[i] == 'w') { str[i] = 'W'; continue; }
     if (str[i] == 'x') { str[i] = 'X'; continue; }
     if (str[i] == 'y') { str[i] = 'Y'; continue; }
     if (str[i] == 'z') { str[i] = 'Z'; continue; }
     }

}

void stolower(char *str)
{
int i;
int len=strlen(str);

     for (i=0; i<len; i++)
     {
     if (str[i] == 'A') { str[i] = 'a'; continue; }
     if (str[i] == 'B') { str[i] = 'b'; continue; }
     if (str[i] == 'C') { str[i] = 'c'; continue; }
     if (str[i] == 'D') { str[i] = 'd'; continue; }
     if (str[i] == 'E') { str[i] = 'e'; continue; }
     if (str[i] == 'F') { str[i] = 'f'; continue; }
     if (str[i] == 'G') { str[i] = 'g'; continue; }
     if (str[i] == 'H') { str[i] = 'h'; continue; }
     if (str[i] == 'I') { str[i] = 'i'; continue; }
     if (str[i] == 'J') { str[i] = 'j'; continue; }
     if (str[i] == 'K') { str[i] = 'k'; continue; }
     if (str[i] == 'L') { str[i] = 'l'; continue; }
     if (str[i] == 'M') { str[i] = 'm'; continue; }
     if (str[i] == 'N') { str[i] = 'n'; continue; }
     if (str[i] == 'O') { str[i] = 'o'; continue; }
     if (str[i] == 'P') { str[i] = 'p'; continue; }
     if (str[i] == 'Q') { str[i] = 'q'; continue; }
     if (str[i] == 'R') { str[i] = 'r'; continue; }
     if (str[i] == 'S') { str[i] = 's'; continue; }
     if (str[i] == 'T') { str[i] = 't'; continue; }
     if (str[i] == 'U') { str[i] = 'u'; continue; }
     if (str[i] == 'V') { str[i] = 'v'; continue; }
     if (str[i] == 'W') { str[i] = 'w'; continue; }
     if (str[i] == 'X') { str[i] = 'x'; continue; }
     if (str[i] == 'Y') { str[i] = 'y'; continue; }
     if (str[i] == 'Z') { str[i] = 'z'; continue; }
     }

}


void str_move_left(char * s, int n)
{
int i;

        for (i=0; i<n-1; i++)
        s[i] = s[i+1];

}

void touppersn(char *str, int n)
{
int i;

        for (i=0; i<n; i++)
        str[i] = toupper(str[i]);
}

void touppers(char *str)
{
int n;
int i;

    n = strlen (str);

    for (i=0; i<n; i++)
    str[i] = toupper(str[i]);
}


void tolowersn(char *str, int n)
{
int i;

        for (i=0; i<n; i++)
        str[i] = tolower(str[i]);
}

void tolowers(char *str)
{
int n;
int i;

    n = strlen (str);

    for (i=0; i<n; i++)
    str[i] = tolower(str[i]);
}





char * chstr_line(char *line, char *str, char *newstr)
{
int i;
int j;
int x;
int n;
int oldsize;
char * aux;

	n = strlen(line);

    oldsize = sizeof(char) * n+1;

	aux = (char*) malloc(oldsize);

    x = 0;

	for (i=0; i<n; i++)
    {
		for (j=0; str[j] == line[i] && str[j] != '\0'; j++)
        i++;

		if (str[j] != '\0')
        {
			/* "str" didn't match */
            i -= j;
			aux[x++] = line[i];
		}

        else
        {
			i--;

			if (strlen(newstr) > strlen(str))
            {
				/* need more memory */
                oldsize += (strlen(newstr) - strlen(str)) * sizeof(char) +1;
				aux = (char*) realloc(aux, oldsize);
			}

			for (j=0; newstr[j] != '\0'; j++)
            aux[x++] = newstr[j];

		}
	}

aux[x] = '\0';
return aux;
}



void chstr(char *namein, char *nameout, char *str, char *newstr)
{
long pos;
int i;
int c;
char *aux;
char *line;

    najin(namein);
    najout(nameout);

    pos = ftell(naji_input);
    c = fgetc(naji_input);
    if (c == '\n')
    fprintf(naji_output, "\n");

	/* line by line */
	while (c != EOF)
    {
		for (i=0; c != EOF && c != '\n' && c != '\0'; i++)
        c = fgetc(naji_input);

		if (i > 0)
        {
            line = (char*) malloc(sizeof(char)*i+1);

			/* go back and save the chars now */
            fseek(naji_input, pos, SEEK_SET);
            fgets(line, i+1, naji_input);

            aux = chstr_line(line, str, newstr);
            fprintf(naji_output, "%s", aux);
			free(aux);
			free(line);
		}
		
        c = fgetc(naji_input);

		if (c =='\n')
        fprintf(naji_output, "\n");

        ungetc(c, naji_input);

        pos = ftell(naji_input);
        c = fgetc(naji_input);

	}

najinclose();
najoutclose();
}




/* returns a line without "str" naji_input it */
char * skipstr_line(char *line, char *str)
{
int i;
int j;
int x;
int n;

char * aux;

	n = strlen(line);

	aux = (char*) malloc(sizeof(char)*n+1);

    x = 0;

	for (i=0; i<n; i++)
    {
		for (j=0; str[j] == line[i] && str[j] != '\0'; j++)
        i++;

		if (str[j] != '\0')
        {
        /* "str" didn't match */
        i-=j;

        aux[x++] = line[i];
		}

        else i--;

	}

aux[x] = '\0';
return aux;
}







void skipstr(char *namein, char *nameout, char *str)
{
long pos;

int i;
int c;

char *aux;
char *line;


    najin(namein);
    najout(nameout);

    pos = ftell(naji_input);
    c = fgetc(naji_input);

    if (c == '\n')
    fprintf(naji_output, "\n");

	/* line by line (it's this or a limited buffer) */
	while (c != EOF)
    {
		for (i=0; c != EOF && c != '\n' && c != '\0'; i++)
        c = fgetc(naji_input);

		if (i > 0)
        {
            line = (char*) malloc(sizeof(char)*i+1);

			/* go back and save the chars now */
            fseek(naji_input, pos, SEEK_SET);
            fgets(line, i+1, naji_input);

            aux = skipstr_line(line, str);
            fprintf(naji_output, "%s", aux);
			free(aux);
			free(line);
		}
		
        c = fgetc(naji_input);

        if (c == '\n')
        fprintf(naji_output, "\n");

        ungetc(c, naji_input);

        pos = ftell(naji_input);
        c = fgetc(naji_input);

	}

najinclose();
najoutclose();
}




/* This function adds a character 'c' to a buffer line_buf in the end. 
Before adding a character it checks for the length of the buffer and
if required allocates more memory for the buffer. 

This functions returns the new buffer pointer to the calling fuction.
*/

char *addtolinebuf(char c, char *line_buf,
int cur_pos, int *cur_size, int block_size)
{
char *swap_buf = NULL;

	if (cur_pos == *cur_size -1)
	{
		/* Buffer exceeded its limits. Reallocate */

        /* Save the current content of the buffer in the swap buffer first */
		swap_buf = (char *) calloc (*cur_size, sizeof (char));
		if (swap_buf == NULL)
		{
			fprintf(stderr, "\n\nError, cannot allocate memory");
			perror(" "); fprintf(stderr, "\n\n");
            return NULL;
		}
        memcpy(swap_buf, line_buf, *cur_size * sizeof (char));

		/* Free the existing allocated memory for the line buffer */
        free(line_buf);

		/* Allocate fresh memory and increase it by BLOCK_SIZE this time */
		line_buf = (char *) calloc ((*cur_size + block_size), sizeof (char));
		if (line_buf == NULL)
		{
			fprintf(stderr, "\n\nError, cannot allocate memory");
			perror(" "); fprintf(stderr, "\n\n");
            return NULL;
		}

		/* Copy old buffer from swap buffer to the line buffer */
        memcpy(line_buf, swap_buf, *cur_size * sizeof(char));

		/* Free the swap buffer */
        free(swap_buf);

		/* Set the current size. */
        *cur_size += block_size;
	}

	/* Add the new character at the end of the buffer */
    line_buf[cur_pos] = c;

    /* printf("\n added [%c] at [%d]", line_buf[cur_pos], cur_pos); */

return line_buf;
}



int isequal(char *str, char *tempbuf, int len, int start_pos)
{
int i;

    for (i=start_pos; i < (start_pos + len); i++)
	{
        if (str[i % len] != tempbuf[i % len])
        break;
	}

    if (i == (start_pos + len))
    return 1;
    
return 0;
}



/* puts vowels inbetween every letter of a word except the first and last letter */

void vowelwrd(char *str)
{

int len = 0;
int i = 0;


len = strlen(str);


   for (i=0; i<len-1; i++)
   {
   printf("%c", str[i]);
   printf("a");
   }
   printf("%c\n", str[len-1]);

   for (i=0; i<len-1; i++)
   {
   printf("%c", str[i]);
   printf("e");
   }
   printf("%c\n", str[len-1]);

   for (i=0; i<len-1; i++)
   {
   printf("%c", str[i]);
   printf("i");
   }
   printf("%c\n", str[len-1]);

   for (i=0; i<len-1; i++)
   {
   printf("%c", str[i]);
   printf("o");
   }
   printf("%c\n", str[len-1]);

   for (i=0; i<len-1; i++)
   {
   printf("%c", str[i]);
   printf("u");
   }
   printf("%c\n", str[len-1]);

}
