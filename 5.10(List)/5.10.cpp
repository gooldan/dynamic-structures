#include "MyList.h"
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	List t;
	/*t.pushBack(2);
	t.pushBack(52);
	t.pushFront(3);
	t.pushFront(4);
	t.pushBack(14);
	t.show();
	t.reverse();

	t.show();
	/*int i = t.popFront();
	i = t.popBack();
	i = t.popBack();
	i = t.popFront();
	i = t.popBack();

	t.clear();
*/
	int i;
	cin >> i;
	while (i != 0)
	{
		t.pushFront(i);
		cin >> i;
	}
	int n = t.count(), sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += t.popFront()*t.popBack();
	}
	cout << sum;
	cin >> i;
}