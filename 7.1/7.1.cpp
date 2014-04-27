#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;
double max(double a, double b)
{
	return (a > b ? a : b);
}

double min(double a, double b)
{
	return (a < b ? a : b);
}
class Base{
public:
	Base(double _a, double _b)
	{
		a = max(_a, _b);
		b = min(_a, _b);
	}
	double examine(double x)
	{
		double t = min(b, x);
		b = min(max(b, x), max(a, b));
		a = max(a, x);
		return t;
	}
	void print()
	{
		cout << a << " " << b << " ";
	}
private:
	double a, b;
};
class Derived1 :public Base{
public:
	Derived1(double _a, double _b, double _c) :Base(_a, _b)
	{
		c = examine(_c);
	}
	double examine(double x)
	{
		c = Base::examine(x);
		return c;
	}
	void print()
	{
		Base::print();
		cout << c << " ";
	}
private:
	double c;
};
class Derived2 :public Base{
public:
	Derived2(double _a, double _b, double _c) :Base(_a, _b)
	{
		c = examine(_c);
	}
	double examine(double x)
	{
		if (x < c)
			x = c;
		c = Base::examine(x);
		return c;
	}
	void print()
	{
		Base::print();
		cout << c << " ";
	}
private:
	double c;
};
int main()
{
	Base a(1, 3);
	Derived1 b(3, 5, 6);
	cout << a.examine(2) << endl;
	a.print();
	cout << endl << b.examine(2) << endl;
	b.print();

	///second version

	cout << -2%6<<" "<<endl << " ======================= " << endl;
	Base c(1, 3);
	Derived2 d(3, 5, 6);
	cout << c.examine(2) << endl;
	c.print();
	cout << endl << d.examine(2) << endl;
	d.print();

	int i;
	cin >> i;

}