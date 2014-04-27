#pragma once

class Vehicle
{
public:
	Vehicle();
	Vehicle(int _x, int _y, int _direction);
	void turn(int d); ///-1 =left, 1=right 
	bool drive(int distance);
	void position();
private:
	int x, y;
	int direction; //0-up 1-right 2-down 3-left
};