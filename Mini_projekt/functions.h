//  functions.h
//  Projekt
//
//  Created by Mouaad Gssair on 11/12/2016.
//  Copyright © 2017 Mouaad Gssair. All rights reserved.
//

#ifndef functions_h
#define functions_h

//Data structur
typedef struct user_data{
    char File_name[25];
    char datum[25];
    char Benutzername[25];
    unsigned int passwort;
    unsigned int alter;
    float gewicht;
    float groesse;
    float bmi;

}user;

void display_menu();            // Menu Display in der main Funktion
void read_file(char * File);               // Ausgabe der Benutzerdaten aufm Monitor
void edit_file(user *new_user );              // Zum Speichern der neuen Benutzerdaten in der Datei
void navigator(char nav);
void * new_user(user *new_user);           // Zum Erstellen und einlesen der neuen Benutzerdaten
void f_bmi(user user);          // BMI Rechner-Funtion
void printline(int count);      // Zeichnen einer horizontale Zeile
char *datetime();               // Funktion zum Einlesen des Datums des Systems
char *create_file( user *new_user, char * File_name); // Funktion zum Erstellen der Datei
char file_search(char *name);   // Eine Funktion , um nach der Datei zu suchen

//display_callender();

#include <stdio.h>

#endif /* functions_h */
