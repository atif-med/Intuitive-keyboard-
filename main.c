#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "prediction.h"

GtkBuilder *builder; // GTK Builder variable
GtkWidget *window;
GtkWidget *supprimer;
GtkWidget *ajouter;
GtkWidget *entry;
GtkWidget *entry2;
GtkTextBuffer *buffer;
GtkTextIter start,end;
GtkWidget *prediction1;
GtkWidget *prediction2;
GtkWidget *prediction3;
GtkWidget *button3;


HashTable hashTab;
HashTable hashTab2;



const char* dictionaryFileName = "dosscomp.txt";
const char* dictionaryFileName2 = "dictiofarnc.txt";

void supprimer_clicked(GtkButton *b);
void entry1_changed(GtkEntry *e);
void button3_clicked(GtkButton *b);

void supprimer_clicked(GtkButton *b){
    char texte[13];
    strcpy(texte,gtk_entry_get_text(entry));
    supprimer_mot("dosscomp.txt",texte);
    //char text[20] = "test";
    gtk_button_set_label(supprimer,texte);

}


void entry1_changed(GtkEntry *e){
    Element *p1=(Element*) malloc(sizeof(Element));
    Element *p2=(Element*) malloc(sizeof(Element));
    Element *p3=(Element*) malloc(sizeof(Element));
    char tmp[30];
    strcpy(tmp,gtk_entry_get_text(e));
    if(strlen(tmp)>=1){
        fonct_comp(&hashTab,dictionaryFileName,&hashTab2,dictionaryFileName2,p1,p2,p3,tmp);
        if(p1!=NULL && p2!=NULL && p3!=NULL){
            gtk_label_set_label(prediction1,p1->value);
            gtk_label_set_label(prediction2,p2->value);
            gtk_label_set_label(prediction3,p3->value);
        }
        
    }
    else{
        gtk_label_set_label(prediction1," ");
        gtk_label_set_label(prediction2," ");
        gtk_label_set_label(prediction3," ");
     }
    
}


void button3_clicked(GtkButton *b){
  GtkWidget *popup_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  GtkWidget *text_view = gtk_text_view_new();
  gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
  GtkTextBuffer *buffer;
  buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
  gtk_text_buffer_set_text(buffer,   ShowPersonalDictionnary(&hashTab), -1);
  gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
  gtk_window_set_default_size(GTK_WINDOW(popup_window), 300, 570);
  gtk_window_set_title(GTK_WINDOW(popup_window), "Dictionnaire Personnel");
    // Add a label to the popup window
  GtkWidget *label = gtk_label_new("This is a popup window!\ntest");
  gtk_container_add(GTK_CONTAINER(popup_window), scrolled_window);

    // Show the popup window
  gtk_widget_show_all(popup_window);
  //free(buffer);
}




int main(int argc, char *argv[])

{
    
   
    initializeHashTable(&hashTab2);
    initializeHashTable(&hashTab);
    //
    
   

    gtk_init(&argc, &argv);

    //builder = gtk_builder_new();

    builder = gtk_builder_new_from_file("appliprediction.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "Window"));
    supprimer = GTK_WIDGET(gtk_builder_get_object(builder, "supprimer"));
    ajouter = GTK_WIDGET(gtk_builder_get_object(builder, "ajouter"));
    entry = GTK_WIDGET(gtk_builder_get_object(builder, "entry"));
    button3 = GTK_WIDGET(gtk_builder_get_object(builder, "button3"));
    entry2 = GTK_WIDGET(gtk_builder_get_object(builder, "entry2"));
    prediction1 = GTK_WIDGET(gtk_builder_get_object(builder, "prediction1"));
    prediction2 = GTK_WIDGET(gtk_builder_get_object(builder, "prediction2"));
    prediction3 = GTK_WIDGET(gtk_builder_get_object(builder, "prediction3"));

    
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_builder_connect_signals(builder,NULL);


    GdkColor color;
    //color.red = 0;
    //color.green = 0x4242;
    //color.blue = 0xd7d7;
    //gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

    g_signal_connect(G_OBJECT(supprimer),"clicked", G_CALLBACK(supprimer_clicked),NULL);
    g_signal_connect(G_OBJECT(entry2), "changed", G_CALLBACK(entry1_changed), NULL);
    g_signal_connect(G_OBJECT(button3), "clicked", G_CALLBACK(button3_clicked), NULL);

    gtk_widget_show(window);
    gtk_main();
    return 0;
}
