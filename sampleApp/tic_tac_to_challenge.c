

/*-----------------------------------------------------------------------------------------
                                        CHALLENGE REQUIREMENTS 
------------------------------------------------------------------------------------------*/
/*
CHALLENGE: write a tic tac to program (naughts and crosses)
how: 
    .create a 3x3 grid represented by a single ore 2D array 
    .each element of the array represents a co-ordinate on the board
    .10 elements (do not use zeroth element for some reason)
functions: 
    .check_for_win - checks to see if a player has won or game is a draw
    .draw_board - redraws the board for each players turn 
    .mark_board - sets the char array with a selection and check for invalid selection
        .populates array with X or O, warns if selection is chosen

display example: 

    Tic Tac Toe 
Player 1 (X)    -   Player 2 (0)
    
1     |     |       case 0,3,6,8
2  1  |  2  |  3    case 1,4,7
3_____|_____|_____  case 2,5 
4     |     |  
5  4  |  5  |  6
6_____|_____|_____    
7     |     |
8  7  |  8  |  9
9     |     |
Player 1, enter a number:  
*/

/*-----------------------------------------------------------------------------------------
                                        HEADERS/ Definitions
------------------------------------------------------------------------------------------*/
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h> 
#define rows 3
#define cols 3

/*-----------------------------------------------------------------------------------------
                                        FUNCTION DECLARATIONS 
------------------------------------------------------------------------------------------*/
bool check_for_win(char coord[rows][cols], int player);
void draw_board(char coord[rows][cols], int row, int col); 
bool mark_board(char coord[rows][cols], int player, int player_choice, bool input_success);
int char_to_int(char ch);
bool play_again(void);
void reset_board(char coord[rows][cols]); 
/*-----------------------------------------------------------------------------------------
                                        BEGIN PROGRAM
------------------------------------------------------------------------------------------*/
int main(void)
{
    
// Variables 
    char board[rows][cols] = 
    {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
    bool play = true;
    int player_choice; 
    bool input_success = false; 
    int Player = 1; 
    bool winner = false;
    int turn_count = 1; 
    //goto test; // Label for jump to test section, use for debugging functions, remove after debugging 
    while (play)
    {
    //Print board 
        printf("\e[1;1H\e[2J");
        printf("\tTic Tac To\n");
        printf("Player 1 (X)\tPlayer 2 (O)\n\n");
        draw_board(board, rows, cols); 
     // if turn count reaches 10 and no winner then we have a draw    
        if (turn_count == 10)
        {
            printf("It's a Draw! \n"); 
            break;
        }
    //scan for player selection - call mark board reprompt if invalid 
        do 
        {
            printf("Player %d, enter a number: ", Player);
            input_success = scanf("%d", &player_choice);
            while(getchar()!= '\n'){} // consume any left over characters in input buff     
            input_success = mark_board(board, Player, player_choice,input_success);
        }
        while (!input_success); 
    
    //check for winner 
        winner = check_for_win(board, Player);
        if(winner)
        {
            // redraw board with winning pattern
            printf("\e[1;1H\e[2J");
            printf("\tTic Tac To\n");
            printf("Player 1 (X)\tPlayer 2 (O)\n\n");
            draw_board(board, rows, cols); 
            printf("Player %d is the winner!\n", Player);
            play = false;// move inside replay promt 
        }
    //conditional exit message + replay prompt - if + replay then reset board array and play flag, // if winner 
        if(winner)
        {
            play = play_again(); 
            if (play)
            {
                reset_board(board); 
                turn_count = 0; 
                Player = 2; // player will be reset to player 1 at end of game while loop 
            }
        }

        turn_count ++; 

    // update player
        if (Player == 1)
            Player = 2;
        else 
            Player = 1; 
    }
/*-----------------------------------------------------------------------------------------
                                        UNIT TESTING  
------------------------------------------------------------------------------------------*/
    // label for testing functions, remove after debugging 
 //   test: 

// final exit message 
    printf("Goodbye ");
    return 0;  
}

/*-----------------------------------------------------------------------------------------
                                        FUNCTION DEFINITIONS 
------------------------------------------------------------------------------------------*/
void draw_board(char coord[rows][cols], int row, int col) 
{
/*
loops over 9 lines of board display, uses switch cases to cover three possible cases of line content 
*/
    int CR = 0; // current row  
    for (int i = 0; i < 9; i++)
    {
        switch (i)
        {
        // rows with only '|'
        case 0:
        case 3:
        case 6:
        case 8: 
            printf("     |     |     \n");
            break;
        // rows with numbers
        case 1:
        case 4: 
        case 7:
            printf("  %c  |  %c  |  %c  \n",coord[CR][0],coord[CR][1],coord[CR][2]);
            CR++;
            break;
        //  rows as lateral divider '_'
        case 2:
        case 5:
            printf("_____|_____|_____\n");
            break;
        default:
            printf("Something has gone wrong");
            break;
        }
    }
}

bool mark_board(char coord[rows][cols], int player, int player_choice, bool input_success)
//Check valid inputs, alter configuration of the board 
{ 
    int row;
    int col;  
    //check valid input:  
    //case 1; invalid type input 
    if (!input_success)
        printf("Invalid input: input must be an integer value from 1-9\n");
    //case 2; invalid range input 
    else if(player_choice < 1 || player_choice > 9)
    {
        input_success=false; 
        printf("Invalid input: input must be in range 1-9\n"); 
    }
    //case 3; occupied co-oordinate input - check happens in board marking switch statement 
    
    if (input_success)
    {   
        // set current row / colukn 
        if(player_choice >= 7)
        {   
            col = player_choice - 7; 
            row = 2; 
        }  
        else if (player_choice >= 4)
        {   
            col = player_choice - 4; 
            row = 1;
        }
        else 
        {
            col = player_choice - 1;
            row = 0;
        }
        // assign board position - check for occupation 
        if (char_to_int(coord[row][col])==player_choice)
            if (player == 1)
                coord[row][col] = 'X'; 
            else 
                coord[row][col] = 'O';
        else 
        {
            printf("Invalid choice: Please pick an un-occupied co-ordinate\n");
            input_success = false;
        }
    }
    return input_success;
}

int char_to_int(char ch)
// convert single character to integer 
{
    char str[2];
    str[0] = ch; 
    str[1] = '\0'; 
    int integer = atoi(str); 
    return integer; 
}

bool check_for_win(char coord[rows][cols], int player)
{   
    //select symbol for checking based on player 
    char symbol; 
    bool win = false; 

    if (player == 1)
        symbol = 'X'; 
    else 
        symbol = 'O'; 
    // check middle element - if occupied by symbol check diagonals 
    if (coord[1][1]==symbol)
    {
        if(coord[0][0]==symbol && coord[2][2]==symbol)
            win = true;
        else if(coord[0][2] == symbol && coord[2][0] == symbol)
            win = true;
    }
    //Check rows
    if (win == false) 
    {
        for (int row = 0 ; row < rows && win == false; row++)
        {
            for (int col = 0 ; col < cols; col++)
            {
                if (coord[row][col]!=symbol)
                    break;

                else if (col == 2) // If on last column  then we have a win 
                    win = true;
            }
        }
    }
    // Check columns only if we have not found a row completion 
    if (win == false)
    {
        for (int col = 0 ; col < cols && win == false; col++)
        {
            for (int row = 0 ; row < rows; row++)
            {
                if (coord[row][col] != symbol)
                    break; 

                else if (row == 2)
                    win = true; 
            } 
        }        
    }
    return win; 
}

bool play_again(void)
/*
    inputs: 
        . Player_choice: character Y or N from scanf input 
        . input_success: return value from scanf ie
*/
{
    char player_choice; 
    bool input_success = false;
    bool play = false; 
    printf("Would you like to play again? Y or N: ");
    do 
    {
        input_success = scanf("%c", &player_choice); 
        while(getchar() != '\n'){} // clear input buffer 
        if (player_choice == 'N' || player_choice == 'Y')
        {
            input_success = true;
            if (player_choice == 'Y')
                play = true;
            break;
        }
        else 
        {
            input_success = false;
            printf("Invalid input... enter Y or N:");
        }
    }
    while(!input_success);
    return play; 
}

void reset_board(char coord[rows][cols])
/*
reset board: upon win and true replay prompt reset the board to inital values
process:  
    .variable: char array of values to be assigned 
    .for loop for assigning values to board array
*/
{
    const char board_vals[rows][cols] = 
    {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < cols; col++)
        {
            coord[row][col] = board_vals[row][col]; 
        }
    }
    return; 

}