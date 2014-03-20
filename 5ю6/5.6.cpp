#include <cstdlib>
#include <iostream>

using namespace std;

const int MAX = 150;

class Queue{
public:
	Queue();
	bool isEmpty();
	bool isFull();
	int size();
	int front();
	void push(int x);
	int pop();
private:
	int mas[MAX];
	int first, last;
};
bool Queue::isEmpty()
{
	return size() == 0;
}
bool Queue::isFull()
{
	return (size() == MAX);
}
int Queue::size()
{
	if (last == -1) return 0;
	return (last < first ? last + (MAX - first) + 1 : last - first + 1);
}
int Queue::front()
{
	if (isEmpty()) return -1;
	return mas[first];
}
Queue::Queue()
{
	for (int i = 0; i < MAX; ++i)
		mas[i] = 0;
	first = 0;
	last = -1;
}
void Queue::push(int x)
{
	if (isFull())
		return;
	if (isEmpty())
	{
		last = 0;
		first = 0;
		mas[last] = x;
		return;
	}
	if (last == MAX - 1)
		last = -1;
	mas[++last] = x;
}
int Queue::pop()
{
	if (isEmpty())
		return -1;
	int k=mas[first];
	mas[first] = 0;
	if (size() == 1)
	{
		last = -1;
		first = 0;
	}
	if (first == MAX - 1)
		first = -1;
	first++;
	return k;
}
int main()
{
	Queue b;
	int n, m, k;
	cin >> n >> m;
	k = n;
	for (int i = 1; i <= n; ++i)
	{
		b.push(i);
	}
	while (b.size() != 1)
	{
		for (int i = 0; i < m-1; ++i)
		{
			b.push(b.pop());
		}
		cout << b.front()<<" ";
		b.pop();
	}
	cout << endl << b.pop() << " - IS A WINNER!! ";
	cout<<b.isEmpty();
	b.push(1);
	cout << b.size();
	int i;
	cin >> i;

}