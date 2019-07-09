#include <iostream>
#include <string>
#include "Person.h"

Person::Person() :name(nullptr), surname(nullptr), age(0) {}

Person::Person(const char *_name, const char *_surname, int _age)
{
	int size = strlen(_name)+1;
	name = new char[size];
	strcpy_s(name, size, _name);
	size = strlen(_surname)+1;
	surname = new char[size];
	strcpy_s(surname, size, _surname);

	age = _age;

}

Person::Person(const Person &obj)
{
	int size = strlen(obj.name)+1;

	name = new char[size];
	strcpy_s(name, size, obj.name);

	size = strlen(obj.surname)+1;
	surname = new char[size];
	strcpy_s(surname, size, obj.surname);

	age = obj.age;
}

Person::Person(Person && obj)
{
	name = obj.name;
	surname = obj.surname;
	age = obj.age;

	obj.name = nullptr;
	obj.surname = nullptr;
	age = 0;
}

Person::~Person()
{
	delete[]name;
	delete[]surname;
}

void Person::setAge(int _age)
{
	if (_age < 0 || _age>150)return;
	age = _age;
}

void Person::setName(const char*_name)
{
	if (name != nullptr) { delete[]name; }

	int size = strlen(_name) + 1;
	name = new char[size];
	for (int i = 0; i < size; i++)
	{
		name[i] = _name[i];
	}

}

void Person::setSurname(const char*_surname)
{
	if (surname != nullptr) { delete[]name; }

	int size = strlen(_surname) + 1;
	surname = new char[size];
	for (int i = 0; i < size; i++)
	{
		surname[i] = _surname[i];
	}
}


void Person::Input()
{
	char*str=new char;
	std::cout << "Set name:" << std::endl;
	std::cin >> str;
	setName(str);

	std::cout << "Set surname:" << std::endl;
	std::cin >> str;
	setSurname(str);

	std::cout << "Set Age:" << std::endl;
	int age;
	std::cin >> age;
	setAge(age);

}

void Person::Print()const
{
	std::cout << "Name: ";
	if (name != nullptr)
	{
		for (int i = 0; i < name[i] != '\0'; i++)
		{
			std::cout << name[i];
		}
	}

	std::cout << "\nSurname: ";
	if (surname != nullptr)
	{
		for (int i = 0; i < surname[i] != '\0'; i++)
		{
			std::cout << surname[i];
		}
	}
	std::cout << "\nAge: " << age << std::endl;

}

Person & Person::operator=(const Person & obj)
{
	if (this == &obj) { return *this; }
	if (name != nullptr || surname != nullptr)
	{
		delete[]name;
		delete[]surname;
	}
	int size = strlen(obj.name);

	name = new char[size + 1];
	strcpy_s(name, size, obj.name);

	size = strlen(obj.surname);
	surname = new char[size + 1];
	strcpy_s(surname, size, obj.surname);

	age = obj.age;

}

Person & Person::operator=(Person && obj)
{
	if (this == &obj) { return *this; }
	if (name != nullptr || surname != nullptr)
	{
		delete[]name;
		delete[]surname;
	}

	name = obj.name;
	surname = obj.surname;
	age - obj.age;

	obj.name = nullptr;
	obj.surname = nullptr;
	age = 0;
}

std::istream & operator>>(std::istream & is, Person & obj)
{
	obj.InputPerson();
	return is;
}

std::ostream & operator<<(std::ostream & os, const Person & obj)
{
	obj.Print();
	return os;
}
