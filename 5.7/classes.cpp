#include "classes.h"
int stoi(String s, int base=10){
	int factor = 1, ans = 0, n = s.lenth();
	for (int i = n - 1; i >= 0; i--) {
		ans += ((s[i]<'A') ? (s[i] - '0') : (s[i] - 'A') + 10)*factor;
		factor *= base;
	}
	return ans;

}
Int::Int() 
{
	num = 0;
}

Int::Int(int _num)
{
	num = _num;
}

Int::Int(String s)
{
	num = stoi(s);
}

Int::Int(String s, int base)
{
	num = stoi(s, base);
}
void Int::print()
{
	cout << num << endl;
}

Int Int::operator--(int notused) {
	Int t(*this);
	--(*this);
	return t;
}

Int Int::operator--()
{
	num--;
	return (*this);
}

Int operator -(Int &a, Int &b)
{
	Int c(a);
	c.num -= b.num;
	return c;
}
void Double::print()
{
	cout << num << endl;
}

Double::Double() 
{
	num = 0;
}

Double::Double(double _num) 
{
	num = _num;
}

Double Double::operator %(int a)
{
	int factor = num / a;
	return num - (a*factor);
}