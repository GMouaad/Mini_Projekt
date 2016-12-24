/*
 * functions.c
 *
 *  Created on: Dec 11, 2016
 *      Author: MouaadGssair
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"prototypes.h"

#define Datenbank "Datenbank.txt"

typedef struct user_data{
	FILE * fp;
	char datum[100];
	char Benutzername[50];
	float gewicht;
	float groesse;
	float bmi;
	int alter;
}user;

// Menu Display in der main Funktion

void display_menu(){

	printline(50);
	printf("\n						%s						\n",datetime());
	printf("\n**************************BMI Rechner**************************\n");
	printf("\n*********			Wählen Sie ein platform 		*************\n");
	printf("\n*********Login : Drücken Sie L-Taste ein*******\n"
			//"*********Neue Benutzer :Drücken Sie N-Taste ein*******\n"
			"*********Überprüfen Sie die Benutzerhistorie: Drücken Sie H-Taste ein******\n"
			"*********\t\tExit:Drücken Sie X-Taste ein\t\t******** ");
	printline(50);
	char nav;
	scanf("%c",&nav);
	navigator(nav);
	//user_data new_user ;
	//new_user(&new_user);
	printline(50);

}

// Ausgabe der Benutzerdaten aufm Monitor

void read_file(){
		FILE *fp;
		fp = fopen("Datenbank.txt" , "r");
		if ((fp = fopen("Datenbank.txt", "r")) == NULL)
		{
			printf("Error! beim Öffnen des Dateis");
			fflush(stdout);
		    // Programm beendet, wenn Der Dateizeiger NULL zurückgibt.
			//exit(1);
			//Zurück zu der Hauptmenu ::
			display_meny();
		}
		char singleLine[200];
		while(!feof(fp)){
			fgets(singleLine,200,fp);
			puts(singleLine);
		}

		fclose(fp);
}

// Zum Speichern der neuen Benutzerdaten

void edit_file( ){   // *fp
	FILE *fp;
	printf("Geben Sie bitte ihre  Name , Gewicht , Groesse und Alter ");
	fflush(stdout);
	user new_user;
	scanf("%s%f%f%i",&new_user.Benutzername, &new_user.gewicht, &new_user.groesse, &new_user.alter);
	//new_user.datum=datetime(); // last time the user registered
	f_bmi(&new_user);
	fp = fopen("Datenbank.txt","w+");
	if ((fp = fopen("Datenbank.txt", "r")) == NULL)
			{
				printf("Error! beim Öffnen des Dateis");
			    // Programm beendet, wenn Der Dateizeiger NULL zurückgibt.
				//exit(1);
				//Zurück zu der Hauptmenu ::
				display_menu();
			}
	fseek(fp,1,SEEK_END);
	new_user.bmi = new_user.gewicht / (new_user.groesse * new_user.groesse);
		printf("loading..");
	fprintf(fp,"\n\t%s\nBenutzername:\t %s\nGewicht:\t%f\nGroesse:\t%f\n"
			   "Alter : %i \nBody Mass Index:\t%f\n",
			   datetime(), new_user.Benutzername , new_user.gewicht,
			   new_user.groesse,new_user.alter, new_user.bmi);
	fflush(stdout);
	int i=50;

	   for(i = 0;i < 50;i++) {
	      fprintf(fp,"=");
		  fflush(stdout);
	   }

	   fprintf(fp,"=\n");
	   fflush(stdout);
	fclose(fp);
}

//

void navigator(char nav){
	int passwort = 0;
	switch(nav){
		case 'H':{
			printf("\n****Herzlich Willkommen in dem BMI Rechner****\n");
			fflush(stdout);
			printf("Geben Sie den Passwort bitte ein\n");
			fflush(stdout);
			scanf("%i",passwort);
			if (passwort == 1111)
				read_file();
			}break;
		case 'L' :{
			printf("\n****Herzlich Willkommen in dem BMI Rechner****\n");
			printf("Geben Sie den Passwort bitte ein\n");
			fflush(stdout);
			scanf("%i",passwort);
			if (passwort == 1111)
				edit_file();

			};break;
		//case 'N':new_user();break;
		default : printf("Falsche Taste eingedrückt, versuchen Sie noch mal");display_menu();
	}
}

// BMI Rechner-Funtion

/*int f_bmi(user user)
{
	user.bmi = user.gewicht / (user.groesse * user.groesse);
	printf("loading..");
	return 0;

}
*/

// Zeichnen einer horizontale Zeile

void printline(int count) {
   int i;

   for(i = 0;i <count-1;i++) {
      printf("=");
	  fflush(stdout);
   }

   printf("=\n");
   fflush(stdout);
}

// Funktion zum Einlesen des Datums des Systems
char *datetime()
{
    char *array = (char*)malloc(sizeof(char)*25);
    time_t result;
    result = time(NULL);
    sprintf(array, "%s", asctime(localtime(&result)));
    array[25] = '\0';
    return array;
}
// Zum Erstellen und einlesen der neuen Benutzerdaten
/* void new_user(){
	printf("Geben Sie ihre  Name , Gewicht , Groesse ");
	fflush(stdout);
	//typedef user_data new_user ={};
	struct user_data new_user;
	scanf("%s%f%f",&new_user.name, &new_user.gewicht, &new_user.groesse);
	new_user.datum=datetime(); // last time the user registered
	FILE * fp;
	fp = fopen("%s.txt","w+",new_user.name); /////////

}*/

