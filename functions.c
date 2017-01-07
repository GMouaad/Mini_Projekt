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
#define KEY 1111

/*
 * typedef struct user_data{
	char File_name[100];
	char datum[100];
	char Benutzername[50];
	unsigned int passwort;
	unsigned int alter;
	float gewicht;
	float groesse;
	float bmi;

}user;
*/
// Menu Display in der main Funktion

void display_menu(){

	printline(50);
	printf("\n						%s						\n",datetime());
	printf("\n**************************BMI Rechner**************************\n");
	printf("\n*********			Wählen Sie ein platform 		*************\n");
	printf("\n*********Login : Drücken Sie L-Taste ein*******\n"
			"*********Neue Benutzer :Drücken Sie N-Taste ein*******\n"
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

void read_file(char * File){
		FILE *fp;
		fp = fopen("Datenbank.txt" , "r");
		if ((fp = fopen("Datenbank.txt", "r")) == NULL)
		{
			printf("Error! beim Öffnen des Dateis");
			fflush(stdout);
		    // Programm beendet, wenn Der Dateizeiger NULL zurückgibt.
			//exit(1);
			//Zurück zu der Hauptmenu ::
			display_menu();
		}
		char singleLine[200];
		while(!feof(fp)){
			fgets(singleLine,200,fp);
			puts(singleLine);
		}

		fclose(fp);
}

// Zum Speichern der neuen Benutzerdaten

void edit_file(user new_user ){   // *fp
	// File pointer zu dem Datenbank file
	FILE *fp_bank;
  	printf("Geben Sie ihre  Gewicht , Groesse und Alter ");
	fflush(stdout);
	scanf("%f%f%i", &new_user.gewicht, &new_user.groesse, &new_user.alter);
	fflush(stdout);
	//new_user.datum=datetime(); // last time the user registered
	//f_bmi(new_user);
	new_user.bmi = new_user.gewicht / (new_user.groesse * new_user.groesse);
	fp_bank = fopen("Datenbank.txt","w+");
	if ((fp_bank = fopen("Datenbank.txt", "r")) == NULL)
			{
				printf("Error! beim Öffnen des Dateis");
			    // Programm beendet, wenn Der Dateizeiger NULL zurückgibt.
				//exit(1);
				//Zurück zu der Hauptmenu ::
				display_menu();
			}
	fseek(fp_bank,1,SEEK_END);
	printf("loading..");
	fprintf(fp_bank,"\n\t%s\nBenutzername:\t %s\nGewicht:\t%f\nGroesse:\t%f\n"
			   "Alter : %i \nBody Mass Index:\t%f\n",
			   datetime(), new_user.Benutzername , new_user.gewicht,
			   new_user.groesse,new_user.alter, new_user.bmi);
	fflush(stdout);
	int i=50;

	for(i = 0;i < 50;i++) {
		fprintf(fp_bank,"=");
		fflush(stdout);
	   }

	   fprintf(fp_bank,"=\n");
	   fflush(stdout);
	fclose(fp_bank);

	// File pointer zu dem userfile
	FILE * fp_user;
	fp_user = fopen(new_user.File_name,"w+");
		if ((fp_user = fopen(new_user.File_name, "r")) == NULL)
				{
					printf("Error! beim Öffnen des Dateis");
				    // Programm beendet, wenn Der Dateizeiger NULL zurückgibt.
					//exit(1);
					//Zurück zu der Hauptmenu ::
					display_menu();
				}
		fseek(fp_user,1,SEEK_END);
		new_user.bmi = new_user.gewicht / (new_user.groesse * new_user.groesse);
		printf("loading..");
		fprintf(fp_user,"\n\t%s\nBenutzername:\t %s\nGewicht:\t%f\nGroesse:\t%f\n"
				   "Alter : %i \nBody Mass Index:\t%f\n",
				   datetime(), new_user.Benutzername , new_user.gewicht,
				   new_user.groesse,new_user.alter, new_user.bmi);
		fflush(stdout);

		for(i = 0;i < 50;i++) {
		      fprintf(fp_user,"=");
			  fflush(stdout);
		   }

		   fprintf(fp_user,"=\n");
		   fflush(stdout);
		fclose(fp_user);
}

//

void navigator(char nav){
	int passwort = 0;
	switch(nav){
		case 'H':
			{
			char name[50], File_name[50];
			printf("\n****Herzlich Willkommen in dem BMI Rechner****\n");
			printf("Geben Sie ihre Name bitte ein\n");
			scanf("%s",name);
			file_search(name);
			printf("Geben Sie den Passwort bitte ein\n");
			fflush(stdout);
			scanf("%i",&passwort);
			if (passwort == KEY)
				read_file(File_name);
			// ruft die Funktion read_file() , Um den Verlauf des Programms anzuzeigen
			}
			break;

		case 'N':{
			printline(50);
			printf("\n****Herzlich Willkommen in dem BMI Rechner****\n");
			new_user();
			printline(50);
			}
			break;
		default : printf("Falsche Taste eingedrückt, versuchen Sie noch mal");display_menu();
		// Error
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

void printline(int count)
{
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

 void * new_user(void)
 {
	user new_user ;
	char *File_name;
	printline(50);
  	printf("Geben Sie ein  Benutzername und Passwort ");
	scanf("%s%i",&new_user.Benutzername, &new_user.passwort);
	//new_user.datum=datetime(); // last time the user registered
	create_file(new_user,File_name);
	edit_file(new_user);
	return 0;
	 /////////

}

char * create_file( user new_user, char * File_name)
{
	//char File_name[0x100];
	File_name[0x100]=new_user.Benutzername;
	snprintf(File_name, sizeof(File_name), "%s.txt", new_user.Benutzername);
	FILE *fp = fopen(File_name, "w");
	printf("Loading..");
	if ((fp = fopen(File_name, "r")) == NULL)
			printf("Error! beim Öffnen des Dateis");
	fclose(fp);
	return File_name;
}
char file_search(char *name)
{
	char File_name[0x100];
	snprintf(File_name, sizeof(File_name), "%s.txt", name);
	printf("Opening %s.txt\n",name);
	return File_name;
}
