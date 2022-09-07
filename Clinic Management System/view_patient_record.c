#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "stdtypes.h"
#include "prototypes.h"

extern struct patient *patientHead;

void view_patient_record(){
	
	struct patient *current = patientHead;
	u32 i = 1;
	
	if(patientHead == NULL) printf("\n\t\t\t\t\t\t\tThere are no records\n");
	
	while(current != NULL){
		system("Color 09");
		printf(" Patient %d\n", i);
		printf(" Name: %s\n", current -> name);
		printf(" Age: %d\n", current -> age);
		printf(" Gender: %s\n", current -> gender);
		printf(" ID: %d\n\n", current -> ID);
		
		current = current -> next;
		i++;
	}
}