#include <iostream>
#include <list>
#include "my_1_string.h"
using namespace std;

int main()
{
	int *ht = new int[233];
	list<String> *t = new list<String>[233];
	for (int i = 0; i < 233; ++i)
		ht[i] = 0;
	String s;
	cin >> s;
	String w;
	int a[8] = { rand() % 117, rand() % 117,
		rand() % 117, rand() % 117, rand() % 117,
		rand() % 117, rand() % 117, rand() % 117, };
	int len = s.lenth();
	int sp = 0,h=0;
	for (int i = 0; i < len+1;++i)
	if (s[i] == ',' || s[i] == ' ' || s[i] == '.' || i == len)
	{
		h = 0;
		if (abs(sp - i) <= 1)
		{
			sp = i+1;
			continue;
		}

		String *s1=new String(8);
		for (int j = sp; j < i; ++j)
		{
			h += s[j] * a[j % 8];
			s1->add(s[j]);
		}
		h = h % 233;
		
		t[h].push_back(*s1);
		
		sp = i+1;
	}
	sp = 0;
	for (int i= 0; i < 233; ++i)
	{
		if (!t[i].empty())
		{
			cout << endl;
			cout << t[i].front() << " ";
			int sv=0;
			while (!t[i].empty())
			{
				sv++;
				t[i].pop_back();
			}
			cout << "- " << sv;
		}
		
	}
	cin >> sp;
}