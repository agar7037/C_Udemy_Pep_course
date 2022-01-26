/* 
Author: Alex Garrett-Jones
date: 26/01/22
purpose: user enter the number of hours worked in a week via std in 
ouput gross pay, taxes and net pay

basic pay rate = $12 an hour
overtime (> 40 hours) = time and half
tax: 
* 15% on first 300 
* 20% on next 150
* 25% of the rest 

process 
1. enter hours 
2. compute total pay (gross) - using if else statement 
3. work out tax (switch statement)

can also use define statements for values we know to be constant 
ie 

#define payrate 12.00
#define tax1 .15
#define tax2 .2
#define tax3 .25
#define overtime 40 

makes code more alterable if rates change

*/

#include <stdio.h>

int main() 
{
    float hours = 0.0;
    float payrate = 12;
    float pay = 0;
    float tax = 0; 
    float netpay = 0;

    printf("Enter hours worked: \n");
    scanf("%f", &hours);

    if (hours > 40)
    {
        pay = 40*payrate + (hours-40)*(1.5*payrate); 
    }
    else 
        pay = hours*payrate;
    printf("grosspay = %.2f\n", pay);
    if (pay > 300)
    {
        tax = 300 * 0.15; 
        if (pay > 450)
        {
            tax = tax + (150 * 0.2);
            tax = tax + (pay - 450)*0.25;
        }

        else 
            tax = tax + 0.2*(pay-300);
    }
    else 
        tax = 0.15*pay; 

    netpay = pay-tax; 

    printf("Gross pay = %.2f\n", pay);
    printf("Total tax = %.2f\n", tax); 
    printf("Net pay = %.2f\n", netpay);

    return 0; 
}