#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "stdtypes.h"
#include "prototypes.h"

struct patient *patientHead = NULL;
struct patient *patientCurrent = NULL;


void main(void){
	
	while(1){
	//h:
	system("cls");
	system("Color 0A");
	printf("\n\n\t\t\t\t\t\t\t1. Admin mode\n\n\t\t\t\t\t\t\t2. User mode");
	u8 ch, pass_flag = 0, admin_flag = 0;
	u8 name1[50]; u16 age; u8 gender[6]; u32 ID;
	static u32 reservations_ID[5] = {0,0,0,0,0};
	ch = getch();
	
	
	//***************** ADMIN *****************//
	
	if(ch == '1'){			
		system("cls");
		printf("\n\t\t\t\t\t\t\tAdmin mode\t\t\t\n\n");
		
		///// Password /////
		
		u16 entry;
		
		printf("Enter password: ");
		
		for(int i = 0; i < 3; i++){
			
			scanf("%d", &entry);
			
			if(entry == 1234){
				break;
			}
			else if(i < 2){
				printf("Try again: ");
			}
			
			if(i == 2) pass_flag = 1;
		}
		
		if(pass_flag == 1) {
			printf("Incorrect\n");     // exit the program
			ch = getch();
		}	
		
		
		///---------- Admin modes ----------///
		
		else{
			while(admin_flag == 0){
				system("cls");
				printf("\n\t\t\t\t\t\t\tAdmin mode\t\t\t\n\n");
				printf("1. Add new patient record\n");
				printf("2. Edit patient record\n");
				printf("3. Reserve a slot with the doctor\n");
				printf("4. Cancel reservation\n");
				printf("5. Exit\n");
			
				u8 choice;
				choice = getch();
				
				switch(choice){
					
					case '1' : 
					printf("\nName: ");
					scanf("%s", name1);
					char name[50];
					strcpy(name, name1);
					printf("Age: ");
					scanf("%d", &age);
					printf("Gender: ");
					scanf("%s", gender);
					printf("ID: ");
					scanf("%d", &ID);
					add_new_patient(name, age, gender, ID);
					break;
					
					case '2' : 
					printf("Enter ID: ");
					u32 entered_ID;
					scanf("%d", &entered_ID);
					edit_record(entered_ID);
					break;
				
					case '3' :;
					u8 reservation_flag = 0;
					for(int i = 0; i < 5; i++){
						if(reservations_ID[i] == 0) reservation_flag = 1;
					}
					if(reservation_flag == 0){
						printf("There are no available reservations at the moment\n");
						ch = getch();
						break;
					};
					printf("Available Slots\n\n");
					if(reservations_ID[0] == 0) printf("1) 2 pm to 2:30 pm\n");
					if(reservations_ID[1] == 0) printf("2) 2:30 pm to 3 pm\n");
					if(reservations_ID[2] == 0) printf("3) 3 pm to 3:30 pm\n");
					if(reservations_ID[3] == 0) printf("4) 4 pm to 4:30 pm\n");
					if(reservations_ID[4] == 0) printf("5) 4:30 pm to 5 pm\n");
					printf("\n");
					reserve_slot(reservations_ID);
					break;
				
					case '4' : 
					cancel_reservation(reservations_ID);
					break;
					
					case '5' : 
					admin_flag = 1;
					break;
				
					default : 
					printf("Invalid entry\n");
					break;
				}
			}
		}
	}
	
	
	//***************** USER *****************//
	
	else if(ch == '2'){
		
		u8 choice;
		u8 choice_flag = 0;
			
		while(choice_flag == 0){
			
			system("cls");
			system("Color 0A");
			printf("\n\t\t\t\t\t\t\tUser mode\t\t\t\n\n");
			printf("1. View patients record\n");
			printf("2. View today's reservations\n");
			printf("3. Exit\n");
		
			choice = getch();
			switch(choice){
				case '1':
				system("cls");
				view_patient_record();
				ch = getch();
				break;
				
				case '2':
				system("cls");
				view_reservations(reservations_ID);
				ch = getch();
				break;
				
				case '3':
				choice_flag = 1;
				break;
				
				default:
				printf("5. Exit\n");
				break;
			}
		}
	}
}
}