#include <iostream>

using namespace std;
class NegValue
{

};
class WrongValue
{
public:
	WrongValue(int t) :wv(t){}
	int wv;
};
double g(int n, double *A)
{
	double sum=0;
	for (int i = 0; i < n; ++i)
	{
		if (A[i] < 0)
			throw NegValue();
		if (A[i]<10 || A[i]>100)
			throw WrongValue(i);
		sum += A[i];
	}
	return sum/=n;
}
double f()
{
	int n, res;
	cin >> n;
	double *a = new double[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (;;)
	{
		try
		{
			res = g(n, a);
			delete[] a;
			return res;
		}
		catch (WrongValue e)
		{
			cout << "error input in " << e.wv << " index\n";
			cout << "input it now: ";
			cin >> a[e.wv];
		}
		catch (NegValue)
		{
			delete[] a;
			throw NegValue();
		}
	}
	
}
int main()
{

	try
	{
		cout << f();
	}
	catch (NegValue)
	{
		cout << "You have a negative value in your massive, goodbye!";
	}
	int i;
	cin >> i;
	return 0;
}