/* ---------- */
/* najitime.c */
/* ---------- */

/* naji date and time functions */

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


/* Begin: System Date/Time Variables */

time_t      time_value;
struct tm   *date_time;
char   naji_buffer[512];

/* End: System Date/Time Variables */








/* Begin: English Date/Time Variables */


char *days[7] = {
    "Sunday",
    "Monday",
    "Tuseday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
};


char *months[12] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};


/* End: English Date/Time Variables */








/* Begin: Turkish Date/Time Variables */


     /* days */
char *gunler[7] = {
    "Pazar",
    "Pazartesi",
    "Sali",
    "Carsamba",
    "Persembe",
    "Cuma",
    "Cumartesi"
};

     /* months */
char *aylar[12] = {
    "Ocak",
    "Subat",
    "Mart",
    "Nisan",
    "Mayis",
    "Haziran",
    "Temmuz",
    "Agustos",
    "Eylul",
    "Ekim",
    "Kasim",
    "Aralik"
};


/* End: Turkish Date/Time Variables */








/* Begin: System Date/Time Functions */


void get_datetime()
{
time(&time_value);
date_time = localtime(&time_value);
}


char * s_systemdt()
{
get_datetime();

sprintf(naji_buffer, "%s", asctime(date_time));

return naji_buffer;
}


void systemdt()
{
printf("\n\nCurrent System Date and Time: %s\n\n", s_systemdt());
}


/* End: System Date/Time Functions */


/* Begin: English Date/Time Functions */


void telltime()
{
get_datetime();

 printf("%02i", date_time->tm_hour);
  putchar(':');
 printf("%02i", date_time->tm_min);
  putchar(':');
 printf("%02i", date_time->tm_sec);

}


char * s_today()
{
int i;

  get_datetime();

  for (i=0; i<=6; i++)
  if (date_time->tm_wday == i)
  return (days[i]);

return ("(DAY ERROR)");
}


char * s_month()
{
int i;

  get_datetime();

  for (i=0; i<=11; i++)
  if (date_time->tm_mon == i)
  return (months[i]);

return ("(MONTH ERROR)");
}


void today()
{
    printf("%s", s_today());
}


void month()
{
    printf("%s", s_month());
}


char * s_dayofmon()
{

  get_datetime();

  sprintf(naji_buffer, "%i", date_time->tm_mday);

return naji_buffer;
}


void dayofmon()
{
printf("%s", s_dayofmon());
}


char * s_year()
{

  get_datetime();

  sprintf(naji_buffer, "%i", ( (1900) + (date_time->tm_year) ) );

return naji_buffer;
}


void year()
{
printf("%s", s_year());
}


void datetime(void)
{
        putchar('\n');
        putchar('\n');

        telltime();  putchar(' ');
        today();     putchar(' ');
        dayofmon();  putchar(' ');
        month();     putchar(' ');
        year();

        putchar('\n');
        putchar('\n');

}


/* End: English Date/Time Functions */















/* Begin: Turkish Date/Time Functions */


void saat()
{
get_datetime();

printf("%02i", date_time->tm_hour);  /* saat   */

putchar(':');

printf("%02i", date_time->tm_min);   /* dakika */

putchar(':');

printf("%02i", date_time->tm_sec);   /* saniye */

}


char * s_bugun()
{
int i;

  get_datetime();

  for (i=0; i<=6; i++)
  if (date_time->tm_wday == i)
  return (gunler[i]);

return ("(GUN HATA)");
}


char * s_ay()
{
int i;

  get_datetime();

  for (i=0; i<=11; i++)
  if (date_time->tm_mon == i)
  return (aylar[i]);

return ("(AY HATA)");
}


void bugun()
{
    printf("%s", s_bugun());
}


void ay()
{
    printf("%s", s_ay());
}


char * s_ayinkaci()
{

  get_datetime();

  sprintf(naji_buffer, "%i", date_time->tm_mday);

return naji_buffer;
}


void ayinkaci()
{
printf("%s", s_ayinkaci());
}


char * s_yil()
{

  get_datetime();

  sprintf(naji_buffer, "%i", ( (1900) + (date_time->tm_year) ) );

return naji_buffer;
}


void yil()
{
printf("%s", s_yil());
}


void saatarih(void)
{
        putchar('\n');
        putchar('\n');

        saat();      putchar(' ');
        bugun();     putchar(' ');
        ayinkaci();  putchar(' ');
        ay();        putchar(' ');
        yil();

        putchar('\n');
        putchar('\n');

}


/* End: Turkish Date/Time Functions */
