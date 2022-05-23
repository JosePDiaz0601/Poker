// This file shall contain the main function for our poker game
#include "poker.h"
#include <time.h>

struct CARD dealer[52];
struct CARD river[5];
struct CARD player1[2];
struct CARD player2[2];
struct CARD player3[2];
struct CARD player4[2];
struct CARD player5[2];
struct CARD player6[2];
int players = 7; // Change this later so that player count isnt hardcoded
int points[6] = {1000, 1000, 1000, 1000, 1000, 1000};
// Main function of the game
void startGame(int players);
void printDecks();

void main()
{
    printf("Welcome to poker, go fuck yourself");
    // Change this later so that player count isnt hardcoded
    startGame(players);
    printDecks();
}

// Starts the game by creating all the cards and placing them in the appropriate deck
void startGame(int players)
{

    srand(time(0));
    int dealerPlayer = rand() % players;

    // Aces
    struct CARD C1 = {'C', 14, 'N'};
    struct CARD D1 = {'D', 14, 'N'};
    struct CARD H1 = {'H', 14, 'N'};
    struct CARD S1 = {'S', 14, 'N'};

    // 2's
    struct CARD C2 = {'C', 2, 'N'};
    struct CARD D2 = {'D', 2, 'N'};
    struct CARD H2 = {'H', 2, 'N'};
    struct CARD S2 = {'S', 2, 'N'};

    // 3's
    struct CARD C3 = {'C', 3, 'N'};
    struct CARD D3 = {'D', 3, 'N'};
    struct CARD H3 = {'H', 3, 'N'};
    struct CARD S3 = {'S', 3, 'N'};

    // 4's
    struct CARD C4 = {'C', 4, 'N'};
    struct CARD D4 = {'D', 4, 'N'};
    struct CARD H4 = {'H', 4, 'N'};
    struct CARD S4 = {'S', 4, 'N'};

    // 5's
    struct CARD C5 = {'C', 5, 'N'};
    struct CARD D5 = {'D', 5, 'N'};
    struct CARD H5 = {'H', 5, 'N'};
    struct CARD S5 = {'S', 5, 'N'};

    // 6's
    struct CARD C6 = {'C', 6, 'N'};
    struct CARD D6 = {'D', 6, 'N'};
    struct CARD H6 = {'H', 6, 'N'};
    struct CARD S6 = {'S', 6, 'N'};

    // 7's
    struct CARD C7 = {'C', 7, 'N'};
    struct CARD D7 = {'D', 7, 'N'};
    struct CARD H7 = {'H', 7, 'N'};
    struct CARD S7 = {'S', 7, 'N'};

    // 8's
    struct CARD C8 = {'C', 8, 'N'};
    struct CARD D8 = {'D', 8, 'N'};
    struct CARD H8 = {'H', 8, 'N'};
    struct CARD S8 = {'S', 8, 'N'};

    // 9's
    struct CARD C9 = {'C', 9, 'N'};
    struct CARD D9 = {'D', 9, 'N'};
    struct CARD H9 = {'H', 9, 'N'};
    struct CARD S9 = {'S', 9, 'N'};

    // 10's
    struct CARD C10 = {'C', 10, 'N'};
    struct CARD D10 = {'D', 10, 'N'};
    struct CARD H10 = {'H', 10, 'N'};
    struct CARD S10 = {'S', 10, 'N'};

    // Jack's
    struct CARD C11 = {'C', 11, 'N'};
    struct CARD D11 = {'D', 11, 'N'};
    struct CARD H11 = {'H', 11, 'N'};
    struct CARD S11 = {'S', 11, 'N'};

    // Queen's
    struct CARD C12 = {'C', 12, 'N'};
    struct CARD D12 = {'D', 12, 'N'};
    struct CARD H12 = {'H', 12, 'N'};
    struct CARD S12 = {'S', 12, 'N'};

    // King's
    struct CARD C13 = {'C', 13, 'N'};
    struct CARD D13 = {'D', 13, 'N'};
    struct CARD H13 = {'H', 13, 'N'};
    struct CARD S13 = {'S', 13, 'N'};

    dealer[0] = C1;
    dealer[1] = D1;
    dealer[2] = H1;
    dealer[3] = S1;
    dealer[4] = C2;
    dealer[5] = D2;
    dealer[6] = H2;
    dealer[7] = S2;
    dealer[8] = C3;
    dealer[9] = D3;
    dealer[10] = H3;
    dealer[11] = S3;
    dealer[12] = C1;
    dealer[13] = D1;
    dealer[14] = H1;
    dealer[15] = S1;
    dealer[16] = C1;
    dealer[17] = D1;
    dealer[18] = H1;
    dealer[19] = S1;
    dealer[20] = C1;
    dealer[21] = D1;
    dealer[22] = H1;
    dealer[23] = S1;
    dealer[24] = C1;
    dealer[25] = D1;
    dealer[26] = H1;
    dealer[27] = S1;
    dealer[28] = C1;
    dealer[29] = D1;
    dealer[30] = H1;
    dealer[31] = S1;
    dealer[32] = C1;
    dealer[33] = D1;
    dealer[34] = H1;
    dealer[35] = S1;
    dealer[36] = C1;
    dealer[37] = D1;
    dealer[38] = H1;
    dealer[39] = S1;
    dealer[40] = C1;
    dealer[41] = D1;
    dealer[42] = H1;
    dealer[43] = S1;
    dealer[44] = C1;
    dealer[45] = D1;
    dealer[46] = H1;
    dealer[47] = S1;
    dealer[48] = C1;
    dealer[49] = D1;
    dealer[50] = H1;
    dealer[51] = S1;

    newRound();
}

// This function gives the river its proper cards and all the players are given new cards
void newRound()
{
    for (int i = 0; i < 52; i++)
    {
        dealer[i].taken = 'N';
    }

    // Give cards to the river
    int i = 0;
    while (i < 5)
    {
        int card = rand() % (52);
        if (dealer[card].taken == 'N')
        {
            river[i] = dealer[card];
            dealer[card].taken = 'Y';
            i++;
        }
        else
        {
            continue;
        }
    }
    i = 0;

    // Give cards to player 1

    while (i < 2)
    {
        int card = rand() % (52);
        if (dealer[card].taken == 'N')
        {
            player1[i] = dealer[card];
            dealer[card].taken = 'Y';
            i++;
        }
        else
        {
            continue;
        }
    }
    i = 0;

    // Give cards to player 2
    while (i < 2)
    {
        int card = rand() % (52);
        if (dealer[card].taken == 'N')
        {
            player2[i] = dealer[card];
            dealer[card].taken = 'Y';
            i++;
        }
        else
        {
            continue;
        }
    }
    i = 0;

    if (players == 4)
    {
        while (i < 2)
        {
            int card = rand() % (52);
            if (dealer[card].taken == 'N')
            {
                player3[i] = dealer[card];
                dealer[card].taken = 'Y';
                i++;
            }
            else
            {
                continue;
            }
        }
        i = 0;
    }

    if (players == 5)
    {
        while (i < 2)
        {
            int card = rand() % (52);
            if (dealer[card].taken == 'N')
            {
                player4[i] = dealer[card];
                dealer[card].taken = 'Y';
                i++;
            }
            else
            {
                continue;
            }
        }
        i = 0;
    }

    if (players == 6)
    {
        while (i < 2)
        {
            int card = rand() % (52);
            if (dealer[card].taken == 'N')
            {
                player5[i] = dealer[card];
                dealer[card].taken = 'Y';
                i++;
            }
            else
            {
                continue;
            }
        }
        i = 0;
    }

    if (players == 7)
    {
        while (i < 2)
        {
            int card = rand() % (52);
            if (dealer[card].taken == 'N')
            {
                player6[i] = dealer[card];
                dealer[card].taken = 'Y';
                i++;
            }
            else
            {
                continue;
            }
        }
        i = 0;
    }
}
void printDecks()
{
    printf("\n");
    if(players >= 3);
    {
        for(int y=0; y<5; y++)
        {
            if(river[y].suit == 'C')
            {
                printf("River's %d card is a %d of Clubs\n", y+1, river[y].type);
            }
            if(river[y].suit == 'D')
            {
                printf("River's %d card is a %d of Diamonds\n", y+1, river[y].type);
            }
            if(river[y].suit == 'H')
            {
                printf("River's %d card is a %d of Hearts\n", y+1, river[y].type);
            }
            if(river[y].suit == 'S')
            {
                printf("River's %d card is a %d of Spades\n", y+1, river[y].type);
            }
        }

        for(int y=0; y<2; y++)
        {
            if(player1[y].suit == 'C')
            {
                printf("Player1's %d card is a %d of Clubs\n", y+1, player1[y].type);
            }
            if(player1[y].suit == 'D')
            {
                printf("Player1's %d card is a %d of Diamonds\n", y+1, player1[y].type);
            }
            if(player1[y].suit == 'H')
            {
                printf("Player1's %d card is a %d of Hearts\n", y+1, player1[y].type);
            }
            if(player1[y].suit == 'S')
            {
                printf("Player1's %d card is a %d of Spades\n", y+1, player1[y].type);
            }
        }
        for(int y = 0; y<2; y++)
        {
            if(player2[y].suit == 'C')
            {
                printf("Player2's %d card is a %d of Clubs\n", y+1, player2[y].type);
            }
            if(player2[y].suit == 'D')
            {
                printf("Player2's %d card is a %d of Diamonds\n", y+1, player2[y].type);
            }
            if(player2[y].suit == 'H')
            {
                printf("Player2's %d card is a %d of Hearts\n", y+1, player2[y].type);
            }
            if(player2[y].suit == 'S')
            {
                printf("Player2's %d card is a %d of Spades\n", y+1, player2[y].type);
            }
        }
    }
    if(players >= 4);
    {
        for(int y = 0; y<2; y++)
        {
            if(player3[y].suit == 'C')
            {
                printf("Player3's %d card is a %d of Clubs\n", y+1, player3[y].type);
            }
            if(player3[y].suit == 'D')
            {
                printf("Player3's %d card is a %d of Diamonds\n", y+1, player3[y].type);
            }
            if(player3[y].suit == 'H')
            {
                printf("Player3's %d card is a %d of Hearts\n", y+1, player3[y].type);
            }
            if(player3[y].suit == 'S')
            {
                printf("Player3's %d card is a %d of Spades\n", y+1, player3[y].type);
            }
        }
    }
    if(players >= 5);
    {
        for(int y = 0; y<2; y++)
        {
            if(player4[y].suit == 'C')
            {
                printf("Player4's %d card is a %d of Clubs\n", y+1, player4[y].type);
            }
            if(player4[y].suit == 'D')
            {
                printf("Player4's %d card is a %d of Diamonds\n", y+1, player4[y].type);
            }
            if(player4[y].suit == 'H')
            {
                printf("Player4's %d card is a %d of Hearts\n", y+1, player4[y].type);
            }
            if(player4[y].suit == 'S')
            {
                printf("Player4's %d card is a %d of Spades\n", y+1, player4[y].type);
            }
        }
    }
    if(players >= 6);
    {
        for(int y = 0; y<2; y++)
        {
            if(player5[y].suit == 'C')
            {
                printf("Player5's %d card is a %d of Clubs\n", y+1, player5[y].type);
            }
            if(player5[y].suit == 'D')
            {
                printf("Player5's %d card is a %d of Diamonds\n", y+1, player5[y].type);
            }
            if(player5[y].suit == 'H')
            {
                printf("Player5's %d card is a %d of Hearts\n", y+1, player5[y].type);
            }
            if(player5[y].suit == 'S')
            {
                printf("Player5's %d card is a %d of Spades\n", y+1, player5[y].type);
            }
        }
    }
    if(players >= 7);
    {
        for(int y = 0; y<2; y++)
        {
            if(player6[y].suit == 'C')
            {
                printf("Player6's %d card is a %d of Clubs\n", y+1, player6[y].type);
            }
            if(player6[y].suit == 'D')
            {
                printf("Player6's %d card is a %d of Diamonds\n", y+1, player6[y].type);
            }
            if(player6[y].suit == 'H')
            {
                printf("Player6's %d card is a %d of Hearts\n", y+1, player6[y].type);
            }
            if(player6[y].suit == 'S')
            {
                printf("Player6's %d card is a %d of Spades\n", y+1, player6[y].type);
            }
        }
    }
    return;
}