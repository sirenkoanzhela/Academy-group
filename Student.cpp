#include "Student.h"

Student::Student() :Person()
{
	rating = 0.0;
	for (int i = 0; i < 14; i++)
	{
		phone[i] = 0;
	}
}

Student::Student(const char* _name, const char* _surname, int _age, const char* _phone, double _rating) :Person(_name, _surname, _age)
{
	rating = _rating;
	for (int i = 0; i < 14; i++)
	{
		phone[i] = _phone[i];
	}
}

Student::Student(const Student& obj) :Person(obj.name, obj.surname, obj.age)
{
	for (int i = 0; i < 14; i++)
	{
		phone[i] = obj.phone[i];
	}
	rating = obj.rating;
}

Student::Student(Student&& obj) :Person(obj)
{
	std::cout << "TEST CONSTRUCTOR MOVING";
	for (int i = 0; i < 14; i++)
	{
		phone[i] = obj.phone[i];
		obj.phone[i] = 0;
	}
	rating = obj.rating;

	obj.rating = 0;
}

double Student::getRating() const
{
	return rating;
}

const char* Student::getPhone() const
{
	return phone;
}

void Student::setPhone(const char* _phone)
{
	if (strlen(_phone) > 14) { return; }
	for (int i = 0; i < 14; i++)
	{
		phone[i] = _phone[i];
	}
}

void Student::setRating(double average)
{
	if (average < 0 || average>5.0)return;
	rating = average;
}

void Student::Print() const
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
	std::cout << "Rating: " << rating << std::endl;
	std::cout << "Phone number: ";
	for (int i = 0; i < 14; i++)
	{
		std::cout << phone[i];
	}
	std::cout << std::endl;
}

void Student::Input()
{
	char* str = new char;
	std::cout << "Set name:" << std::endl;
	std::cin >> str;
	setName(str);

	std::cout << "Set surname:" << std::endl;
	std::cin >> str;
	setSurname(str);

	std::cout << "Set Age:" << std::endl;
	double temp;
	std::cin >> temp;
	setAge(temp);

	std::cout << "Set Rating:" << std::endl;
	std::cin >> temp;
	setRating(temp);

	std::cout << "Set Phone:" << std::endl;
	do {
		std::cin >> str;
	} while (strlen(str) != 14);
	//const char* str_temp = str;
	setPhone(str);
}

Student& Student::operator=(const Student& obj)
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
	rating = obj.rating;
	for (int i = 0; i < 14; i++)
	{
		phone[i] = obj.phone[i];
	}
	return *this;
}

Student& Student::operator=(Student&& obj)
{
	if (this == &obj) { return *this; }
	if (name != nullptr || surname != nullptr)
	{
		delete[]name;
		delete[]surname;
	}

	for (int i = 0; i < 14; i++)
	{
		phone[i] = obj.phone[i];
		obj.phone[i] = 0;
	}

	name = obj.name;
	surname = obj.surname;
	age = obj.age;
	rating = obj.rating;

	obj.name = nullptr;
	obj.surname = nullptr;
	age = 0;
	rating = 0;
	return *this;
}

std::istream& operator>>(std::istream& is, Student& obj)
{
	obj.Input();
	return is;
}

std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	obj.Print();
	return os;
}
