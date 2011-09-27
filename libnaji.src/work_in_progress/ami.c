#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

char *knot[2] = {
" ",
"NOT"
};

char *mathoper[16] = {
" ",
"EQUALS",
"LESS THAN",
"GREATER THAN",
"LESS THAN OR EQUALS",
"GREATER THAN OR EQUALS",
"PLUS",
"MINUS",
"TIMES",
"DIVIDED BY",
"THE POWER OF",
"PLUS EQUALS",
"MINUS EQUALS",
"TIMES EQUALS",
"DIVIDED EQUALS",
"POWER OF EQUALS"
};

char *andor[2] = {
"AND",
"OR"
};

unsigned long mo=0;
unsigned long i=0;
unsigned long o=0;
unsigned long noto=0;
while (1)
{


for (mo=0; mo<16; mo++)
for (o=0; o<2; o++)
for (noto=0; noto<2; noto++)
{
printf("AM I %s %lu %s AM I %s %lu?\n", mathoper[mo],i,andor[o],mathoper[mo],i+1);
printf("AM I %s %s %lu %s AM I %s %lu?\n", knot[noto],mathoper[mo],i,andor[o],mathoper[mo],i+1);
printf("AM I %s %lu %s AM I %s %s %lu?\n", mathoper[mo],i,andor[o],knot[noto],mathoper[mo],i+1);
printf("AM I %s %s %lu %s AM I %s %s %lu?\n", knot[noto],mathoper[mo],i,andor[o],knot[noto],mathoper[mo],i+1);
fgetc(stdin);
i++;
}

}

return 0;
}
