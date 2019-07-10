#include <iostream>
#include "Academy_Group.h"
#include "Student.h"


int main()
{

	AcademyGroup*group_1 = new AcademyGroup;

	for (int i = 0; i < 3; i++) 
	{
		Student*st = new Student("temp_name", "temp_surname", 23, "12345678901234", 4.4);
		//st->Input();
		group_1->AddStudents(st);
	}
	group_1->Print();

	
	return 0;
}