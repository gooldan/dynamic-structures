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
	void delNullStr();//�������� ������� �����
	void findFreeVar();
	void basisBuild();
	double res[MaxSize][MaxSize];
	int res_m=-1;
	void show();
private:
	double a[MaxSize][MaxSize];
	int freeVar[MaxSize];//������ ��� �������� ����� i-��� ��������� ����������
	int numFreeVar = 0; //���������� �� ����������
	double sols[MaxSize];
	int m, n;
};