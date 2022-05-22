/*GUI Functions 
Worked on by: Jose Diaz | Cameron Bagheri
*/

#include "graphics.h"

GtkWidget *CreateWindow(	/* create the server window */
	int *argc,
	char **argv[])
{
    GtkWidget *Window;
    GtkWidget *VBox, *DrawArea, *Frame, *Label;
    GtkWidget *ShutdownButton;

    /* initialize the GTK libraries */
    gtk_init(argc, argv);

    /* create the main, top level window */
    Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(Window), Program);
    gtk_window_set_default_size(GTK_WINDOW(Window), 260, 280);
    gtk_container_set_border_width (GTK_CONTAINER(Window), 10);

    /* overall vertical arrangement in the window */
    VBox = gtk_vbox_new(FALSE, 10);
    gtk_container_add(GTK_CONTAINER(Window), VBox);

    /* on the top, put a drawing area */
    DrawArea = gtk_drawing_area_new();
    gtk_widget_set_size_request(DrawArea, 250, 250);
    gtk_container_add(GTK_CONTAINER(VBox), DrawArea);

    /* in the middle, a frame with the digital display of the time */
    Frame = gtk_frame_new("Time and Date");
    gtk_container_add(GTK_CONTAINER(VBox), Frame);
    Label = gtk_label_new("n/a");
    gtk_container_add(GTK_CONTAINER(Frame), Label);

    /* on the bottom, a button to shutdown the server and quit */
    ShutdownButton = gtk_button_new_with_label("Shutdown Server and Quit");
    gtk_container_add(GTK_CONTAINER(VBox), ShutdownButton);

    /* make sure that everything becomes visible */
    gtk_widget_show_all(Window);

    /* connect drawing area with function to render a clock */
    g_signal_connect(DrawArea, "expose_event",
			G_CALLBACK(DrawAreaExposed), NULL);

    /* make clock widgets public */
    DigitalClock = (GtkLabel*)Label;
    AnalogClock = DrawArea;

    /* connect window-close with function terminating this server */
    g_signal_connect(Window, "destroy",
			G_CALLBACK(ShutdownClicked), NULL);

    /* connect shutdown button with function terminating this server */
    g_signal_connect(ShutdownButton, "clicked",
                        G_CALLBACK(ShutdownClicked), NULL);

    return(Window);
}