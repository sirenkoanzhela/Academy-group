#include<iostream>
#include "Academy_Group.h"

using namespace std; //for testing

AcademyGroup::AcademyGroup() :pSt(nullptr), count(0) {}

AcademyGroup::AcademyGroup(const AcademyGroup& obj)
{
	count = obj.count;

	pSt = new Student * [count];

	for (int i = 0; i < count; i++)
	{
		pSt[i] = obj.pSt[i];
	}
}

AcademyGroup::AcademyGroup(AcademyGroup&& obj) noexcept
{
	count = obj.count;
	pSt = new Student * [count];

	for (int i = 0; i < count; i++)
	{
		pSt[i] = obj.pSt[i];
		obj.pSt[i] = nullptr;
	}
	obj.count = 0;
}

AcademyGroup::~AcademyGroup()
{
	for (int i = 0; i < count; i++)
	{
		delete pSt[i];
	}
}

void AcademyGroup::AddStudents(Student*& st)
{
	Student** temp = new Student * [count];

	if (pSt != nullptr) {

		for (int i = 0; i < count; i++)
		{
			temp[i] = pSt[i];
		}
	}

	temp[count] = st;
	count++;
	pSt = temp;
}

void AcademyGroup::Print()
{
	for (int i = 0; i < count; i++)
	{
		pSt[i]->Print();
		std::cout << std::endl;
	}
}