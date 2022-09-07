#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "stdtypes.h"
#include "prototypes.h"

void edit_record(u32 ID){
	
	extern struct patient *patientHead;
	struct patient *current = patientHead;
	u8 flag = 0, c;
	
	while(current != NULL){
		if(current -> ID == ID){
			printf("Name: ");
			scanf("%s", current -> name);
			printf("Age: ");
			u8 age1;
			scanf("%d", &age1);
			current -> age = age1;
			printf("Gender: ");
			scanf("%s", current -> gender);
			flag = 1; break;
		}
		current = current -> next;
	}
	if(flag == 0){
		printf("No such ID exists\n");
		c = getch();
		system("cls");
	}
}