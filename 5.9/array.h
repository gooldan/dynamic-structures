#pragma once
#include <cstdlib>

template <class T>
class Array
{
public:
	Array();
	Array(int mSize, int initVal = 0);
	Array(Array &a);
	~Array();
	int getSize();
	Array &operator=(Array &a);
	T &operator[](int ind);
private:
	int size;
	T *p;
};
template <class T>
Array<T>::Array()
{
	size = 0;
}
template <class T>
Array<T>::Array(Array<T> &a)
{
	size = a.size;
	p = new T[size];
	for (int i = 0; i < size; i++)
		p[i] = a.p[i];
}
template <class T>
Array<T>::Array(int mSize, int initVal = 0)
{
	size = mSize;
	p = new T[size];
	for (int i = 0; i < size; ++i)
	{
		p[i] = initVal;
	}
}

template <class T>
Array<T>::~Array()
{
	if (size == 0) 
		return;
	delete[] p;
	size = 0;
}

template <class T>
int Array<T>::getSize()
{
	return size;
}

template <class T>
Array<T> &Array<T>::operator=(Array<T> &a)
{
	if (this == &a) return *this;
	if (size != 0)
		delete[] p;
	size = a.size;
	
	p = new T[size];
	for (int i = 0; i < size; i++)
		p[i] = a.p[i];

	return (*this);

}
template <class T>
T &Array<T>::operator[](int ind)
{
	if (ind >= size || ind < 0)
		exit(EXIT_FAILURE);
	return p[ind];
}