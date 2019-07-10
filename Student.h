#pragma once
#include "Person.h"

class Student :public Person
{
	std::string phone;
	double rating;
public:
	Student();
	Student(std::string, std::string, int, std::string , double);
	Student(const Student& obj);
	Student(Student&& obj);
	double getRating() const;
	std::string getPhone() const;
	void setPhone(std::string phone);
	void setRating(double average);
	void Print() const;
	void Input();
	Student& operator=(const Student& obj);
	Student& operator=(Student&& obj);
	friend std::istream& operator>>(std::istream& is, Student& obj);
	friend std::ostream& operator<<(std::ostream& os, const Student& obj);
};