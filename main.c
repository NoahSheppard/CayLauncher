#include <gtk/gtk.h>

static void on_activate(GtkApplication *app) {
    // Create a new window
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Hello GTK4");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Create a box for vertical layout with more Windows-like spacing
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);  // Reduced spacing
    gtk_widget_set_margin_start(box, 12);
    gtk_widget_set_margin_end(box, 12);
    gtk_widget_set_margin_top(box, 12);
    gtk_widget_set_margin_bottom(box, 12);

    // Create a header bar (more native-looking title bar)
    GtkWidget *header = gtk_header_bar_new();
    gtk_window_set_titlebar(GTK_WINDOW(window), header);

    // Create widgets with more platform-native styling
    GtkWidget *label = gtk_label_new("Welcome to GTK4!");
    gtk_widget_add_css_class(label, "title-4");  // Use system font

    // Create a button with platform styling
    GtkWidget *button = gtk_button_new_with_label("Click Me!");
    gtk_widget_add_css_class(button, "suggested-action");  // Give it platform-native prominence

    // Add widgets to box
    gtk_box_append(GTK_BOX(box), label);
    gtk_box_append(GTK_BOX(box), button);

    // Add some spacing between widgets
    gtk_widget_set_margin_top(button, 12);

    // Set the box as the window's child
    gtk_window_set_child(GTK_WINDOW(window), box);

    // Show the window
    gtk_widget_show(window);
}

int main(int argc, char *argv[]) {
    // Set theme-related environment variables
    g_setenv("GTK_THEME", "adw-gtk3", TRUE);  // For Windows theme
    // Alternative themes:
    //g_setenv("GTK_THEME", "adw-gtk3", TRUE);  // For macOS-like theme
    // g_setenv("GTK_THEME", "Adwaita", TRUE);   // For GNOME/modern look

    // Create a new application
    GtkApplication *app = gtk_application_new("com.example.hello", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    
    // Run the application
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    
    // Clean up
    g_object_unref(app);
    return status;
}