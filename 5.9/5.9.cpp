#include <iostream>
#include "array.h"
using namespace std;

int main()
{
	Array<int> x(10, 117);
	Array <int> y = x;

	for (int i = 0; i < y.getSize(); i++)
		cout << y[i] << " ";
	cout << endl;
	Array<int> z(5);

	z = y;
	for (int i = 0; i < z.getSize(); i++)
		cout << z[i] << " ";
	cout << endl;
	x = x;
	for (int i = 0; i < z.getSize(); i++)
		cout << x[i] << " ";

	Array<int> *test = new Array<int>;
	delete test;

	int i;
	cin >> i;
}