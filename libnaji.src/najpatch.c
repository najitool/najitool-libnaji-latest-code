/* ---------- */
/* najpatch.c */
/* ---------- */

/* naji patching functions */

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

void patch(char *named)
{
char buffer[1024];
unsigned long offset=0;
int value=0;
char *end;

unsigned long bytes_patched = 0;

long filesize = 0;

  najed(named);

  filesize = najedsize();

    loop
    {

    printf("\nType offset to point to: ");
    safegets(buffer, 1000);
    printf("\n");
    offset = strtoul(buffer, &end, 0);

    if (offset > filesize)
    {
    fprintf(stderr, "Error, offset cannot be greater than filesize.\n");
    continue;
    }


    loop
    {

    printf("Type new value 0-255: ");
    safegets(buffer, 1000);
    printf("\n");
    value = atoi(buffer);


    if (value > 255)
    {
    fprintf(stderr, "Error, value cannot be greater than 255.\n");
    continue;
    }

    else if (value < 0)
    {
    fprintf(stderr, "Error, value cannot be less than 0.\n");
    continue;
    }

    else break;

    }



    printf("Proceed with patch? [Y]es/[N]o/[Q]uit ");
    safegets(buffer, 1000);
    printf("\n");

    if (buffer[0] == 'y' || buffer[0] == 'Y')
    {

    fseek(naji_edit, offset, SEEK_SET);
    fputc(value, naji_edit);
    bytes_patched++;

    printf("Successfully patched offset %lu with the value %i\n", offset, value);
    printf("Patch again? [Y]es/[No] ");
    safegets(buffer, 1000);
    printf("\n");
    if (buffer[0] == 'y' || buffer[0] == 'Y')
    continue;

    else break;
    }

    else if (buffer[0] == 'n' || buffer[0] == 'N')
    continue;

    else if (buffer[0] == 'q' || buffer[0] == 'Q')
    break;

    else continue;

    }

printf("Sucessfully patched %lu bytes of data.\n", bytes_patched);


najedclose();
}



void qpatch(char *named, char *patch_file)
{
char *end;
char buffer[200];
char converted_buffer[200];

int value = 0;
unsigned long offset = 0;

unsigned long bytes_patched = 0;

long filesize = 0;

int i;


najin(patch_file);
najed(named);

filesize = najedsize();


    loop
    {

    /* gets offset */

       if ( fgets(buffer, 100, naji_input) == NULL )
       break;

       for (i=0; i<100; i++)
       if ( ! (buffer[i] < '0' && buffer[i] > '9') )
       converted_buffer[i] = buffer[i];

       offset = strtoul(converted_buffer, &end, 0);
    

    if (offset > filesize)
    {
    fprintf(stderr, "Patch file error, offset cannot be greater than filesize.\n");
    break;
    }



    /* gets value */

       if ( fgets(buffer, 100, naji_input) == NULL )
       break;

       for (i=0; i<100; i++)
       if ( ! (buffer[i] < '0' && buffer[i] > '9') )
       converted_buffer[i] = buffer[i];
 
       value = atoi(converted_buffer);



    if (value > 255)
    {
    fprintf(stderr, "Patch file error, value cannot be greater than 255.\n");
    break;
    }

    if (value < 0)
    {
    fprintf(stderr, "Patch file error, value cannot be less than 0.\n");
    break;
    }



    /* seek to offset */
    fseek(naji_edit, offset, SEEK_SET);

    /* write value */
    fputc(value, naji_edit);
    bytes_patched++;
    }


printf("Sucessfully patched %lu bytes of data.\n", bytes_patched);
if (bytes_patched > filesize)
{
fprintf(stderr, "WARNING: The amount of bytes patched were more than the filesize.\n");
fprintf(stderr, "This means certain location(s) were patched more than once,\n");
fprintf(stderr, "because they were specified in the patch file more than once.\n");
fprintf(stderr, "There is a minor bug in the patch file, it is recommended that\n");
fprintf(stderr, "delete the duplicate patcher instructions in the patch file before\n");
fprintf(stderr, "you release it.\n");
}



najinclose();
najedclose();
}
 


void mkpatch(char *original, char *patched, char *patchfile)
{
int a;
int b;

unsigned long offset = 0;
unsigned long bytes  = 0;

long insize = 0;
long in2size = 0;

najin(original);
najin2(patched);
najout(patchfile);

insize = najinsize();
in2size = najin2size();

if (insize != in2size)
{
fprintf(stderr, "Error, orginal file and patched file must be the same size for the patch to be made.\n");
return;
}


offset--;

    loop
    {
    
      a = fgetc(naji_input);
      b = fgetc(naji_input2);
    
      if (a == EOF)
      break;

      offset++;
    
      if (a != b)
      {
      fprintf(naji_output, "%lu\n", offset);
      fprintf(naji_output, "%lu\n", (unsigned long)b);
      bytes++;
      }

    }


printf("\n");
printf("Patch file %s successfully made which patches %lu bytes.\n", patchfile, bytes);
printf("\n");
printf("Feel free to bundle najitool with your patch file,\n");
printf("if you are releasing it or backing it up to CD or floppy etc.\n");
printf("\n");
printf("You might want to make a patch.bat or patch.sh file containing:\n");
printf("najitool qpatch %s %s\n", original, patchfile);
printf("\n");

najinclose();
najin2close();
najoutclose();
}

