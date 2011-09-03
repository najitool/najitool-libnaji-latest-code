/* --------- */
/* naji_db.c */
/* --------- */

/* naji database functions */

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

char buffer[306];

FILE *naji_db_file;

void add_entry(char *entry)
{
    printf(entry);
    safegets(buffer, 300);
    
    fprintf(naji_db_file, "%s%s\n", entry, buffer);
    fflush(naji_db_file);
return;
}



void naji_database(void)
{

    printf("\n\ntip: you should name it something like book.txt\n");
    printf("so you can view and edit it with notepad.\n\n");

    printf("enter a file name, if the file exists the data\n");
    printf("will be added to the end of the file: ");

    safegets(buffer, 300);

    naji_db_file = fopen(buffer, "ab");

    if (naji_db_file == NULL)
    {
    fprintf(stderr, "\n\nError opening file %s", buffer);
    perror(" ");
    fprintf(stderr, "\n\n");
    exit(1);
    }


    loop
    {

    printf("\n\ntip: type N/A if it's not available.\n\n");

    add_entry("full name: ");
    add_entry("date of birth: ");
    add_entry("marital status: ");
    add_entry("height: ");
    add_entry("weight: ");
    add_entry("build: ");
    add_entry("hair color: ");
    add_entry("eye color: ");
    add_entry("favourite food: ");
    add_entry("favourite drink: ");
    add_entry("home number: ");
    add_entry("work number: ");
    add_entry("fax number: ");
    add_entry("cell number: ");
    add_entry("home address: ");
    add_entry("work address: ");
    add_entry("e-mail: ");
    add_entry("website: ");
    add_entry("mother's full name: ");
    add_entry("mother's date of birth: ");
    add_entry("father's full name: ");
    add_entry("father's date of birth: ");
    add_entry("number of sisters: ");
    add_entry("number of brothers: ");

    fputc('\n', naji_db_file);
    
    printf("\n\ndo you want to enter more people?\n");
    printf("type no to quit or anything else to continue: \n");
    safegets(buffer, 300);

    if (strcmp(buffer, "no") == 0)
    endloop;
    }

fflush(naji_db_file);
fclose(naji_db_file);
}

