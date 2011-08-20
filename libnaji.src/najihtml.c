/* ---------- */
/* najihtml.c */
/* ---------- */

/* naji HTML (Hyper Text Markup Language) functions */

/* this  .c  file is a part */
/* of libnaji version 0.6.3 */

/* libnaji is based on   */
/* the original najitool */

/* both najitool and libnaji */
/* are public domain and are */
/* made by the same author   */
/* please read license.txt   */

/* made by NECDET COKYAZICI  */

/* getlinks made by YEHRCL   */


#include "libnaji.h"


void htmlfast(char *namein, char *nameout)
{
int a;

najin(namein);
najout(nameout);


fprintf(naji_output,
"<html><head><title>%s - converted with najitool</title></head><body><pre>",
nameout);

    loop
    {
    a = fgetc(naji_input);
    if (a == EOF) endloop;

    if ( (a != '<') && (a != '>') )
    fputc(a, naji_output);

    if (a == '<')
    fprintf(naji_output, "&lt;");

    if (a == '>')
    fprintf(naji_output, "&gt;");
    }



fprintf(naji_output, "<p> <hr> This HTML page was converted with <b> najitool. </b> <br> ");
fprintf(naji_output, "From plain text to HTML with all the formating preserved. <br>");

fprintf(naji_output,
"With the command: <i> najitool htmlfast %s %s </i> <br> ",
namein, nameout);

fprintf(naji_output,
"You can get <b> najitool </b> the completely free tool at: <br> ");

fprintf(naji_output,
"<b> <a href=\"http://najitool.sf.net/\"> http://najitool.sf.net/ </a> </b> <hr> <p>");

fprintf(naji_output, "</pre> </body> </html>");

najinclose();
najoutclose();
}


/* todo: make it convert http, https, and ftp links */
/* into clicable <a href=""> </a> links */

/* note: <li> means bullet point */

void txt2html(char *namein, char *nameout)
{
int a;
int i;
int numof_tabs=4;


najin(namein);
najout(nameout);


fprintf(naji_output, 
"<html> <head> <title>%s - converted with najitool </title> </head> <body>",
 nameout);

    while(1)
    {
    a = fgetc(naji_input);
    if (a == EOF) break;

    if ( (a != '\n') && (a != '<') && (a != '>') && (a != '\t') )
    fputc(a, naji_output);
    
    if (a == '\n')
    fprintf(naji_output, "<br>\n");
    
    if (a == '<')
    fprintf(naji_output, "&lt;");

    if (a == '>')
    fprintf(naji_output, "&gt;");

    if (a == '\t')
    {
    for (i=0; i<numof_tabs; i++)
    fprintf(naji_output, "&nbsp;");
    }


    }

fprintf(naji_output,
"<p> <hr> This HTML page was converted with <b> najitool </b> from plain text to HTML. <br>");

fprintf(naji_output,
"With the command: <i> najitool txt2html %s %s </i> <br> ",
namein, nameout);

fprintf(naji_output,
"You can get <b> najitool </b> the completely free tool at: <br> ");

fprintf(naji_output,
"<b> <a href=\"http://najitool.sf.net/\"> http://najitool.sf.net/ </a> </b> <hr> <p>");

fprintf(naji_output, "</body> </html>");

najinclose();
najoutclose();
}



void html2txt(char *namein, char *nameout)
{
int a;

najin(namein);
najout(nameout);


    while(1)
    {

    a = fgetc(naji_input);
    if (a == EOF) break;

    if (a == '<')
    {

      while (1)
      {

      a = fgetc(naji_input);
      if (a == EOF) break;

        if (a == 'p' || a == 'P')
        {

         a = fgetc(naji_input);
         if (a == EOF) break;

           if (a == '>')
           {
           fputc('\n', naji_output);
           fputc('\n', naji_output);
           break;
           }

           else
           {
           ungetc(a, naji_input);
           }

        }
        else


        if (a == 'b' || a == 'B')
        {

        a = fgetc(naji_input);
        if (a == EOF) break;


         if (a == 'r' || a == 'R')
         {
         a = fgetc(naji_input);
         if (a == EOF) break;


           if (a == '>')
           {
           fputc('\n', naji_output);
           break;
           }

           else
           {
           ungetc(a, naji_input);
           }


         }



        }
   

      if (a == '>') break;
      }

    }



    else if (a == '\n')
    {

      while (1)
      {

      a = fgetc(naji_input);
      if (a == EOF) break;

      if (a == '\n') continue;

      else
      {
      fputc(' ', naji_output);
      ungetc(a, naji_input);
      break;
      }

    }


    }




    else if (a == ' ')
    {

      while (1)
      {

      a = fgetc(naji_input);
      if (a == EOF) break;

      if (a == ' ') continue;

      else
      {
      fputc(' ', naji_output);
      ungetc(a, naji_input);
      break;
      }

    }


    }


    else
    if
    (a != '<'  &&
     a != '>'  &&
     a != '\n' &&
     a != '\r' &&
     a != ' ')
    fputc(a, naji_output);


    }



  


najinclose();
najoutclose();
}


void hilist(char *namein, char *nameout)
{
char buffer[1050];
int i;

najin(namein);
najout(nameout);


fprintf(naji_output, 
"<html>\n\n<head> <title> %s - generated with najitool </title> </head>\n\n<body>\n\n\n\n\n",
 nameout);


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

   fprintf(naji_output, "<img src=\"%s\"><p>\n", buffer);
   }


fprintf(naji_output,
"\n\n\n\n<p>\n\n<hr> This HTML page was generated with <b> najitool </b> <br>\n");

fprintf(naji_output, "From a plain text file with a list of image names <br>\n");

fprintf(naji_output,
"With the command: <i> najitool hilist %s %s </i> <br>\n",
namein, nameout);

fprintf(naji_output,
"You can get <b> najitool </b> the completely free tool at: <br>\n");

fprintf(naji_output,
"<b> <a href=\"http://najitool.sf.net/\"> http://najitool.sf.net/ </a> </b>\n\n<hr>\n\n<p>\n\n");

fprintf(naji_output, "\n\n\n</body>\n\n</html>\n\n");


najinclose();
najoutclose();
}




void downlist(char *namein, char *nameout)
{
char buffer[1050];
int i;

najin(namein);
najout(nameout);


fprintf(naji_output, 
"<html>\n\n<head> <title> %s - generated with najitool </title> </head>\n\n<body>\n\n\n\n\n",
 nameout);


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

   fprintf(naji_output, "<a href=\"%s\">%s</a><p>\n", buffer, buffer);
   }


fprintf(naji_output,
"\n\n\n\n<p>\n\n<hr> This HTML page was generated with <b> najitool </b> <br>\n");

fprintf(naji_output, "From a plain text file with a list of files to download <br>\n");

fprintf(naji_output,
"With the command: <i> najitool downlist %s %s </i> <br>\n",
namein, nameout);

fprintf(naji_output,
"You can get <b> najitool </b> the completely free tool at: <br>\n");

fprintf(naji_output,
"<b> <a href=\"http://najitool.sf.net/\"> http://najitool.sf.net/ </a> </b>\n\n<hr>\n\n<p>\n\n");

fprintf(naji_output, "\n\n\n</body>\n\n</html>\n\n");


najinclose();
najoutclose();
}


void getlinks(char *namein, char *nameout)
{
char temp[12];
int i;

najin(namein);
najout(nameout);

	temp[11] = '\0';

        for (i=0; i<10; i++)
        temp[i] = fgetc(naji_input);

        while ((temp[10] = fgetc(naji_input)) != EOF)
        {
        touppersn(temp, 7);

		if (!strcmp (temp, "<A HREF=\"ht") ||
		    !strcmp (temp, "<A HREF=\"ft") ||
		    !strcmp (temp, "<A HREF=\"ma"))
                    {
			fputc(temp[9], naji_output);
			fputc(temp[10], naji_output);

                        str_move_left(temp, 11);

                        while ( (temp[10] = fgetc(naji_input)) != '\"')
                        {
				fputc(temp[10], naji_output);
                                str_move_left(temp, 11);
			}

			fputc('\n', naji_output);

		}

                str_move_left(temp, 11);

	}


najinclose();
najoutclose();
}
