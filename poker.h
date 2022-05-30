// Header file for poker.c
// test
#ifndef POKERHEADER
#define POKERHEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void printDecks();
void startGame(int players);
int main(int argc, char *argv[]);
void newRound();
char player1Name[16] = "empty";
char player2Name[16] = "empty";
char player3Name[16] = "empty";
char player4Name[16] = "empty";
char player5Name[16] = "empty";
char player6Name[16] = "empty";
struct CARD
{
    char suit;
    int type;
    char taken;
};

#endif
