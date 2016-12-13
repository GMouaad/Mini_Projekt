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
	char name[50];
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

		fp = fopen("data.txt" , "r");
		char singleLine[200];
		while(!feof(fp)){
			fgets(singleLine,200,fp);
			puts(singleLine);
		}


		fclose(fp);
}

// Zum Speichern der neuen Benutzerdaten
void edit_file(user_data){   // *fp
	FILE * fp;
	fp = fopen("data.txt","w+");
	fseek(fp,1,SEEK_END);
	fputs(user_data);

	fclose(fp);
}

// Zum Erstellen und einlesen der neuen Benutzerdaten
void new_user(typedef user_data new_user){
	printf("Geben Sie ihre  Name , Gewicht , Groesse ");
	fflush(stdout);
	//typedef user_data new_user ={};
	scanf("%s%f%f",&new_user.name, &new_user.gewicht, &new_user.groesse);
	new_user.datum=datetime(); // last time the user registered
}

// Menu Display in der main Funktion
void display_menu(){

	printline(50);
	printf("\n						%s						\n",datetime());
	printf("\n**************************BMI Rechner**************************\n");
	printf("\n*********			Wählen Sie ein platform 		*************\n");
	printf("\n*********Login : Drücken Sie L-Taste ein*******\n*********Neue Benutzer :Drücken Sie N-Taste ein*******\n");
	char nav;
	scanf("%c",&nav);
	navigator();
	user_data new_user ;
	new_user(&new_user);
	printline(50);

}
void navigator(char nav){

	switch(nav){
		case 'L':;
		case 'N':new_user();
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
