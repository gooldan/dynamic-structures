#include "list.h"
#include <iostream>
#include <cstdlib>
int Max(int a, int b)
{
	return a > b ? a : b;
}
using namespace std;
int main()
{
	List list;
	for (int i = 0; i < 6; i++)
	{
		list.pushFront(rand() % 117);
		list.pushBack(rand() % 117);
	}

	for (List::iterator it = list.begin(); it != list.end(); ++it)
		cout << *it << " ";
	cout << endl;
	list.show();

	for (int i = 0; i < 3; i++)
	{
		list.popBack();
		list.popFront();
	}

	list.show();
	cout << list.count() << endl;

	for (List::iterator it = --(list.end()); it != list.begin(); --it)
		cout << *it << " ";
	cout << *list.begin();
	cout << endl;
	int max = *(list.begin());
	for (List::iterator it = list.begin(); it != list.end(); ++it)
		max = Max(*it, max);

	cout << max << endl;

	list.show();
	cout << endl;

	
	for (List::iterator it = list.begin(); it != list.end(); ++it)
		if (*it % 2 == 0)
			list.insert(it, *it - 1);
	list.show();
	cout << endl;
	list.insert(list.begin(), 99);
	list.insert(list.end(), 117);
	list.show();
	for (List::iterator it = list.begin(); it != list.end(); ++it)
	if (*it % 3 == 0)
	{
		it = list.erase(it);
		--it;
	}

	list.show();
	List::iterator it = list.begin();
	while (it != list.end())
	{
		it=list.erase(it);
		list.show();
	}
	int i;
	cin >> i;
}