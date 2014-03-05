#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
struct stack
{
	stack *next;
	char data;
};
void Push(char c, stack *&a)
{
	stack *t = new stack;
	t->data = c;
	t->next = NULL;
	if (a!= NULL)
		t->next = a;
	a = t;
}

char Pop(stack *&a)
{
	if (a == NULL)
		return 7;
	char res = a->data;
	if (a->next == NULL)
	{
		delete a;
		a = NULL;
		return res;
	}
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
bool IsCorrect(char *s)
{
	int len = strlen(s);
	bool res = true;
	stack *cup = new stack;
	cup = NULL;
	for (int i = 0; i < len; ++i)
	{
		if ((s[i] == '}') || (s[i] == ']') || (s[i] == ')'))
		{
			char c = Pop(cup);
			if (s[i] == '}' && c != '{')
				res = false;
			if (s[i] == ']' && c != '[')
				res = false;
			if (s[i] == ')' && c != '(')
				res = false;
			if (!res) break;
		}
		else
		if ((s[i] == '{') || (s[i] == '[') || (s[i] == '('))
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
	delete[]s;
	cin >> i;
}