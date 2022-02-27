#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>


int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const char*)a;
    int arg2 = *(const char*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
 
    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}

int main(void)
{
    char alpha[12] = "dczxfolgja";
 //   size_t size = sizeof(alpha)/sizeof(*alpha); 
    qsort(alpha, strlen(alpha), sizeof(char), compare_ints);
    printf("%s", alpha); 


}