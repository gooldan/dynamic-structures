#pragma once
const int MaxSize = 100;
const double vm = 1e-6;
class Gauss{
public:
	Gauss(double b[MaxSize][MaxSize], int m, int n);
	void toTriangle();
	void partialSolution();
	void Solve();//решает матрицу методом Гаусса
	void delNullStr();//удаляет нулевые строки
	void findFreeVar();
	void basisBuild();
	double getResElem(int i, int j);
	double getResM();
	void show();
private:
	double a[MaxSize][MaxSize];
	int freeVar[MaxSize];//массив где хранится номер i-той свободной переменной
	int numFreeVar = 0; //количество св переменных
	double sols[MaxSize];//здесь хранятся конкретные решения для текущей ситуации
	int m, n;
	int res_m = -1;
	double res[MaxSize][MaxSize];
};
