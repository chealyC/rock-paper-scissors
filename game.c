#include "game.h"
#include <stdio.h>
#include <stdlib.h>

/*Generate a random hand between 0 and NUM_HANDS - 1*/
int randomHand(void)
{
    return rand() % NUM_HANDS;
}

int chooseHand(void)
{
    int choice;

    do
    {
    printf("Please choose a hand:\n");
    printf("ROCK = 0\n");
    printf("SCISSORS = 1\n");
    printf("PAPER = 2\n");

    scanf("%d", &choice);

    /*Check that the player entered a valid hand*/
    if (choice < 0 || choice > 2)
        printf("Please enter a valid number.\n");

    } while (choice < 0 || choice > 2);

    return choice;
}

void displayHand(int hand)
{
    /*Display the name of the selected hand*/
    switch (hand)
    {
        case 0:
            printf("ROCK\n");
            break;
        case 1:
            printf("SCISSORS\n");
            break;
        case 2:
            printf("PAPER\n");
            break;
        default:
            printf("Invalid hand\n");
    }
}

/*
* Determine the winner:
* 0 = draw
* 1 = player wins
* 2 = computer wins
*/
int determineWinner(int player, int computer)
{
    /*Same hand means a draw*/
    if (player == computer)
        return 0;

    /*Checks possible combinations where the player wins*/
    if ((player == 0 && computer == 1) ||
        (player == 1 && computer == 2) ||
        (player == 2 && computer == 0))
        return 1;

    return 2;
}