#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
struct stack
{
	stack *next;
	int data;
};
void Push(char c, stack *&a)
{
	stack *t = new stack;
	t->data = c;
	t->next = a;
	a = t;
}

int Pop(stack *&a)
{
	if (a == NULL)
		return 0;
	int res = a->data;
	stack *t = a->next;
	delete a;
	a = t;
	return res;
}
void Clean(stack *&a)
{
	while (a)
	{
		if (a->next == NULL)
		{
			delete a;
			a = NULL;
			continue;
		}
		stack *t = a->next;
		delete a;
		a = t;
	}
}
bool IsEmpty(stack *&a)
{
	return (a == NULL);
}
#pragma warning(disable: 4996)
int main(int argc, char *argv[])
{
	stack *cup = NULL;
	for (int i = 1; i < argc; i++)
	{
		if (argv[i][0] == '+')
			Push(Pop(cup) + Pop(cup),cup);
		else
		if (argv[i][0] == '-'){
			int t1 = Pop(cup);
			int t2 = Pop(cup);
			Push(t2 - t1, cup);
		}
		else
		if (argv[i][0] == '*')
			Push(Pop(cup) * Pop(cup), cup);
		else
		if (argv[i][0] == '/'){
			int t1 = Pop(cup);
			int t2 = Pop(cup);
			Push(t2/t1, cup);
		}
		else
		{
			Push(atoi(argv[i]), cup);
		}
	}

	cout<<Pop(cup);
	Clean(cup);
	return EXIT_SUCCESS;
}
