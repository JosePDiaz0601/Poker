// This file shall contain the main function for our poker game
#include "poker.h"
#include <time.h>

int players = 7;

void main()
{
    print("\nWelcome to Unoptimized Poker, our newly released poker game from LoadingTM!\n");
    // Change this later so that player count isnt hardcoded
    startGame(players);
}

void startGame(int players)
{
    srand(time(0));
    int dealerPlayer = rand() % players;

    // Dealer Deck
    struct DECK *dealer = {NULL, NULL, 1000, 'D', 52};
    struct DECK *river = {NULL, NULL, 1000, 'R', 0};
    struct DECK *player1 = {NULL, NULL, 1000, 1, 0};
    struct DECK *player2 = {NULL, NULL, 1000, 1, 0};
    struct DECK *player3 = {NULL, NULL, 1000, 1, 0};
    struct DECK *player4 = {NULL, NULL, 1000, 1, 0};
    struct DECK *player5 = {NULL, NULL, 1000, 1, 0};
    struct DECK *player6 = {NULL, NULL, 1000, 1, 0};
    // Aces
    struct CARD *C1 = {'C', 14, NULL, NULL, *dealer};
    struct CARD *D1 = {'D', 14, NULL, NULL, *dealer};
    struct CARD *H1 = {'H', 14, NULL, NULL, *dealer};
    struct CARD *S1 = {'S', 14, NULL, NULL, *dealer};

    // 2's
    struct CARD *C2 = {'C', 2, NULL, NULL, *dealer};
    struct CARD *D2 = {'D', 2, NULL, NULL, *dealer};
    struct CARD *H2 = {'H', 2, NULL, NULL, *dealer};
    struct CARD *S2 = {'S', 2, NULL, NULL, *dealer};

    // 3's
    struct CARD *C3 = {'C', 3, NULL, NULL, *dealer};
    struct CARD *D3 = {'D', 3, NULL, NULL, *dealer};
    struct CARD *H3 = {'H', 3, NULL, NULL, *dealer};
    struct CARD *S3 = {'S', 3, NULL, NULL, *dealer};

    // 4's
    struct CARD *C4 = {'C', 4, NULL, NULL, *dealer};
    struct CARD *D4 = {'D', 4, NULL, NULL, *dealer};
    struct CARD *H4 = {'H', 4, NULL, NULL, *dealer};
    struct CARD *S4 = {'S', 4, NULL, NULL, *dealer};

    // 5's
    struct CARD *C5 = {'C', 5, NULL, NULL, *dealer};
    struct CARD *D5 = {'D', 5, NULL, NULL, *dealer};
    struct CARD *H5 = {'H', 5, NULL, NULL, *dealer};
    struct CARD *S5 = {'S', 5, NULL, NULL, *dealer};

    // 6's
    struct CARD *C6 = {'C', 6, NULL, NULL, *dealer};
    struct CARD *D6 = {'D', 6, NULL, NULL, *dealer};
    struct CARD *H6 = {'H', 6, NULL, NULL, *dealer};
    struct CARD *S6 = {'S', 6, NULL, NULL, *dealer};

    // 7's
    struct CARD *C7 = {'C', 7, NULL, NULL, *dealer};
    struct CARD *D7 = {'D', 7, NULL, NULL, *dealer};
    struct CARD *H7 = {'H', 7, NULL, NULL, *dealer};
    struct CARD *S7 = {'S', 7, NULL, NULL, *dealer};

    // 8's
    struct CARD *C8 = {'C', 8, NULL, NULL, *dealer};
    struct CARD *D8 = {'D', 8, NULL, NULL, *dealer};
    struct CARD *H8 = {'H', 8, NULL, NULL, *dealer};
    struct CARD *S8 = {'S', 8, NULL, NULL, *dealer};

    // 9's
    struct CARD *C9 = {'C', 9, NULL, NULL, *dealer};
    struct CARD *D9 = {'D', 9, NULL, NULL, *dealer};
    struct CARD *H9 = {'H', 9, NULL, NULL, *dealer};
    struct CARD *S9 = {'S', 9, NULL, NULL, *dealer};

    // 10's
    struct CARD *C10 = {'C', 10, NULL, NULL, *dealer};
    struct CARD *D10 = {'D', 10, NULL, NULL, *dealer};
    struct CARD *H10 = {'H', 10, NULL, NULL, *dealer};
    struct CARD *S10 = {'S', 10, NULL, NULL, *dealer};

    // Jack's
    struct CARD *C11 = {'C', 11, NULL, NULL, *dealer};
    struct CARD *D11 = {'D', 11, NULL, NULL, *dealer};
    struct CARD *H11 = {'H', 11, NULL, NULL, *dealer};
    struct CARD *S11 = {'S', 11, NULL, NULL, *dealer};

    // Queen's
    struct CARD *C12 = {'C', 12, NULL, NULL, *dealer};
    struct CARD *D12 = {'D', 12, NULL, NULL, *dealer};
    struct CARD *H12 = {'H', 12, NULL, NULL, *dealer};
    struct CARD *S12 = {'S', 12, NULL, NULL, *dealer};

    // King's
    struct CARD *C13 = {'C', 13, NULL, NULL, *dealer};
    struct CARD *D13 = {'D', 13, NULL, NULL, *dealer};
    struct CARD *H13 = {'H', 13, NULL, NULL, *dealer};
    struct CARD *S13 = {'S', 13, NULL, NULL, *dealer};

    C1->next = D1;
    D1->next = H1;
    H1->next = S1;
    S1->next = C2;

    D1->prev = C1;
    H1->prev = D1;
    S1->prev = H1;
    C2->prev = S1;

    C2->next = D1;
    D2->next = H1;
    H2->next = S1;
    S2->next = C3;

    D2->prev = C2;
    H2->prev = D2;
    S2->prev = H2;
    C3->prev = S2;

    C3->next = D1;
    D3->next = H1;
    H3->next = S1;
    S3->next = C4;

    D3->prev = C3;
    H3->prev = D3;
    S3->prev = H3;
    C4->prev = S3;

    C4->next = D4;
    D4->next = H4;
    H4->next = S4;
    S4->next = C5;

    D4->prev = C4;
    H4->prev = D4;
    S4->prev = H4;
    C5->prev = S4;

    C5->next = D5;
    D5->next = H5;
    H5->next = S5;
    S5->next = C6;

    D5->prev = C5;
    H5->prev = D5;
    S5->prev = H5;
    C6->prev = S5;

    C6->next = D6;
    D6->next = H6;
    H6->next = S6;
    S6->next = C7;

    D6->prev = C6;
    H6->prev = D6;
    S6->prev = H6;
    C7->prev = S6;

    C7->next = D7;
    D7->next = H7;
    H7->next = S7;
    S7->next = C8;

    D7->prev = C7;
    H7->prev = D7;
    S7->prev = H7;
    C8->prev = S7;

    C8->next = D8;
    D8->next = H8;
    H8->next = S8;
    S8->next = C9;

    D8->prev = C8;
    H8->prev = D8;
    S8->prev = H8;
    C9->prev = S8;

    C9->next = D9;
    D9->next = H9;
    H9->next = S9;
    S9->next = C10;

    D9->prev = C9;
    H9->prev = D9;
    S9->prev = H9;
    C10->prev = S9;

    C10->next = D10;
    D10->next = H10;
    H10->next = S10;
    S10->next = C11;

    D10->prev = C10;
    H10->prev = D10;
    S10->prev = H10;
    C11->prev = S10;

    C11->next = D11;
    D11->next = H11;
    H11->next = S11;
    S11->next = C12;

    D11->prev = C11;
    H11->prev = D11;
    S11->prev = H11;
    C12->prev = S11;

    C12->next = D12;
    D12->next = H12;
    H12->next = S12;
    S12->next = C13;

    D12->prev = C12;
    H12->prev = D12;
    S12->prev = H12;
    C13->prev = S12;

    C13->next = D13;
    D13->next = H13;
    H13->next = S13;

    D13->prev = C13;
    H13->prev = D13;
    S13->prev = H13;

    dealer->first = C1;

    // Give cards to the river
    for (int i = 0; i < 5; i++)
    {
        int card = rand() % (dealer->length);
        struct CARD *temp;
        for (int i = 0; i < card; i++)
        {
            if (i == 0)
            {
                *temp = *dealer->first;
            }
            else
            {
                *temp = *temp->next;
            }
        }
        // This is incomplete
        *river->first = *temp;
        *temp->prev->next = *temp->next;
        *temp->next->prev = *temp->prev;
        dealer->length = (dealer->length) - 1;
        river->length = river->length + 1;
        temp->next = NULL;
    }

    // Give all of the players their first cards and put the 2 cards in the river
    for (int i = 0; i < players; i++)
    {
    }
}
