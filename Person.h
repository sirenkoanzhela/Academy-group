#pragma once
#include <iostream>

class Person
{
protected:
	char*name;
	char*surname;
	int age;
public:
	Person();
	Person(const char*, const char*, int);
	Person(const Person&);
	Person(Person &&obj);
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

	void Input();
	void Print()const;

	Person& operator=(const Person &obj);
	Person& operator=(Person &&obj);

	friend std::istream& operator>>(std::istream &is, Person& obj);
	friend std::ostream& operator<<(std::ostream &os, const Person& obj);
};
