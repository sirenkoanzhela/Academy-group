#include "Student.h"


Student::Student() :Person(), rating(0.0) { }

Student::Student(std::string name, std::string surname, int age,
	std::string _phone, double _rating) : Person(name, surname, age), rating(_rating), phone(_phone) {}

Student::Student(const Student& obj) :Person(obj.name, obj.surname, obj.age)
{
	phone = obj.phone;
	rating = obj.rating;
}

Student::Student(Student&& obj) noexcept:Person(obj)
{
	phone = obj.phone;
	rating = obj.rating;

	obj.rating = 0;
	obj.phone.clear();
}

void Student::setPhone(std::string _phone)
{
	phone = _phone;
}

void Student::setRating(double average)
{
	if (average < 0 || average>5.0) return;
	rating = average;
}

void Student::Print() const
{
	Person::Print();
	std::cout << "Rating: " << rating << std::endl;
	std::cout << "Phone number: ";
	std::cout << phone;
	std::cout << std::endl;
}

void Student::Input()
{
	Person::Input();

	double temp;
	std::string str;

	std::cout << "Set Rating:" << std::endl;
	std::cin >> temp;
	setRating(temp);

	std::cout << "Set Phone:" << std::endl;

	std::cin.ignore();
	std::getline(std::cin, str);
	setPhone(str);
}

Student& Student::operator=(const Student& obj)
{

	if (this == &obj) { return *this; }

	name = obj.name;
	surname = obj.surname;
	age = obj.age;
	rating = obj.rating;
	phone = obj.phone;

	return *this;
}

Student& Student::operator=(Student&& obj)noexcept
{
	if (this == &obj) { return *this; }

	name = obj.name;
	surname = obj.surname;
	phone = obj.phone;
	age = obj.age;
	rating = obj.rating;

	obj.name.clear();
	obj.surname.clear();
	obj.phone.clear();
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
