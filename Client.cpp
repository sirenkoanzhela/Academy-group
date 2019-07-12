#include <iostream>
#include "Academy_Group.h"
#include "Student.h"

using namespace Academy_Group;

int main()
{
	AcademyGroup* group_1 = new AcademyGroup;

	Student* st_1 = new Student("TEST_NAME_01", "TEST_SURNAME", 23, "12345678901234", 4.4);
	Student* st_2 = new Student("TEST_NAME_02", "TEST_SURNAME", 23, "12345678901234", 4.4);
	Student* st_3 = new Student("TEST_NAME_03", "TEST_SURNAME", 23, "12345678901234", 4.4);
	
	group_1->AddStudents(st_1);
	group_1->AddStudents(st_2);
	group_1->AddStudents(st_3);

	std::cout << "-------------DEFAULT GROUP--------------\n" << std::endl;

	group_1->Print();

	std::cout << "-------------ADD STUDENT--------------\n" << std::endl;


	Student* st_04 = new Student("Alex", "Smith", 23, "12345678901234", 4.4);
	group_1->AddStudents(st_04);
	group_1->Print();


	std::cout << "-------------DELETE STUDENT--------------\n" << std::endl;

	group_1->DeleteStudent(group_1->FindStudent(st_04->getName(), st_04->getSurname()));
	group_1->Print();

	//std::cout << "-------------EDIT STUDENT--------------\n" << std::endl;
	//group_1->EditStudent(st_3);
	//group_1->Print();


	return 0;
}