/*
Auther: Alex Garrett-Jones 
Date: 26/01/22 
Purpose: challenge to print the byte size of common C data types 
*/
#include <stdio.h>
#include <stdlib.h>
int main() 
{
    printf("size of int: %zd\n", sizeof(int));
    printf("size of char: %zd \n", sizeof(char));
    printf("size of long: %zd\n", sizeof(long));
    printf("size of long long: %zd\n", sizeof(long long));
    printf("size of double: %zd\n", sizeof(double));
    printf("size of long doube: %zd\n",sizeof(long double));
    printf("size of float: %zd\n", sizeof(float));
    printf("size of short: %zd\n", sizeof(short));

    return 0; 
}