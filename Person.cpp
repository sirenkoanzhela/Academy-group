#include <iostream>
#include <string>
#include "Person.h"

Person::Person() :age(0),name(nullptr),surname(nullptr) {}

Person::Person(std::string _name, std::string _surname, int _age)
{
	name = _name;
	surname = _surname;
	age = _age;
}

Person::Person(const Person &obj)
{
	name = obj.name;
	surname = obj.surname;
	age = obj.age;
}

Person::Person(Person && obj)
{
	age = 0;
	name = obj.name;
	surname = obj.surname;
}

Person::~Person()
{
	name.clear();
	surname.clear();
}

void Person::setAge(int _age)
{
	if (_age < 0 || _age>150)return;
	age = _age;
}

void Person::setName(const std::string _name)
{
	name = _name;
}

void Person::setSurname(const std::string _surname)
{
	surname = _surname;
}


void Person::Input()
{
	std::string str;
	std::getline(std::cin, str);
	setName(str);

	std::cout << "Set surname:" << std::endl;
	std::getline(std::cin, str);
	setSurname(str);

	std::cout << "Set Age:" << std::endl;
	int age;
	std::cin >> age;
	setAge(age);

}

void Person::Print()const
{
	std::cout << "Name: ";
	std::cout << name;

	std::cout << "\nSurname: ";
	std::cout << surname;

	std::cout << "\nAge: " << age << std::endl;

}

Person & Person::operator=(const Person & obj)
{
	if (this == &obj) { return *this; }

	name = obj.name;
	surname = obj.surname;
	age = obj.age;

	return *this;
}

Person & Person::operator=(Person && obj)
{
	if (this == &obj) { return *this; }
	name = obj.name;
	surname = obj.surname;
	age = obj.age;

	obj.name.clear();
	obj.surname.clear();
	age = 0;

	return *this;
}

std::istream & operator>>(std::istream & is, Person & obj)
{
	obj.Input();
	return is;
}

std::ostream & operator<<(std::ostream & os, const Person & obj)
{
	obj.Print();
	return os;
}
