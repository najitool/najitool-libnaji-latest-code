/* ---------- */
/* najhtmdb.c */
/* ---------- */

/* naji html database functions */

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

char buffer_html[306];

FILE *naji_html_db_file;

void add_entry_html(char *entry)
{
    printf(entry);
    safegets(buffer_html, 300);
    
    fprintf(naji_html_db_file, "<b>%s</b>%s<br>\n", entry, buffer_html);
    fflush(naji_html_db_file);
return;
}

void add_entry_html_email(char *entry)
{
    printf(entry);
    safegets(buffer_html, 300);
    
    fprintf(naji_html_db_file, "<b>%s</b><a href=\"mailto:%s\">%s</a></br>\n",
    entry, buffer_html, buffer_html);
    fflush(naji_html_db_file);
return;
}

void add_entry_html_link(char *entry)
{
    printf(entry);
    safegets(buffer_html, 300);
    
    fprintf(naji_html_db_file, "<b>%s</b><a href=\"%s\">%s</a><br>\n",
    entry, buffer_html, buffer_html);
    fflush(naji_html_db_file);
return;
}


void naji_html_database(void)
{

    printf("\n\ntip: you should name it something like book.htm\n");
    printf("so you can view it with your web browser.\n");

    printf("enter a file name, if the file exists the data\n");
    printf("will be added to the end of the file: ");

    safegets(buffer_html, 300);

    naji_html_db_file = fopen(buffer_html, "ab");

    if (naji_html_db_file == NULL)
    {
    fprintf(stderr, "\n\nError opening file %s", buffer_html);
    perror(" ");
    fprintf(stderr, "\n\n");
    exit(1);
    }


    loop
    {

    printf("\n\ntip: type N/A if it's not available.\n\n");

    fprintf(naji_html_db_file, "<hr>\n");

    add_entry_html("full name: ");
    add_entry_html("date of birth: ");
    add_entry_html("marital status: ");
    add_entry_html("height: ");
    add_entry_html("weight: ");
    add_entry_html("build: ");
    add_entry_html("hair color: ");
    add_entry_html("eye color: ");
    add_entry_html("favourite food: ");
    add_entry_html("favourite drink: ");
    add_entry_html("home number: ");
    add_entry_html("work number: ");
    add_entry_html("fax number: ");
    add_entry_html("cell number: ");
    add_entry_html("home address: ");
    add_entry_html("work address: ");
    add_entry_html_email("e-mail: ");
    add_entry_html_link("website: ");
    add_entry_html("mother's full name: ");
    add_entry_html("mother's date of birth: ");
    add_entry_html("father's full name: ");
    add_entry_html("father's date of birth: ");
    add_entry_html("number of sisters: ");
    add_entry_html("number of brothers: ");

/*    fprintf(naji_html_db_file, "<br>\n"); */
    
    printf("\n\ndo you want to enter more people?\n");
    printf("type no to quit or anything else to continue: \n");
    safegets(buffer_html, 300);

    if (strcmp(buffer_html, "no") == 0)
    endloop;
    }

fflush(naji_html_db_file);
fclose(naji_html_db_file);
}

