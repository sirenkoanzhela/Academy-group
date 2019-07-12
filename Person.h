#pragma once
#include <iostream>
#include <string>

class Person
{
protected:
	std::string name;
	std::string surname;
	int age;
public:
	Person();
	Person(std::string, std::string, int);
	Person(const Person&);
	Person(Person&& obj)noexcept;
	~Person();

	std::string getName()const
	{
		return name;
	}
	std::string getSurname()const
	{
		return surname;
	}
	int getAge()const
	{
		return age;
	}

	void setAge(int);
	void setName(const std::string);
	void setSurname(const std::string);

	void Input();
	virtual void Print()const;

	Person& operator=(const Person& obj);
	Person& operator=(Person&& obj)noexcept;

	friend std::istream& operator>>(std::istream& is, Person& obj);
	friend std::ostream& operator<<(std::ostream& os, const Person& obj);
};