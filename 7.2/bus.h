#pragma once
#include "vehicle.h"
class GreedyBus :public Vehicle
{
public:
	GreedyBus() :Vehicle(){ money = 0; pCount = 0; }
	GreedyBus(int _x, int _y, int _Direction) :Vehicle(_x, _y, _Direction){ money = 0; pCount = 0; }
	bool drive(int distance);
	void goIn(int count);
	void goOut(int count);
	void profit();
private:
	int pCount,money;
};