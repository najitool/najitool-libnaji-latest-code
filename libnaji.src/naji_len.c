/* ---------- */
/* naji_len.c */
/* ---------- */

/* naji popular length converters */

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


char buffer[1024];
char *end;

double meters=0;
double yards=0;
double feet=0;
double inches=0;
double cm=0;
double mm=0;
double km=0;
double miles=0;





void miles_to_mm(void)
{

printf("enter the amount of miles: ");
safegets(buffer, 1000);

miles = strtod(buffer, &end);

mm = miles * 1609344;

printf("\n\n%f miles is %f mm\n\n", miles, mm);
}



void mm_to_miles(void)
{

printf("enter the amount of mm: ");
safegets(buffer, 1000);

mm = strtod(buffer, &end);

if (mm == 0)
miles = 0;

else
miles = mm / 1609344;

printf("\n\n%f mm is %f miles\n\n", mm, miles);
}







void miles_to_cm(void)
{

printf("enter the amount of miles: ");
safegets(buffer, 1000);

miles = strtod(buffer, &end);

cm = miles * 160934.4;

printf("\n\n%f miles is %f cm\n\n", miles, cm);
}



void cm_to_miles(void)
{

printf("enter the amount of cm: ");
safegets(buffer, 1000);

cm = strtod(buffer, &end);

if (cm == 0)
miles = 0;

else
miles = cm / 160934.4;

printf("\n\n%f cm is %f miles\n\n", cm, miles);
}







void miles_to_inches(void)
{

printf("enter the amount of miles: ");
safegets(buffer, 1000);

miles = strtod(buffer, &end);

inches = miles * 63360;

printf("\n\n%f miles is %f inches\n\n", miles, inches);
}




void inches_to_miles(void)
{

printf("enter the amount of inches: ");
safegets(buffer, 1000);

inches = strtod(buffer, &end);

if (inches == 0)
miles = 0;

else
miles = inches / 63360;

printf("\n\n%f inches is %f miles\n\n", inches, miles);
}








void miles_to_feet(void)
{

printf("enter the amount of miles: ");
safegets(buffer, 1000);

miles = strtod(buffer, &end);

feet = miles * 5280;

printf("\n\n%f miles is %f feet\n\n", miles, feet);
}



void feet_to_miles(void)
{

printf("enter the amount of feet: ");
safegets(buffer, 1000);

feet = strtod(buffer, &end);

if (feet == 0)
miles = 0;

else
miles = feet / 5280;

printf("\n\n%f feet is %f miles\n\n", feet, miles);
}








void miles_to_yards(void)
{

printf("enter the amount of miles: ");
safegets(buffer, 1000);

miles = strtod(buffer, &end);

yards = miles * 1760;

printf("\n\n%f miles is %f yards\n\n", miles, yards);
}



void yards_to_miles(void)
{

printf("enter the amount of yards: ");
safegets(buffer, 1000);

yards = strtod(buffer, &end);

if (yards == 0)
miles = 0;

else
miles = yards / 1760;

printf("\n\n%f yards is %f miles\n\n", yards, miles);
}









void miles_to_meters(void)
{

printf("enter the amount of miles: ");
safegets(buffer, 1000);

miles = strtod(buffer, &end);

meters = miles * 1609.344;

printf("\n\n%f miles is %f meters\n\n", miles, meters);
}



void meters_to_miles(void)
{

printf("enter the amount of meters: ");
safegets(buffer, 1000);

meters = strtod(buffer, &end);

if (meters == 0)
miles = 0;

else
miles = meters / 1609.344;

printf("\n\n%f meters is %f miles\n\n", meters, miles);
}








void miles_to_km(void)
{

printf("enter the amount of miles: ");
safegets(buffer, 1000);

miles = strtod(buffer, &end);

km = miles * 1.609344;

printf("\n\n%f miles is %f km\n\n", miles, km);
}



void km_to_miles(void)
{

printf("enter the amount of km: ");
safegets(buffer, 1000);

km = strtod(buffer, &end);

if (km == 0)
miles = 0;

else
miles = km / 1.609344;

printf("\n\n%f km is %f miles\n\n", km, miles);
}






void km_to_yards(void)
{

printf("enter the amount of km: ");
safegets(buffer, 1000);

km = strtod(buffer, &end);

yards = km * 1093.613298;

printf("\n\n%f km is %f yards\n\n", km, yards);
}




void yards_to_km(void)
{

printf("enter the amount of yards: ");
safegets(buffer, 1000);

yards = strtod(buffer, &end);

if (yards == 0)
km = 0;

else
km = yards / 1093.613298;

printf("\n\n%f yards is %f km\n\n", yards, km);
}







void km_to_feet(void)
{

printf("enter the amount of km: ");
safegets(buffer, 1000);

km = strtod(buffer, &end);

feet = km * 3280.839895;

printf("\n\n%f km is %f feet\n\n", km, feet);
}




void feet_to_km(void)
{

printf("enter the amount of feet: ");
safegets(buffer, 1000);

feet = strtod(buffer, &end);

if (feet == 0)
km = 0;

else
km = feet / 3280.839895;

printf("\n\n%f feet is %f km\n\n", feet, km);
}







void km_to_inches(void)
{

printf("enter the amount of km: ");
safegets(buffer, 1000);

km = strtod(buffer, &end);

inches = km * 39370.07874;

printf("\n\n%f km is %f inches\n\n", km, inches);
}



void inches_to_km(void)
{

printf("enter the amount of inches: ");
safegets(buffer, 1000);

inches = strtod(buffer, &end);

if (inches == 0)
km = 0;

else
km = inches / 39370.07874;

printf("\n\n%f inches is %f km\n\n", inches, km);
}






void km_to_meters(void)
{

printf("enter the amount of km: ");
safegets(buffer, 1000);

km = strtod(buffer, &end);

meters = km * 1000;

printf("\n\n%f km is %f meters\n\n", km, meters);
}



void meters_to_km(void)
{

printf("enter the amount of meters: ");
safegets(buffer, 1000);

meters = strtod(buffer, &end);

if (meters == 0)
km = 0;

else
km = meters / 1000;

printf("\n\n%f meters is %f km\n\n", meters, km);
}






void km_to_cm(void)
{

printf("enter the amount of km: ");
safegets(buffer, 1000);

km = strtod(buffer, &end);

cm = km * 100000;

printf("\n\n%f km is %f cm\n\n", km, cm);
}



void cm_to_km(void)
{

printf("enter the amount of cm: ");
safegets(buffer, 1000);

cm = strtod(buffer, &end);

if (cm == 0)
km = 0;

else
km = cm / 100000;

printf("\n\n%f cm is %f km\n\n", cm, km);
}



void km_to_mm(void)
{

printf("enter the amount of km: ");
safegets(buffer, 1000);

km = strtod(buffer, &end);

mm = km * 1000000;

printf("\n\n%f km is %f mm\n\n", km, mm);
}



void mm_to_km(void)
{

printf("enter the amount of mm: ");
safegets(buffer, 1000);

mm = strtod(buffer, &end);

if (mm == 0)
km = 0;

else
km = mm / 1000000;

printf("\n\n%f mm is %f km\n\n", mm, km);
}




void yards_to_meters(void)
{

printf("enter the amount of yards: ");
safegets(buffer, 1000);

yards = strtod(buffer, &end);

meters = yards * 0.9144;

printf("\n\n%f yards is %f meters\n\n", yards, meters);
}


void meters_to_yards(void)
{

printf("enter the amount of meters: ");
safegets(buffer, 1000);

meters = strtod(buffer, &end);

if (meters == 0)
yards = 0;

else
yards = meters / 0.9144;

printf("\n\n%f meters is %f yards\n\n", meters, yards);
}





void yards_to_feet(void)
{

printf("enter the amount of yards: ");
safegets(buffer, 1000);

yards = strtod(buffer, &end);

feet = yards * 3;

printf("\n\n%f yards is %f feet\n\n", yards, feet);
}



void feet_to_yards(void)
{

printf("enter the amount of feet: ");
safegets(buffer, 1000);

feet = strtod(buffer, &end);

if (feet == 0)
yards = 0;

else
yards = feet / 3;

printf("\n\n%f feet is %f yards\n\n", feet, yards);
}






void yards_to_inches(void)
{

printf("enter the amount of yards: ");
safegets(buffer, 1000);

yards = strtod(buffer, &end);

inches = yards * 36;

printf("\n\n%f yards is %f inches\n\n", yards, inches);
}



void inches_to_yards(void)
{

printf("enter the amount of inches: ");
safegets(buffer, 1000);

inches = strtod(buffer, &end);

if (inches == 0)
yards = 0;

else
yards = inches / 36;

printf("\n\n%f inches is %f yards\n\n", inches, yards);
}





void yards_to_cm(void)
{

printf("enter the amount of yards: ");
safegets(buffer, 1000);

yards = strtod(buffer, &end);

cm = yards * 91.44;

printf("\n\n%f yards is %f cm\n\n", yards, cm);
}



void cm_to_yards(void)
{

printf("enter the amount of cm: ");
safegets(buffer, 1000);

cm = strtod(buffer, &end);

if (cm == 0)
yards = 0;

else
yards = cm / 91.44;

printf("\n\n%f cm is %f yards\n\n", cm, yards);
}






void yards_to_mm(void)
{

printf("enter the amount of yards: ");
safegets(buffer, 1000);

yards = strtod(buffer, &end);

mm = yards * 914.4;

printf("\n\n%f yards is %f mm\n\n", yards, mm);
}



void mm_to_yards(void)
{

printf("enter the amount of mm: ");
safegets(buffer, 1000);

mm = strtod(buffer, &end);

if (mm == 0)
yards = 0;

else
yards = mm / 914.4;

printf("\n\n%f mm is %f yards\n\n", mm, yards);
}





void meters_to_mm(void)
{

printf("enter the amount of meters: ");
safegets(buffer, 1000);

meters = strtod(buffer, &end);

mm = meters * 1000;

printf("\n\n%f meters is %f mm\n\n", meters, mm);
}



void mm_to_meters(void)
{

printf("enter the amount of mm: ");
safegets(buffer, 1000);

mm = strtod(buffer, &end);

if (mm == 0)
meters = 0;

else
meters = mm / 1000;

printf("\n\n%f mm is %f meters\n\n", mm, meters);
}



void feet_to_mm(void)
{

printf("enter the amount of feet: ");
safegets(buffer, 1000);

feet = strtod(buffer, &end);

mm = feet * 304.8;

printf("\n\n%f feet is %f mm\n\n", feet, mm);
}




void mm_to_feet(void)
{

printf("enter the amount of mm: ");
safegets(buffer, 1000);

mm = strtod(buffer, &end);

if (mm == 0)
feet = 0;

else
feet = mm / 304.8;

printf("\n\n%f mm is %f feet\n\n", mm, feet);
}





void inches_to_mm(void)
{

printf("enter the amount of inches: ");
safegets(buffer, 1000);

inches = strtod(buffer, &end);

mm = inches * 25.4;

printf("\n\n%f inches is %f mm\n\n", inches, mm);
}



void mm_to_inches(void)
{

printf("enter the amount of mm: ");
safegets(buffer, 1000);

mm = strtod(buffer, &end);

if (mm == 0)
inches = 0;

else
inches = mm / 25.4;

printf("\n\n%f mm is %f inches\n\n", mm, inches);
}



void cm_to_mm(void)
{

printf("enter the amount of cm: ");
safegets(buffer, 1000);

cm = strtod(buffer, &end);

mm = cm * 10;

printf("\n\n%f cm is %f mm\n\n", cm, mm);
}


void mm_to_cm(void)
{

printf("enter the amount of mm: ");
safegets(buffer, 1000);

mm = strtod(buffer, &end);

if (mm == 0)
cm = 0;

else
cm = mm / 10;

printf("\n\n%f mm is %f cm\n\n", mm, cm);
}







void inches_to_meters(void)
{

printf("enter the amount of inches: ");
safegets(buffer, 1000);

inches = strtod(buffer, &end);

if (inches == 0)
meters = 0;

else
meters = inches / 39.370079;

printf("\n\n%f inches is %f meters\n\n", inches, meters);
}



void meters_to_inches(void)
{

printf("enter the amount of meters: ");
safegets(buffer, 1000);

meters = strtod(buffer, &end);

inches = meters * 39.370079;

printf("\n\n%f meters is %f inches\n\n", meters, inches);
}



void feet_to_meters(void)
{

printf("enter the amount of feet: ");
safegets(buffer, 1000);

feet = strtod(buffer, &end);

if (feet == 0)
meters = 0;

else
meters = feet / 3.28084;

printf("\n\n%f feet is %f meters\n\n", feet, meters);
}


void meters_to_feet(void)
{

printf("enter the amount of meters: ");
safegets(buffer, 1000);

meters = strtod(buffer, &end);

feet = meters * 3.28084;

printf("\n\n%f meters is %f feet\n\n", meters, feet);
}





void meters_to_cm(void)
{

printf("enter the amount of meters: ");
safegets(buffer, 1000);

meters = strtod(buffer, &end);

cm = meters * 100;

printf("\n\n%f meters is %f cm\n\n", meters, cm);
}


void cm_to_meters(void)
{

printf("enter the amount of cm: ");
safegets(buffer, 1000);

cm = strtod(buffer, &end);

if (cm == 0)
meters = 0;

else
meters = cm / 100;

printf("\n\n%f cm is %f meters\n\n", cm, meters);
}





void feet_to_inches(void)
{

printf("enter the amount of feet: ");
safegets(buffer, 1000);

feet = strtod(buffer, &end);

inches = feet * 12;

printf("\n\n%f feet is %f inches\n\n", feet, inches);
}


void inches_to_feet(void)
{

printf("enter the amount of inches: ");
safegets(buffer, 1000);

inches = strtod(buffer, &end);

if (inches == 0)
feet = 0;

else
feet = inches / 12;

printf("\n\n%f inches is %f feet\n\n", inches, feet);
}






void feet_to_cm(void)
{

printf("enter the amount of feet: ");
safegets(buffer, 1000);

feet = strtod(buffer, &end);

cm = feet * 30.48;

printf("\n\n%f feet is %f cm\n\n", feet, cm);
}



void cm_to_feet(void)
{

printf("enter the amount of cm: ");
safegets(buffer, 1000);

cm = strtod(buffer, &end);

if (cm == 0)
feet = 0;

else
feet = cm / 30.48;

printf("\n\n%f cm is %f feet\n\n", cm, feet);
}







void inches_to_cm(void)
{

printf("enter the amount of inches: ");
safegets(buffer, 1000);

inches = strtod(buffer, &end);

cm = inches * 2.54;

printf("\n\n%f inches is %f cm\n\n", inches, cm);
}



void cm_to_inches(void)
{

printf("enter the amount of cm: ");
safegets(buffer, 1000);

cm = strtod(buffer, &end);

if (cm == 0)
inches = 0;

else
inches = cm / 2.54;

printf("\n\n%f cm is %f inches\n\n", cm, inches);
}






void length(void)
{
char choice[10];


  loop
  {

  printf("Please choose:\n");
  printf("     0. exit program        19. meters to mm       38. inches to km\n");
  printf("     1. inches to cm        20. mm to meters       39. km to feet\n");
  printf("     2. cm to inches        21. yards to mm        40. feet to km\n");
  printf("     3. feet to cm          22. mm to yards        41. km to yards\n");
  printf("     4. cm to feet          23. yards to cm        42. yards to km\n");
  printf("     5. feet to inches      24. cm to yards        43. miles to km\n");
  printf("     6. inches to feet      25. yards to inches    44. km to miles\n");
  printf("     7. meters to cm        26. inches to yards    45. miles to meters\n");
  printf("     8. cm to meters        27. yards to feet      46. meters to miles\n");
  printf("     9. meters to feet      28. feet to yards      47. miles to yards\n");
  printf("    10. feet to meters      29. yards to meters    48. yards to miles\n");
  printf("    11. meters to inches    30. meters to yards    49. miles to feet\n");
  printf("    12. inches to meters    31. km to mm           50. feet to miles\n");
  printf("    13. cm to mm            32. mm to km           51. miles to inches\n");
  printf("    14. mm to cm            33. km to cm           52. inches to miles\n");
  printf("    15. inches to mm        34. cm to km           53. miles to cm\n");
  printf("    16. mm to inches        35. km to meters       54. cm to miles\n");
  printf("    17. feet to mm          36. meters to km       55. miles to mm\n");
  printf("    18. mm to feet          37. km to inches       56. mm to miles\n");


  safegets(choice, 5);

  if (!strcmp(choice, "0"))  exit(0);
  if (!strcmp(choice, "1"))  inches_to_cm();
  if (!strcmp(choice, "2"))  cm_to_inches();
  if (!strcmp(choice, "3"))  feet_to_cm();
  if (!strcmp(choice, "4"))  cm_to_feet();
  if (!strcmp(choice, "5"))  feet_to_inches();
  if (!strcmp(choice, "6"))  inches_to_feet();
  if (!strcmp(choice, "7"))  meters_to_cm();
  if (!strcmp(choice, "8"))  cm_to_meters();
  if (!strcmp(choice, "9"))  meters_to_feet();
  if (!strcmp(choice, "10")) feet_to_meters();
  if (!strcmp(choice, "11")) meters_to_inches();
  if (!strcmp(choice, "12")) inches_to_meters();
  if (!strcmp(choice, "13")) cm_to_mm();
  if (!strcmp(choice, "14")) mm_to_cm();
  if (!strcmp(choice, "15")) inches_to_mm();
  if (!strcmp(choice, "16")) mm_to_inches();
  if (!strcmp(choice, "17")) feet_to_mm();
  if (!strcmp(choice, "18")) mm_to_feet();
  if (!strcmp(choice, "19")) meters_to_mm();
  if (!strcmp(choice, "20")) mm_to_meters();
  if (!strcmp(choice, "21")) yards_to_mm();
  if (!strcmp(choice, "22")) mm_to_yards();
  if (!strcmp(choice, "23")) yards_to_cm();
  if (!strcmp(choice, "24")) cm_to_yards();
  if (!strcmp(choice, "25")) yards_to_inches();
  if (!strcmp(choice, "26")) inches_to_yards();
  if (!strcmp(choice, "27")) yards_to_feet();
  if (!strcmp(choice, "28")) feet_to_yards();
  if (!strcmp(choice, "29")) yards_to_meters();
  if (!strcmp(choice, "30")) meters_to_yards();
  if (!strcmp(choice, "31")) km_to_mm();
  if (!strcmp(choice, "32")) mm_to_km();
  if (!strcmp(choice, "33")) km_to_cm();
  if (!strcmp(choice, "34")) cm_to_km();
  if (!strcmp(choice, "35")) km_to_meters();
  if (!strcmp(choice, "36")) meters_to_km();
  if (!strcmp(choice, "37")) km_to_inches();
  if (!strcmp(choice, "38")) inches_to_km();
  if (!strcmp(choice, "39")) km_to_feet();
  if (!strcmp(choice, "40")) feet_to_km();
  if (!strcmp(choice, "41")) km_to_yards();
  if (!strcmp(choice, "42")) yards_to_km();
  if (!strcmp(choice, "43")) miles_to_km();
  if (!strcmp(choice, "44")) km_to_miles();
  if (!strcmp(choice, "45")) miles_to_meters();
  if (!strcmp(choice, "46")) meters_to_miles();
  if (!strcmp(choice, "47")) miles_to_yards();
  if (!strcmp(choice, "48")) yards_to_miles();
  if (!strcmp(choice, "49")) miles_to_feet();
  if (!strcmp(choice, "50")) feet_to_miles();
  if (!strcmp(choice, "51")) miles_to_inches();
  if (!strcmp(choice, "52")) inches_to_miles();
  if (!strcmp(choice, "53")) miles_to_cm();
  if (!strcmp(choice, "54")) cm_to_miles();
  if (!strcmp(choice, "55")) miles_to_mm();
  if (!strcmp(choice, "56")) mm_to_miles();


  }

}
