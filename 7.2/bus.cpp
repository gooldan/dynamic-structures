#include "bus.h"
#include <iostream>

using namespace std;
int GreedyBus::drive(int distance)
{
	
	int dist = Vehicle::drive(distance);
	money += dist*pCount;
	return dist;
}
void GreedyBus::goIn(int count)
{
	pCount += count;
}
void GreedyBus::goOut(int count)
{
	pCount -= count;
	if (pCount < 0)
		pCount = 0;
}
void GreedyBus::profit()
{
	cout << money <<" rubles! wow "<< endl;
}