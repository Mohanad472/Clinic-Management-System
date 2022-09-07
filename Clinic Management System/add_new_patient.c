#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "stdtypes.h"
#include "prototypes.h"

extern struct patient *patientHead;
extern struct patient *patientCurrent;

void add_new_patient(u8 name[], u16 age, u8 gender[], u32 ID){
	
	struct patient *ptr = (struct patient*)malloc(sizeof(struct patient));
	struct patient *current = patientHead;
	u8 flag = 0;
	
	while(current != NULL){
		if(current -> ID == ID){
			printf("Entery rejected, ID already exists\n");
			u8 c;
			c = getch();
			system("cls");
			flag = 1;
			break;
			}
			current = current -> next;
	}
	if(flag == 0){
		if(patientHead == NULL){
		patientHead = ptr;
		ptr -> next = NULL;
		patientCurrent = patientHead;
	}
	else{
		patientCurrent -> next = ptr;
		ptr -> next = NULL;
		patientCurrent = ptr;
	};
	ptr -> age = age;
	strcpy(ptr -> gender, gender);
	strcpy(ptr -> name, name);
	ptr -> ID = ID;
	}
}
