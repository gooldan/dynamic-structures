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
int Vehicle::drive(int distance)
{
	int val;
	if (direction == 0)
	{
		val = y;
		y -=distance;
		
		if (y < 0)
		{
			y = 0;
			return val;
		}
		else
			return distance;
	}
	if (direction == 1)
	{
		val = 10 - x;
		x += distance;
		if (x > 10)
		{
			x = 10;
			return val;
		}
		else
			return distance;
	}
	if (direction == 2)
	{
		val = 10 - y;
		y += distance;
		if (y > 10)
		{
			y = 10;
			return val;
		}
		else
			return distance;
	}
	if (direction == 3)
	{
		val = x;
		x -= distance;
		if (x < 0)
		{
			x = 0;
			return val;
		}
		else
			return distance;
	}
}
void Vehicle::position()
{
	cout << x << " " << y << " ";
	if (direction == 0) cout << "up";
	else
	if (direction == 1) cout << "right";
	else
	if (direction == 2) cout << "down";
	else
	cout << "left";
	cout<<endl;
}