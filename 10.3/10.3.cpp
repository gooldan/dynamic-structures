#include <iostream>

using namespace std;
int num;
int sump;
int view[100];
void Print(int **a,int *w,int *p,int s, int n)
{
	
	if (a[s][n] == 0) 
		return;        
	else if (a[s - 1][n] == a[s][n])
		Print(a,w,p,s - 1, n);  
	else
	{
		Print(a,w,p,s - 1, n - w[s]); 
		view[num] = s;
		num+=1;
		sump += p[s];
	}
}
int main()
{
	num = 0;
	sump = 0;
	int w[100] = { 0 };
	int p[100] = { 0 };
	
	int N, W;
	cin >> N >> W;
	int **a = new int*[N + 1];
	for (int i = 0; i < N + 1; ++i)
		a[i]=new int[W + 1];

	for (int i = 1; i <= N; ++i)
	{
		cin >> w[i]>>p[i];
	}
	for (int i = 0; i <= N; ++i)
		a[i][0] = 0;
	for (int i = 0; i <= W; ++i)
		a[0][i] = 0;
	for (int i = 1; i <= N; ++i)       
	{                       
		for (int j = 0; j <= W; ++j)   
		{
			a[i][j] = a[i - 1][j];
			if (j >= w[i] && (a[i - 1][j - w[i]] + p[i] > a[i][j]))
				a[i][j] = a[i - 1][j - w[i]] + p[i];
		}
	};
	Print(a,w,p,N, W);
	cout << num << " " << sump<<endl;
	for (int i = 0; i < num; ++i)
		cout << view[i] << " ";
	for (int i = 0; i < N+1; i++){
		delete[] a[i];
	}
	delete[]a;
	cin >> N;
}