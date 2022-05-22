// Header file for poker.c
#ifndef POKERHEADER
#define POKERHEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void startGame(int players);

struct DECK
{
    struct CARD *first;      // Their First Card
    struct DECK *nextPlayer; // The next player/deck
    int points;
    char number; // The player 'Number'
    int length;  // The length of the deck
};
struct CARD
{
    char suit;
    int type;
    struct CARD *next;
    struct CARD *prev;
    struct DECK *deck;
};

#endif
