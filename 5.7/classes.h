#pragma once
#include <iostream>
#include "my_1_string.h"
using namespace std;
class Int;
class Double{
public:
	void print();
	Double();
	Double(double _num);
	Double operator %(int a);
	Double operator %(Int a);

private:
	double num;
};


class Int{
public:
	Int(int _num=0);
	Int(String s, int base=10);
	void print();
	Int operator--(int notused);
	Int operator--();
	Int operator-();
	friend Int operator -(Int &a, Int &b);
	friend Double Double::operator%(Int a);
private:
	int num;
};