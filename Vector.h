#pragma once
#include <iostream>

class Vector
{
	int* vect;
	int size;
public:
	Vector();
	Vector(int);
	Vector(const int*, int);
	Vector(const Vector&);
	Vector(Vector&&);
	~Vector();

	void Print();

	int getSize()const;
	void Input(const int&, int);
	void Clear();
	bool isEmpty()const;
	void Add(const int&);
	void Insert(int, const int&);
	void Remove(int);

	Vector& operator++();
	Vector operator++(int);
	Vector& operator--();
	Vector operator--(int);
	Vector& operator=(const Vector&);
	Vector& operator=(Vector&&);

	int&operator[](int);
	Vector operator+(const Vector&);
	Vector operator+(int);
	Vector& operator+=(const Vector&);
	Vector operator - (const Vector& v);
	Vector operator - (int);
	Vector& operator -= (const Vector& v);
	Vector operator * (const Vector& v);
	Vector operator * (int);
	Vector& operator *= (int);

	friend std::istream& operator>>(std::istream&, Vector&);
	friend std::ostream& operator<<(std::ostream&, Vector&);
};
