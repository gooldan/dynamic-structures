#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int d[1000], p[1000],a[1000]; 
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) 
	{
		d[i] = 1;
		p[i] = -1;
		for (int j = 0; j < i; ++j)
			if (a[j] < a[i])
				if (1 + d[j] > d[i]) 
				{
					d[i] = 1 + d[j];
					p[i] = j;
				}
	}

	int ans = d[0], pos = 0;
	for (int i = 0; i<n; ++i)
	if (d[i] > ans) 
	{
		ans = d[i];
		pos = i;
	}
	cout << ans << endl;

	vector<int> path;
	while (pos != -1) {
		path.push_back(pos);
		pos = p[pos];
	}
	reverse(path.begin(), path.end());
	for (int i = 0; i<(int)path.size(); ++i)
		cout << a[path[i]] << ' ';
	cin >> n;
}