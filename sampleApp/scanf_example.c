#include <stdio.h> 
#include <stdlib.h>

int main() {
    char str[100]; //<--- define a character array stored inside variable str of size 100
    int i; //<-- define a variable i which is an integer
    
    printf("Enter a number and a string: ");
    scanf("%d %s", &i, str); //<--two arguments first arg "%s,%d" defines data type expected
//"str, &i" defines the destination variables for the two expected data types 
//user will enter an array of characters of no more than 100, and then an integer - scanf stores char array in str variable 
//stores integer in variable i by using a pointer to varaible i. 
    printf("\nYou entered: %d::::%s\n", i, str); // print f retrieves values stored in variables str and i
    fflush(stdin);
    //getchar();
    system("read -p 'Press Enter to continue...' var");
    return 0;
}