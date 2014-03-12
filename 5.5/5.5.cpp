#include <cstdlib>
#include <iostream>

using namespace std;
const int MAX = 10;
class Polynominal{
public:
	double value(double x);
	Polynominal();
	void set_coef(int pow, double val);
	void print();
	Polynominal operator+(Polynominal x);
	Polynominal operator*(Polynominal x);
	Polynominal operator-(Polynominal x);
private:
	double a[MAX];
};
Polynominal::Polynominal()
{
	for (int i = 0; i < MAX; ++i)
		a[i] = 0;
}
double Polynominal::value(double x)
{
	double sum = 0;
	for (int i = 0; i < MAX; ++i)
	{
		sum += a[i] * pow(x, MAX - i - 1);
	}
	return sum;
}
void Polynominal::set_coef(int pow, double val)
{
	if (pow>MAX - 1) return;
	a[pow] = val;
}
Polynominal Polynominal::operator+(Polynominal x)
{
	Polynominal t;
	for (int i = 0; i < MAX; ++i)
	{
		t.a[i] = a[i] + x.a[i];
	}
	return t;
}
void Polynominal::print()
{
	int max = 0;
	int i = MAX - 1;
	while (a[i--] == 0);
	max = i + 1;
	if (max != 1)
	{
		if (a[max] != 1)
			cout << a[max];
		cout << "x^" << max;
		for (int i = max - 1; i > 1; --i)
		if (a[i] != 0)
		{
			cout << (a[i] > 0 ? "+" : "-");
			if (a[i] != 1)
				cout << abs(a[i]);
			cout << "x^" << i;
		}
		if (a[1] != 0)
		{
			cout << (a[1] > 0 ? "+" : "-");
			if (abs(a[1]) != 1)
				cout << abs(a[1]);
			cout << "x";
		}
	}
	else
	{
		if (abs(a[1]) != 1)
			cout << a[1];
		cout << "x";
	}
	if (a[0] != 0)
		cout << (a[0] > 0 ? "+" : "-") << abs(a[0]) << ' ';
	cout << endl;
}
Polynominal Polynominal::operator-(Polynominal x)
{
	Polynominal t;
	for (int i = 0; i < MAX; ++i)
	{
		t.a[i] = a[i] - x.a[i];
	}
	return t;
}
Polynominal Polynominal::operator*(Polynominal x)
{
	Polynominal t;
	for (int i = 0; i < MAX; ++i)
	for (int j = 0; j < MAX; ++j)
	if (i + j < MAX - 1 && a[i] != 0 && x.a[i] != 0)
		t.a[i + j] += a[i] * x.a[j];
	return t;
}
int main()
{
	Polynominal t;
	t.set_coef(0, -3);
	t.set_coef(1, -1);
	t.set_coef(3, -5);
	t.set_coef(7, -5);
	t.print();
	Polynominal t1;
	t1.set_coef(0, -5);
	t1.set_coef(1, 3);
	t1.set_coef(2, 2);
	t1.print();
	Polynominal t3 = t1 + t;
	t3.print();
	t3 = t1*t;
	t3.print();
	t3 = t1 - t3;
	t3.print();
	Polynominal a;
	a.set_coef(0, -1);
	a.set_coef(1, 2);
	a.print();
	Polynominal b;
	b.set_coef(0, 1);
	b.set_coef(1, -2);

	b.print();
	Polynominal c = a*b;
	c.print();
	cout << t3.value(1);
	int i;
	cin >> i;
}