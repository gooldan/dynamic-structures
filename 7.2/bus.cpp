#include "bus.h"
#include <iostream>

using namespace std;
bool GreedyBus::drive(int distance)
{
	money += distance*pCount;

	return Vehicle::drive(distance);
	
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