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
#include"prototypes.h"

#define Datenbank "Datenbank.txt"

int main(int argc, char **argv)
{


	while(1){

		display_menu();
		printline(50);
		char x;
		printf("Drucken sie X , um dass Programm zu beenden. Sonst drücken Sie eine beliebige andere Taste");
		fflush(stdout);
		scanf("%c",&x);
		fflush(stdin);
		if(x == 'X')
			break;
		}
	

	return 0;
}
