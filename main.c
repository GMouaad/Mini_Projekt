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



int main(void)
{
	FILE * fp ;
	fp = fopen("data.txt" , "r");
	fprintf("data file ");
	while(1){


		display_menu();
		display_callender();

		break;
		}
	
	fclose(fp);
	return 0;
}
