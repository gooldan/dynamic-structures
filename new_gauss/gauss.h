#pragma once
const int MaxSize = 100;
const double vm = 1e-6;
class Gauss{
public:
	Gauss();
	Gauss(double b[MaxSize][MaxSize], int m, int n);
	void toTriangle();
	void noSolution();
	void partialSolution();
	void Solve();
	void delNullStr();//удаление нулевых строк
	void findFreeVar();
	void basisBuild();
	double res[MaxSize][MaxSize];
	int res_m=-1;
	void show();
private:
	double a[MaxSize][MaxSize];
	int freeVar[MaxSize];//массив где хранится номер i-той свободной переменной
	int numFreeVar = 0; //количество св переменных
	double sols[MaxSize];
	int m, n;
};