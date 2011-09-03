/* ---------- */
/* naji_uni.c */
/* ---------- */

/* naji unicode functions */

/* this  .c  file is a part */
/* of libnaji version 0.6.4 */

/* libnaji is based on   */
/* the original najitool */

/* both najitool and libnaji */
/* are public domain and are */
/* made by the same author   */
/* please read license.txt   */

/* made by NECDET COKYAZICI  */

#include "libnaji.h"

char fnamebuf[100];

void naji_unicode_html_header(int n)
{
int i;

fprintf(naji_output,"<html><head><title>Unicode Symbols Page %i - generated with najitool, courtesy of NECDET COKYAZICI</title></head><body>", n);
fprintf(naji_output,"<hr>Courtesy of NECDET COKYAZICI, the programmer of najitool<br>");
fprintf(naji_output,"<p> These HTML pages with every possible Unicode letter/symbol <br> were generated with <b> najitool </b> ");
fprintf(naji_output," with the command: <p> <i> najitool unihtml </i> <p>");

fprintf(naji_output,"You can get <b> najitool </b> the completely free tool at: <br> ");
fprintf(naji_output,"<b> <a href=\"http://najitool.sf.net/\"> http://najitool.sf.net/ </a></b><hr><p>");

fprintf(naji_output,"<p>The numbers near the Unicode letter/symbol <br>");
fprintf(naji_output, "are here for you to use in your HTML pages. <br>");



fprintf(naji_output,"Just open your HTML page with a normal text editor, <br>");
fprintf(naji_output,"like vi or notepad, and put &#38;&#35;unicode number here&#59 <br>");
fprintf(naji_output," for example &#38;&#35;1586&#59 which appears as &#1587; an Arabic letter. <p><hr>");


    fprintf(naji_output, "Generated Pages: ");

    for (i=1; i<=61; i++)
    {
    if (i == 10) fprintf(naji_output, "<br>");
    if (i == 30) fprintf(naji_output, "<br>");
    if (i == 50) fprintf(naji_output, "<br>");
    fprintf(naji_output, "<a href=\"ucode%02i.htm\">%i</a> ", i, i);
    }

fprintf(naji_output, "<p><hr>");

}


void naji_unicode_html_end(void)
{
int i;

fprintf(naji_output, "<p><hr>");

    fprintf(naji_output, "Generated Pages: ");

    for (i=1; i<=61; i++)
    {
    if (i == 10) fprintf(naji_output, "<br>");
    if (i == 30) fprintf(naji_output, "<br>");
    if (i == 50) fprintf(naji_output, "<br>");
    fprintf(naji_output, "<a href=\"ucode%02i.htm\">%i</a> ", i, i);
    }

fprintf(naji_output, "<p><hr>");
fprintf(naji_output, "</body></html>");


}


/* mass deleter of the files it generates */
/* please be careful when using it and */
/* please dont abuse this system */
void naji_del_gen_unicode_html_pages(void)
{
int i;
int delete_errors=0;

    for (i=1; i<=99; i++)
    {

        sprintf(fnamebuf, "ucode%02i.htm", i);




        if(remove(fnamebuf) < 0)
        {
        fprintf(stderr, "Error deleting file %s", fnamebuf);
        perror(" ");
        delete_errors++;
        }
        else
        printf("Deleted file %s\n", fnamebuf);

    }

exit(delete_errors);
}




void naji_gen_unicode_html_pages(void)
{
int i = 0;
int unicode_max = 0xFFFF;  /* max is 65535 - 0xFFFF */
int unicode_min = 0;
int unicode_last = 60000;

int addby=1000;

int x = unicode_min;
int y = addby;

int n = 1;


    /* todo: arab2uni */

    while(1)
    {

    if (y > unicode_last) break;

    sprintf(fnamebuf, "ucode%02i.htm", n);
    najout(fnamebuf);


    naji_unicode_html_header(n);


    for (i=x; i<y; i++)
    fprintf(naji_output, "&#%i; %i<p>", i, i);

    naji_unicode_html_end();
    najoutclose();
    n++;
    
    x+=addby;

    y+=addby;
    }

    sprintf(fnamebuf, "ucode%02i.htm", n);
    najout(fnamebuf);

    naji_unicode_html_header(n);

    for (i=x; i<=unicode_max; i++)
    fprintf(naji_output, "&#%i; %i<p>", i, i);

    naji_unicode_html_end();
    najoutclose();

}

