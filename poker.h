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
    struct CARD *first;
    struct CARD *last;
    int length;
};
struct CARD
{
    char suit;
    int type;
    struct CARD *next;
    struct DECK *deck;
};

#endif
