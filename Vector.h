/*
File: Vector.h
Description:
Course: 150018 C++ Workshop, Exercise 4, Question 3
Author: Dan Zilberstein
Students: eli iluz 311201354
		& avishay farkash 205918790
*/
#ifndef VECTOR_H
#define VECTOR_H


#include<iostream>
#include<cstring>


class Vector {
private:
	int capacity;
	int size;
	int* data;
public:
	Vector(int capacity = 10, int size = 0, int* data = nullptr);
	Vector(const Vector& v1);
	Vector(Vector&& v1);

	Vector& operator =(const Vector& v1);
	Vector& operator =(Vector&& v1);

	~Vector() {
		delete[] data;
	}

	int getCapacity()const;

	int getSize()const;

	friend std::ostream& operator << (std::ostream& out, Vector& v1);
	friend std::istream& operator >>(std::istream& in, Vector& v1);

	/*
		vector operator = (vector& v2) {
			vector(v2);
		}
		*/
	bool operator ==(Vector& v2);

	int& operator [](int i);

	int& operator * (const Vector& v2);

	Vector operator + (const Vector& v2);

	void clear();
	void delLast();
	void insert(int val);
};

std::ostream& operator << (std::ostream& out, Vector& v1);
std::istream& operator >>(std::istream& in, Vector& v1);

#endif // !VECTOR_H


