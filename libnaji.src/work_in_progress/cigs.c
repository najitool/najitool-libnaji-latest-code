#include <stdio.h>
#include <stdlib.h>

int cigarettes;
int hour;

int days_left_to_live;

void go_super_market_for_cigs()
{
cigarettes +=40;
printf("Bought 40 cigarettess at super market at %02i:00 hours\n", hour);
}

void go_corner_shop_for_cigs()
{
cigarettes +=40;
printf("Bought 40 cigarettess at corner shop at %02i:00 hours\n", hour);
}

void go_petrol_station_for_cigs()
{
cigarettes +=40;
printf("Bought 40 cigarettess at petrol station at %02i:00 hours\n", hour);
}

void go_shop_for_cigs()
{
if (hour > 7 && hour < 22)
go_super_market_for_cigs();

else if (hour > 11 && hour < 23)
go_corner_shop_for_cigs();

else
go_petrol_station_for_cigs();
}

void man_wakeup()
{

if (cigarettes == 0)
go_shop_for_cigs();
}

int main()
{
int i;
int j;
unsigned long lifetimecigs=0;
days_left_to_live=356*30;

srand(time(0));

cigarettes = 0;

for (i=0; i<days_left_to_live; i++)
{

printf("Day number: %i\n", i);

hour = rand() % 24;

man_wakeup();

for (j=0; j<cigarettes; j++)
{
printf("Smoking cigarette number %i\n", j);
lifetimecigs++;
//fgetc(stdin);
}

cigarettes=0;

printf("You fell asleep. Cigarettes smoked so far in lifetime %lu\n", lifetimecigs);

}
printf("You died, rip naji :'(\n");

return 0;
}
