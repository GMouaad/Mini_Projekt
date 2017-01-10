//
//  main.c
//  Projekt
//
//  Created by Mouaad Gssair on 06/01/2017.
//  Published on Github : https://github.com/GMouaad/Mini_Projekt.git
//  Copyright © 2017 Mouaad Gssair. All rights reserved.
/*
 * main.c
 *
 *  Created on: Dec 11, 2016
 *      Author: MouaadGssair
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"functions.h"

#define Datenbank "Datenbank.txt"

int main(int argc, char **argv)
{
    
    // Eine unendliche Schleife
    while(1){
        // Aufruf der Funktion display_menu() (s. functions.c)
        display_menu();
        printline(50);
        char x;
        printf("Drucken sie X , um dass Programm zu beenden. Sonst drücken Sie eine beliebige andere Taste");
        fflush(stdout);
        scanf("%c",&x);
        fflush(stdin);
        if(x == 'X')
            exit(1);
        // Programm beendet, wenn der Benutzer X-Taste drückt.
    }
    
    
    return 0;
}

