#pragma once
#include "Person.h"

class Student :public Person
{
	std::string phone;
	double rating;
public:
	Student();
	Student(std::string, std::string, int, std::string, double);
	Student(const Student& obj);
	Student(Student&& obj)noexcept;
	double getRating() const
	{
		return rating;
	}
	std::string getPhone() const
	{
		return phone;
	}
	void setPhone(std::string phone);
	void setRating(double average);
	void Print() const;
	void Input();
	Student& operator=(const Student& obj);
	Student& operator=(Student&& obj)noexcept;
	friend std::istream& operator>>(std::istream& is, Student& obj);
	friend std::ostream& operator<<(std::ostream& os, const Student& obj);
};