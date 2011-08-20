/* ---------- */
/* najiprog.c */
/* ---------- */

/* naji programming functions  */

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


void bin2c(char *namein, char *nameout, char *array_name)
{
int a;
int i=0;
int end=15;
int fsize_var=0;
int fsize_max=0;

najin(namein);
najout(nameout);

fsize_max = najinsize();
fsize_var = fsize_max;

fprintf(naji_output, "\n/*  converted with najitool with the command:  */\n");
fprintf(naji_output, "\n/*  najitool bin2c %s %s %s  */\n\n", namein, nameout, array_name);
fprintf(naji_output, "/*  please  keep  these  comments  here  so  others  can  use  */\n");
fprintf(naji_output, "/*  najitool the completely free tool for doing this as well.  */\n");
fprintf(naji_output, "/*  you can get najitool here: http://najitool.sf.net/         */\n\n");

    fprintf(naji_output,"unsigned char %s[%i] = \n{\n", array_name, fsize_max);

    loop
    {
    a = fgetc(naji_input);

    if (fsize_var == 1) endloop;

    if (i == end) { fprintf(naji_output, "\n"); i=0; }

    fprintf(naji_output, "0x%02X,", a);
    i++;
    
    fsize_var--;
    }

fprintf(naji_output, "\n0x%02X", a);
fprintf(naji_output, "};\n\n");

najinclose();
najoutclose();
}


void hmaker(char *namein)
{
char buffer[402];

najin(namein);

    loop
    {

    fgets(buffer, 400, naji_input); 

    if (feof(naji_input))
    endloop;

    if (!strncmp("int", buffer, 3))       printf(buffer);

    if (!strncmp("FILE", buffer, 4))      printf(buffer);
    if (!strncmp("void", buffer, 4))      printf(buffer);
    if (!strncmp("char", buffer, 4))      printf(buffer);
    if (!strncmp("long", buffer, 4))      printf(buffer);
    if (!strncmp("uint", buffer, 4))      printf(buffer);
    if (!strncmp("UINT", buffer, 4))      printf(buffer);
    if (!strncmp("auto", buffer, 4))      printf(buffer);

    if (!strncmp("uchar", buffer, 5))     printf(buffer);
    if (!strncmp("ulong", buffer, 5))     printf(buffer);
    if (!strncmp("UCHAR", buffer, 5))     printf(buffer);
    if (!strncmp("ULONG", buffer, 5))     printf(buffer);
    if (!strncmp("short", buffer, 5))     printf(buffer);
    if (!strncmp("float", buffer, 5))     printf(buffer);
    if (!strncmp("class", buffer, 5))     printf(buffer);
    if (!strncmp("union", buffer, 5))     printf(buffer);
    if (!strncmp("const", buffer, 5))     printf(buffer);

    if (!strncmp("double", buffer, 6))    printf(buffer);
    if (!strncmp("struct", buffer, 6))    printf(buffer);
    if (!strncmp("signed", buffer, 6))    printf(buffer);
    if (!strncmp("static", buffer, 6))    printf(buffer);
    if (!strncmp("extern", buffer, 6))    printf(buffer);
    if (!strncmp("size_t", buffer, 6))    printf(buffer);
    if (!strncmp("time_t", buffer, 6))    printf(buffer);

    if (!strncmp("wchar_t", buffer, 7))   printf(buffer);
    if (!strncmp("typedef", buffer, 7))   printf(buffer);

    if (!strncmp("unsigned", buffer, 8))  printf(buffer);
    if (!strncmp("register", buffer, 8))  printf(buffer);
    if (!strncmp("volatile", buffer, 8))  printf(buffer);
    if (!strncmp("#include", buffer, 8))  printf(buffer);
    }

najinclose();
}


void hmakerf(char *namein, char *nameout)
{
char buffer[402];

najin(namein);
najout(nameout);

    loop
    {

    fgets(buffer, 400, naji_input); 

    if (feof(naji_input))
    endloop;

    if (!strncmp("int", buffer, 3))       fprintf(naji_output, buffer);

    if (!strncmp("FILE", buffer, 4))      fprintf(naji_output, buffer);
    if (!strncmp("void", buffer, 4))      fprintf(naji_output, buffer);
    if (!strncmp("char", buffer, 4))      fprintf(naji_output, buffer);
    if (!strncmp("long", buffer, 4))      fprintf(naji_output, buffer);
    if (!strncmp("uint", buffer, 4))      fprintf(naji_output, buffer);
    if (!strncmp("UINT", buffer, 4))      fprintf(naji_output, buffer);
    if (!strncmp("auto", buffer, 4))      fprintf(naji_output, buffer);

    if (!strncmp("uchar", buffer, 5))     fprintf(naji_output, buffer);
    if (!strncmp("ulong", buffer, 5))     fprintf(naji_output, buffer);
    if (!strncmp("UCHAR", buffer, 5))     fprintf(naji_output, buffer);
    if (!strncmp("ULONG", buffer, 5))     fprintf(naji_output, buffer);
    if (!strncmp("short", buffer, 5))     fprintf(naji_output, buffer);
    if (!strncmp("float", buffer, 5))     fprintf(naji_output, buffer);
    if (!strncmp("class", buffer, 5))     fprintf(naji_output, buffer);
    if (!strncmp("union", buffer, 5))     fprintf(naji_output, buffer);
    if (!strncmp("const", buffer, 5))     fprintf(naji_output, buffer);

    if (!strncmp("double", buffer, 6))    fprintf(naji_output, buffer);
    if (!strncmp("struct", buffer, 6))    fprintf(naji_output, buffer);
    if (!strncmp("signed", buffer, 6))    fprintf(naji_output, buffer);
    if (!strncmp("static", buffer, 6))    fprintf(naji_output, buffer);
    if (!strncmp("extern", buffer, 6))    fprintf(naji_output, buffer);
    if (!strncmp("size_t", buffer, 6))    fprintf(naji_output, buffer);
    if (!strncmp("time_t", buffer, 6))    fprintf(naji_output, buffer);

    if (!strncmp("wchar_t", buffer, 7))   fprintf(naji_output, buffer);
    if (!strncmp("typedef", buffer, 7))   fprintf(naji_output, buffer);

    if (!strncmp("unsigned", buffer, 8))  fprintf(naji_output, buffer);
    if (!strncmp("register", buffer, 8))  fprintf(naji_output, buffer);
    if (!strncmp("volatile", buffer, 8))  fprintf(naji_output, buffer);
    if (!strncmp("#include", buffer, 8))  fprintf(naji_output, buffer);
    }

najinclose();
najoutclose();
}


void makarray(char *namein, char *nameout, char *namevar)
{
/* Don't worry, the memory taken up by variables in functions
 * are freed when the function ends, in case you didn't know.
 */
   char buffer[1050];

int i;

najin(namein);
najout(nameout);


 fprintf(naji_output, "char *%s[] = {\n", namevar);

   while(1)
   {
   fgets(buffer, 1024, naji_input);

   if (feof(naji_input))
   break;

           for (i=0; buffer[i] != 0; i++)
           {

                if (buffer[i] == '\n')
                {
                buffer[i] = '\0';
                break;
                }

                if (buffer[i] == '\r')
                {
                buffer[i] = '\0';
                break;
                }
           }

   fprintf(naji_output, "\"%s\",\n", buffer);
   }

   najinclose();
   najoutclose();

   najed(nameout);
   fseek(naji_edit, -2, SEEK_END);
   fprintf(naji_edit, "\n};\n");
   najedclose();

}









void printftx(char *namein, char *nameout)
{
char buffer[1050];

int i;

najin(namein);
najout(nameout);



   while(1)
   {
   fgets(buffer, 1024, naji_input);

   if (feof(naji_input))
   break;

           for (i=0; buffer[i] != 0; i++)
           {

                if (buffer[i] == '\n')
                {
                buffer[i] = '\0';
                break;
                }

                if (buffer[i] == '\r')
                {
                buffer[i] = '\0';
                break;
                }
           }

   fprintf(naji_output, "printf(\"");



       for (i=0; buffer[i] != 0; i++)
       {

           if (buffer[i] == '\"')
           {
           fputc('\\', naji_output);
           fputc('\"', naji_output);
           }

           else if (buffer[i] == '\\')
           {
           fputc('\\', naji_output);
           fputc('\\', naji_output);
           }

       else
       fputc(buffer[i], naji_output);
       }

   fprintf(naji_output, "\\n\");\n");
   }


   najinclose();
   najoutclose();
}

