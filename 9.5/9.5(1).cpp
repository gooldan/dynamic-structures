#include <iostream>
#include <fstream>
#include <map>
#include "my_1_string.h"
using namespace std;

int main()
{
	ifstream in("dict.txt");
	String s;
	int x;
	map<int, String> m;
	while (in >> x) 
	{
		in >> s;
		m[x] = s;
	}
	while (cin >> x) 
	{
		if (m.find(x) != m.end())
			cout << m[x] << " ";
	}
	return 0;
}