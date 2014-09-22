#include <iostream>
using namespace std;
class task
{
public:
	task():cost(0), deadline(0),num(0){};
	task(int c,int d,int n) :cost(c), deadline(d),num(n){};
	int cost;
	int deadline;
	int num;
};
void sort(task *a,int m)
{
	for (int i = 0; i < m; i++)
	for (int j = 0; j < m - i - 1; j++)
	if (a[j].cost < a[j + 1].cost)
		swap(a[j], a[j + 1]);
}
int main()
{
	int n, m;
	cin >> n >> m;
	task *tasks = new task[m];
	for (int i = 0; i < m; ++i)
	{
		cin >> tasks[i].deadline >> tasks[i].cost;
		tasks[i].num = i + 1;
	}
	sort(tasks,m);
	int *schedule = new int[n+1];
	for (int i = 1; i < n+1; ++i)
	{
		schedule[i] = 0;
	}
	int sum = 0;
	for (int i = 0; i < m; ++i)
	{
		int j = 0;
		j = tasks[i].deadline;
		while (j >= 0 && schedule[j--] != 0)
		;
		if (j < 0) continue;
		schedule[++j] = tasks[i].num;
		sum += tasks[i].cost;
	}
	cout << sum << endl;
	for (int i = 1; i < n + 1; ++i)
	{
		cout << schedule[i] << " ";
	}
	delete[] tasks;
	delete[] schedule;
	cin >> m;
}