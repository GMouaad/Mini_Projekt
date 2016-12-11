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


void display()
{
	
	
	
}

void display_menu(){

}

/*
void display_Kalender(){
	int kalender[][];
}
*/
void f_bmi(){
	float gewicht;
	float groesse;
	float bmi;

	printf("Gib dein Gewicht in kg ein: ");
	scanf("%lf", &gewicht);

	printf("Gib deine Groesse in Metern ein: ");
    scanf("%lf", &groesse);

	bmi = gewicht / (groesse * groesse);
}
char datum(){
	time_t mytime;
    mytime = time(NULL);
    return (ctime(&mytime));
}
