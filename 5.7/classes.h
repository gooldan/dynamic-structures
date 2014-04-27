#pragma once
#include <iostream>
#include "my_1_string.h"
using namespace std;
class Int{
public:
	Int();
	Int(int _num);
	Int(String s);
	Int(String s, int base);
	void print();
	Int operator--(int notused);
	Int operator--();

	friend Int operator -(Int &a, Int &b);
private:
	int num;
};
class Double{

public:
	void print();
	Double();
	Double(double _num);
	Double operator %(int a);

private:
	double num;
};