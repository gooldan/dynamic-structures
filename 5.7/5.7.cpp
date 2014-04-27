#include <iostream>
#include "classes.h"
using namespace std;
int main()
{
	String s("117");
	String s1("AA");
	Int a;
	Int b(2);
	Int c(s);
	Int d(s1, 16);
	d--;
	d.print();
	a = d - c;
	a.print();
	Double D(-12.3);
	(D % 5).print();
	int i;
	cin >> i;
}
