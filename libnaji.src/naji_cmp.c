/* ---------- */
/* naji_cmp.c */
/* ---------- */

/* naji file comparing functions */

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


void compfile(char *namein, char *namein2, int cont_on_diff)
{
int a;
int b;

int a_line=1;
int b_line=1;

int a_offset=0;
int b_offset=0;

najin(namein);
najin2(namein2);

    loop
    {
    
    a = fgetc(naji_input);
    b = fgetc(naji_input2);
    

  if (a == EOF)
  {
  fprintf(stderr, "\n\nEnd of File (EOF) on first input file: %s\n", namein);
  fprintf(stderr, "on offset: %i\n", a_offset);
  return;
  }

  if (b == EOF)
  {
  fprintf(stderr, "\n\nEnd of File (EOF) on second input file: %s\n", namein2);
  fprintf(stderr, "on offset: %i\n", b_offset);
  return;
  }

    a_offset++;
    b_offset++;
    
    
    if (a == '\n') a_line++;
    if (b == '\n') b_line++;

  if (a != b)
  {
  fprintf(stderr, "\n\nFiles %s and %s differ at offset %i.\n",
  namein, namein2, a_offset);
  fprintf(stderr, "%s line %i\n", namein, a_line);
  fprintf(stderr, "%s line %i\n\n", namein2, b_line);

  if (cont_on_diff == NAJI_FALSE)
  return;


  }


    }

}



void compare(char *namein, char *namein2)
{
compfile(namein, namein2, NAJI_FALSE);
najinclose();
najin2close();
}

/* continuous compare, does not stop comparing when files differ */
void ccompare(char *namein, char *namein2)
{
compfile(namein, namein2, NAJI_TRUE);
najinclose();
najin2close();
}

