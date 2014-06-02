#include <iostream>

using namespace std;

int main()
{
	const int n = 11;
	int a[n] = { 3, 0, 12, 5, 1, 17, 6, 5, 18, 4, 2 };
	/*for (int i = 0; i < 10; ++i)
	{
		cin >> a[i];
	}*/
	int k;
	cin >> k;
	for (int i = 0; i < n; ++i)
	{
		int count = 0;
		int same = 0;
		for (int j = 0; j < n; ++j)
		{
			if (a[j]<a[i])
				count++;
			else
			if (a[j] == a[i])
				same++;
		}
		if (count < k+1 && count+same-1>=k)
		{
			k = a[i];
			break;
		}
	}
	cout << k;
}