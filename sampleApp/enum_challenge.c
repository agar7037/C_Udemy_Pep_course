/* 
Author: Alex Garrett-Jones
Purpose: challenge for using enum data structure to dissply outputs 
*/

#include <stdio.h>
#include <stdlib.h>

int main() 
{
// delcare enum data type Company
    enum Company 
    {
        GOOGLE, 
        FACEBOOK, 
        XEROX,
        YAHOO, 
        EBAY,
        MICROSOFT
    };

// create three instances of enum Company

    enum Company company1 = XEROX;
    enum Company company2 = GOOGLE;
    enum Company company3 = EBAY; 

// print value of companys 

    printf("company1: %d\n", company1);
    printf("company2: %d\n", company2);
    printf("company3: %d",company3);

// bit wise example 
    signed int A = 28;
    signed int B = 103; 
    signed int result = A & B; 
    
// integer float division example 
    float C = B/A; // doesn't work if A and B are integers 
    float AA = 28;
    float BB = 103; 
    C = BB/AA;

    return 0; 
}
