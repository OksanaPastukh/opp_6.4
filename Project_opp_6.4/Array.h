#pragma once
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

template <class T> // T - тип
class Array
{
	T* v; // внутрішній масив
	int size; // кількість елементів
public:
	Array(int newsize); // конструктор ініціалізації
	Array(Array&); // конструктор копіювання
	~Array(); // деструктор

	T& operator [] (int index); // індексування
	Array& operator = (const Array&); // присвоєння
	friend ostream& operator << <>(ostream&, Array&);
	friend istream& operator >> <>(istream&, Array&); // введення

	bool MyTask();
};
template <class T>
Array<T>::Array(int newsize) // конструктор ініціалізації
{
	v = new T[size = newsize]; // новий розмір, виділення пам'яті для елементів
	for (int i = 0; i < size; i++) // присвоєння нульових значень елементам
		v[i] = T();
}
template <class T>
Array<T>::Array(Array<T>& x) // конструктор копіювання
{
	v = new T[size = x.size]; // новий розмір, виділення пам'яті для елементів
	for (int i = 0; i < size; i++) // присвоєння значень елементам
		v[i] = x.v[i];
}
template <class T>
Array<T>::~Array()
{
	delete[] v; // звільнення пам'яті
}


template <class T>
T& Array<T>::operator [] (int index)
{
	if (index < 0 || index >= size)
	{
		throw exception("Index out of the range");
	}
	return v[index];
}
template <class T>
Array<T>& Array<T>::operator = (const Array<T>& x)
{
	if (this != &x)
	{
		delete[] v;
		v = new T[size = x.size];
		for (int i = 0; i < size; i++)
			v[i] = x.v[i];
	}
	return *this;
}
template <class T>
istream& operator >> (istream& is, Array<T>& x)
{
	cout << "Input " << x.size << " elements of vector" << endl;
	for (int i = 0; i < x.size; i++) {
		cout << "element[" << i << "] =  ";
		is >> x.v[i];
	}
	return is;
}
template <class T>
ostream& operator << (ostream& os, Array<T>& x)
{
	for (int i = 0; i < x.size; i++)
		os << x.v[i] << ' ';
	os << endl;
	return os;
}
template <class T>
bool Array<T>::MyTask()
{
	bool result = false;
	for (int i = 0; i < size; i++)
	{
		if (v[i] == v[i + 1])
		{
			result = true;
		}
	}
	return result;
}
