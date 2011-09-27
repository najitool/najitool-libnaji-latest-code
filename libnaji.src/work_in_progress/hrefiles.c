#include "../najio.c"

void hrefiles(void)
{
char temp[4096];
char buffer[4096];

char *p = NULL;
int i = 0;

najin("index.html");


while (1)
{


if (feof(naji_input))
break;

najifgets(temp, 4095, naji_input);

p = strstr(temp, "<a href=\"");


if (p != NULL)
{

i = 0;
p += 9;

while (1)
{

if ( (*p == '\0') || (*p == '\"') )
{
buffer[i] = '\0';
printf("Making empty file: \"%s\"\n", buffer);
najout(buffer);
najoutclose();
break;
}

buffer[i] = *p;
i++;
p++;

}


}

}


najinclose();
}