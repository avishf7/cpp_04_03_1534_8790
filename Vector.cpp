/*
File: Vector.cpp
Description:
Course: 150018 C++ Workshop, Exercise 4, Question 3
Author: Dan Zilberstein
Students: eli iluz 311201354
		& avishay farkash 205918790
*/
#include"vector.h"
#pragma warning(disable: 4996)

using namespace std;



Vector::Vector(int capacity, int size, int* data) :capacity(capacity), size(size), data(nullptr)
{
	if (data != nullptr)
	{
		this->data = new int[capacity];
		for (int i = 0; i < size; i++)
			this->data[i] = data[i];
	}
}


Vector::Vector(const Vector& v1) :capacity(0), size(0), data(nullptr) {
	this->capacity = v1.capacity;
	this->size = v1.size;
	if (v1.data != nullptr)
	{
		this->data = new int[v1.capacity];
		for (int i = 0; i < v1.size; i++)
			this->data[i] = v1.data[i];
	}
}

Vector::Vector(Vector&& v1) :capacity(v1.capacity), size(v1.size), data(v1.data) {
	// Avoid temp object DTOR removing the dynamic data which is now used in our object
	v1.data = nullptr;
	v1.size = 0;
	v1.capacity = 0;
}

int Vector::getCapacity()const {
	return capacity;
}

int Vector::getSize()const {
	return size;
}

Vector& Vector:: operator = (const Vector& v1) {
	if (this == &v1)
		return*this;
	this->capacity = v1.capacity;
	this->size = v1.size;
	if (data != v1.data) {
		delete[] data;
		data = new int[v1.capacity];
		for (int i = 0; i < v1.size; i++)
			this->data[i] = v1.data[i];
	}
	return *this;
}

Vector& Vector:: operator = (Vector&& v1) {
	this->capacity = v1.capacity;
	this->size = v1.size;
	delete[] this->data;
	this->data = v1.data;
	v1.data = nullptr;

	return *this;
}

ostream& operator << (ostream& out, Vector& v1) {
	out << "capacity: " << v1.capacity << " size: " << v1.size << " content: ";
	for (int i = 0; i < v1.size; i++) {
		out << v1[i] << " ";
	}
	return out;
}

istream& operator>>(istream& in, Vector& v1)
{
	int var, size;

	cout << "Enter vector size(maximum - 9):";
	in >> size;

	if (v1.size > v1.capacity)
		throw "ERROR: the size is out of range.";

	v1.data = new int[v1.capacity];

	cout << "Enter " << size << " variabels:" << endl;

	try 
	{
		for (int i = 0; i < size; i++)
		{
			in >> var;
			v1.insert(var);
		}
	}
	catch (const char*)
	{
		throw;
	}
}


bool Vector:: operator ==(Vector& v2) {
	if (this->size == v2.size) {
		for (int i = 0; i < this->size; i++) {
			if (this->data[i] != v2.data[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

int& Vector::operator [](int i) {
	if ((i >= this->size) || (i < 0)) {
		throw "ERROR: index is out of range.";
	}
	return this->data[i];
}

int& Vector::operator * (const Vector& v2) {
	int sum = 0;
	if (this->size == v2.size) {
		for (int i = 0; i < this->size; i++)
			sum += this->data[i] * v2.data[i];
	}
	else {
		throw "ERROR: the vectors size must be equal.";
	}

	return sum;
}

Vector Vector:: operator + (const Vector& v2) {
	Vector v3(this->capacity + v2.capacity, this->size + v2.size, new int[this->capacity + v2.capacity]);

	try
	{
		for (int i = 0; i < this->size; i++)
			v3.insert(this->data[i]);
		for (int i = 0; i < v2.size; i++)
			v3.insert(v2.data[i]);
	}
	catch (const char*)
	{
		throw;
	}

	return v3;
}

void Vector::clear() {
	for (int i = 0; i < this->size; i++)
		this->data[i] = 0;

	this->size = 0;
}

void Vector::delLast() {
	if (this->size > 0) {
		this->data[--size] = 0;
	}
	else
		throw "ERROR: vector is empty: size = 0. ";

}
void Vector::insert(int val) {
	if (this->size <= this->capacity)
		this->data[size++] = val;
	else
	{
		char* str = new char[40];
		stringstream sstr;
		sstr << "ERROR: the vector is full: capacity = ";
		sstr << capacity;
		sstr.getline(str, 40);
		throw str;
	}
}