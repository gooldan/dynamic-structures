#include <cstdlib>
#include <iostream>
#include "gauss.h"
#include <fstream>
using namespace std;
bool test_gauss(const char *in_name, const char *out_name)
{
	ifstream in(in_name);
	ifstream out(out_name);
	int m, n;
	double a[MaxSize][MaxSize];
	in >> m >> n;
	for (int i = 0; i < m; ++i)
	for (int j = 0; j < n; ++j)
		in >> a[i][j];

	Gauss Matrix(a, m, n);
	Matrix.Solve();
	//Matrix.show();
	double res[MaxSize][MaxSize];
	int m_rows;
	out >> m_rows;
	for (int i = 0; i < m_rows; ++i)
	for (int j = 0; j < n - 1; ++j)
		in >> res[i][j];
	if (m_rows == Matrix.res_m)
	{
		for (int i = 0; i < m_rows; ++i)
		for (int j = 0; j < n - 1; ++j)
		if (res[i][j] - Matrix.res[i][j]>vm)
			return false;
		return true;
	}
	return false;
}
void main()
{
	if (!test_gauss("input1.txt", "output1.txt"))
	{
		cout << "Test 1 failed!" << endl;
		return;
	}
	if (!test_gauss("input2.txt", "output2.txt"))
	{
		cout << "Test 2 failed!" << endl;
		return;
	}
	if (!test_gauss("input3.txt", "output3.txt"))
	{
		cout << "Test 3 failed!" << endl;
		return;
	}
	
	if (!test_gauss("input4.txt", "output4.txt"))
	{
		cout << "Test 4 failed!" << endl;
		return;
	}

	if (!test_gauss("input5.txt", "output5.txt"))
	{
		cout << "Test 5 failed!" << endl;
		return;
	}
	
	if (!test_gauss("input6.txt", "output6.txt"))
	{
		cout << "Test 6 failed!" << endl;
		return;
	}

	if (!test_gauss("input7.txt", "output7.txt"))
	{
		cout << "Test 7 failed!" << endl;
		return;
	}
	cout << "All tests completed! SUCCESS!";
	int i;
	cin >> i;
}