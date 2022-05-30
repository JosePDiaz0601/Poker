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

int player1points,player2points,player3points,player4points,player5points,player6points = 1000;
int pot = 0;
int currentplayerturn = 1;
int players = 7; // Change this later so that player count isnt hardcoded
int points[6] = {1000, 1000, 1000, 1000, 1000, 1000};
// Main function of the game

int main(void)
{
    printf("Welcome to poker");
    // Change this later so that player count isnt hardcoded
    startGame(players);
    printDecks();
    return 0;  
}

// Starts the game by creating all the cards and placing them in the appropriate deck
void startGame(int players)
{

    srand(time(NULL));

    // commented out for error
    // int dealerPlayer = rand() % players;

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
    dealer[12] = C4;
    dealer[13] = D4;
    dealer[14] = H4;
    dealer[15] = S4;
    dealer[16] = C5;
    dealer[17] = D5;
    dealer[18] = H5;
    dealer[19] = S5;
    dealer[20] = C6;
    dealer[21] = D6;
    dealer[22] = H6;
    dealer[23] = S6;
    dealer[24] = C7;
    dealer[25] = D7;
    dealer[26] = H7;
    dealer[27] = S7;
    dealer[28] = C8;
    dealer[29] = D8;
    dealer[30] = H8;
    dealer[31] = S8;
    dealer[32] = C9;
    dealer[33] = D9;
    dealer[34] = H9;
    dealer[35] = S9;
    dealer[36] = C10;
    dealer[37] = D10;
    dealer[38] = H10;
    dealer[39] = S10;
    dealer[40] = C11;
    dealer[41] = D11;
    dealer[42] = H11;
    dealer[43] = S11;
    dealer[44] = C12;
    dealer[45] = D12;
    dealer[46] = H12;
    dealer[47] = S12;
    dealer[48] = C13;
    dealer[49] = D13;
    dealer[50] = H13;
    dealer[51] = S13;

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

    if (players >= 4)
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

    if (players >= 5)
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

    if (players >= 6)
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

    if (players >= 7)
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
  currentplayerturn = 1;
}

int playerPoints(struct CARD player[2])
{

    // Create a temp that combines the river and the players card in order to make comparisons easier

    struct CARD temp[7];
    struct CARD noPairs[7];
    temp[0] = river[0];
    temp[1] = river[1];
    temp[2] = river[2];
    temp[3] = river[3];
    temp[4] = river[4];
    temp[5] = player[0];
    temp[6] = player[1];

    noPairs[0] = temp[0];
    noPairs[1] = temp[1];
    noPairs[2] = temp[2];
    noPairs[3] = temp[3];
    noPairs[4] = temp[4];
    noPairs[5] = temp[5];
    noPairs[6] = temp[6];

    int points = 0;
    // Bubble Sort
    int sort = 0;
    struct CARD hold;
    while (sort == 0)
    {
        for (int i = 0; i < 6; i++)
        {
            if (temp[i].type > temp[i + 1].type)
                hold = temp[i];
            temp[i] = temp[i + 1];
            temp[i + 1] = hold;
        }
        if (temp[0].type <= temp[1].type <= temp[2].type <= temp[3].type <= temp[4].type <= temp[5].type <= temp[6].type)
        {
            sort = 1;
        }
    }

    int size = 7;
    int key, i, index = -1;

    /*
     * iterate the array elements using loop
     * if any element matches the key, store the index
     */

    for (i = 0; i < size; i++)
    {
        if (noPairs[i].type == noPairs[i + 1].type)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        // shift all the element from index+1 by one position to the left
        for (i = index; i < size - 1; i++)
            noPairs[i] = noPairs[i + 1];

        // Combined 4 of a kind, 3 of a kind, 2 of a kind
        int pairs = 0;
        int fourOfAKind, threeOfAKind = 0;

        // Four of a Kind
        for (int i = 6; i >= 2; i--)
        {
            if (temp[i].type == temp[i - 1].type == temp[i - 2].type == temp[i - 3].type)
            {
              points = points + (50000 * temp[i].type);
              fourOfAKind++;
              break;
            }
        }

        // Three of a kind
        for (int i = 6; i >= 2; i--)
        {
            if ((temp[i].type == temp[i - 1].type == temp[i - 2].type) && (fourOfAKind == 0))
            {
                points = points + (2000 * temp[i].type);
              threeOfAKind++;
                break;
            }
        }
        // Two of a kind
        for (int i = 6; i >= 1; i--)
        {
            if ((temp[i].type == temp[i - 1].type) && (pairs < 2) && (threeOfAKind == 0) && (fourOfAKind == 0))
            {
                points = points + (100 * temp[i].type);
                i--;
                pairs++;
            }
        }
    }
    // Straight
    int count = 0;
    int check = 0;
    for (int i = 0; i <= 2; i++)
    {
        for (int y = i + 1; y <= 6; y++)
            if (temp[y - 1].type == temp[y].type - 1)
            {
                count++;
              if(count == 4)
              {
                break;
              }
            }
    }
    if (count >= 4)
    {
        points = points + 30000;
    }

    // Straight but for ACE rule
    for (int i = 0; i <= 6; i++)
    {
        if (temp[i].type == 14 && check == 0)
        {
            check = 1;
        }
        if (temp[i].type == 2 && check == 1)
        {
            check = 2;
        }
        if (temp[i].type == 3 && check == 2)
        {
            check = 3;
        }
        if (temp[i].type == 4 && check == 3)
        {
            check = 4;
        }
        if (temp[i].type == 5 && check == 4)
        {
            check = 5;
        }
    }
    if (check == 5)
    {
        points = points + 30000;
    }

    // Flush
    int heart, spade, club, diamond = 0;
    for (int i = 0; i < 7; i++)
    {

        if (temp[i].suit == 'H')
        {
            heart = heart + 1;
        }
        if (temp[i].suit == 'S')
        {
            spade = spade + 1;
        }
        if (temp[i].suit == 'C')
        {
            club = club + 1;
        }
        if (temp[i].suit == 'D')
        {
            diamond = diamond + 1;
        }
    }
    if ((heart >= 5) || (spade >= 5) || (club >= 5) || (diamond >= 5))
    {
        points = points + 35000;
    }

    
    // adds value for the highest card
    if (player[0].type > player[1].type)
    {
        points = points + player[0].type;
    }
    else
    {
        points = points + player[1].type;
    }

  //Straight Flush
  char suitCheck;
  int counter, typeCheck;
  for(int r = 0; r >= 6; r++)
  {
    counter = 0;
    
      suitCheck = temp[r].suit;
      typeCheck = temp[r].type;
      for(int c = 0; r >= 6; r++)
      {
        if(temp[c].type == typeCheck+1 && temp[c].suit == suitCheck)
        {
          counter++;
        }
        if(temp[c].type == typeCheck+2 && temp[c].suit == suitCheck)
        {
          counter++;
        }
        if(temp[c].type == typeCheck+3 && temp[c].suit == suitCheck)
        {
          counter++;
        }
        if(temp[c].type == typeCheck+4 && temp[c].suit == suitCheck)
        {
          counter++;
        }
        
      }
    if(counter == 4)
    {
      points = points + 700000;
      break;
    }
  }

  //Royal Flush

  for(int r = 0; r >= 6; r++)
  {
    counter = 0;
    if(temp[r].type == 10)
    {
      suitCheck = temp[r].suit;

      for(int c = 0; r >= 6; r++)
      {
        if(temp[c].type == 11 && temp[c].suit == suitCheck)
        {
          counter++;
        }
        if(temp[c].type == 12 && temp[c].suit == suitCheck)
        {
          counter++;
        }
        if(temp[c].type == 13 && temp[c].suit == suitCheck)
        {
          counter++;
        }
        if(temp[c].type == 14 && temp[c].suit == suitCheck)
        {
          counter++;
        }
        
      }
    }
    if(counter == 4)
    {
      points = points + 800000;
      break;
    }
  }
}

// Prints out all the decks
void printDecks(struct CARD deck[])
{
    printf("\n");
    if (players >= 3)
    {
        for (int y = 0; y < sizeof *deck; y++)
        {
            if (deck[y].suit == 'C')
            {
                printf("Deck's %d card is a %d of Clubs\n", y + 1, deck[y].type);
            }
            if (deck[y].suit == 'D')
            {
                printf("Deck's %d card is a %d of Diamonds\n", y + 1, deck[y].type);
            }
            if (deck[y].suit == 'H')
            {
                printf("Deck's %d card is a %d of Hearts\n", y + 1, deck[y].type);
            }
            if (deck[y].suit == 'S')
            {
                printf("Deck's %d card is a %d of Spades\n", y + 1, deck[y].type);
            }
        }
    }
}

void call(int player)
{
  currentplayerturn++;
  if (currentplayerturn == players)
  {
    currentplayerturn = 1;
  }
}
