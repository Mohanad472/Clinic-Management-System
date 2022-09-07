#include <stdio.h>
#include <conio.h>
#include "stdtypes.h"
#include "prototypes.h"

extern struct patient *patientHead;

void cancel_reservation(u32 *p){
	
	printf("Please enter ID: ");
	u32 ID;
	scanf("%d", &ID);
	u8 flag = 0;
	struct patient *current = patientHead;
	u8 c;
	
	while(current != NULL){
		if(current -> ID == ID){
			flag = 1;
			break;
			}
			current = current -> next;
	}
	if(flag == 0){
		printf("No such ID exists\n");
		c = getch();
	}
	else{
		for(int i = 0; i < 5; i++){
			if(*(p+i) == ID){
			printf("Reservation cancelled\n");
			c = getch();
			*(p+i) = 0;
			break;
			}
			else{
				if(i == 4){
					printf("There is no reservation with this ID\n");
					c = getch();
				}
			}
		}
	}
}	