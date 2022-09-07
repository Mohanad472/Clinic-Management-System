#include "stdtypes.h"

void add_new_patient(u8 name[], u16 age, u8 gender[], u32 ID);
void view_patient_record();
void edit_record(u32 ID);
void cancel_reservation(u32 *p);
void reserve_slot(u32 *reserve_ptr);
void view_reservations(u32 *view_ptr);

struct patient{
	
	u8 name[50];
	u16 age;
	u8 gender[6];
	u32 ID;
	struct patient *next;
};
