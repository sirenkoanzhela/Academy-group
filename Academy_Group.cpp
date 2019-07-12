#include<iostream>
#include "Academy_Group.h"

using namespace std; //for testing
using namespace Academy_Group;

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

void AcademyGroup::AddStudents(Student* st)
{
	Student** temp = new Student * [count];


	for (int i = 0; i < count; i++)
	{
		temp[i] = pSt[i];
	}

	temp[count] = st;
	count++;
	pSt = temp;
}

void AcademyGroup::DeleteStudent(Student* st)
{
	
	if (!IsStudent(st))
	{
		std::cout << "[ Student not exist ]\n" << std::endl;
		return;
	}

	Student** temp = new Student * [count - 1];
	int i = 0;

	for (; i < count; i++)
	{
		temp[i] = pSt[i];
		if (pSt[i] == st) {
			delete pSt[i];

			for (int j = i; j < count; j++, i++)
			{
				temp[i] = pSt[i + 1];
			}
			pSt = temp;
			count--;
			return;
		}
		
	}
}

void Academy_Group::AcademyGroup::EditStudent(Student* st)
{
	if (!IsStudent(st))
	{
		std::cout << "[ Student not exist ]\n" << std::endl;
		return;
	}

	st->Input();
}

void AcademyGroup::Print()
{
	for (int i = 0; i < count; i++)
	{
		pSt[i]->Print();
		std::cout << std::endl;
	}
}

Student* AcademyGroup::FindStudent(std::string _name, std::string _surname)
{
	
	for (int i = 0; i < count; i++)
	{
		if (pSt[i]->getName() == _name && pSt[i]->getSurname() == _surname)
		{
			return pSt[i];
		}
	}
	return nullptr;
}

void Academy_Group::AcademyGroup::Save()
{
	FILE* f;
	fopen_s(&f, "data.bin", "wb");
	if (f == nullptr)
	{
		cout << "Cannot open this file!" << endl;
		return;
	}


	for (int i = 0; i < count; i++)
	{
		int size_name = sizeof(pSt[i]->getName());
		fwrite(&size_name, sizeof(int), 1, f);
		fwrite(pSt[i]->getName(), sizeof(char), size_name, f);
	}
	
	
}

bool AcademyGroup::IsStudent(Student*st)
{
	for (int i = 0; i < count; i++)
	{
		if (pSt[i] == st) { return true; }
	}
	return false;
}
