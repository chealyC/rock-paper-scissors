#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"game.h"

int main(void) 
{
    /*Seed the random number generator using the current time*/
    srand(time(NULL));

    /*Initialise scores*/
    int playerScore = 0;
    int computerScore = 0;
    int draws = 0;

    /*Start game*/
    char playAgain = 'y';

    while(playAgain == 'y' || playAgain == 'Y')
    {  
        int player = chooseHand();
        int computer = randomHand(); 

        printf("You chose: ");
        displayHand(player);

        printf("Computer chose: ");
        displayHand(computer);

        int result = determineWinner(player, computer);

        /*Update score based on result*/
        if (result == 0)
        {
            printf("It's a draw!\n");
            draws++;
        }
        else if (result == 1)
        {    
            printf("You win!\n");
            playerScore++;
        }
        else
        {
            printf("Computer wins!\n");
            computerScore++;
        }

        /*Display current scores*/
        printf("\nScore:\n");
        printf("Player: %d\n", playerScore);
        printf("Computer: %d\n", computerScore);
        printf("Draws: %d\n", draws);

        /*Confirm if player wants to go another round*/
        printf("\nPress y to play again.\n");
        scanf(" %c", &playAgain);
    }

    return 0;
}
