/*
challenge: Create program that uses a two dimensional array in a weather program 
purpose: 
    .find total rainfall for each year
    .average yearly rainfall (row average) 
    .average monthly rainfall accross 5 years (column average)
how: 
    .use 2D array with hard-coded values for rainfall amounts for past 5 years
    .5X12 array 
    .rows = years; columns = months 
    .rainfall amounts can be floating point values 
output: 
    .under two column  table (year, rainfall total)
    .then "the yearly average is .... inches"
    . then "Monthly averages" list of months with their average displayed underneath 

hints: 
    .
*/
#define Years 5
#define Months 12
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
int main(void)
{
//VARIABLES 
    float weather_data[Years][Months] = 
    {
        {44.23f, 22.48f, 33.56f, 66.78f, 55.45f, 67.35f, 40.10f, 33.78f, 33.92f, 10.10f, 12.20f, 20.69f},
        {24.58f, 33.23f, 34.87f, 50.44f, 48.21f, 30.99f, 21.45f, 32.54f, 97.32f, 69.32f, 12.35f, 40.58f},
        {13.48f, 25.83f, 49.57f, 20.58f, 00.38f, 19.83f, 32.47f, 19.49f, 39.57f, 19.30f, 28.48f, 49.17f},
        {48.58f, 91.38f, 55.33f, 20.00f, 10.38f, 11.22f, 55.55f, 00.12f, 49.55f, 59.29f, 11.33f, 44.33f},
        {59.44f, 20.58f, 20.22f, 88.88f, 39.42f, 22.45f, 22.99f, 02.22f, 99.00f, 92.34f, 14.32f, 48.38f}
    };
    float year_avg = 0.0f;
    float month_avg[Months] = {0.0f};
    float year_tot[Years] = {0.0f}; 
    int start_year = 2010; 
    char table_format[] = "YEAR\t\tTOTAL (inches)\n"; //formating rain fall table 

//two column array showing year and total 
    // formatting table 
    printf("%s",table_format);
    for(int i =0; i<strlen(table_format); i++){
        printf("--");
    }
    printf("\n");
    // calcualting totals
    for (int y = 0;  y < Years; y++ )
    {
        for(int m = 0; m < Months; m++)
        {
            year_tot[y] = year_tot[y]+weather_data[y][m];
        }
        printf("%d\t|\t%.2f\n", start_year+y, year_tot[y]);
        year_avg = year_avg+year_tot[y]; // compute running total accross 5 years 
    }
//5 yearly average (average of yearly totals) calculation
    year_avg = year_avg/(float)Years;
    printf("\nThe five yearly average is: %.2f inches \n\n", year_avg);

//Monthly (column) average calculation 
    printf("Monthly averages: \n"); 
    printf("JAN\tFEB\tMAR\tAPR\tMAY\tJUN\tJUL\tAUG\tSEP\tOCT\tNOV\tDEC\n");
    for(int m = 0; m < Months; m++)
    {
        for(int y = 0; y < Years; y++)
        {
            month_avg[m]=month_avg[m]+weather_data[y][m];
        }
        month_avg[m] = month_avg[m]/Years;
        printf("%.2f\t",month_avg[m]);
    }
    printf("\n");
    return 0; 

}
