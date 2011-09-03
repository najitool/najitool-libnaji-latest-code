/* ---------- */
/* najifind.c */
/* ---------- */

/* naji finding/searching functions */

/* this  .c  file is a part */
/* of libnaji version 0.6.4 */

/* libnaji is based on   */
/* the original najitool */

/* both najitool and libnaji */
/* are public domain and are */
/* made by the same author   */
/* please read license.txt   */

/* made by NECDET COKYAZICI  */

/* find_basis, findi_line */
/*     made by YEHRCL     */


#include "libnaji.h"


int (*fl_ptr)(const char *line, const char *str);

unsigned long find_matches = 0;



int findi_line(const char *line, const char *str)
{
char *straux;
char *lineaux;

   lineaux = (char*) malloc(sizeof(char) * (strlen(line) + 1));
   straux  = (char*) malloc(sizeof(char) * (strlen(str)  + 1));

   strcpy(straux, str);
   strcpy(lineaux, line);

   touppers(straux);
   touppers(lineaux);

   if (strstr(lineaux, straux) == NULL)
   return 0;

find_matches++;
return 1;
}


int find_line(const char *line, const char *str)
{

   if (strstr(line, str) == NULL)
   return 0;

find_matches++;
return 1;
}



void find_basis(char *namein, char *str, int sensitive, int show_matches)
{
long pos;
int i;
int c;
int found;
char *line;

find_matches = 0;


        if (sensitive == NAJI_TRUE)
        fl_ptr = find_line;

        else if (sensitive == NAJI_FALSE)
        fl_ptr = findi_line;

        najin(namein);

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

            /* go back and save the chars now */
            fseek(naji_input, pos, SEEK_SET);
            fgets(line, (i+1), naji_input);

            found = fl_ptr(line, str);
        
            if (found)
            printf("%s\n", line);
        
            free(line);
            }
                
            pos = ftell(naji_input);
            c = fgetc(naji_input);
        }

  if (show_matches == NAJI_TRUE)
  printf("\n\n%lu lines containing the string \"%s\"\n\n", find_matches, str);

najinclose();
}




void find(char *namein, char *str)
{
find_basis(namein, str, NAJI_TRUE, NAJI_FALSE);
}

void findi(char *namein, char *str)
{
find_basis(namein, str, NAJI_FALSE, NAJI_FALSE);
}

void cfind(char *namein, char *str)
{
find_basis(namein, str, NAJI_TRUE, NAJI_TRUE);
}

void cfindi(char *namein, char *str)
{
find_basis(namein, str, NAJI_FALSE, NAJI_TRUE);
}


