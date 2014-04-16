#include "gauss.h"
#include <math.h>
#include <iostream>;
using namespace std;
void swap(double &a, double &b)
{
	double c = a;
	a = b;
	b = c;
	return;
}
void Gauss::show()
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;
	for (int i = 0; i < res_m; ++i)
	{
		for (int j = 0; j < n-1; ++j)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
void Gauss::toTriangle()
{
	double k;
	int max;
	int r = 0; //текущий ряд
	for (int c = 0; c < n; ++c)
	{
		max = r;
		//находим максимальный по модулю элемент из столбца
		for (int t = r; t<m; ++t)
		{
			if (abs(a[t][c])>abs(a[max][c]))
				max = t;
		}
		//если столбец нулевой, ничего не меняем
		if (a[max][c] == 0) {
			continue;
		}

		//делаем строку с максимальным по модулю элементом первой сверху
		for (int j = c; j < n; ++j)
		{
			swap(a[r][j], a[max][j]);
		}
		for (int i = r + 1; i < m; ++i)
		{
			k = a[i][c] / a[r][c];
			for (int j = c; j < n; ++j)
			{
				a[i][j] -= k*a[r][j];
				if (abs(a[i][j]) < vm)
					a[i][j] = 0;
			}
		}
		r++;

	}
}
Gauss::Gauss()
{

}
Gauss::Gauss(double _a[MaxSize][MaxSize], int _m, int _n)
{
	m = _m;
	n = _n;
	for (int i = 0; i < m; ++i)
	for (int j = 0; j < n; ++j)
		a[i][j] = _a[i][j];

}
void Gauss::delNullStr()
{
	//убираем нулевые строки
	for (int i = m - 1; i >= 0; --i)
	{
		bool tr = true;
		for (int j = n - 1; j >= 0; --j)
		{
			if (a[i][j] != 0)
				tr = false;
		}
		if (tr) m--;
	}
}
void Gauss::findFreeVar()
{
	for (int i = 0; i < n; ++i){
		freeVar[i] = -1;
	}
	int t = 0;
	for (int i = 0; i < m - 1; i++)
	{
		while (a[i][i + t] == 0)
		{
			freeVar[numFreeVar++] = i + t;
			t++;
		}
		if (i + t + 1 >= n)
		{
			noSolution();
			return;
		}
		while ((i + t + 1<n-1) && a[i + 1][i + t + 1] == 0)
		{
			freeVar[numFreeVar++] = i + t + 1;
			t++;
		}
	}
	for (int i = m+t; i < n-1; ++i)
	{
		freeVar[numFreeVar++] = i;
	}

}
void Gauss::basisBuild()
{
	res_m = numFreeVar + 1;
	for (int i = 0; i < m; ++i)
	{
		a[i][n - 1] = 0;
	}
	int p;
	double sum = 0;
	//базис пространства решений
	for (int i = 0; i<numFreeVar; ++i)
	{
		sols[freeVar[i]] = 1;
		p = n - 2;
		for (int j = m - 1; j >= 0; --j)
		{
			for (int v = numFreeVar - 1; v >= 0; --v)
			{
				if (freeVar[v] == p)
					p--;
			}
			sum = a[j][n - 1];
			for (int k = n - 2; k > p; --k)
			{
				sum -= sols[k] * a[j][k];
			}
			if (a[j][p] != 0)
				sols[p] = sum / a[j][p];
			else
			{
				sols[p] = 0;
			}
			p--;
			sum = 0;
		}
		for (int j = 0; j < n - 1; ++j)
			res[i + 1][j] = sols[j];
		sols[freeVar[i]] = 0;

	}
}
void Gauss::Solve()
{
	toTriangle();
	findFreeVar();
	if (res_m == 0) return;
	delNullStr();
	partialSolution();
	if (numFreeVar != 0)
		basisBuild();

}
void Gauss::partialSolution()
{
	for (int i = 0; i < n-1; ++i)
	{
		sols[i] = 0;
	}
	sols[n - 1] = 1;
	double sum = 0;
	int p = n - 2;
	for (int i = m - 1; i >= 0; --i)
	{
		if (numFreeVar > 0)
		{
			for (int v = numFreeVar - 1; v >= 0; --v)
			{
				if (freeVar[v] == p)
					p--;
			}
		}
		sum = a[i][n - 1];
		for (int j = n - 2; j > p; --j)
		{
			sum -= sols[j] * a[i][j];
		}
		if (a[i][p] != 0)
		{
			sols[p] = sum / a[i][p];
		}
		else
		{
			res_m = 0;
			return;
		}
		p--;
		sum = 0;
	}
	for (int i = 0; i < n - 1; ++i)
		res[0][i] = sols[i];
	res_m = 1;
}
void Gauss::noSolution()
{
	res_m = 0;
	return;
}