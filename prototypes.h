/*
 * prototypes.h
 *
 *  Created on: Dec 11, 2016
 *      Author: MouaadGssair
 */
#ifndef Datenbank
#define Datenbank "Datenbank.txt"

#endif

typedef struct user_data{
	char File_name[100];
	char datum[100];
	char Benutzername[50];
	unsigned int passwort;
	unsigned int alter;
	float gewicht;
	float groesse;
	float bmi;

}user;


#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_


void display();
void display_menu();
void read_file();
void edit_file( );
void navigator(char nav);
void * new_user(void);
void f_bmi(user user);
void printline(int count);
char *datetime();
char * create_file( user new_user, char * File_name);
char file_search(char *name);
//display_callender();

#endif /* PROTOTYPES_H_ */


