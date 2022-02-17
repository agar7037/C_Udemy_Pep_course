/*
program tasks 
. Generate random number - user guesses what the number is 
. User can only enter number from 1 - 20 with error checking on this bounds
. If guess is valid tell user they are too high or too low or correct
. User has 5 attempts, if not correct then user is told the number they were supposesed to guess 

output 
line1 : this is a guessing game (information about rules )
on each guess: 
    .how many tries left 
    .prompt for guess 
    .information about the guess (high,low,correct)

*/
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

int main(void)
{  
// Outer loop = whether or not we are playing - player can choose to continue at the end of each game 
    _Bool play = 1; 
    while (play)
    {
        printf("\e[1;1H\e[2J");
        printf("This is a number Guessing game.\n");
        printf("Guess a number between 1 & 20, I will tell you if you are either too high or too low. You have 5 attempts\n");
// Input variables 
        int guess = 0; 
        char newline_consume;
        int success = 0;

// Random number vars 
        time_t t;
        srand((unsigned) time(&t));
        int target = rand() % 21;
        if (target == 0);// zero check ensures range 1:20
            target++;
// Middle loop computes 5 times, this is the number of guesses we have 
        for(int i = 5; i > 0; i--)
        {
            printf("You have %d more attempts\n",i);
            
        //Keep prompting user for input until guess is a number between 1 & 20
            while (success == 0)
            {
                printf("Enter a number between 1 and 20: ");
                success = scanf("%d", &guess);
                

                while(newline_consume = getchar()!= '\n'){} // new lines left in input buffer from number input
                
                if (success == 0)
                {
                    printf("This is not a valid choice\n");
                    continue;
                }
                //printf("guess <=0: %d", guess<=0);
                else if (guess <= 0 || guess > 20)
                {
                    success = 0;
                    printf("This is not a valid choice\n");
                }
                
            }
            success = 0; // reset input success 
        // Checking the answer against our target, begins with attempts left check
            if (guess == target) // correct case - enter replay prompt loop 
            {
                printf("That is correct! Congradulations. Would you like to play agian? Y or N: ");
                char cont;
                while (success == 0)
                {
                    success = scanf("%c", &cont);
                    while(newline_consume = getchar() != '\n'){} // new lines left in input buffer from number input
                    if (success == 0)
                    {
                        printf("invalid selection, enter Y or N: ");
                    }
                    else if (cont != 'N' && cont != 'Y')
                    {
                        printf("invalid selection, enter Y or N: ");
                        success = 0; 
                    }
                    else if (cont == 'N')
                        play = 0;
                }
                break;
            }
            else if (i == 1) // Run out of attempts case - enter preplay prompt loop  
            {
                printf("You have run out of attempts the number you were aiming for was %d\n", target);
                printf("Would you like to play agian? Y or N: ");
                char cont;
                while (success == 0)
                {
                    success = scanf("%c", &cont);
                    while(newline_consume = getchar() != '\n'){} // New lines left in input buffer from number input
                    if (success == 0)
                    {
                        printf("invalid selection, enter Y or N: ");
                    }
                    else if (cont != 'N' && cont != 'Y')
                    {
                        printf("invalid selection, enter Y or N: ");
                        success = 0; 
                    }
                    else if (cont == 'N')
                        play = 0;
                }
                break;
            } 
            else if (guess < target) // Less than target case
            
                printf("Too low! Guess again\n");
            else
                printf("Too high! Guess again\n"); // Greater than target case
        }

    }
    printf("Goodbye!\n");
    return 0;
}