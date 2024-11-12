#include <gtk/gtk.h>

static void on_activate(GtkApplication *app) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "CayLauncher");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6); 
    gtk_widget_set_margin_start(box, 12);
    gtk_widget_set_margin_end(box, 12);
    gtk_widget_set_margin_top(box, 12);
    gtk_widget_set_margin_bottom(box, 12);

    GtkWidget *header = gtk_header_bar_new();
    gtk_window_set_titlebar(GTK_WINDOW(window), header);

    GtkWidget *label = gtk_label_new("CayLauncher");
    gtk_widget_add_css_class(label, "title-4");

    GtkWidget *button = gtk_button_new_with_label("Click Me!");
    gtk_widget_add_css_class(button, "suggested-action");

    gtk_box_append(GTK_BOX(box), label);
    gtk_box_append(GTK_BOX(box), button);

    gtk_widget_set_margin_top(button, 12);
    gtk_window_set_child(GTK_WINDOW(window), box);
    gtk_widget_show(window);
}

int main(int argc, char *argv[]) {
    g_setenv("GTK_THEME", "win32", TRUE);

    GtkApplication *app = gtk_application_new("com.example.hello", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    
    g_object_unref(app);
    return status;
}