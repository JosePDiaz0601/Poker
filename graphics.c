//GUI Functions 
//Worked on by: Jose Diaz | Cameron Bagheri

#include "graphics.h"

//const char *Program = NULL;

time_t seconds;
time_t t;

int random;

    GtkWidget *Window;

    GtkWidget *NewLabel;

GtkWidget *foldButton, *callButton, *raiseButton;
    GtkWidget *table;
    GtkWidget *pCard1, *pCard2;
    GtkWidget *tCard1, *tCard2, *tCard3, *tCard4, *tCard5;

    GtkWidget *tLabel, *pLabel; //just player and table label

/*


	int *argc,
	char **argv[])
{
    GtkWidget *Window;
    GtkWidget *VBox, *DrawArea, *Frame, *Label, *PlayerCard1, *PlayerCard2, *PlayerCard3, *PlayerCard4, *PlayerCard5,
              *TableCard1, *TableCard2, *TableCard3, *TableCard4, *TableCard5;
    GtkWidget *ShutdownButton;

    
    gtk_init(argc, argv);

   
    Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(Window), Program);
    gtk_window_set_default_size(GTK_WINDOW(Window), 260, 280);
    gtk_container_set_border_width (GTK_CONTAINER(Window), 10);

    
    VBox = gtk_vbox_new(FALSE, 10);
    gtk_container_add(GTK_CONTAINER(Window), VBox);

   
    DrawArea = gtk_drawing_area_new();
    gtk_widget_set_size_request(DrawArea, 250, 250);
    gtk_container_add(GTK_CONTAINER(VBox), DrawArea);

    
    Frame = gtk_frame_new("Time and Date");
    gtk_container_add(GTK_CONTAINER(VBox), Frame);
    Label = gtk_label_new("n/a");
    gtk_container_add(GTK_CONTAINER(Frame), Label);
    
    
    ShutdownButton = gtk_button_new_with_label("Shutdown Server and Quit");
    gtk_container_add(GTK_CONTAINER(VBox), ShutdownButton);

    
    gtk_widget_show_all(Window);

   
    g_signal_connect(DrawArea, "expose_event",
			G_CALLBACK(DrawAreaExposed), NULL);


    DigitalClock = (GtkLabel*)Label;
    AnalogClock = DrawArea;

    
    g_signal_connect(Window, "destroy",
			G_CALLBACK(ShutdownClicked), NULL);

    
    g_signal_connect(ShutdownButton, "clicked",
                        G_CALLBACK(ShutdownClicked), NULL);

    return(Window);
} 
*/
GtkWidget *CreateWindow(	/* create the server window */
	int *argc,
	char **argv[])
{
    



    

    /* initialize the GTK libraries */


    gtk_init(argc, argv);


    Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //gtk_window_set_title(GTK_WINDOW(Window), Program);
    gtk_window_set_default_size(GTK_WINDOW(Window),1000, 1000);
    gtk_container_set_border_width (GTK_CONTAINER(Window), 0);

    foldButton = gtk_button_new_with_label("fold");
    raiseButton = gtk_button_new_with_label("raise");
    callButton = gtk_button_new_with_label("call");


    table = gtk_table_new (6, 6, FALSE); //creation of the table that will be the windows ONLY child widget. We should update one of the 6 to be N eventually.
    gtk_container_add (GTK_CONTAINER (Window), table);
    gtk_table_resize (table, 20,20);

    tLabel = gtk_label_new("Table's Cards");
    pLabel = gtk_label_new("Player's Cards");
    NewLabel = gtk_label_new("Poker");
        return(Window);
} /* end of CreateWindow */

void makeCards(char* RecvBuf){
srand(time(NULL));

random = rand() % 13 + 1;
printf("\n%s %d %c %c\n", RecvBuf, random, RecvBuf[0], RecvBuf[2]);


if (RecvBuf[0] == 'C'){

    if (random == 1){
        tCard1 = gtk_image_new_from_file ("./images/ace_of_clubs.png");}
    if (random == 2){
        tCard1 = gtk_image_new_from_file ("./images/2_of_clubs.png");}
    if (random == 3){
        tCard1 = gtk_image_new_from_file ("./images/3_of_clubs.png");}
    if (random == 4){
        tCard1 = gtk_image_new_from_file ("./images/4_of_clubs.png");}
    if (random == 5){
        tCard1 = gtk_image_new_from_file ("./images/5_of_clubs.png");}
    if (random == 6){
        tCard1 = gtk_image_new_from_file ("./images/6_of_clubs.png");}
    if (random == 7){
        tCard1 = gtk_image_new_from_file ("./images/7_of_clubs.png");}
    if (random == 8){
        tCard1 = gtk_image_new_from_file ("./images/8_of_clubs.png");}
    if (random == 9){
        tCard1 = gtk_image_new_from_file ("./images/9_of_clubs.png");}
    if (random == 10){
        tCard1 = gtk_image_new_from_file ("./images/10_of_clubs.png");}
    if (random == 11){
        tCard1 = gtk_image_new_from_file ("./images/jack_of_clubs.png");}
    if (random == 12){
        tCard1 = gtk_image_new_from_file ("./images/queen_of_clubs.png");}
    if (random == 13){
        tCard1 = gtk_image_new_from_file ("./images/king_of_clubs.png");}
            }
random = rand() % 13 + 1;
    if (RecvBuf[2] == 'C'){
    if (random == 1){
        tCard2 = gtk_image_new_from_file ("./images/ace_of_clubs.png");}
    if (random == 2){
        tCard2 = gtk_image_new_from_file ("./images/2_of_clubs.png");}
    if (random == 3){
        tCard2 = gtk_image_new_from_file ("./images/3_of_clubs.png");}
    if (random == 4){
        tCard2 = gtk_image_new_from_file ("./images/4_of_clubs.png");}
    if (random == 5){
        tCard2 = gtk_image_new_from_file ("./images/5_of_clubs.png");}
    if (random == 6){
        tCard2 = gtk_image_new_from_file ("./images/6_of_clubs.png");}
    if (random == 7){
        tCard2 = gtk_image_new_from_file ("./images/7_of_clubs.png");}
    if (random == 8){
        tCard2 = gtk_image_new_from_file ("./images/8_of_clubs.png");}
    if (random == 9){
        tCard2 = gtk_image_new_from_file ("./images/9_of_clubs.png");}
    if (random == 10){
        tCard2 = gtk_image_new_from_file ("./images/10_of_clubs.png");}
    if (random == 11){
        tCard2 = gtk_image_new_from_file ("./images/jack_of_clubs.png");}
    if (random == 12){
        tCard2 = gtk_image_new_from_file ("./images/queen_of_clubs.png");}
    if (random == 13){
        tCard2 = gtk_image_new_from_file ("./images/king_of_clubs.png");}
            }
    if (RecvBuf[4] == 'C'){
random = rand() % 13 + 1;
    if (random == 1){
        tCard3 = gtk_image_new_from_file ("./images/ace_of_clubs.png");}
    if (random == 2){
        tCard3 = gtk_image_new_from_file ("./images/2_of_clubs.png");}
    if (random == 3){
        tCard3 = gtk_image_new_from_file ("./images/3_of_clubs.png");}
    if (random == 4){
        tCard3 = gtk_image_new_from_file ("./images/4_of_clubs.png");}
    if (random == 5){
        tCard3 = gtk_image_new_from_file ("./images/5_of_clubs.png");}
    if (random == 6){
        tCard3 = gtk_image_new_from_file ("./images/6_of_clubs.png");}
    if (random == 7){
        tCard3 = gtk_image_new_from_file ("./images/7_of_clubs.png");}
    if (random == 8){
        tCard3 = gtk_image_new_from_file ("./images/8_of_clubs.png");}
    if (random == 9){
        tCard3 = gtk_image_new_from_file ("./images/9_of_clubs.png");}
    if (random == 10){
        tCard3 = gtk_image_new_from_file ("./images/10_of_clubs.png");}
    if (random == 11){
        tCard3 = gtk_image_new_from_file ("./images/jack_of_clubs.png");}
    if (random == 12){
        tCard3 = gtk_image_new_from_file ("./images/queen_of_clubs.png");}
    if (random == 13){
        tCard3 = gtk_image_new_from_file ("./images/king_of_clubs.png");}
            }
random = rand() % 13 + 1;
    if (RecvBuf[6] == 'C'){
    if (random == 1){
        tCard4 = gtk_image_new_from_file ("./images/ace_of_clubs.png");}
    if (random == 2){
        tCard4 = gtk_image_new_from_file ("./images/2_of_clubs.png");}
    if (random == 3){
        tCard4 = gtk_image_new_from_file ("./images/3_of_clubs.png");}
    if (random == 4){
        tCard4 = gtk_image_new_from_file ("./images/4_of_clubs.png");}
    if (random == 5){
        tCard4 = gtk_image_new_from_file ("./images/5_of_clubs.png");}
    if (random == 6){
        tCard4 = gtk_image_new_from_file ("./images/6_of_clubs.png");}
    if (random == 7){
        tCard4 = gtk_image_new_from_file ("./images/7_of_clubs.png");}
    if (random == 8){
        tCard4 = gtk_image_new_from_file ("./images/8_of_clubs.png");}
    if (random == 9){
        tCard4 = gtk_image_new_from_file ("./images/9_of_clubs.png");}
    if (random == 10){
        tCard4 = gtk_image_new_from_file ("./images/10_of_clubs.png");}
    if (random == 11){
        tCard4 = gtk_image_new_from_file ("./images/jack_of_clubs.png");}
    if (random == 12){
        tCard4 = gtk_image_new_from_file ("./images/queen_of_clubs.png");}
    if (random == 13){
        tCard4 = gtk_image_new_from_file ("./images/king_of_clubs.png");}
            }
random = rand() % 13 + 1;
    if (RecvBuf[8] == 'C'){
    if (random == 1){
        tCard5 = gtk_image_new_from_file ("./images/ace_of_clubs.png");}
    if (random == 2){
        tCard5 = gtk_image_new_from_file ("./images/2_of_clubs.png");}
    if (random == 3){
        tCard5 = gtk_image_new_from_file ("./images/3_of_clubs.png");}
    if (random == 4){
        tCard5 = gtk_image_new_from_file ("./images/4_of_clubs.png");}
    if (random == 5){
        tCard5 = gtk_image_new_from_file ("./images/5_of_clubs.png");}
    if (random == 6){
        tCard5 = gtk_image_new_from_file ("./images/6_of_clubs.png");}
    if (random == 7){
        tCard5 = gtk_image_new_from_file ("./images/7_of_clubs.png");}
    if (random == 8){
        tCard5 = gtk_image_new_from_file ("./images/8_of_clubs.png");}
    if (random == 9){
        tCard5 = gtk_image_new_from_file ("./images/9_of_clubs.png");}
    if (random == 10){
        tCard5 = gtk_image_new_from_file ("./images/10_of_clubs.png");}
    if (random == 11){
        tCard5 = gtk_image_new_from_file ("./images/jack_of_clubs.png");}
    if (random == 12){
        tCard5 = gtk_image_new_from_file ("./images/queen_of_clubs.png");}
    if (random == 13){
        tCard5 = gtk_image_new_from_file ("./images/king_of_clubs.png");}
            }
random = rand() % 13 + 1;
    if (RecvBuf[0] == 'D'){

    if (random == 1){
        tCard1 = gtk_image_new_from_file ("./images/ace_of_diamonds.png");}
    if (random == 2){
        tCard1 = gtk_image_new_from_file ("./images/2_of_diamonds.png");}
    if (random == 3){
        tCard1 = gtk_image_new_from_file ("./images/3_of_diamonds.png");}
    if (random == 4){
        tCard1 = gtk_image_new_from_file ("./images/4_of_diamonds.png");}
    if (random == 5){
        tCard1 = gtk_image_new_from_file ("./images/5_of_diamonds.png");}
    if (random == 6){
        tCard1 = gtk_image_new_from_file ("./images/6_of_diamonds.png");}
    if (random == 7){
        tCard1 = gtk_image_new_from_file ("./images/7_of_diamonds.png");}
    if (random == 8){
        tCard1 = gtk_image_new_from_file ("./images/8_of_diamonds.png");}
    if (random == 9){
        tCard1 = gtk_image_new_from_file ("./images/9_of_diamonds.png");}
    if (random == 10){
        tCard1 = gtk_image_new_from_file ("./images/10_of_diamonds.png");}
    if (random == 11){
        tCard1 = gtk_image_new_from_file ("./images/jack_of_diamonds.png");}
    if (random == 12){
        tCard1 = gtk_image_new_from_file ("./images/queen_of_diamonds.png");}
    if (random == 13){
        tCard1 = gtk_image_new_from_file ("./images/king_of_diamonds.png");}
            }
random = rand() % 13 + 1;
    if (RecvBuf[2] == 'D'){
    if (random == 1){
        tCard2 = gtk_image_new_from_file ("./images/ace_of_diamonds.png");}
    if (random == 2){
        tCard2 = gtk_image_new_from_file ("./images/2_of_cdiamonds.png");}
    if (random == 3){
        tCard2 = gtk_image_new_from_file ("./images/3_of_diamonds.png");}
    if (random == 4){
        tCard2 = gtk_image_new_from_file ("./images/4_of_diamonds.png");}
    if (random == 5){
        tCard2 = gtk_image_new_from_file ("./images/5_of_diamonds.png");}
    if (random == 6){
        tCard2 = gtk_image_new_from_file ("./images/6_of_diamonds.png");}
    if (random == 7){
        tCard2 = gtk_image_new_from_file ("./images/7_of_diamonds.png");}
    if (random == 8){
        tCard2 = gtk_image_new_from_file ("./images/8_of_diamonds.png");}
    if (random == 9){
        tCard2 = gtk_image_new_from_file ("./images/9_of_diamonds.png");}
    if (random == 10){
        tCard2 = gtk_image_new_from_file ("./images/10_of_diamonds.png");}
    if (random == 11){
        tCard2 = gtk_image_new_from_file ("./images/jack_of_diamondspng");}
    if (random == 12){
        tCard2 = gtk_image_new_from_file ("./images/queen_of_diamonds.png");}
    if (random == 13){
        tCard2 = gtk_image_new_from_file ("./images/king_of_diamonds.png");}
            }
            random = rand() % 13 + 1;
    if (RecvBuf[4] == 'D'){

    if (random == 1){
        tCard3 = gtk_image_new_from_file ("./images/ace_of_diamonds.png");}
    if (random == 2){
        tCard3 = gtk_image_new_from_file ("./images/2_of_diamonds.png");}
    if (random == 3){
        tCard3 = gtk_image_new_from_file ("./images/3_of_diamonds.png");}
    if (random == 4){
        tCard3 = gtk_image_new_from_file ("./images/4_of_diamonds.png");}
    if (random == 5){
        tCard3 = gtk_image_new_from_file ("./images/5_of_diamonds.png");}
    if (random == 6){
        tCard3 = gtk_image_new_from_file ("./images/6_of_diamonds.png");}
    if (random == 7){
        tCard3 = gtk_image_new_from_file ("./images/7_of_diamonds.png");}
    if (random == 8){
        tCard3 = gtk_image_new_from_file ("./images/8_of_diamonds.png");}
    if (random == 9){
        tCard3 = gtk_image_new_from_file ("./images/9_of_diamonds.png");}
    if (random == 10){
        tCard3 = gtk_image_new_from_file ("./images/10_of_diamonds.png");}
    if (random == 11){
        tCard3 = gtk_image_new_from_file ("./images/jack_of_diamonds.png");}
    if (random == 12){
        tCard3 = gtk_image_new_from_file ("./images/queen_of_diamondspng");}
    if (random == 13){
        tCard3 = gtk_image_new_from_file ("./images/king_of_diamonds.png");}
            }
random = rand() % 13 + 1;
    if (RecvBuf[6] == 'D'){
    if (random == 1){
        tCard4 = gtk_image_new_from_file ("./images/ace_of_diamonds.png");}
    if (random == 2){
        tCard4 = gtk_image_new_from_file ("./images/2_of_diamonds.png");}
    if (random == 3){
        tCard4 = gtk_image_new_from_file ("./images/3_of_diamonds.png");}
    if (random == 4){
        tCard4 = gtk_image_new_from_file ("./images/4_of_diamonds.png");}
    if (random == 5){
        tCard4 = gtk_image_new_from_file ("./images/5_of_diamonds.png");}
    if (random == 6){
        tCard4 = gtk_image_new_from_file ("./images/6_of_diamonds.png");}
    if (random == 7){
        tCard4 = gtk_image_new_from_file ("./images/7_of_diamonds.png");}
    if (random == 8){
        tCard4 = gtk_image_new_from_file ("./images/8_of_diamonds.png");}
    if (random == 9){
        tCard4 = gtk_image_new_from_file ("./images/9_of_diamonds.png");}
    if (random == 10){
        tCard4 = gtk_image_new_from_file ("./images/10_of_diamonds.png");}
    if (random == 11){
        tCard4 = gtk_image_new_from_file ("./images/jack_of_diamonds.png");}
    if (random == 12){
        tCard4 = gtk_image_new_from_file ("./images/queen_of_diamonds.png");}
    if (random == 13){
        tCard4 = gtk_image_new_from_file ("./images/king_of_diamonds.png");}
            }
random = rand() % 13 + 1;
    if (RecvBuf[8] == 'D'){
    if (random == 1){
        tCard5 = gtk_image_new_from_file ("./images/ace_of_diamonds.png");}
    if (random == 2){
        tCard5 = gtk_image_new_from_file ("./images/2_of_diamonds.png");}
    if (random == 3){
        tCard5 = gtk_image_new_from_file ("./images/3_of_diamonds.png");}
    if (random == 4){
        tCard5 = gtk_image_new_from_file ("./images/4_of_diamonds.png");}
    if (random == 5){
        tCard5 = gtk_image_new_from_file ("./images/5_of_diamonds.png");}
    if (random == 6){
        tCard5 = gtk_image_new_from_file ("./images/6_of_diamonds.png");}
    if (random == 7){
        tCard5 = gtk_image_new_from_file ("./images/7_of_diamonds.png");}
    if (random == 8){
        tCard5 = gtk_image_new_from_file ("./images/8_of_diamonds.png");}
    if (random == 9){
        tCard5 = gtk_image_new_from_file ("./images/9_of_diamonds.png");}
    if (random == 10){
        tCard5 = gtk_image_new_from_file ("./images/10_of_diamonds.png");}
    if (random == 11){
        tCard5 = gtk_image_new_from_file ("./images/jack_of_diamonds.png");}
    if (random == 12){
        tCard5 = gtk_image_new_from_file ("./images/queen_of_diamonds.png");}
    if (random == 13){
        tCard5 = gtk_image_new_from_file ("./images/king_of_diamonds.png");}
            }
            random = rand() % 13 + 1;
     if (RecvBuf[0] == 'H'){
 
   if (random == 1){
       tCard1 = gtk_image_new_from_file ("./images/ace_of_hearts.png");}
   if (random == 2){
       tCard1 = gtk_image_new_from_file ("./images/2_of_hearts.png");}
   if (random == 3){
       tCard1 = gtk_image_new_from_file ("./images/3_of_hearts.png");}
   if (random == 4){
       tCard1 = gtk_image_new_from_file ("./images/4_of_hearts.png");}
   if (random == 5){
       tCard1 = gtk_image_new_from_file ("./images/5_of_hearts.png");}
   if (random == 6){
       tCard1 = gtk_image_new_from_file ("./images/6_of_hearts.png");}
   if (random == 7){
       tCard1 = gtk_image_new_from_file ("./images/7_of_hearts.png");}
   if (random == 8){
       tCard1 = gtk_image_new_from_file ("./images/8_of_hearts.png");}
   if (random == 9){
       tCard1 = gtk_image_new_from_file ("./images/9_of_hearts.png");}
   if (random == 10){
       tCard1 = gtk_image_new_from_file ("./images/10_of_hearts.png");}
   if (random == 11){
       tCard1 = gtk_image_new_from_file ("./images/jack_of_hearts.png");}
   if (random == 12){
       tCard1 = gtk_image_new_from_file ("./images/queen_of_hearts.png");}
   if (random == 13){
       tCard1 = gtk_image_new_from_file ("./images/king_of_hearts.png");}
           }
 random = rand() % 13 + 1;
   if (RecvBuf[2] == 'H'){
   if (random == 1){
       tCard2 = gtk_image_new_from_file ("./images/ace_of_hearts.png");}
   if (random == 2){
       tCard2 = gtk_image_new_from_file ("./images/2_of_chearts.png");}
   if (random == 3){
       tCard2 = gtk_image_new_from_file ("./images/3_of_hearts.png");}
   if (random == 4){
       tCard2 = gtk_image_new_from_file ("./images/4_of_hearts.png");}
   if (random == 5){
       tCard2 = gtk_image_new_from_file ("./images/5_of_hearts.png");}
   if (random == 6){
       tCard2 = gtk_image_new_from_file ("./images/6_of_hearts.png");}
   if (random == 7){
       tCard2 = gtk_image_new_from_file ("./images/7_of_hearts.png");}
   if (random == 8){
       tCard2 = gtk_image_new_from_file ("./images/8_of_hearts.png");}
   if (random == 9){
       tCard2 = gtk_image_new_from_file ("./images/9_of_hearts.png");}
   if (random == 10){
       tCard2 = gtk_image_new_from_file ("./images/10_of_hearts.png");}
   if (random == 11){
       tCard2 = gtk_image_new_from_file ("./images/jack_of_heartspng");}
   if (random == 12){
       tCard2 = gtk_image_new_from_file ("./images/queen_of_hearts.png");}
   if (random == 13){
       tCard2 = gtk_image_new_from_file ("./images/king_of_hearts.png");}
           }
           random = rand() % 13 + 1;
   if (RecvBuf[4] == 'H'){
 
   if (random == 1){
       tCard3 = gtk_image_new_from_file ("./images/ace_of_hearts.png");}
   if (random == 2){
       tCard3 = gtk_image_new_from_file ("./images/2_of_hearts.png");}
   if (random == 3){
       tCard3 = gtk_image_new_from_file ("./images/3_of_hearts.png");}
   if (random == 4){
       tCard3 = gtk_image_new_from_file ("./images/4_of_hearts.png");}
   if (random == 5){
       tCard3 = gtk_image_new_from_file ("./images/5_of_hearts.png");}
   if (random == 6){
       tCard3 = gtk_image_new_from_file ("./images/6_of_hearts.png");}
   if (random == 7){
       tCard3 = gtk_image_new_from_file ("./images/7_of_hearts.png");}
   if (random == 8){
       tCard3 = gtk_image_new_from_file ("./images/8_of_hearts.png");}
   if (random == 9){
       tCard3 = gtk_image_new_from_file ("./images/9_of_hearts.png");}
   if (random == 10){
       tCard3 = gtk_image_new_from_file ("./images/10_of_hearts.png");}
   if (random == 11){
       tCard3 = gtk_image_new_from_file ("./images/jack_of_hearts.png");}
   if (random == 12){
       tCard3 = gtk_image_new_from_file ("./images/queen_of_heartspng");}
   if (random == 13){
       tCard3 = gtk_image_new_from_file ("./images/king_of_hearts.png");}
           }
 random = rand() % 13 + 1;
   if (RecvBuf[6] == 'H'){
   if (random == 1){
       tCard4 = gtk_image_new_from_file ("./images/ace_of_hearts.png");}
   if (random == 2){
       tCard4 = gtk_image_new_from_file ("./images/2_of_hearts.png");}
   if (random == 3){
       tCard4 = gtk_image_new_from_file ("./images/3_of_hearts.png");}
   if (random == 4){
       tCard4 = gtk_image_new_from_file ("./images/4_of_hearts.png");}
   if (random == 5){
       tCard4 = gtk_image_new_from_file ("./images/5_of_hearts.png");}
   if (random == 6){
       tCard4 = gtk_image_new_from_file ("./images/6_of_hearts.png");}
   if (random == 7){
       tCard4 = gtk_image_new_from_file ("./images/7_of_hearts.png");}
   if (random == 8){
       tCard4 = gtk_image_new_from_file ("./images/8_of_hearts.png");}
   if (random == 9){
       tCard4 = gtk_image_new_from_file ("./images/9_of_hearts.png");}
   if (random == 10){
       tCard4 = gtk_image_new_from_file ("./images/10_of_hearts.png");}
   if (random == 11){
       tCard4 = gtk_image_new_from_file ("./images/jack_of_hearts.png");}
   if (random == 12){
       tCard4 = gtk_image_new_from_file ("./images/queen_of_hearts.png");}
   if (random == 13){
       tCard4 = gtk_image_new_from_file ("./images/king_of_hearts.png");}
           }
 random = rand() % 13 + 1;
   if (RecvBuf[8] == 'H'){
   if (random == 1){
       tCard5 = gtk_image_new_from_file ("./images/ace_of_hearts.png");}
   if (random == 2){
       tCard5 = gtk_image_new_from_file ("./images/2_of_hearts.png");}
   if (random == 3){
       tCard5 = gtk_image_new_from_file ("./images/3_of_hearts.png");}
   if (random == 4){
       tCard5 = gtk_image_new_from_file ("./images/4_of_hearts.png");}
   if (random == 5){
       tCard5 = gtk_image_new_from_file ("./images/5_of_hearts.png");}
   if (random == 6){
       tCard5 = gtk_image_new_from_file ("./images/6_of_hearts.png");}
   if (random == 7){
       tCard5 = gtk_image_new_from_file ("./images/7_of_hearts.png");}
   if (random == 8){
       tCard5 = gtk_image_new_from_file ("./images/8_of_hearts.png");}
   if (random == 9){
       tCard5 = gtk_image_new_from_file ("./images/9_of_hearts.png");}
   if (random == 10){
       tCard5 = gtk_image_new_from_file ("./images/10_of_hearts.png");}
   if (random == 11){
       tCard5 = gtk_image_new_from_file ("./images/jack_of_hearts.png");}
   if (random == 12){
       tCard5 = gtk_image_new_from_file ("./images/queen_of_hearts.png");}
   if (random == 13){
       tCard5 = gtk_image_new_from_file ("./images/king_of_hearts.png");}
           }
           random = rand() % 13 + 1;
 if (RecvBuf[0] == 'S'){
 
   if (random == 1){
       tCard1 = gtk_image_new_from_file ("./images/ace_of_spades.png");}
   if (random == 2){
       tCard1 = gtk_image_new_from_file ("./images/2_of_spades.png");}
   if (random == 3){
       tCard1 = gtk_image_new_from_file ("./images/3_of_spades.png");}
   if (random == 4){
       tCard1 = gtk_image_new_from_file ("./images/4_of_spades.png");}
   if (random == 5){
       tCard1 = gtk_image_new_from_file ("./images/5_of_spades.png");}
   if (random == 6){
       tCard1 = gtk_image_new_from_file ("./images/6_of_spades.png");}
   if (random == 7){
       tCard1 = gtk_image_new_from_file ("./images/7_of_spades.png");}
   if (random == 8){
       tCard1 = gtk_image_new_from_file ("./images/8_of_spades.png");}
   if (random == 9){
       tCard1 = gtk_image_new_from_file ("./images/9_of_spades.png");}
   if (random == 10){
       tCard1 = gtk_image_new_from_file ("./images/10_of_spades.png");}
   if (random == 11){
       tCard1 = gtk_image_new_from_file ("./images/jack_of_spades.png");}
   if (random == 12){
       tCard1 = gtk_image_new_from_file ("./images/queen_of_spades.png");}
   if (random == 13){
       tCard1 = gtk_image_new_from_file ("./images/king_of_spades.png");}
           }
 random = rand() % 13 + 1;
   if (RecvBuf[2] == 'S'){
   if (random == 1){
       tCard2 = gtk_image_new_from_file ("./images/ace_of_spades.png");}
   if (random == 2){
       tCard2 = gtk_image_new_from_file ("./images/2_of_cspades.png");}
   if (random == 3){
       tCard2 = gtk_image_new_from_file ("./images/3_of_spades.png");}
   if (random == 4){
       tCard2 = gtk_image_new_from_file ("./images/4_of_spades.png");}
   if (random == 5){
       tCard2 = gtk_image_new_from_file ("./images/5_of_spades.png");}
   if (random == 6){
       tCard2 = gtk_image_new_from_file ("./images/6_of_spades.png");}
   if (random == 7){
       tCard2 = gtk_image_new_from_file ("./images/7_of_spades.png");}
   if (random == 8){
       tCard2 = gtk_image_new_from_file ("./images/8_of_spades.png");}
   if (random == 9){
       tCard2 = gtk_image_new_from_file ("./images/9_of_spades.png");}
   if (random == 10){
       tCard2 = gtk_image_new_from_file ("./images/10_of_spades.png");}
   if (random == 11){
       tCard2 = gtk_image_new_from_file ("./images/jack_of_spadespng");}
   if (random == 12){
       tCard2 = gtk_image_new_from_file ("./images/queen_of_spades.png");}
   if (random == 13){
       tCard2 = gtk_image_new_from_file ("./images/king_of_spades.png");}
           }
           random = rand() % 13 + 1;
   if (RecvBuf[4] == 'S'){
 
   if (random == 1){
       tCard3 = gtk_image_new_from_file ("./images/ace_of_spades.png");}
   if (random == 2){
       tCard3 = gtk_image_new_from_file ("./images/2_of_spades.png");}
   if (random == 3){
       tCard3 = gtk_image_new_from_file ("./images/3_of_spades.png");}
   if (random == 4){
       tCard3 = gtk_image_new_from_file ("./images/4_of_spades.png");}
   if (random == 5){
       tCard3 = gtk_image_new_from_file ("./images/5_of_spades.png");}
   if (random == 6){
       tCard3 = gtk_image_new_from_file ("./images/6_of_spades.png");}
   if (random == 7){
       tCard3 = gtk_image_new_from_file ("./images/7_of_spades.png");}
   if (random == 8){
       tCard3 = gtk_image_new_from_file ("./images/8_of_spades.png");}
   if (random == 9){
       tCard3 = gtk_image_new_from_file ("./images/9_of_spades.png");}
   if (random == 10){
       tCard3 = gtk_image_new_from_file ("./images/10_of_spades.png");}
   if (random == 11){
       tCard3 = gtk_image_new_from_file ("./images/jack_of_spades.png");}
   if (random == 12){
       tCard3 = gtk_image_new_from_file ("./images/queen_of_spadespng");}
   if (random == 13){
       tCard3 = gtk_image_new_from_file ("./images/king_of_spades.png");}
           }
 random = rand() % 13 + 1;
   if (RecvBuf[6] == 'S'){
   if (random == 1){
       tCard4 = gtk_image_new_from_file ("./images/ace_of_spades.png");}
   if (random == 2){
       tCard4 = gtk_image_new_from_file ("./images/2_of_spades.png");}
   if (random == 3){
       tCard4 = gtk_image_new_from_file ("./images/3_of_spades.png");}
   if (random == 4){
       tCard4 = gtk_image_new_from_file ("./images/4_of_spades.png");}
   if (random == 5){
       tCard4 = gtk_image_new_from_file ("./images/5_of_spades.png");}
   if (random == 6){
       tCard4 = gtk_image_new_from_file ("./images/6_of_spades.png");}
   if (random == 7){
       tCard4 = gtk_image_new_from_file ("./images/7_of_spades.png");}
   if (random == 8){
       tCard4 = gtk_image_new_from_file ("./images/8_of_spades.png");}
   if (random == 9){
       tCard4 = gtk_image_new_from_file ("./images/9_of_spades.png");}
   if (random == 10){
       tCard4 = gtk_image_new_from_file ("./images/10_of_spades.png");}
   if (random == 11){
       tCard4 = gtk_image_new_from_file ("./images/jack_of_spades.png");}
   if (random == 12){
       tCard4 = gtk_image_new_from_file ("./images/queen_of_spades.png");}
   if (random == 13){
       tCard4 = gtk_image_new_from_file ("./images/king_of_spades.png");}
           }
 random = rand() % 13 + 1;

   if (RecvBuf[8] == 'S'){
   if (random == 1){
       tCard5 = gtk_image_new_from_file ("./images/ace_of_spades.png");}
   if (random == 2){
       tCard5 = gtk_image_new_from_file ("./images/2_of_spades.png");}
   if (random == 3){
       tCard5 = gtk_image_new_from_file ("./images/3_of_spades.png");}
   if (random == 4){
       tCard5 = gtk_image_new_from_file ("./images/4_of_spades.png");}
   if (random == 5){
       tCard5 = gtk_image_new_from_file ("./images/5_of_spades.png");}
   if (random == 6){
       tCard5 = gtk_image_new_from_file ("./images/6_of_spades.png");}
   if (random == 7){
       tCard5 = gtk_image_new_from_file ("./images/7_of_spades.png");}
   if (random == 8){
       tCard5 = gtk_image_new_from_file ("./images/8_of_spades.png");}
   if (random == 9){
       tCard5 = gtk_image_new_from_file ("./images/9_of_spades.png");}
   if (random == 10){
       tCard5 = gtk_image_new_from_file ("./images/10_of_spades.png");}
   if (random == 11){
       tCard5 = gtk_image_new_from_file ("./images/jack_of_spades.png");}
   if (random == 12){
       tCard5 = gtk_image_new_from_file ("./images/queen_of_spades.png");}
   if (random == 13){
       tCard5 = gtk_image_new_from_file ("./images/king_of_spades.png");}
           }


//PLAYER CARDS 

random = rand() % 13 + 1;

   if (RecvBuf[10] == 'S'){
   if (random == 1){
       pCard1 = gtk_image_new_from_file ("./images/ace_of_spades.png");}
   if (random == 2){
       pCard1 = gtk_image_new_from_file ("./images/2_of_spades.png");}
   if (random == 3){
       pCard1 = gtk_image_new_from_file ("./images/3_of_spades.png");}
   if (random == 4){
       pCard1 = gtk_image_new_from_file ("./images/4_of_spades.png");}
   if (random == 5){
       pCard1 = gtk_image_new_from_file ("./images/5_of_spades.png");}
   if (random == 6){
       pCard1 = gtk_image_new_from_file ("./images/6_of_spades.png");}
   if (random == 7){
       pCard1 = gtk_image_new_from_file ("./images/7_of_spades.png");}
   if (random == 8){
       pCard1 = gtk_image_new_from_file ("./images/8_of_spades.png");}
   if (random == 9){
       pCard1 = gtk_image_new_from_file ("./images/9_of_spades.png");}
   if (random == 10){
       pCard1 = gtk_image_new_from_file ("./images/10_of_spades.png");}
   if (random == 11){
       pCard1 = gtk_image_new_from_file ("./images/jack_of_spades.png");}
   if (random == 12){
       pCard1 = gtk_image_new_from_file ("./images/queen_of_spades.png");}
   if (random == 13){
       pCard1 = gtk_image_new_from_file ("./images/king_of_spades.png");}
           }
random = rand() % 13 + 1;
 
   if (RecvBuf[10] == 'C'){
   if (random == 1){
       pCard1 = gtk_image_new_from_file ("./images/ace_of_clubs.png");}
   if (random == 2){
       pCard1 = gtk_image_new_from_file ("./images/2_of_clubs.png");}
   if (random == 3){
       pCard1 = gtk_image_new_from_file ("./images/3_of_clubs.png");}
   if (random == 4){
       pCard1 = gtk_image_new_from_file ("./images/4_of_clubs.png");}
   if (random == 5){
       pCard1 = gtk_image_new_from_file ("./images/5_of_clubs.png");}
   if (random == 6){
       pCard1 = gtk_image_new_from_file ("./images/6_of_clubs.png");}
   if (random == 7){
       pCard1 = gtk_image_new_from_file ("./images/7_of_clubs.png");}
   if (random == 8){
       pCard1 = gtk_image_new_from_file ("./images/8_of_clubs.png");}
   if (random == 9){
       pCard1 = gtk_image_new_from_file ("./images/9_of_clubs.png");}
   if (random == 10){
       pCard1 = gtk_image_new_from_file ("./images/10_of_clubs.png");}
   if (random == 11){
       pCard1 = gtk_image_new_from_file ("./images/jack_of_clubs.png");}
   if (random == 12){
       pCard1 = gtk_image_new_from_file ("./images/queen_of_clubs.png");}
   if (random == 13){
       pCard1 = gtk_image_new_from_file ("./images/king_of_clubs.png");}
           }
random = rand() % 13 + 1;
 
   if (RecvBuf[10] == 'D'){
   if (random == 1){
       pCard1 = gtk_image_new_from_file ("./images/ace_of_diamonds.png");}
   if (random == 2){
       pCard1 = gtk_image_new_from_file ("./images/2_of_diamonds.png");}
   if (random == 3){
       pCard1 = gtk_image_new_from_file ("./images/3_of_diamonds.png");}
   if (random == 4){
       pCard1 = gtk_image_new_from_file ("./images/4_of_diamonds.png");}
   if (random == 5){
       pCard1 = gtk_image_new_from_file ("./images/5_of_diamonds.png");}
   if (random == 6){
       pCard1 = gtk_image_new_from_file ("./images/6_of_diamonds.png");}
   if (random == 7){
       pCard1 = gtk_image_new_from_file ("./images/7_of_diamonds.png");}
   if (random == 8){
       pCard1 = gtk_image_new_from_file ("./images/8_of_diamonds.png");}
   if (random == 9){
       pCard1 = gtk_image_new_from_file ("./images/9_of_diamonds.png");}
   if (random == 10){
       pCard1 = gtk_image_new_from_file ("./images/10_of_diamonds.png");}
   if (random == 11){
       pCard1 = gtk_image_new_from_file ("./images/jack_of_diamonds.png");}
   if (random == 12){
       pCard1 = gtk_image_new_from_file ("./images/queen_of_diamonds.png");}
   if (random == 13){
       pCard1 = gtk_image_new_from_file ("./images/king_of_diamonds.png");}
           }

random = rand() % 13 + 1;
 
   if (RecvBuf[10] == 'H'){
   if (random == 1){
       pCard1 = gtk_image_new_from_file ("./images/ace_of_hearts.png");}
   if (random == 2){
       pCard1 = gtk_image_new_from_file ("./images/2_of_hearts.png");}
   if (random == 3){
       pCard1 = gtk_image_new_from_file ("./images/3_of_hearts.png");}
   if (random == 4){
       pCard1 = gtk_image_new_from_file ("./images/4_of_hearts.png");}
   if (random == 5){
       pCard1 = gtk_image_new_from_file ("./images/5_of_hearts.png");}
   if (random == 6){
       pCard1 = gtk_image_new_from_file ("./images/6_of_hearts.png");}
   if (random == 7){
       pCard1 = gtk_image_new_from_file ("./images/7_of_hearts.png");}
   if (random == 8){
       pCard1 = gtk_image_new_from_file ("./images/8_of_hearts.png");}
   if (random == 9){
       pCard1 = gtk_image_new_from_file ("./images/9_of_hearts.png");}
   if (random == 10){
       pCard1 = gtk_image_new_from_file ("./images/10_of_hearts.png");}
   if (random == 11){
       pCard1 = gtk_image_new_from_file ("./images/jack_of_hearts.png");}
   if (random == 12){
       pCard1 = gtk_image_new_from_file ("./images/queen_of_hearts.png");}
   if (random == 13){
       pCard1 = gtk_image_new_from_file ("./images/king_of_hearts.png");}
           }


random = rand() % 13 + 1;

   if (RecvBuf[12] == 'S'){
   if (random == 1){
       pCard2 = gtk_image_new_from_file ("./images/ace_of_spades.png");}
   if (random == 2){
       pCard2 = gtk_image_new_from_file ("./images/2_of_spades.png");}
   if (random == 3){
       pCard2 = gtk_image_new_from_file ("./images/3_of_spades.png");}
   if (random == 4){
       pCard2 = gtk_image_new_from_file ("./images/4_of_spades.png");}
   if (random == 5){
       pCard2 = gtk_image_new_from_file ("./images/5_of_spades.png");}
   if (random == 6){
       pCard2 = gtk_image_new_from_file ("./images/6_of_spades.png");}
   if (random == 7){
       pCard2 = gtk_image_new_from_file ("./images/7_of_spades.png");}
   if (random == 8){
       pCard2 = gtk_image_new_from_file ("./images/8_of_spades.png");}
   if (random == 9){
       pCard2 = gtk_image_new_from_file ("./images/9_of_spades.png");}
   if (random == 10){
       pCard2 = gtk_image_new_from_file ("./images/10_of_spades.png");}
   if (random == 11){
       pCard2 = gtk_image_new_from_file ("./images/jack_of_spades.png");}
   if (random == 12){
       pCard2 = gtk_image_new_from_file ("./images/queen_of_spades.png");}
   if (random == 13){
       pCard2 = gtk_image_new_from_file ("./images/king_of_spades.png");}
           }
random = rand() % 13 + 1;
 
   if (RecvBuf[12] == 'C'){
   if (random == 1){
       pCard2 = gtk_image_new_from_file ("./images/ace_of_clubs.png");}
   if (random == 2){
       pCard2 = gtk_image_new_from_file ("./images/2_of_clubs.png");}
   if (random == 3){
       pCard2 = gtk_image_new_from_file ("./images/3_of_clubs.png");}
   if (random == 4){
       pCard2 = gtk_image_new_from_file ("./images/4_of_clubs.png");}
   if (random == 5){
       pCard2 = gtk_image_new_from_file ("./images/5_of_clubs.png");}
   if (random == 6){
       pCard2 = gtk_image_new_from_file ("./images/6_of_clubs.png");}
   if (random == 7){
       pCard2 = gtk_image_new_from_file ("./images/7_of_clubs.png");}
   if (random == 8){
       pCard2 = gtk_image_new_from_file ("./images/8_of_clubs.png");}
   if (random == 9){
       pCard2 = gtk_image_new_from_file ("./images/9_of_clubs.png");}
   if (random == 10){
       pCard2 = gtk_image_new_from_file ("./images/10_of_clubs.png");}
   if (random == 11){
       pCard2 = gtk_image_new_from_file ("./images/jack_of_clubs.png");}
   if (random == 12){
       pCard2 = gtk_image_new_from_file ("./images/queen_of_clubs.png");}
   if (random == 13){
       pCard2 = gtk_image_new_from_file ("./images/king_of_clubs.png");}
           }
random = rand() % 13 + 1;
 
   if (RecvBuf[12] == 'D'){
   if (random == 1){
       pCard2 = gtk_image_new_from_file ("./images/ace_of_diamonds.png");}
   if (random == 2){
       pCard2 = gtk_image_new_from_file ("./images/2_of_diamonds.png");}
   if (random == 3){
       pCard2 = gtk_image_new_from_file ("./images/3_of_diamonds.png");}
   if (random == 4){
       pCard2 = gtk_image_new_from_file ("./images/4_of_diamonds.png");}
   if (random == 5){
       pCard2 = gtk_image_new_from_file ("./images/5_of_diamonds.png");}
   if (random == 6){
       pCard2 = gtk_image_new_from_file ("./images/6_of_diamonds.png");}
   if (random == 7){
       pCard2 = gtk_image_new_from_file ("./images/7_of_diamonds.png");}
   if (random == 8){
       pCard2 = gtk_image_new_from_file ("./images/8_of_diamonds.png");}
   if (random == 9){
       pCard2 = gtk_image_new_from_file ("./images/9_of_diamonds.png");}
   if (random == 10){
       pCard2 = gtk_image_new_from_file ("./images/10_of_diamonds.png");}
   if (random == 11){
       pCard2 = gtk_image_new_from_file ("./images/jack_of_diamonds.png");}
   if (random == 12){
       pCard2 = gtk_image_new_from_file ("./images/queen_of_diamonds.png");}
   if (random == 13){
       pCard2 = gtk_image_new_from_file ("./images/king_of_diamonds.png");}
           }

random = rand() % 13 + 1;
 
   if (RecvBuf[12] == 'H'){
   if (random == 1){
       pCard2 = gtk_image_new_from_file ("./images/ace_of_hearts.png");}
   if (random == 2){
       pCard2 = gtk_image_new_from_file ("./images/2_of_hearts.png");}
   if (random == 3){
       pCard2 = gtk_image_new_from_file ("./images/3_of_hearts.png");}
   if (random == 4){
       pCard2 = gtk_image_new_from_file ("./images/4_of_hearts.png");}
   if (random == 5){
       pCard2 = gtk_image_new_from_file ("./images/5_of_hearts.png");}
   if (random == 6){
       pCard2 = gtk_image_new_from_file ("./images/6_of_hearts.png");}
   if (random == 7){
       pCard2 = gtk_image_new_from_file ("./images/7_of_hearts.png");}
   if (random == 8){
       pCard2 = gtk_image_new_from_file ("./images/8_of_hearts.png");}
   if (random == 9){
       pCard2 = gtk_image_new_from_file ("./images/9_of_hearts.png");}
   if (random == 10){
       pCard2 = gtk_image_new_from_file ("./images/10_of_hearts.png");}
   if (random == 11){
       pCard2 = gtk_image_new_from_file ("./images/jack_of_hearts.png");}
   if (random == 12){
       pCard2 = gtk_image_new_from_file ("./images/queen_of_hearts.png");}
   if (random == 13){
       pCard2 = gtk_image_new_from_file ("./images/king_of_hearts.png");}
           }


//player card 1
//player card 1
/*
char receivedSuit;
int receivedType, cardPosition;
if (receivedSuit == 'C' && receivedType == 2 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/2_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 3 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/3_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 4 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/4_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 5 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/5_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 6 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/6_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 7 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/7_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 8 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/8_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 9 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/9_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 10 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/10_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 11 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/jack_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 12 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/queen_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 13 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/king_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 14 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/ace_of_clubs.png");}

if (receivedSuit == 'S' && receivedType == 2 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/2_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 3 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/3_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 4 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/4_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 5 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/5_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 6 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/6_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 7 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/7_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 8 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/8_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 9 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/9_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 10 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/10_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 11 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/jack_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 12 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/queen_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 13 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/king_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 14 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/ace_of_spades.png");}

if (receivedSuit == 'H' && receivedType == 2 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/2_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 3 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/3_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 4 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/4_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 5 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/5_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 6 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/6_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 7 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/7_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 8 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/8_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 9 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/9_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 10 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/10_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 11 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/jack_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 12 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/queen_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 13 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/king_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 14 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/ace_of_hearts.png");}

if (receivedSuit == 'D' && receivedType == 2 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/2_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 3 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/3_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 4 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/4_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 5 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/5_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 6 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/6_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 7 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/7_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 8 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/8_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 9 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/9_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 10 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/10_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 11 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/jack_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 12 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/queen_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 13 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/king_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 14 && cardPosition == 6){pCard1 = gtk_image_new_from_file ("./images/ace_of_diamonds.png");}

//player card 2
if (receivedSuit == 'C' && receivedType == 2 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/2_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 3 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/3_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 4 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/4_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 5 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/5_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 6 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/6_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 7 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/7_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 8 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/8_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 9 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/9_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 10 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/10_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 11 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/jack_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 12 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/queen_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 13 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/king_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 14 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/ace_of_clubs.png");}

if (receivedSuit == 'S' && receivedType == 2 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/2_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 3 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/3_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 4 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/4_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 5 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/5_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 6 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/6_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 7 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/7_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 8 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/8_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 9 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/9_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 10 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/10_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 11 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/jack_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 12 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/queen_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 13 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/king_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 14 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/ace_of_spades.png");}

if (receivedSuit == 'H' && receivedType == 2 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/2_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 3 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/3_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 4 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/4_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 5 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/5_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 6 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/6_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 7 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/7_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 8 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/8_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 9 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/9_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 10 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/10_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 11 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/jack_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 12 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/queen_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 13 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/king_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 14 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/ace_of_hearts.png");}

if (receivedSuit == 'D' && receivedType == 2 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/2_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 3 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/3_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 4 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/4_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 5 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/5_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 6 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/6_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 7 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/7_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 8 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/8_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 9 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/9_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 10 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/10_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 11 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/jack_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 12 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/queen_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 13 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/king_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 14 && cardPosition == 7){pCard2 = gtk_image_new_from_file ("./images/ace_of_diamonds.png");}

//river card 1
if (receivedSuit == 'C' && receivedType == 2 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/2_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 3 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/3_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 4 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/4_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 5 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/5_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 6 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/6_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 7 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/7_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 8 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/8_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 9 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/9_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 10 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/10_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 11 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/jack_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 12 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/queen_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 13 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/king_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 14 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/ace_of_clubs.png");}

if (receivedSuit == 'S' && receivedType == 2 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/2_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 3 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/3_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 4 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/4_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 5 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/5_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 6 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/6_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 7 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/7_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 8 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/8_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 9 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/9_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 10 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/10_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 11 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/jack_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 12 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/queen_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 13 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/king_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 14 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/ace_of_spades.png");}

if (receivedSuit == 'H' && receivedType == 2 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/2_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 3 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/3_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 4 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/4_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 5 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/5_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 6 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/6_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 7 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/7_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 8 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/8_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 9 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/9_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 10 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/10_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 11 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/jack_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 12 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/queen_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 13 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/king_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 14 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/ace_of_hearts.png");}

if (receivedSuit == 'D' && receivedType == 2 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/2_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 3 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/3_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 4 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/4_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 5 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/5_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 6 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/6_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 7 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/7_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 8 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/8_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 9 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/9_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 10 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/10_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 11 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/jack_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 12 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/queen_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 13 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/king_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 14 && cardPosition == 1){tCard1 = gtk_image_new_from_file ("./images/ace_of_diamonds.png");}

//river card 2
if (receivedSuit == 'C' && receivedType == 2 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/2_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 3 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/3_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 4 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/4_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 5 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/5_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 6 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/6_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 7 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/7_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 8 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/8_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 9 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/9_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 10 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/10_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 11 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/jack_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 12 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/queen_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 13 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/king_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 14 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/ace_of_clubs.png");}

if (receivedSuit == 'S' && receivedType == 2 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/2_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 3 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/3_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 4 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/4_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 5 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/5_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 6 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/6_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 7 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/7_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 8 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/8_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 9 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/9_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 10 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/10_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 11 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/jack_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 12 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/queen_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 13 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/king_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 14 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/ace_of_spades.png");}

if (receivedSuit == 'H' && receivedType == 2 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/2_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 3 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/3_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 4 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/4_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 5 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/5_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 6 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/6_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 7 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/7_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 8 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/8_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 9 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/9_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 10 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/10_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 11 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/jack_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 12 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/queen_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 13 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/king_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 14 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/ace_of_hearts.png");}

if (receivedSuit == 'D' && receivedType == 2 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/2_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 3 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/3_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 4 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/4_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 5 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/5_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 6 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/6_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 7 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/7_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 8 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/8_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 9 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/9_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 10 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/10_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 11 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/jack_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 12 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/queen_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 13 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/king_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 14 && cardPosition == 2){tCard2 = gtk_image_new_from_file ("./images/ace_of_diamonds.png");}

//river card 3
if (receivedSuit == 'C' && receivedType == 2 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/2_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 3 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/3_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 4 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/4_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 5 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/5_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 6 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/6_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 7 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/7_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 8 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/8_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 9 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/9_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 10 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/10_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 11 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/jack_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 12 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/queen_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 13 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/king_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 14 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/ace_of_clubs.png");}

if (receivedSuit == 'S' && receivedType == 2 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/2_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 3 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/3_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 4 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/4_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 5 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/5_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 6 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/6_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 7 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/7_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 8 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/8_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 9 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/9_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 10 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/10_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 11 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/jack_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 12 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/queen_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 13 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/king_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 14 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/ace_of_spades.png");}

if (receivedSuit == 'H' && receivedType == 2 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/2_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 3 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/3_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 4 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/4_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 5 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/5_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 6 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/6_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 7 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/7_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 8 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/8_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 9 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/9_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 10 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/10_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 11 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/jack_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 12 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/queen_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 13 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/king_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 14 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/ace_of_hearts.png");}

if (receivedSuit == 'D' && receivedType == 2 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/2_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 3 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/3_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 4 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/4_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 5 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/5_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 6 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/6_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 7 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/7_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 8 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/8_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 9 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/9_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 10 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/10_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 11 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/jack_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 12 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/queen_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 13 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/king_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 14 && cardPosition == 3){tCard3 = gtk_image_new_from_file ("./images/ace_of_diamonds.png");}

//river card 4
if (receivedSuit == 'C' && receivedType == 2 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/2_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 3 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/3_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 4 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/4_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 5 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/5_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 6 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/6_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 7 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/7_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 8 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/8_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 9 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/9_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 10 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/10_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 11 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/jack_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 12 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/queen_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 13 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/king_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 14 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/ace_of_clubs.png");}

if (receivedSuit == 'S' && receivedType == 2 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/2_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 3 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/3_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 4 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/4_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 5 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/5_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 6 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/6_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 7 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/7_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 8 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/8_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 9 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/9_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 10 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/10_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 11 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/jack_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 12 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/queen_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 13 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/king_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 14 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/ace_of_spades.png");}

if (receivedSuit == 'H' && receivedType == 2 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/2_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 3 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/3_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 4 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/4_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 5 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/5_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 6 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/6_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 7 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/7_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 8 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/8_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 9 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/9_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 10 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/10_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 11 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/jack_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 12 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/queen_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 13 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/king_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 14 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/ace_of_hearts.png");}

if (receivedSuit == 'D' && receivedType == 2 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/2_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 3 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/3_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 4 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/4_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 5 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/5_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 6 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/6_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 7 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/7_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 8 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/8_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 9 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/9_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 10 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/10_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 11 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/jack_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 12 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/queen_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 13 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/king_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 14 && cardPosition == 4){tCard4 = gtk_image_new_from_file ("./images/ace_of_diamonds.png");}

//river card 5
if (receivedSuit == 'C' && receivedType == 2 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/2_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 3 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/3_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 4 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/4_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 5 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/5_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 6 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/6_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 7 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/7_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 8 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/8_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 9 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/9_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 10 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/10_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 11 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/jack_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 12 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/queen_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 13 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/king_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 14 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/ace_of_clubs.png");}

if (receivedSuit == 'S' && receivedType == 2 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/2_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 3 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/3_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 4 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/4_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 5 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/5_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 6 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/6_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 7 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/7_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 8 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/8_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 9 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/9_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 10 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/10_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 11 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/jack_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 12 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/queen_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 13 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/king_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 14 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/ace_of_spades.png");}

if (receivedSuit == 'H' && receivedType == 2 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/2_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 3 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/3_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 4 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/4_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 5 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/5_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 6 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/6_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 7 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/7_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 8 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/8_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 9 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/9_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 10 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/10_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 11 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/jack_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 12 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/queen_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 13 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/king_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 14 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/ace_of_hearts.png");}

if (receivedSuit == 'D' && receivedType == 2 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/2_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 3 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/3_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 4 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/4_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 5 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/5_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 6 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/6_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 7 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/7_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 8 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/8_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 9 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/9_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 10 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/10_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 11 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/jack_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 12 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/queen_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 13 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/king_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 14 && cardPosition == 5){tCard5 = gtk_image_new_from_file ("./images/ace_of_diamonds.png");}
*/

/*
    pCard1 = gtk_image_new_from_file ("./images/handsome.png");
    pCard2 = gtk_image_new_from_file ("./images/handsome2.png");
    pCard3 = gtk_image_new_from_file ("./images/3_of_clubs.png");
    pCard4 = gtk_image_new_from_file ("./images/3_of_clubs.png");
    pCard5 = gtk_image_new_from_file ("./images/3_of_clubs.png");
    *//*
    tCard1 = gtk_image_new_from_file ("./images/3_of_clubs.png");
    tCard2 = gtk_image_new_from_file ("./images/3_of_clubs.png");
    tCard3 = gtk_image_new_from_file ("./images/3_of_clubs.png");
    tCard4 = gtk_image_new_from_file ("./images/3_of_clubs.png");
    tCard5 = gtk_image_new_from_file ("./images/3_of_clubs.png");    */


    //tCard1 = gtk_image_new_from_file ("./images/3_of_clubs.png");

    gtk_table_attach(table,tCard1,0,1,1,3,2,2,10,10);
    gtk_table_attach(table,tCard2,1,2,1,3,2,2,10,10);
    gtk_table_attach(table,tCard3,2,3,1,3,2,2,10,10);
    gtk_table_attach(table,tCard4,3,4,1,3,2,2,10,10);
    gtk_table_attach(table,tCard5,4,5,1,3,2,2,10,10);

    gtk_table_attach(table,NewLabel,0,1,0,1,2,2,10,10);

    gtk_table_attach(table,pCard1,0,1,4,6,2,2,10,10);
    gtk_table_attach(table,pCard2,1,2,4,6,2,2,10,10);

    gtk_table_attach(table,tLabel,2,3,0,1,2,2,0,0);
    gtk_table_attach(table,pLabel,2,3,3,4,2,2,0,0);

    gtk_table_attach(table,foldButton,5,6,2,3,2,2,10,10);
    gtk_table_attach(table,raiseButton,5,6,3,4,2,2,10,10);
    gtk_table_attach(table,callButton,5,6,4,5,2,2,10,10);


    gtk_widget_show_all(Window);

}







void UpdateWindow(void)		/* render the window on screen */
{
   /* this server has it's own main loop for handling client connections;
    * as such, it can't have the usual GUI main loop (gtk_main);
    * instead, we call this UpdateWindow function on regular basis
    */
    while(gtk_events_pending())
    {
    

	gtk_main_iteration();

    }
} /* end of UpdateWindow */