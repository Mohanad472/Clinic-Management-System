#include <stdio.h>
#include <conio.h>
#include "stdtypes.h"
#include "prototypes.h"

extern struct patient *patientHead;

void reserve_slot(u32 *reserve_ptr){
	
	u8 slot, ID_flag = 0, reserve_flag = 0, c;
	u32 slot_ID;
	
	printf("Enter ID: ");
	scanf("%d", &slot_ID);

	struct patient *current = patientHead;
	
	while(current != NULL){
		if(current -> ID == slot_ID){
			ID_flag = 1;
			break;
			}
			current = current -> next;
	}
	if(ID_flag == 0){
		printf("No such ID exists\n");
		c = getch();
	}
	else{
		for(int i = 0; i < 5; i++){
			if(*(reserve_ptr + i) == slot_ID){
				printf("This ID already has a reservation\n");
				c = getch();
				reserve_flag = 1;
				break;
			}
		}
		if(reserve_flag == 0){
		printf("Enter the slot number: ");
		scanf("%d", &slot);
		if(*(reserve_ptr + (slot -1)) != 0){
			printf("This slot is already reserved\n");
			c = getch();
		}
		else *(reserve_ptr + (slot - 1)) = slot_ID;
		}
	}
}
		