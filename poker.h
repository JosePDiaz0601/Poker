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
void runGame();
int roundOver();
int winner = 0;
int currentPotAmount;
int currentBetAmount;
int players;
int currentplayerturn;
/*
char player1Name[16] = "\0";
char player2Name[16] = "\0";
char player3Name[16] = "\0";
char player4Name[16] = "\0";
char player5Name[16] = "\0";
char player6Name[16] = "\0";
*/

struct CARD
{
    char suit;
    int type;
    char taken;
};

struct PLAYERDATA
{
    char *playerName[16];
    int playerSeat;
    int points;
    int hasFolded;
    bool connected;
};

struct CARD dealer[52];
struct CARD river[5];
struct CARD player1[2];
struct CARD player2[2];
struct CARD player3[2];
struct CARD player4[2];
struct CARD player5[2];
struct CARD player6[2];
struct PLAYERDATA player1data;
struct PLAYERDATA player2data;
struct PLAYERDATA player3data;
struct PLAYERDATA player4data;
struct PLAYERDATA player5data;
struct PLAYERDATA player6data;

// player1data.playerName = "Test";

const char *riverStringCat(int i, char *SendBuf);

void raise(struct PLAYERDATA player, int raiseAmount);
void fold(struct PLAYERDATA player);
void call(struct PLAYERDATA player);

#endif
