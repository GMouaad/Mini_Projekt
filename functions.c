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

typedef struct {
	char datum[10];
	char Benutzername[50];
	float gewicht;
	float groesse;
	float bmi;
}user_data;

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

// Ausgabe der Benutzerdaten aufm Monitor
void read_file(*fp){

		fp = fopen("user.txt" , "r");
		char singleLine[200];
		while(!feof(fp)){
			fgets(singleLine,200,fp);
			puts(singleLine);
		}


		fclose(fp);
}

// Zum Speichern der neuen Benutzerdaten
void edit_file( *fp ){   // *fp
	//FILE * fp;
	fp = fopen("user.txt","w+");
	fseek(fp,1,SEEK_END);
	//fputs(user);
	struct user_data user;
	fprintf("\n\t%s\nBenutzername:\t %s\nGewicht:\t%f\nGroesse:\t%f\nBody Mass Index:\t%f", user.datum, user.name , user.gewicht, user.groesse, user.bmi);
	fclose(fp);
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

// Menu Display in der main Funktion
void display_menu(){

	printline(50);
	printf("\n						%s						\n",datetime());
	printf("\n**************************BMI Rechner**************************\n");
	printf("\n*********			Wählen Sie ein platform 		*************\n");
	printf("\n*********Login : Drücken Sie L-Taste ein*******\n"
			//"*********Neue Benutzer :Drücken Sie N-Taste ein*******\n"
			"*********Check the history: Drücken Sie C-Taste ein******\n"
			"*********\t\tExit:Drücken Sie X-Taste ein\t\t******** ");
	char nav;
	scanf("%c",&nav);
	navigator();
	//user_data new_user ;
	//new_user(&new_user);
	printline(50);

}
void navigator(char nav){

	switch(nav){
		case 'L':{
			char search_name[50];
			printf("Geben Sie ihre Benutzername");
			scanf("%s",search_name);

			read_file();
		}break;
		case 'X' :
		//case 'N':new_user();break;
		default : printf("Falsche Taste eingedrückt, versuchen Sie noch mal");display_menu();
	}
}

/*
void display_Kalender(){
	int kalender[][];
}
*/

// BMI Rechner-Funtion
void f_bmi(typedef user_data user)
{


	user.bmi = user.gewicht / (user.groesse * user.groesse);
	user.datum=datetime();
	edit_file(user);
}
char *datetime()
{
    char *array = (char*)malloc(sizeof(char)*25);
    time_t result;
    result = time(NULL);
    sprintf(array, "%s", asctime(localtime(&result)));
    array[25] = '\0';
    return array;
}
