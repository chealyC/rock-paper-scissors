#ifndef GAME_H
#define GAME_H

#define NUM_HANDS 3

int randomHand(void);
int chooseHand(void);
void displayHand(int hand);
int determineWinner(int player, int computer);

#endif