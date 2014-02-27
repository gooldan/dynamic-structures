#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
struct stack
{
	stack *next, *head;
	char data;
	int size = 0;
};
void Push(char c, stack *&a)
{
	stack *t = new stack;
	t->data = c;
	t->next = a->head;
	a->head = t;
	a->size++;
}
char Pop(stack *&a)
{
	if (a->size == 0)
		return 7;
	char res = a->head->data;
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
bool IsCorrect(char *s)
{
	int len = strlen(s);
	bool res = true;
	stack *cup = new stack;
	for (int i = 0; i < len; ++i)
	{
		if ((s[i] == '}') || (s[i] == ']') || (s[i] == ')'))
		{
			char c = Pop(cup);
			if (s[i] == '}')
			if (c != '{')
				res = false;
			if (s[i] == ']')
			if (c != '[')
				res = false;
			if (s[i] == ')')
			if (c != '(')
				res = false;
			if (!res) break;
		}
		else
		if ((s[i] == '{') || (s[i] == '[') || (s[i] = '('))
			Push(s[i], cup);
	}
	if (!IsEmpty(cup)) res = false;
	Clean(cup);
	return res;
}
int main()
{
	char c = 0;
	int i = 0;
	char *s = new char[100];
	while (c != '\n')
	{
		c = getchar();
		s[i++] = c;
	}
	s[--i] = '\0';
	cout << IsCorrect(s);
	cin >> i;
}