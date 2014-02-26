#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
struct complex
{
	double re;
	double im;
};
complex ToComplex(double x, double y)
{
	complex a;
	a.re = x;
	a.im = y;
	return a;
}
complex Conjugation(complex n)
{
	complex a = n;
	a.im *= -1;
	return a;
}
void print(complex n)
{
	cout << n.re << (n.im > 0 ? "+" : "-") << abs(n.im) << "i";
}
void println(complex n)
{
	cout << n.re << (n.im > 0 ? "+" : "-") << abs(n.im) << "i" << endl;
}
complex operator +(complex a, complex b)
{
	return ToComplex(a.re + b.re, a.im + b.im);
}
complex operator -(complex a, complex b)
{
	return ToComplex(a.re - b.re, a.im - b.im);
}
complex operator *(complex a, complex b)
{
	return ToComplex(a.re*b.re - a.im*b.im, a.im*b.re + a.re*b.im);
}
bool operator <(complex a, complex b)
{
	return (a.re==b.re?a.im<b.im:a.re<b.re);
}
bool operator >(complex a, complex b)
{
	return (a.re == b.re ? a.im>b.im : a.re>b.re);
}
bool operator <=(complex a, complex b)
{
	return (a.re == b.re ? a.im<=b.im : a.re<=b.re);
}
bool operator >=(complex a, complex b)
{
	return (a.re == b.re ? a.im>=b.im : a.re>=b.re);
}
template <class T>
void qsort(T a[], int l, int r)
{
	if (l == r) return;
	T x = a[rand() % (r - l) + l];
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (i < r)
		qsort(a, i, r);
	if (l < j)
		qsort(a, l, j);
}
int main()
{
	int i;
	complex a[1000];
	time_t ltime;

	srand(time(&ltime));
	for (int i = 0; i < 1000; ++i)
	{
		a[i] = ToComplex(rand() % 200 - 100, rand() % 200 - 100);
		print(a[i]);
		cout << " ";
	}
	cout << endl;
	qsort(a, 0, 999);
	for (int i = 0; i < 10; ++i)
	{
		print(a[i]);
		cout << " ";
	}
	cin >> i;
}