/* ---------- */
/* najimath.c */
/* ---------- */

/* naji math functions and macros */
/* (it's maths for people in the uk) */

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

/* todo, make a function that says, first, second, third, fourth,
fith, sixth, seventh, eighth, ninth, tenth
and also a more complicated one that says 343rd for example
and a function that says it full, like three hundred and fourty
third, and also a another function that says an integer, or floating
point in normal english and turkish

very useful for redirecting to text to speech programs
i've used some modern text to speech programs that sound
like they are real human.
*/
 

void rand_init(void) { srand(time(NULL)); }

ulong ul_rand_range (ulong start, ulong end)
{ return ( ( (rand() % (end) ) + (start) ) ); }

slong sl_rand_range(slong start, slong end)
{ return ( ( (rand() % (end) ) + (start) ) ); }

uint ui_rand_range(uint start, uint end)
{ return ( ( (rand() % (end) ) + (start) ) ); }

sint si_rand_range(sint start, sint end)
{ return ( ( (rand() % (end) ) + (start) ) ); }

uchar uc_rand_range(uchar start, uchar end)
{ return ( ( (rand() % (end) ) + (start) ) ); }

schar sc_rand_range(schar start, schar end)
{ return ( ( (rand() % (end) ) + (start) ) ); }


/* i couldnt remember what these were called so i made up my own term */
void naji_addim(unsigned long start, unsigned long end, unsigned long addby)
{
int i;

for (i=start; i<=end; i+=addby)
printf("% 4i", i);

printf("\n");
}
/*
void naji_hexaddim(unsigned long start, unsigned long end, unsigned long addby)
{
int i;

for (i=start; i<=end; i+=addby)
printf("% 4X", i);

printf("\n");
}
*/
void addim(int max_times)
{
int i;

for (i=1; i<=max_times; i++)
naji_addim(i, (max_times * i), i);
}
/*
void hexaddim()
{
int i;
int max_times=30;

for (i=1; i<=max_times; i++)
naji_hexaddim(i, (max_times * i), i);
}
*/


/*
Give it a start and end range, and it returns you the total of all the
numbers from start to end added up, for example, if you give a range
1 to 100, the total of all the numbers from 1 to 100 added up is 5050.
*/

int rngtotal(int start, int end)
{
int a=0;
int b=0;

 for (a=start; a<=end; a++)
 b+=a;

return b;
}



void rngtotal_test()
{

 printf("\n\n%i\n\n", rngtotal(1, 100));

}


void naji_calc(void)
{
double a;
double b;
double result;
char *end;

char buffer[100];

int oper;


safegets(buffer, 80);
a = strtod(buffer, &end);

    loop
    {

        printf("\n+ - * /\n");
        safegets(buffer, 80);
    
        if (!strcmp(buffer, "+"))
        {
        oper = '+';
        endloop;
        }
    
        else if (!strcmp(buffer, "-"))
        {
        oper = '-';
        endloop;
        }

        else if (!strcmp(buffer, "*"))
        {
        oper = '*';
        endloop;
        }

        else if (!strcmp(buffer, "/"))
        {
        oper = '/';
        endloop;
        }

    
    }


safegets(buffer, 80);
b = strtod(buffer, &end);


    if (oper == '+')
    result = (a + b);

    else if (oper == '-')
    result = (a - b);
    
    else if (oper == '*')
    result = (a * b);

    else if (oper == '/')
    result = (a / b);


printf("\n%f\n", result);

return;
}



void engnum(void)
{
char *units[10] = {
"zero",
"one",
"two",
"three",
"four",
"five",
"six",
"seven",
"eight",
"nine",
};

char *teens[10] = {
"ten",
"eleven",
"twelve",
"thirteen",
"fourteen",
"fifteen",
"sixteen",
"seventeen",
"eighteen",
"nineteen",
};

char *tens[8] = {
"twenty",
"thirty",
"fourty",
"fifty",
"sixty",
"seventy",
"eighty",
"ninety"
};


int i=0;
int tens_pos=0;
int hundreds_pos=0;
int thousands_pos=0;

/***/
  for (i=1; i<10; i++)
  printf("%s\n", units[i]);

  for (i=0; i<10; i++)
  printf("%s\n", teens[i]);

  for (tens_pos=0; tens_pos<8; tens_pos++)
  {

    printf("%s\n", tens[tens_pos]);

    for (i=1; i<10; i++)
    printf("%s %s\n", tens[tens_pos], units[i]);
  }
/***/


/***/


  for (hundreds_pos=1; hundreds_pos<10; hundreds_pos++)
  {


  printf("%s hundred\n", units[hundreds_pos]);
  

  for (i=1; i<10; i++)
  printf("%s hundred and %s\n", units[hundreds_pos], units[i]);

  for (i=0; i<10; i++)
  printf("%s hundred and %s\n", units[hundreds_pos], teens[i]);

  for (tens_pos=0; tens_pos<8; tens_pos++)
  {

    printf("%s hundred and %s\n", units[hundreds_pos], tens[tens_pos]);

    for (i=1; i<10; i++)
    printf("%s hundred and %s %s\n",
    units[hundreds_pos], tens[tens_pos], units[i]);
  }


 }

/***/







/***/

  for (thousands_pos=1; thousands_pos<10; thousands_pos++)
  {

  printf("%s thousand\n", units[thousands_pos]);

  for (i=1; i<10; i++)
  printf("%s thousand and %s\n", units[thousands_pos], units[i]);

  for (i=0; i<10; i++)
  printf("%s thousand and %s\n", units[thousands_pos], teens[i]);

  for (tens_pos=0; tens_pos<8; tens_pos++)
  {

    printf("%s thousand and %s\n", units[thousands_pos], tens[tens_pos]);

    for (i=1; i<10; i++)
    printf("%s thousand and %s %s\n",
    units[thousands_pos], tens[tens_pos], units[i]);
  }



  for (hundreds_pos=1; hundreds_pos<10; hundreds_pos++)
  {


  printf("%s thousand %s hundred\n",
  units[thousands_pos], units[hundreds_pos]);
  

  for (i=1; i<10; i++)
  printf("%s thousand %s hundred and %s\n",
  units[thousands_pos], units[hundreds_pos], units[i]);

  for (i=0; i<10; i++)
  printf("%s thousand %s hundred and %s\n",
  units[thousands_pos], units[hundreds_pos], teens[i]);

  for (tens_pos=0; tens_pos<8; tens_pos++)
  {

    printf("%s thousand %s hundred and %s\n",
    units[thousands_pos], units[hundreds_pos], tens[tens_pos]);

    for (i=1; i<10; i++)
    printf("%s thousand %s hundred and %s %s\n",
    units[thousands_pos], units[hundreds_pos], tens[tens_pos], units[i]);
  }





 }



}


/***/




}




void turnum(void)
{
char *units[10] = {
"sifir",
"bir",
"iki",
"uc",
"dort",
"bes",
"alti",
"yedi",
"sekiz",
"dokuz",
};

char *teens[10] = {
"on",
"on bir",
"on iki",
"on uc",
"on dort",
"on bes",
"on alti",
"on yedi",
"on sekiz",
"on dokuz",
};

char *tens[8] = {
"yirmi",
"otuz",
"kirk",
"eli",
"altmis",
"yetmis",
"seksen",
"doksan"
};


int i=0;
int tens_pos=0;
int hundreds_pos=0;
int thousands_pos=0;

/***/
  for (i=1; i<10; i++)
  printf("%s\n", units[i]);

  for (i=0; i<10; i++)
  printf("%s\n", teens[i]);

  for (tens_pos=0; tens_pos<8; tens_pos++)
  {

    printf("%s\n", tens[tens_pos]);

    for (i=1; i<10; i++)
    printf("%s %s\n", tens[tens_pos], units[i]);
  }
/***/


/***/


  printf("yuz\n");
  

  for (i=1; i<10; i++)
  printf("yuz %s\n", units[i]);

  for (i=0; i<10; i++)
  printf("yuz %s\n", teens[i]);

  for (tens_pos=0; tens_pos<8; tens_pos++)
  {

    printf("yuz %s\n", tens[tens_pos]);

    for (i=1; i<10; i++)
    printf("yuz %s %s\n",
    tens[tens_pos], units[i]);
  }


  for (hundreds_pos=2; hundreds_pos<10; hundreds_pos++)
  {


  printf("%s yuz\n", units[hundreds_pos]);
  

  for (i=1; i<10; i++)
  printf("%s yuz %s\n", units[hundreds_pos], units[i]);

  for (i=0; i<10; i++)
  printf("%s yuz %s\n", units[hundreds_pos], teens[i]);

  for (tens_pos=0; tens_pos<8; tens_pos++)
  {

    printf("%s yuz %s\n", units[hundreds_pos], tens[tens_pos]);

    for (i=1; i<10; i++)
    printf("%s yuz %s %s\n",
    units[hundreds_pos], tens[tens_pos], units[i]);
  }


 }

/***/







/***/


  printf("bin\n");

  for (i=1; i<10; i++)
  printf("bin %s\n", units[i]);

  for (i=0; i<10; i++)
  printf("bin %s\n", teens[i]);

  for (tens_pos=0; tens_pos<8; tens_pos++)
  {

    printf("bin %s\n", tens[tens_pos]);

    for (i=1; i<10; i++)
    printf("bin %s %s\n",
    tens[tens_pos], units[i]);
  }



  printf("bin yuz\n");

  for (i=1; i<10; i++)
  printf("bin yuz %s\n", units[i]);

  for (i=0; i<10; i++)
  printf("bin yuz %s\n", teens[i]);

  for (tens_pos=0; tens_pos<8; tens_pos++)
  {

    printf("bin yuz %s\n", tens[tens_pos]);

    for (i=1; i<10; i++)
    printf("bin yuz %s %s\n",
    tens[tens_pos], units[i]);
  }





  for (hundreds_pos=2; hundreds_pos<10; hundreds_pos++)
  {


  printf("bin %s yuz\n",
  units[hundreds_pos]);
  

  for (i=1; i<10; i++)
  printf("bin %s yuz %s\n",
  units[hundreds_pos], units[i]);

  for (i=0; i<10; i++)
  printf("bin %s yuz %s\n",
  units[hundreds_pos], teens[i]);

  for (tens_pos=0; tens_pos<8; tens_pos++)
  {

    printf("bin %s yuz %s\n",
    units[hundreds_pos], tens[tens_pos]);

    for (i=1; i<10; i++)
    printf("bin %s yuz %s %s\n",
    units[hundreds_pos], tens[tens_pos], units[i]);
  }





 }




/***/





/***/

  for (thousands_pos=2; thousands_pos<10; thousands_pos++)
  {

  printf("%s bin\n", units[thousands_pos]);

  for (i=1; i<10; i++)
  printf("%s bin %s\n", units[thousands_pos], units[i]);

  for (i=0; i<10; i++)
  printf("%s bin %s\n", units[thousands_pos], teens[i]);

  for (tens_pos=0; tens_pos<8; tens_pos++)
  {

    printf("%s bin %s\n", units[thousands_pos], tens[tens_pos]);

    for (i=1; i<10; i++)
    printf("%s bin %s %s\n",
    units[thousands_pos], tens[tens_pos], units[i]);
  }




  printf("%s bin yuz\n", units[thousands_pos]);
  

  for (i=1; i<10; i++)
  printf("%s bin yuz %s\n",
  units[thousands_pos], units[i]);

  for (i=0; i<10; i++)
  printf("%s bin yuz %s\n",
  units[thousands_pos], teens[i]);

  for (tens_pos=0; tens_pos<8; tens_pos++)
  {

    printf("%s bin yuz %s\n",
    units[thousands_pos], tens[tens_pos]);

    for (i=1; i<10; i++)
    printf("%s bin yuz %s %s\n",
    units[thousands_pos], tens[tens_pos], units[i]);
  }




  for (hundreds_pos=2; hundreds_pos<10; hundreds_pos++)
  {


  printf("%s bin %s yuz\n",
  units[thousands_pos], units[hundreds_pos]);
  

  for (i=1; i<10; i++)
  printf("%s bin %s yuz %s\n",
  units[thousands_pos], units[hundreds_pos], units[i]);

  for (i=0; i<10; i++)
  printf("%s bin %s yuz %s\n",
  units[thousands_pos], units[hundreds_pos], teens[i]);

  for (tens_pos=0; tens_pos<8; tens_pos++)
  {

    printf("%s bin %s yuz %s\n",
    units[thousands_pos], units[hundreds_pos], tens[tens_pos]);

    for (i=1; i<10; i++)
    printf("%s bin %s yuz %s %s\n",
    units[thousands_pos], units[hundreds_pos], tens[tens_pos], units[i]);
  }





 }



}


/***/





}





void gplus(int start, int end)
{
int x;
int y;

  if (start > end)
  {
  fprintf(stderr, "ERROR: start value cannot be greater than end value.\n");
  return;
  }

for (x=start; x<=end; x++)
for (y=start; y<=end; y++)
printf("%d + %d = %d\n", x, y, (x + y));
}



void gminus(int start, int end)
{
int x;
int y;


  if (start > end)
  {
  fprintf(stderr, "ERROR: start value cannot be greater than end value.\n");
  return;
  }

for (x=start; x<=end; x++)
for (y=start; y<=end; y++)
printf("%d - %d = %d\n", x, y, (x - y));
}



void gtimes(int start, int end)
{
int x;
int y;

  if (start > end)
  {
  fprintf(stderr, "ERROR: start value cannot be greater than end value.\n");
  return;
  }

for (x=start; x<=end; x++)
for (y=start; y<=end; y++)
printf("%d x %d = %d\n", x, y, (x * y));
}



void gdivide(float start, float end)
{
float x;
float y;


  if ( (start == 0) ||  (end == 0) )
  {
  fprintf(stderr, "ERROR: cannot divide by zero.\n");
  return;
  }


  if (start > end)
  {
  fprintf(stderr, "ERROR: start value cannot be greater than end value.\n");
  return;
  }



for (x=start; x<=end; x++)
for (y=start; y<=end; y++)
printf("%f / %f = %f\n", x, y, (x / y));
}


