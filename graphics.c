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

   //Test
   int p1Points = 1000;
   int p2Points = 1000;
   int p3Points = 1000;
   int p4Points = 1000;
   int p5Points = 1000;
   int p6Points = 1000;
   char* display = "";
   
   white = gtk_image_new_from_file ("./images/white_image.png");
   gtk_layout_put(GTK_LAYOUT(layout), white, 1075, 35);
   gtk_widget_set_size_request(white, 180, 150);

   //Display labels for players scores/points
   gtk_label_set_text(GTK_LABEL (player1Score), " NEW STRING"); 
   display = g_strdup_printf("Player 1 Score: %d", p1Points);
   player1Score = gtk_label_new(display);
   gtk_layout_put(GTK_LAYOUT(layout), player1Score, 1100, 40);
   gtk_widget_set_size_request(callButton, 80, 35);
   display = g_strdup_printf("Player 1 Score: %d", (p1Points-100));
   gtk_label_set_text(GTK_LABEL (player1Score), display);
   g_free(display);   

   display = g_strdup_printf("Player 2 Score: %d", p2Points); 
   player2Score = gtk_label_new(display);
   gtk_layout_put(GTK_LAYOUT(layout), player2Score, 1100, 65);
   gtk_widget_set_size_request(callButton, 80, 35);
   g_free(display);   

   display = g_strdup_printf("Player 3 Score: %d", p3Points); 
   player3Score = gtk_label_new(display);
   gtk_layout_put(GTK_LAYOUT(layout), player3Score, 1100, 90);
   gtk_widget_set_size_request(callButton, 80, 35);
   g_free(display);   

   display = g_strdup_printf("Player 4 Score: %d", p4Points); 
   player4Score = gtk_label_new(display);
   gtk_layout_put(GTK_LAYOUT(layout), player4Score, 1100, 115);
   gtk_widget_set_size_request(callButton, 80, 35);
   g_free(display);   

   display = g_strdup_printf("Player 5 Score: %d", p5Points); 
   player5Score = gtk_label_new(display);
   gtk_layout_put(GTK_LAYOUT(layout), player5Score, 1100, 140);
   gtk_widget_set_size_request(callButton, 80, 35);
   g_free(display);   

   display = g_strdup_printf("Player 6 Score: %d", p6Points); 
   player6Score = gtk_label_new(display);
   gtk_layout_put(GTK_LAYOUT(layout), player6Score, 1100, 165);
   gtk_widget_set_size_request(callButton, 80, 35);
   g_free(display);   

 
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
   
   g_signal_connect(foldButton, "clicked",
			G_CALLBACK(clientFold), NULL);
   g_signal_connect(callButton, "clicked",
			G_CALLBACK(clientCall), NULL);
   g_signal_connect(raiseButton, "clicked",
			G_CALLBACK(clientRaise), NULL);
 
   return 0;
 

 //for example, when foldbutton "clicked", we run clientFold, passing the argument NULL into it. 

 

 /*g_signal_connect(callButton, "clicked",
			G_CALLBACK(clientCall, NULL);

 g_signal_connect(raiseButton, "clicked",
			G_CALLBACK(clientRaise, NULL);*/
}


 
void makeCards(char cardSuit, char cardType, GtkWidget *Card){

   printf("\nEntered Make Cards %c %c\n", your1CardSuit, your1CardType);
   if(cardSuit == 'C'){
       switch(cardType){
 
           case  '2' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/2_of_clubs.png");
           break;
 
           case  '3' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/3_of_clubs.png");
           break;
 
           case '4' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/4_of_clubs.png");
           break;
 
           case '5' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/5_of_clubs.png");
           break;
 
           case  '6' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/6_of_clubs.png");
           break;
 
           case '7' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/7_of_clubs.png");
           break;
 
           case  '8' :
           printf("\nEntered");
          gtk_image_set_from_file(Card, "./images/8_of_clubs.png");
           break;
 
           case '9' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/9_of_clubs.png");
           break;
 
           case  'T' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/10_of_clubs.png");
           break;
 
           case  'J' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/jack_of_clubs2.png");
           break;
 
           case  'Q' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/queen_of_clubs2.png");
           break;
 
           case 'K' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/king_of_clubs2.png");
           break;
 
           case  'A' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/ace_of_clubs.png");
           break;
 
           default:
           printf("Somehow couldn't get the right cards? This is Clubs"); }
                  
           }if(cardSuit == 'H'){
           switch(cardType){
 
           case  '2' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/2_of_hearts.png");
           break;
 
           case '3' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/3_of_hearts.png");
           break;
 
           case  '4' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/4_of_hearts.png");
           break;
 
           case  '5' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/5_of_hearts.png");
           break;
 
           case '6' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/6_of_hearts.png");
           break;
 
           case  '7' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/7_of_hearts.png");
           break;
 
           case  '8' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/8_of_hearts.png");
           break;
 
           case  '9' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/9_of_hearts.png");
           break;
 
           case 'T' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/10_of_hearts.png");
           break;
 
           case 'J' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/jack_of_hearts2.png");
           break;
 
           case 'Q' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/queen_of_hearts.png");
           break;
 
           case 'K' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/king_of_hearts2.png");
           break;
 
           case  'A' :
           printf("\nEntered");
           gtk_image_set_from_file(Card, "./images/ace_of_hearts.png");
           break;
 
           default:
           printf("Somehow couldn't get the right cards? This is hearts");
                         }
 
       }if(cardSuit == 'D'){
           switch(cardType){
 
           case  '2' :
           gtk_image_set_from_file(Card, "./images/2_of_diamonds.png");
           break;
 
           case  '3' :
           gtk_image_set_from_file(Card, "./images/3_of_diamonds.png");
           break;
 
           case  '4' :
           gtk_image_set_from_file(Card, "./images/4_of_diamonds.png");
           break;
 
           case  '5' :
           gtk_image_set_from_file(Card, "./images/5_of_diamonds.png");
           break;
 
           case '6' :
           gtk_image_set_from_file(Card, "./images/6_of_diamonds.png");
           break;
 
           case  '7' :
           gtk_image_set_from_file(Card, "./images/7_of_diamonds.png");
           break;
 
           case  '8' :
           gtk_image_set_from_file(Card, "./images/8_of_diamonds.png");
           break;
 
           case  '9' :
           gtk_image_set_from_file(Card, "./images/9_of_diamonds.png");
           break;
 
           case  'T' :
           gtk_image_set_from_file(Card, "./images/10_of_diamonds.png");
           break;
 
           case  'J' :
           gtk_image_set_from_file(Card, "./images/jack_of_diamonds2.png");
           break;
 
           case 'Q' :
           gtk_image_set_from_file(Card, "./images/queen_of_diamonds.png");
           break;
 
           case  'K' :
           gtk_image_set_from_file(Card, "./images/king_of_diamonds2.png");
           break;
 
           case  'A' :
           gtk_image_set_from_file(Card, "./images/ace_of_diamonds.png");
           break;
 
           default:
           printf("Somehow couldn't get the right cards? This is diamonds");
                         }
       }
       if(cardSuit == 'S'){
           switch(cardType){
 
           case  '2' :
           gtk_image_set_from_file(Card, "./images/2_of_spades.png");
           break;
 
           case  '3' :
           gtk_image_set_from_file(Card, "./images/3_of_spades.png");
           break;
 
           case  '4' :
           gtk_image_set_from_file(Card, "./images/4_of_spades.png");
           break;
 
           case  '5' :
           gtk_image_set_from_file(Card, "./images/5_of_spades.png");
           break;
 
           case  '6' :
           gtk_image_set_from_file(Card, "./images/6_of_spades.png");
           break;
 
           case '7' :
           gtk_image_set_from_file(Card, "./images/7_of_spades.png");
           break;
 
           case  '8' :
           gtk_image_set_from_file(Card, "./images/8_of_spades.png");
           break;
 
           case '9' :
           gtk_image_set_from_file(Card, "./images/9_of_spades.png");
           break;
 
           case 'T' :
           gtk_image_set_from_file(pCard1, "./images/10_of_spades.png");
           break;
 
           case 'J' :
           gtk_image_set_from_file(Card, "./images/jack_of_spades2.png");
           break;
 
           case 'Q' :
           gtk_image_set_from_file(Card, "./images/queen_of_spades.png");
           break;
 
           case 'K' :
           gtk_image_set_from_file(Card, "./images/king_of_spades2.png");
           break;
 
           case 'A' :
           gtk_image_set_from_file(Card, "./images/ace_of_spades.png");
           break;
 
           default:
           printf("Somehow couldn't get the right cards? This is spades");
                         }}
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

