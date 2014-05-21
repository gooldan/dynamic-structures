#include <iostream>
#include "bus.h"
#include "my_1_string.h"
using namespace std;
int stoi(String s)
{
	int len = s.lenth() - 2;
	char *ts = new char[len + 1];
	ts[len] = '\0';
	int i = len - 1;
	while (s[s.lenth()-1] != ' ')
	{
		ts[i--] = s.pop_back();
	}
	int k = atoi(ts);
	delete[] ts;
	return k;
}
int main()
{
	GreedyBus *Bus= new GreedyBus;
	String s;
	do
	{
		cin >> s; 
		if (s[0] == 'l')
			Bus->turn(-1);
		else
		if (s[0] == 'r')
			Bus->turn(1);
		else
		if (s[0] == 'm')
			Bus->profit();
		else
		if (s[0] == 'w')
			Bus->position();
		else
		if (s[0] == 's')
		{
			delete Bus;
			Bus=new GreedyBus(s[2] - '0', s[4] - '0', s[6] - '0' - 1);
		}
		else
		if (s[0] == 'f')
			Bus->drive(stoi(s));
		else
		if (s[0] == 'i')
			Bus->goIn(stoi(s));
		else
		if (s[0] == 'o')
			Bus->goOut(stoi(s));
	} while (s != "exit");
	cout << "Your travel is over. Profit from the last travel is: ";
	Bus->profit();
	delete Bus;
	int i;
	cin >> i;
}