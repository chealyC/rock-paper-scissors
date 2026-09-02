#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"game.h"

int main(void) 
{
    srand(time(NULL));

    int playerScore = 0;
    int computerScore = 0;
    int draws = 0;

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

        printf("\nScore:\n");
        printf("Player: %d\n", playerScore);
        printf("Computer: %d\n", computerScore);
        printf("Draws: %d\n", draws);

        printf("\nPress y to play again.\n");
        scanf(" %c", &playAgain);
    }

    return 0;
}