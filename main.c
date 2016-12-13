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



int main(int argc, char **argv)
{


	while(1){

		display_menu();
		//display_callender();
		printline(50);
		char q;
		printf("Drucken sie Q , um dass Programm zu beenden. Sonst drücken Sie eine beliebige andere Taste");
		fflush(stdout);
		scanf("%c",&q);
		fflush(stdin);
		if(q == 'q')
			break;
		}
	

	return 0;
}
