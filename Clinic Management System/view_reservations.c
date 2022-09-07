#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "stdtypes.h"

void view_reservations(u32 *view_ptr)
{
	system("Color 09");
	u8 counter = 0;
	for(int i = 0; i < 5; i++){
		if(*(view_ptr + i) != 0){
			switch(i){
				case 0:
				printf("ID %d\tReservation from 2 pm to 2:30 pm\n", *(view_ptr + i));
				break;
				
				case 1:
				printf("ID %d\tReservation from 2:30 pm to 3 pm\n", *(view_ptr + i));
				break;
				
				case 2:
				printf("ID %d\tReservation from 3 pm to 3:30 pm\n", *(view_ptr + i));
				break;
				
				case 3:
				printf("ID %d\tReservation from 4 pm to 4:30 pm\n", *(view_ptr + i));
				break;
				
				case 4:
				printf("ID %d\tReservation from 4:30 pm to 5 pm\n", *(view_ptr + i));
				break;
				
				default:
				break;
			}
		}
		else counter++;
	}
	if(counter == 5) printf("There are no reservations today\n");	
}