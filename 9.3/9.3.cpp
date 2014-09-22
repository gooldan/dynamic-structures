#include <iostream>
#include <vector>
#include "my_1_string.h"
using namespace std;
const int h = 233;
int a[8] = { rand() % 117, rand() % 117,
rand() % 117, rand() % 117, rand() % 117,
rand() % 117, rand() % 117, rand() % 117, };

int HashF(String s)
{
	int sum = 0;
	int size = s.lenth();
	for (int i = 0; i < size; ++i)
		sum += a[i] * s[i];
	return sum % h;
}

class hashTable
{
public:
	void add(String s)
	{
		int hv = HashF(s);
		bool f = true;
		for (int i = 0; i < table[hv].size(); i++)
		if (table[hv][i] == s)
		{
			f = false;
			count[hv][i]++;
			break;
		}
		if (f)
		{
			table[hv].push_back(s);
			count[hv].push_back(1);
		}
	}
	void printAndDestroy()
	{
		for (int i = 0; i < 233; ++i)
		{

			while (!table[i].empty())
			{
				cout << endl;
				cout << table[i].back() << " - " << count[i].back();
				table[i].pop_back();
				count[i].pop_back();
			}
		}
	}
private:
	vector<String> table[h];
	vector<int> count[h];
};
int main()
{
	hashTable ht;
	String s;
	cin >> s;
	int len = s.lenth();
	int sp = 0;
	for (int i = 0; i < len + 1; ++i)
	if (s[i] == ',' || s[i] == ' ' || s[i] == '.' || i == len)
	{
		if (abs(sp - i) < 1)
		{
			sp = i + 1;
			continue;
		}

		String *s1 = new String(8);
		for (int j = sp; j < i; ++j)
		{
			s1->add(s[j]);
		}
		ht.add(*s1);
		sp = i + 1;
	}
	ht.printAndDestroy();
	cin >> sp;
}