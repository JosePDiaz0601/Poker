GUI Functions 
Worked on by: Jose Diaz | Cameron Bagheri

#include "graphics.h"
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
    GtkWidget *DrawArea, *Frame, *Label; //*VBox
    GtkWidget *MYBOX;
    GtkWidget *ShutdownButton;
    GtkWidget *Card1, *Card2, *Card3;

    /* initialize the GTK libraries */
    gtk_init(argc, argv);

    /* create the main, top level window */
    Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(Window), Program);
    gtk_window_set_default_size(GTK_WINDOW(Window), 800, 800);
    gtk_container_set_border_width (GTK_CONTAINER(Window), 10);

    /* overall vertical arrangement in the window */
    //VBox = gtk_vbox_new(FALSE, 10);
   // gtk_container_add(GTK_CONTAINER(Window), VBox);

    MYBOX = gtk_hbox_new(FALSE, 3);
    gtk_container_add(GTK_CONTAINER(Window), MYBOX);

    Card1 = gtk_button_new_with_label("Card1");
    gtk_container_add(GTK_CONTAINER(MYBOX), Card1);

    Card2 = gtk_button_new_with_label("Card2");
    gtk_container_add(GTK_CONTAINER(MYBOX), Card2);

    Card3 = gtk_button_new_with_label("Card3");
    gtk_container_add(GTK_CONTAINER(MYBOX), Card3);

    /* on the top, put a drawing area */
    DrawArea = gtk_drawing_area_new();
    gtk_widget_set_size_request(DrawArea, 150, 250);
    gtk_container_add(GTK_CONTAINER(MYBOX), DrawArea);

    /* in the middle, a frame with the digital display of the time */
    Frame = gtk_frame_new("Poker Time");
    gtk_container_add(GTK_CONTAINER(MYBOX), Frame);
    Label = gtk_label_new("n/a");
    gtk_container_add(GTK_CONTAINER(Frame), Label);

    /* on the bottom, a button to shutdown the server and quit */
    ShutdownButton = gtk_button_new_with_label("QUIT POKER");
    gtk_container_add(GTK_CONTAINER(MYBOX), ShutdownButton);

    /* make sure that everything becomes visible */
    gtk_widget_show_all(Window);