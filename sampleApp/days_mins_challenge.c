/*Author: Alex Garrett-Jones 
Date: 26/01/2022
Purpose: take minutes from user input, display total number of days and years in standard output 
---------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h> 

int main() 
{ 
    double mins = 0; 
    double year = 0; 
    double days = 0; 
//take minutes from user input as a double 
    printf("Enter a number: ");
    scanf("%lf", &mins); // using %lf as a format specifier for double (note: %f does not work here)
    days = mins/1440; 
    year = days/365; 

// print to terminal 
    printf("Number of minutes: %lf\n", mins);
    printf("Number of days: %lf\n", days);
    printf("Number of years: %lf\n",year);

    return 0; 
}