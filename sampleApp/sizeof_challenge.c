/*
Auther: Alex Garrett-Jones 
Date: 26/01/22 
Purpose: challenge to print the byte size of common C data types 
*/
#include <stdio.h>
#include <stdlib.h>
int main() 
{
    char s[] = "this is a string";
    char *s1 = "this is a string, it doesn't matter how long this is, it is a pointer so s will always be 8 bytes";// string literal stored in read only memory
    // altering ^^^ this string is illegal and will blow up your program 
    int* i;
    *i = 8;
    size_t s_size = sizeof(s);
    size_t s1_size = sizeof(s1);
    printf("size of int: %zd\n", sizeof(int));
    printf("size of char: %zd \n", sizeof(char));
    printf("size of long: %zd\n", sizeof(long));
    printf("size of long long: %zd\n", sizeof(long long));
    printf("size of double: %zd\n", sizeof(double));
    printf("size of long doube: %zd\n",sizeof(long double));
    printf("size of float: %zd\n", sizeof(float));
    printf("size of short: %zd\n", sizeof(short));
    printf("size of s: %zd\n", s_size);
    printf("size of s1: %zd\n", s1_size);
    printf("%s\n", s);
    printf("%s\n", s1);
    printf("%d", *i); 


    return 0; 
}