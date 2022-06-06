//GUI Functions
//Worked on by: Jose Diaz | Cameron Bagheri
 //
#include "graphics.h"
 
//const char *Program = NULL;
 
int check = 0;
time_t seconds;
time_t t;
 int awesome;
int random;
 
   GtkWidget *Window, *layout;
  
   GtkWidget *background; //poker table background image
 
   GtkWidget *NewLabel;
 
GtkWidget *foldButton, *callButton, *raiseButton;
   GtkWidget *table;
   GtkWidget *pCard1, *pCard2;
   GtkWidget *o1Card1, *o1Card2, *o2Card1, *o2Card2, *o3Card1, *o3Card2, *o4Card1, *o4Card2, *o5Card1, *o5Card2; //opponents cards
   GtkWidget *tCard1, *tCard2, *tCard3, *tCard4, *tCard5;
 
   GtkWidget *tLabel, *pLabel; //just player and table label
 
 
GtkWidget *CreateWindow(    /* create the server window */
   int *argc,
   char **argv[])
{
 
   gtk_init(argc, argv);
   printf("test");
   Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_default_size(GTK_WINDOW(Window), 1920, 1080);
   gtk_window_set_position(GTK_WINDOW(Window), GTK_WIN_POS_CENTER);
   gtk_window_maximize(GTK_WINDOW(Window));
 
   layout = gtk_layout_new(NULL, NULL);
   gtk_container_add(GTK_CONTAINER (Window), layout);
   gtk_widget_show(layout);
 
   background = gtk_image_new_from_file("./images/background_poker.png");
   gtk_layout_put(GTK_LAYOUT(layout), background, 0, 0);
 
   foldButton = gtk_button_new_with_label("Fold");
   gtk_layout_put(GTK_LAYOUT(layout), foldButton, 1150, 550);
   gtk_widget_set_size_request(foldButton, 80, 35);
 
   raiseButton = gtk_button_new_with_label("raise");
   gtk_layout_put(GTK_LAYOUT(layout), raiseButton, 1150, 600);
   gtk_widget_set_size_request(raiseButton, 80, 35);
 
   callButton = gtk_button_new_with_label("call");
   gtk_layout_put(GTK_LAYOUT(layout), callButton, 1150, 650);
   gtk_widget_set_size_request(callButton, 80, 35);
 
   //CARD DISPLAYS
   // *TEMPORARY* ASSIGNING ALL OPPONENTS TO BLANK CARDS
 
if(check == 0){
   o1Card1 = gtk_image_new_from_file ("./images/poker_card.png");
   o1Card2 = gtk_image_new_from_file ("./images/poker_card.png");
   o2Card1 = gtk_image_new_from_file ("./images/poker_card.png");
   o2Card2 = gtk_image_new_from_file ("./images/poker_card.png");
   o3Card1 = gtk_image_new_from_file ("./images/poker_card.png");
   o3Card2 = gtk_image_new_from_file ("./images/poker_card.png");
   o4Card1 = gtk_image_new_from_file ("./images/poker_card.png");
   o4Card2 = gtk_image_new_from_file ("./images/poker_card.png");
   o5Card1 = gtk_image_new_from_file ("./images/poker_card.png");
   o5Card2 = gtk_image_new_from_file ("./images/poker_card.png");
 
   tCard1 = gtk_image_new_from_file ("./images/poker_card.png");
   tCard2 = gtk_image_new_from_file ("./images/poker_card.png");
   tCard3 = gtk_image_new_from_file ("./images/poker_card.png");
   tCard4 = gtk_image_new_from_file ("./images/poker_card.png");
   tCard5 = gtk_image_new_from_file ("./images/poker_card.png");
 
   pCard1 = gtk_image_new_from_file ("./images/poker_card.png");
   pCard2 = gtk_image_new_from_file ("./images/poker_card.png");
   check++;
}
 
   gtk_layout_put(GTK_LAYOUT(layout), o1Card1, 100, 50);
   gtk_widget_set_size_request(o1Card1, 100, 145);
   gtk_layout_put(GTK_LAYOUT(layout), o1Card2, 150, 50);
   gtk_widget_set_size_request(o2Card2, 100, 145);
 
   gtk_layout_put(GTK_LAYOUT(layout), o2Card1, 300, 50);
   gtk_widget_set_size_request(o2Card1, 100, 145);
   gtk_layout_put(GTK_LAYOUT(layout), o2Card2, 350, 50);
   gtk_widget_set_size_request(o2Card2, 100, 145);
 
   gtk_layout_put(GTK_LAYOUT(layout), o3Card1, 500, 50);
   gtk_widget_set_size_request(o3Card1, 100, 145);
   gtk_layout_put(GTK_LAYOUT(layout), o3Card2, 550, 50);
   gtk_widget_set_size_request(o3Card2, 100, 145);
 
   gtk_layout_put(GTK_LAYOUT(layout), o4Card1, 700, 50);
   gtk_widget_set_size_request(o4Card1, 100, 145);
   gtk_layout_put(GTK_LAYOUT(layout), o4Card2, 750, 50);
   gtk_widget_set_size_request(o4Card2, 100, 145);
 
   gtk_layout_put(GTK_LAYOUT(layout), o5Card1, 900, 50);
   gtk_widget_set_size_request(o5Card1, 100, 145);
   gtk_layout_put(GTK_LAYOUT(layout), o5Card2, 950, 50);
   gtk_widget_set_size_request(o5Card2, 100, 145);
 
   gtk_layout_put(GTK_LAYOUT(layout), tCard1, 150, 300);
   gtk_widget_set_size_request(tCard1, 100, 145);
   gtk_layout_put(GTK_LAYOUT(layout), tCard2, 350, 300);
   gtk_widget_set_size_request(tCard2, 100, 145);
   gtk_layout_put(GTK_LAYOUT(layout), tCard3, 550, 300);
   gtk_widget_set_size_request(tCard3, 100, 145);
   gtk_layout_put(GTK_LAYOUT(layout), tCard4, 750, 300);
   gtk_widget_set_size_request(tCard4, 100, 145);
   gtk_layout_put(GTK_LAYOUT(layout), tCard5, 950, 300);
   gtk_widget_set_size_request(tCard5, 100, 145);
 
   gtk_layout_put(GTK_LAYOUT(layout), pCard1, 450, 600);
   gtk_widget_set_size_request(pCard1, 100, 145);
   gtk_layout_put(GTK_LAYOUT(layout), pCard2, 850, 600);
   gtk_widget_set_size_request(pCard2, 100, 145);
  
 
   g_signal_connect_swapped(G_OBJECT(Window), "destroy",
   G_CALLBACK(gtk_main_quit), NULL);
 
   gtk_widget_show_all(Window);
 
 
   return 0;
 
}
 
void makeCards(){
   //gtk_image_clear (pCard1);
   //gtk_image_clear (pCard2);
   printf("\nEntered Make Cards %c %c\n", your1CardSuit, your1CardType);
   if(your1CardSuit == 'C'){
       switch(your1CardType){
 
           case  '2' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/2_of_clubs.png");
           break;
 
           case  '3' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/3_of_clubs.png");
           break;
 
           case '4' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/4_of_clubs.png");
           break;
 
           case '5' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/5_of_clubs.png");
           break;
 
           case  '6' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/6_of_clubs.png");
           break;
 
           case '7' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/7_of_clubs.png");
           break;
 
           case  '8' :
           printf("\nEntered");
          gtk_image_set_from_file(pCard1, "./images/8_of_clubs.png");
           break;
 
           case '9' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/9_of_clubs.png");
           break;
 
           case  'T' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/10_of_clubs.png");
           break;
 
           case  'J' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/jack_of_clubs2.png");
           break;
 
           case  'Q' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/queen_of_clubs2.png");
           break;
 
           case 'K' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/king_of_clubs2.png");
           break;
 
           case  'A' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/ace_of_clubs.png");
           break;
 
           default:
           printf("Somehow couldn't get the right cards? This is Clubs"); }
                  
           }if(your1CardSuit == 'H'){
           switch(your1CardType){
 
           case  '2' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/2_of_hearts.png");
           break;
 
           case '3' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/3_of_hearts.png");
           break;
 
           case  '4' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/4_of_hearts.png");
           break;
 
           case  '5' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/5_of_hearts.png");
           break;
 
           case '6' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/6_of_hearts.png");
           break;
 
           case  '7' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/7_of_hearts.png");
           break;
 
           case  '8' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/8_of_hearts.png");
           break;
 
           case  '9' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/9_of_hearts.png");
           break;
 
           case 'T' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/10_of_hearts.png");
           break;
 
           case 'J' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/jack_of_hearts2.png");
           break;
 
           case 'Q' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/queen_of_hearts2.png");
           break;
 
           case 'K' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/king_of_hearts2.png");
           break;
 
           case  'A' :
           printf("\nEntered");
           gtk_image_set_from_file(pCard1, "./images/ace_of_hearts.png");
           break;
 
           default:
           printf("Somehow couldn't get the right cards? This is hearts");
                         }
 
       }if(your1CardSuit == 'D'){
           switch(your1CardType){
 
           case  '2' :
           gtk_image_set_from_file(pCard1, "./images/2_of_diamonds.png");
           break;
 
           case  '3' :
           gtk_image_set_from_file(pCard1, "./images/3_of_diamonds.png");
           break;
 
           case  '4' :
           gtk_image_set_from_file(pCard1, "./images/4_of_diamonds.png");
           break;
 
           case  '5' :
           gtk_image_set_from_file(pCard1, "./images/5_of_diamonds.png");
           break;
 
           case '6' :
           gtk_image_set_from_file(pCard1, "./images/6_of_diamonds.png");
           break;
 
           case  '7' :
           gtk_image_set_from_file(pCard1, "./images/7_of_diamonds.png");
           break;
 
           case  '8' :
           gtk_image_set_from_file(pCard1, "./images/8_of_diamonds.png");
           break;
 
           case  '9' :
           gtk_image_set_from_file(pCard1, "./images/9_of_diamonds.png");
           break;
 
           case  'T' :
           gtk_image_set_from_file(pCard1, "./images/10_of_diamonds.png");
           break;
 
           case  'J' :
           gtk_image_set_from_file(pCard1, "./images/jack_of_diamonds2.png");
           break;
 
           case 'Q' :
           gtk_image_set_from_file(pCard1, "./images/queen_of_diamonds2.png");
           break;
 
           case  'K' :
           gtk_image_set_from_file(pCard1, "./images/king_of_diamonds2.png");
           break;
 
           case  'A' :
           gtk_image_set_from_file(pCard1, "./images/ace_of_diamonds.png");
           break;
 
           default:
           printf("Somehow couldn't get the right cards? This is diamonds");
                         }
       }
       if(your1CardSuit == 'S'){
           switch(your1CardType){
 
           case  '2' :
           gtk_image_set_from_file(pCard1, "./images/2_of_spades.png");
           break;
 
           case  '3' :
           gtk_image_set_from_file(pCard1, "./images/3_of_spades.png");
           break;
 
           case  '4' :
           gtk_image_set_from_file(pCard1, "./images/4_of_spades.png");
           break;
 
           case  '5' :
           gtk_image_set_from_file(pCard1, "./images/5_of_spades.png");
           break;
 
           case  '6' :
           gtk_image_set_from_file(pCard1, "./images/6_of_spades.png");
           break;
 
           case '7' :
           gtk_image_set_from_file(pCard1, "./images/7_of_spades.png");
           break;
 
           case  '8' :
           gtk_image_set_from_file(pCard1, "./images/8_of_spades.png");
           break;
 
           case '9' :
           gtk_image_set_from_file(pCard1, "./images/9_of_spades.png");
           break;
 
           case 'T' :
           gtk_image_set_from_file(pCard1, "./images/10_of_spades.png");
           break;
 
           case 'J' :
           gtk_image_set_from_file(pCard1, "./images/jack_of_spades2.png");
           break;
 
           case 'Q' :
           gtk_image_set_from_file(pCard1, "./images/queen_of_spades2.png");
           break;
 
           case 'K' :
           gtk_image_set_from_file(pCard1, "./images/king_of_spades2.png");
           break;
 
           case 'A' :
           gtk_image_set_from_file(pCard1, "./images/ace_of_spades.png");
           break;
 
           default:
           printf("Somehow couldn't get the right cards? This is spades");
                         }
 
 
 
 
       }
   if(your2CardSuit == 'C'){
       switch(your2CardType){
 
           case  '2' :
           gtk_image_set_from_file(pCard2, "./images/2_of_clubs.png");
           break;
 
           case  '3' :
           gtk_image_set_from_file(pCard2, "./images/3_of_clubs.png");
           break;
 
           case  '4' :
           gtk_image_set_from_file(pCard2, "./images/4_of_clubs.png");
           break;
 
           case  '5' :
           gtk_image_set_from_file(pCard2, "./images/5_of_clubs.png");
           break;
 
           case  '6' :
           gtk_image_set_from_file(pCard2, "./images/6_of_clubs.png");
           break;
 
           case  '7' :
           gtk_image_set_from_file(pCard2, "./images/7_of_clubs.png");
           break;
 
           case '8' :
           gtk_image_set_from_file(pCard2, "./images/8_of_clubs.png");
           break;
 
           case  '9' :
           gtk_image_set_from_file(pCard2, "./images/9_of_clubs.png");
           break;
 
           case  'T' :
           gtk_image_set_from_file(pCard2, "./images/10_of_clubs.png");
           break;
 
           case  'J' :
           gtk_image_set_from_file(pCard2, "./images/jack_of_clubs2.png");
           break;
 
           case 'Q' :
           gtk_image_set_from_file(pCard2, "./images/queen_of_clubs2.png");
           break;
 
           case  'K' :
           gtk_image_set_from_file(pCard2, "./images/king_of_clubs2.png");
           break;
 
           case  'A' :
           gtk_image_set_from_file(pCard2, "./images/ace_of_clubs.png");
           break;
 
           default:
           printf("Somehow couldn't get the right cards? This is Clubs");
                         }
   }
           if(your2CardSuit == 'H'){
           switch(your2CardType){
 
           case '2' :
           gtk_image_set_from_file(pCard2, "./images/2_of_hearts.png");
           break;
 
           case  '3' :
           gtk_image_set_from_file(pCard2, "./images/3_of_hearts.png");
           break;
 
           case  '4' :
           gtk_image_set_from_file(pCard2, "./images/4_of_hearts.png");
           break;
 
           case  '5' :
           gtk_image_set_from_file(pCard2, "./images/5_of_hearts.png");
           break;
 
           case  '6' :
           gtk_image_set_from_file(pCard2, "./images/6_of_hearts.png");
           break;
 
           case  '7' :
           gtk_image_set_from_file(pCard2, "./images/7_of_hearts.png");
           break;
 
           case  '8' :
           gtk_image_set_from_file(pCard2, "./images/8_of_hearts.png");
           break;
 
           case  '9' :
           gtk_image_set_from_file(pCard2, "./images/9_of_hearts.png");
           break;
 
           case  'T' :
           gtk_image_set_from_file(pCard2, "./images/10_of_hearts.png");
           break;
 
           case  'J' :
           gtk_image_set_from_file(pCard2, "./images/jack_of_hearts2.png");
           break;
 
           case 'Q' :
           gtk_image_set_from_file(pCard2, "./images/queen_of_hearts2.png");
           break;
 
           case  'K' :
           gtk_image_set_from_file(pCard2, "./images/king_of_hearts2.png");
           break;
 
           case  'A' :
           gtk_image_set_from_file(pCard2, "./images/ace_of_hearts.png");
           break;
 
           default:
           printf("Somehow couldn't get the right cards? This is hearts");
                         }
           }
       if(your2CardSuit == 'D'){
           switch(your2CardType){
 
           case '2' :
           gtk_image_set_from_file(pCard2, "./images/2_of_diamonds.png");
           break;
 
           case '3' :
           gtk_image_set_from_file(pCard2, "./images/3_of_diamonds.png");
           break;
 
           case '4' :
           gtk_image_set_from_file(pCard2, "./images/4_of_diamonds.png");
           break;
 
           case '5' :
           gtk_image_set_from_file(pCard2, "./images/5_of_diamonds.png");
           break;
 
           case '6' :
           gtk_image_set_from_file(pCard2, "./images/6_of_diamonds.png");
           break;
 
           case '7' :
           gtk_image_set_from_file(pCard2, "./images/7_of_diamonds.png");
           break;
 
           case '8' :
           gtk_image_set_from_file(pCard2, "./images/8_of_diamonds.png");
           break;
 
           case '9' :
           gtk_image_set_from_file(pCard2, "./images/9_of_diamonds.png");
           break;
 
           case 'T' :
           gtk_image_set_from_file(pCard2, "./images/10_of_diamonds.png");
           break;
 
           case 'J' :
           gtk_image_set_from_file(pCard2, "./images/jack_of_diamonds2.png");
           break;
 
           case 'Q' :
           gtk_image_set_from_file(pCard2, "./images/queen_of_diamonds2.png");
           break;
 
           case 'K' :
           gtk_image_set_from_file(pCard2, "./images/king_of_diamonds2.png");
           break;
 
           case 'A' :
           gtk_image_set_from_file(pCard2, "./images/ace_of_diamonds.png");
           break;
 
           default:
           printf("Somehow couldn't get the right cards? This is diamonds");
                         }
 
       }if(your2CardSuit == 'S'){
           switch(your2CardType)
       {
 
           case '2' :
           gtk_image_set_from_file(pCard2, "./images/2_of_spades.png");
           break;
 
           case '3' :
           gtk_image_set_from_file(pCard2, "./images/3_of_spades.png");
           break;
 
           case '4' :
           gtk_image_set_from_file(pCard2, "./images/4_of_spades.png");
           break;
 
           case '5' :
           gtk_image_set_from_file(pCard2, "./images/5_of_spades.png");
           break;
 
           case '6' :
           gtk_image_set_from_file(pCard2, "./images/6_of_spades.png");
           break;
 
           case '7' :
           gtk_image_set_from_file(pCard2, "./images/7_of_spades.png");
           break;
 
           case  '8' :
           gtk_image_set_from_file(pCard2, "./images/8_of_spades.png");
           break;
 
           case  '9' :
           gtk_image_set_from_file(pCard2, "./images/9_of_spades.png");
           break;
 
           case  'T' :
           gtk_image_set_from_file(pCard2, "./images/10_of_spades.png");
           break;
 
           case  'J' :
           gtk_image_set_from_file(pCard2, "./images/jack_of_spades2.png");
           break;
 
           case  'Q' :
           gtk_image_set_from_file(pCard2, "./images/queen_of_spades2.png");
           break;
 
           case  'K' :
           gtk_image_set_from_file(pCard2, "./images/king_of_spades2.png");
           break;
 
           case 'A' :
           gtk_image_set_from_file(pCard2, "./images/ace_of_spades.png");
           break;
 
           default:
           printf("Somehow couldn't get the right cards? This is spades");
           }
       }
   gtk_layout_put(GTK_LAYOUT(layout), pCard1, 450, 600);
   gtk_widget_set_size_request(pCard1, 100, 145);
   gtk_layout_put(GTK_LAYOUT(layout), pCard2, 850, 600);
   gtk_widget_set_size_request(pCard2, 100, 145);
 
       printf("\nExit Make Cards\n");
       return;
}
      
 
 
 
 
 
 
 
 
void UpdateWindow(void)    
{
 
  
   while(gtk_events_pending())
   {
 
   gtk_main_iteration();
 
   }
}

