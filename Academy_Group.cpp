#include<iostream>
#include "Academy_Group.h"

using namespace std; //for testing

AcademyGroup::AcademyGroup() :pSt(nullptr), count(0) {}

AcademyGroup::AcademyGroup(const AcademyGroup & obj)
{
	count = obj.count;
	const short int k = 0;

	pSt = new Student*[count];

	for (int i = 0; i < count; i++)
	{
		pSt[k][i] = obj.pSt[k][i];
	}
}

AcademyGroup::AcademyGroup(AcademyGroup && obj)
{
	count = obj.count;
	const short int k = 0;

	pSt = new Student*[count];

	for (int i = 0; i < count; i++)
	{
		pSt[k][i] = obj.pSt[k][i];
		obj.pSt[k] = nullptr;
	}
	obj.count = 0;
}

AcademyGroup::~AcademyGroup()
{
	for (int i = 0; i < count; i++)
	{
		delete[] pSt[i];
	}
}

void AcademyGroup::AddStudents(Student*&st)
{
	if (pSt == nullptr) {

		pSt = new Student*;
		pSt[count] = st;
		count++;
		return;
	}

	Student**temp = new Student*[count];
	for (int i = 0; i < count; i++)
	{
		temp[i] = pSt[i];

	}
	pSt = new Student*[count + 1];

	for (int i = 0; i < count; i++)
	{
		pSt[i] = temp[i];
	}
	pSt[++count] = st;
}

void AcademyGroup::Print()
{
	for (int i = 0; i < count; i++)
	{
		pSt[i]->Print();
		std::cout << std::endl;
	}
}


