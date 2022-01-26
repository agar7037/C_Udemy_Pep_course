#include <stdio.h> 

int main() 
{
    int UserNumber = 0;
    printf("enter a number: ");
    scanf("%d", &UserNumber);

    if ((UserNumber%2) != 0)
        printf("number is odd\n"); 
    else 
        printf("number is even\n");
    return 0; 
}