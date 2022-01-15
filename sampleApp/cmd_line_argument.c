#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{ //implement main function with argument specifiers required for cmd line args
    int numberOfArguments = argc; 
    char *argument1 = argv[0];
    char *argument2 = argv[1]; 
    char *argument3 = argv[2];
    char *argument4 = argv[3];
  
    int Argument4 = atoi(argument4); //casts value of argument4 to integer 

    printf("Number of Arguments: %d\n", numberOfArguments);
    printf("Argument 1 is the program name: %s\n",argument1); 
    printf("Argument 2 is the command line argument: %s\n",argument2);
    printf("Argument 3 is cmd line arg 2: %s\n", argument3);
    
    // can we use to pass an integer? 
    printf("Argument 4  is integer cmd arg: %d\n", Argument4); 
    Argument4=Argument4+5;
    printf("validation of integer: %d\n", Argument4);

    return 0;
} 
