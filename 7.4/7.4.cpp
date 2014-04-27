#include <iostream>

using namespace std;
class Vehicle
{
public:
	Vehicle(int id) :motorId(id){};
	void PrintMotor()
	{
		cout << "My motor id is: " << motorId<<endl;
	}
private:
	int motorId;
};
class GroundVehicle : virtual public Vehicle
{
public:
	GroundVehicle(int id, int wd) :Vehicle(id), wheelDiam(wd){};
	void PrintFull()
	{
		Vehicle::PrintMotor();
		cout << "My wheel diametr is: " << wheelDiam << endl;
	}

private:
	int wheelDiam;
};
class FlyingVehicle :virtual public  Vehicle
{
public:
	FlyingVehicle(int id, int tn) :Vehicle(id), turbineNum(tn){};
	void PrintFull()
	{
		Vehicle::PrintMotor();
		cout << "I have " << turbineNum << " turbines" << endl;
	}

private:
	int turbineNum;
};
class Aircraft :public FlyingVehicle,public GroundVehicle
{
public:
	Aircraft(int id,int wd, int tn) :Vehicle(id),GroundVehicle(id,wd),FlyingVehicle(id,tn){};
	void PrintFull()
	{
		GroundVehicle::PrintFull();
		FlyingVehicle::PrintFull();
		
	}

private:
};
int main()
{
	Aircraft B707(1, 2, 3);
	B707.PrintFull();
	int i;
	cin >> i;
}