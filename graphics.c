GUI Functions 
Worked on by: Jose Diaz | Cameron Bagheri

#include "graphics.h"


time_t seconds;

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


    GtkWidget *Window;

    GtkWidget *NewLabel;
    GtkWidget *foldButton, *callButton, *raiseButton;
    GtkWidget *table;
    GtkWidget *pCard1, *pCard2, *pCard3, *pCard4, *pCard5;
    GtkWidget *tCard1, *tCard2, *tCard3, *tCard4, *tCard5;

    GtkWidget *tLabel, *pLabel; //just player and table label


    /* initialize the GTK libraries */


    gtk_init(argc, argv);


    Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(Window), Program);
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

if (receivedSuit == 'C' && receivedType == 2){pCard1 = gtk_image_new_from_file ("./bin/2_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 3){pCard1 = gtk_image_new_from_file ("./bin/3_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 4){pCard1 = gtk_image_new_from_file ("./bin/4_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 5){pCard1 = gtk_image_new_from_file ("./bin/5_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 6){pCard1 = gtk_image_new_from_file ("./bin/6_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 7){pCard1 = gtk_image_new_from_file ("./bin/7_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 8){pCard1 = gtk_image_new_from_file ("./bin/8_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 9){pCard1 = gtk_image_new_from_file ("./bin/9_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 10){pCard1 = gtk_image_new_from_file ("./bin/10_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 11){pCard1 = gtk_image_new_from_file ("./bin/jack_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 12){pCard1 = gtk_image_new_from_file ("./bin/queen_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 13){pCard1 = gtk_image_new_from_file ("./bin/king_of_clubs.png");}
if (receivedSuit == 'C' && receivedType == 14){pCard1 = gtk_image_new_from_file ("./bin/ace_of_clubs.png");}

if (receivedSuit == 'S' && receivedType == 2){pCard1 = gtk_image_new_from_file ("./bin/2_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 3){pCard1 = gtk_image_new_from_file ("./bin/3_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 4){pCard1 = gtk_image_new_from_file ("./bin/4_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 5){pCard1 = gtk_image_new_from_file ("./bin/5_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 6){pCard1 = gtk_image_new_from_file ("./bin/6_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 7){pCard1 = gtk_image_new_from_file ("./bin/7_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 8){pCard1 = gtk_image_new_from_file ("./bin/8_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 9){pCard1 = gtk_image_new_from_file ("./bin/9_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 10){pCard1 = gtk_image_new_from_file ("./bin/10_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 11){pCard1 = gtk_image_new_from_file ("./bin/jack_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 12){pCard1 = gtk_image_new_from_file ("./bin/queen_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 13){pCard1 = gtk_image_new_from_file ("./bin/king_of_spades.png");}
if (receivedSuit == 'S' && receivedType == 14){pCard1 = gtk_image_new_from_file ("./bin/ace_of_spades.png");}

if (receivedSuit == 'H' && receivedType == 2){pCard1 = gtk_image_new_from_file ("./bin/2_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 3){pCard1 = gtk_image_new_from_file ("./bin/3_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 4){pCard1 = gtk_image_new_from_file ("./bin/4_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 5){pCard1 = gtk_image_new_from_file ("./bin/5_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 6){pCard1 = gtk_image_new_from_file ("./bin/6_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 7){pCard1 = gtk_image_new_from_file ("./bin/7_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 8){pCard1 = gtk_image_new_from_file ("./bin/8_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 9){pCard1 = gtk_image_new_from_file ("./bin/9_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 10){pCard1 = gtk_image_new_from_file ("./bin/10_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 11){pCard1 = gtk_image_new_from_file ("./bin/jack_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 12){pCard1 = gtk_image_new_from_file ("./bin/queen_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 13){pCard1 = gtk_image_new_from_file ("./bin/king_of_hearts.png");}
if (receivedSuit == 'H' && receivedType == 14){pCard1 = gtk_image_new_from_file ("./bin/ace_of_hearts.png");}

if (receivedSuit == 'D' && receivedType == 2) {pCard1 = gtk_image_new_from_file ("./bin/2_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 3){pCard1 = gtk_image_new_from_file ("./bin/3_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 4){pCard1 = gtk_image_new_from_file ("./bin/4_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 5){pCard1 = gtk_image_new_from_file ("./bin/5_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 6){pCard1 = gtk_image_new_from_file ("./bin/6_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 7){pCard1 = gtk_image_new_from_file ("./bin/7_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 8){pCard1 = gtk_image_new_from_file ("./bin/8_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 9){pCard1 = gtk_image_new_from_file ("./bin/9_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 10){pCard1 = gtk_image_new_from_file ("./bin/10_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 11){pCard1 = gtk_image_new_from_file ("./bin/jack_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 12){pCard1 = gtk_image_new_from_file ("./bin/queen_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 13){pCard1 = gtk_image_new_from_file ("./bin/king_of_diamonds.png");}
if (receivedSuit == 'D' && receivedType == 14){pCard1 = gtk_image_new_from_file ("./bin/ace_of_diamonds.png")}

    
  /*  pCard1 = gtk_image_new_from_file ("./bin/handsome.png");
    pCard2 = gtk_image_new_from_file ("./bin/handsome2.png");
    pCard3 = gtk_image_new_from_file ("./bin/3_of_clubs.png");
    pCard4 = gtk_image_new_from_file ("./bin/3_of_clubs.png");
    pCard5 = gtk_image_new_from_file ("./bin/3_of_clubs.png");
    
    tCard1 = gtk_image_new_from_file ("./bin/3_of_clubs.png");
    tCard2 = gtk_image_new_from_file ("./bin/3_of_clubs.png");
    tCard3 = gtk_image_new_from_file ("./bin/3_of_clubs.png");
    tCard4 = gtk_image_new_from_file ("./bin/3_of_clubs.png");
    tCard5 = gtk_image_new_from_file ("./bin/3_of_clubs.png");    */

    gtk_table_attach(table,tCard1,0,1,1,3,2,2,10,10);
    gtk_table_attach(table,tCard2,1,2,1,3,2,2,10,10);
    gtk_table_attach(table,tCard3,2,3,1,3,2,2,10,10);
    gtk_table_attach(table,tCard4,3,4,1,3,2,2,10,10);
    gtk_table_attach(table,tCard5,4,5,1,3,2,2,10,10);

    gtk_table_attach(table,NewLabel,0,1,0,1,2,2,10,10);

    gtk_table_attach(table,pCard1,0,1,4,6,2,2,10,10);
    gtk_table_attach(table,pCard2,1,2,4,6,2,2,10,10);
    gtk_table_attach(table,pCard3,2,3,4,6,2,2,10,10);
    gtk_table_attach(table,pCard4,3,4,4,6,2,2,10,10);
    gtk_table_attach(table,pCard5,4,5,4,6,2,2,10,10);

    gtk_table_attach(table,tLabel,2,3,0,1,2,2,0,0);
    gtk_table_attach(table,pLabel,2,3,3,4,2,2,0,0);

    gtk_table_attach(table,foldButton,5,6,2,3,2,2,10,10);
    gtk_table_attach(table,raiseButton,5,6,3,4,2,2,10,10);
    gtk_table_attach(table,callButton,5,6,4,5,2,2,10,10);


    gtk_widget_show_all(Window);



    /* connect window-close with function terminating this server */
    g_signal_connect(Window, "destroy",
			G_CALLBACK(ShutdownClicked), NULL);


    return(Window);
} /* end of CreateWindow */

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