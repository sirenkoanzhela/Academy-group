#include "Vector.h"

Vector::Vector() : size(0), vect(nullptr) { }
Vector::Vector(int _size)
{
	size = _size;
	vect = new int[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = 0;
	}
}
Vector::Vector(const int*ptr, int _size)
{
	size = _size;
	vect = new int[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = ptr[i];
	}
}
Vector::Vector(const Vector&obj)
{
	size = obj.size;
	vect = new int[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = obj.vect[i];
	}
}
Vector::Vector(Vector&&obj)
{
	vect = obj.vect;
	size = obj.size;
	obj.size = 0;
	obj.vect = nullptr;
}
Vector::~Vector()
{
	if (vect != nullptr)
	{
		delete[]vect;
	}
}

void Vector::Print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << vect[i] << std::endl;
	}
}
int Vector::getSize()const
{
	return size;
}
void Vector::Clear()
{
	delete[]vect;
	vect = nullptr;
	size = 0;
}
bool Vector::isEmpty()const
{
	if (vect == nullptr && size == 0) { return true; }
	return false;
}
void Vector::Input(const int&_size, int value)
{
	if (vect != nullptr) { delete[]vect; }
	size = _size;
	vect = new int[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = value;
	}
}
void Vector::Add(const int&item)
{
	size += 1;
	int*temp = new int[size];
	int i = 0;
	for (i = 0; i < (size - 1); i++)
	{

		temp[i] = vect[i];
	}
	temp[i] = item;
	delete[]vect;
	vect = temp;
}
void Vector::Insert(int index, const int&item)
{
	size += 1;
	int*temp = new int[size];
	for (int i = 0; i < index; i++)
	{
		temp[i] = vect[i];
	}
	temp[index] = item;
	for (int i = (index + 1); i < size; i++)
	{
		temp[i] = vect[i - 1];
	}
	delete[]vect;
	vect = temp;
}
void Vector::Remove(int index)
{
	size -= 1;
	int*temp = new int[size];
	for (int i = 0; i < index; i++)
	{
		temp[i] = vect[i];
	}
	for (int i = index; i < size; i++)
	{
		temp[i] = vect[i + 1];
	}
	delete[]vect;
	vect = temp;
}

Vector& Vector::operator++()
{
	for (int i = 0; i < size; i++)
	{
		vect[i] = ++vect[i];
	}
	return *this;
}
Vector Vector::operator++(int k)
{
	Vector temp_vect;
	temp_vect.vect = new int[size];
	for (int i = 0; i < size; i++)
	{
		temp_vect.vect[i] = vect[i];
		vect[i] = ++vect[i];
	}

	return temp_vect;
}
Vector& Vector::operator--()
{
	for (int i = 0; i < size; i++)
	{
		vect[i] = --vect[i];
	}
	return *this;
}
Vector Vector::operator--(int k)
{
	Vector temp_vect;
	temp_vect.vect = new int[size];
	for (int i = 0; i < size; i++)
	{
		temp_vect.vect[i] = vect[i];
		vect[i] = --vect[i];
	}

	return temp_vect;
}
Vector& Vector::operator=(const Vector&obj)
{
	if (this == &obj) { return *this; }
	delete[] this->vect;
	size = obj.size;
	vect = new int[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = obj.vect[i];
	}
	return *this;
}
Vector& Vector::operator=(Vector&&obj)
{
	vect = obj.vect;
	size = obj.size;
	obj.size = 0;
	obj.vect = nullptr;
	return *this;
}
int& Vector::operator[](int index)
{
	return vect[index];
}
Vector Vector::operator+(const Vector&obj)
{
	Vector temp;
	int index = 0;
	temp.size = size + obj.size;
	temp.vect = new int[temp.size];
	for (int i = 0; i < size; i++)
	{
		temp.vect[i] = vect[i];
	}
	for (int i = size; i < temp.size; i++)
	{
		temp.vect[i] = obj.vect[index];
		index++;
	}
	return temp;
}
Vector Vector::operator+(int item)
{
	for (int i = 0; i < size; i++)
	{
		vect[i] += item;
	}
	return *this;
}
Vector& Vector::operator+=(const Vector&obj)
{
	int*temp = new int[size + obj.size];
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		temp[i] = vect[i];
	}
	for (int i = size; i < (size + obj.size); i++)
	{
		temp[i] = obj.vect[index];
		index++;
	}
	delete[]vect;
	vect = temp;
	size += obj.size;
	return *this;
}
Vector Vector::operator-(const Vector&obj)
{
	Vector temp;
	if (size == obj.size)
	{
		temp.size = size;
		temp.vect = new int[temp.size];
		for (int i = 0; i < temp.size; i++)
		{
			temp.vect[i] = vect[i] - obj.vect[i];
		}
		return temp;
	}
	else if (size != obj.size && size != 0 && obj.size != 0)
	{
		if (size > obj.size) { temp.size = size; }
		else temp.size = obj.size;

		temp.vect = new int[temp.size];
		for (int i = 0; i < temp.size; i++)
		{
			if (size > obj.size)
			{
				for (int i = 0; i < obj.size; i++)
				{
					temp.vect[i] = vect[i] - obj.vect[i];
				}
				for (int i = obj.size; i < temp.size; i++)
				{
					temp.vect[i] = vect[i];
				}
			}
			else
			{
				for (int i = 0; i < size; i++)
				{
					temp.vect[i] = vect[i] - obj.vect[i];
				}
				for (int i = size; i < temp.size; i++)
				{
					temp.vect[i] = obj.vect[i];
				}
			}
		}
		return temp;
	}
	if (size == 0)
	{
		temp.vect = new int[obj.size];
		for (int i = 0; i < obj.size; i++)
		{
			temp.vect[i] = obj.vect[i];
		}
	}
	else
	{
		temp.vect = new int[size];
		for (int i = 0; i < size; i++)
		{
			temp.vect[i] = vect[i];
		}
	}
	return temp;
}
Vector Vector::operator-(int value)
{
	Vector temp;
	temp.size = size;
	temp.vect = new int[temp.size];
	for (int i = 0; i < temp.size; i++)
	{
		temp.vect[i] = vect[i] - value;
	}
	return temp;
}
Vector& Vector::operator-=(const Vector&obj)
{
	if (size == obj.size)
	{
		for (int i = 0; i < size; i++)
		{
			vect[i] = vect[i] - obj.vect[i];
		}
		return *this;
	}
	else if (size != obj.size && size != 0 && obj.size != 0)
	{
		if (size < obj.size)
		{
			int*temp = new int[obj.size];
			for (int i = 0; i < size; i++)
			{
				temp[i] = vect[i] - obj.vect[i];
			}
			for (int i = size; i < obj.size; i++)
			{
				temp[i] = obj.vect[i];
			}
			delete[]vect;
			vect = temp;
			return *this;
		}
		else if (obj.size < size)
		{
			int*temp = new int[size];
			for (int i = 0; i < obj.size; i++)
			{
				temp[i] = vect[i] - obj.vect[i];
			}
			for (int i = obj.size; i < size; i++)
			{
				temp[i] = vect[i];
			}
			delete[]vect;
			vect = temp;
			return *this;
		}
	}
	if (size == 0 && vect == nullptr)
	{
		size = obj.size;
		vect = new int[size];
		for (int i = 0; i < size; i++)
		{
			vect[i] = obj.vect[i];
		}
		return *this;
	}
	else if (obj.size == 0 && obj.vect == nullptr)
	{
		return *this;
	}
}
Vector Vector::operator*(const Vector&obj)
{
	Vector temp;
	if (size == obj.size)
	{
		temp.size = size;
		temp.vect = new int[temp.size];
		for (int i = 0; i < temp.size; i++)
		{
			temp.vect[i] = vect[i] * obj.vect[i];
		}
		return temp;
	}

	else if (size != obj.size && size != 0 && obj.size != 0)
	{
		if (size > obj.size) { temp.size = size; }
		else temp.size = obj.size;

		temp.vect = new int[temp.size];
		for (int i = 0; i < temp.size; i++)
		{
			if (size > obj.size)
			{
				for (int i = 0; i < obj.size; i++)
				{
					temp.vect[i] = vect[i] * obj.vect[i];
				}
				for (int i = obj.size; i < temp.size; i++)
				{
					temp.vect[i] = vect[i];
				}
			}
			else
			{
				for (int i = 0; i < size; i++)
				{
					temp.vect[i] = vect[i] * obj.vect[i];
				}
				for (int i = size; i < temp.size; i++)
				{
					temp.vect[i] = obj.vect[i];
				}
			}
		}
		return temp;
	}
	if (size == 0)
	{
		temp.vect = new int[obj.size];
		for (int i = 0; i < obj.size; i++)
		{
			temp.vect[i] = obj.vect[i];
		}
	}
	else
	{
		temp.vect = new int[size];
		for (int i = 0; i < size; i++)
		{
			temp.vect[i] = vect[i];
		}
	}
	return temp;
}
Vector Vector::operator*(int value)
{
	Vector temp;
	temp.size = size;
	temp.vect = new int[temp.size];
	for (int i = 0; i < temp.size; i++)
	{
		temp.vect[i] = vect[i] * value;
	}
	return temp;
}
Vector& Vector::operator*=(int value)
{
	for (int i = 0; i < size; i++)
	{
		vect[i] = vect[i] * value;
	}
	return *this;
}

std::istream& operator>>(std::istream&is, Vector&obj)
{
	int size = 0;
	int item = 0;
	std::cout << "ENTER SIZE OF VECTOR" << std::endl;
	std::cin >> size;
	std::cout << "PUSH BACK" << std::endl;
	std::cin >> item;
	if (obj.vect != nullptr) { delete[]obj.vect; }
	obj.size = size;
	obj.vect = new int[size];
	for (int i = 0; i < size; i++)
	{
		obj.vect[i] = item;
	}
	return is;
}
std::ostream& operator<<(std::ostream&os, Vector&obj)
{
	obj.Print();
	return os;
}