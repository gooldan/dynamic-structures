#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
struct stack
{
	stack *next, *head;
	char data[10];
	int size = 0;
};
void Push(char *s, stack *&a)
{
	stack *t = new stack;
	int len = strlen(s);
	for (int i = 0; i <= len; ++i)
	{
		t->data[i] = s[i];
	}
	t->next = a->head;
	a->head = t;
	a->size++;
}
char* Pop(stack *&a)
{
	if (a->size == 0)
		return "";
	int len = strlen(a->head->data);
	char  *res = new char[len];
	for (int i = 0; i <= len; ++i)
	{
		res[i] = a->head->data[i];
	}
	stack *t = a->head;
	a->head = t->next;
	delete t;
	a->size--;
	return res;
}
void Clean(stack *&a)
{
	while (a->size)
	{
		stack *t = a->head;
		a->head = t->next;
		delete t;
		a->size--;
	}
}
bool IsEmpty(stack *&a)
{
	return (a->size == 0);
}
void sti(int a, char *&buffer)
{
	int k = (int)log10(a);
	buffer = new char[k];
	for (int i = k; i >= 0; --i)
	{
		buffer[i] = a % 10 + '0';
		a /= 10;
	}
	buffer[++k] = '\0';
}
#pragma warning(disable: 4996)
int main(int argc, char *argv[])
{
	stack *cup = new stack;


	for (int i = 1; i < argc; i++)
	{
		char *s = "";
		if (argv[i][0] == '+')
			sti(atoi(Pop(cup)) + atoi(Pop(cup)), s);
		else
		if (argv[i][0] == '*')
			sti(atoi(Pop(cup)) * atoi(Pop(cup)), s);
		else
		if (argv[i][0] == '/'){
			int t1 = atoi(Pop(cup));
			int t2=atoi(Pop(cup));
			sti(t2 / t1, s);
		}
		else
			s = argv[i];

		Push(s, cup);

	}
	char *s = "";
	if (!IsEmpty(cup))
		s = Pop(cup);
	Clean(cup);
	int len = strlen(s);
	for (int i = 0; i < len; ++i)
		cout << s[i];
	return EXIT_SUCCESS;
}