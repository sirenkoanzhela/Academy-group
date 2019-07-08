#pragma once
#include <iostream>

class Person
{
	char*name;
	char*surname;
	int age;
public:
	Person();
	Person(const char*, const char*, int);
	Person(const Person&);
	~Person();

	char*getName()const
	{
		return name;
	}
	char*getSurname()const
	{
		return surname;
	}
	int getAge()const
	{
		return age;
	}

	void setAge(int);
	void setName(const char*);
	void setSurname(const char*);

	void Print();

	void InputPerson();
	void PrintPerson();
};
