#include "vehicle.h"
#include <iostream>

using namespace std;

Vehicle::Vehicle()
{
	x = 5;
	y = 5;
	direction = 0;
}
Vehicle::Vehicle(int _x, int _y, int _direction) :x(_x), y(_y), direction(_direction)
{
}
void Vehicle::turn(int d)
{
		
	direction = ((direction + 4) + d) % 4;
}
bool Vehicle::drive(int distance)
{
	if (direction == 0)
	{
		y -= distance;
		if (y < 0)
		{
			y = 0;
			return false;
		}
		else
			return true;
	}
	if (direction == 1)
	{
		x += distance;
		if (x > 10)
		{
			x = 10;
			return false;
		}
		else
			return true;
	}
	if (direction == 2)
	{
		y += distance;
		if (y > 10)
		{
			y = 10;
			return false;
		}
		else
			return true;
	}
	if (direction == 3)
	{
		x -= distance;
		if (x < 0)
		{
			x = 0;
			return false;
		}
		else
			return true;
	}
}
void Vehicle::position()
{
	cout << x << " " << y << endl;
}