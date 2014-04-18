#include "MyList.h"
#include <iostream>
#include <cstdlib>
using namespace std;

List::List()
{
	Element t;
	t.data = 0;
	t.next = NULL;
	t.prev = NULL;
	head = &t;
	tail = &t;
}
void List::pushFront(const int &x)
{

	Element *p = new Element;
	p->next = NULL;
	p->prev = NULL;
	p->data = x;
	if (size == 0)
	{
		head = p;
		tail = p;
	}
	else
	{
		Element *h = head;
		head = p;
		head->next = h;
		h->prev = p;
		if (size == 1)
			tail = h;
	}
	size++;
}
void List::pushBack(const int &x)
{
	Element *p = new Element;
	p->next = NULL;
	p->prev = NULL;
	p->data = x;
	if (size == 0)
	{
		tail = p;
		head = p;
	}
	else
	{
		Element *h = tail;
		tail = p;
		tail->prev = h;
		h->next = p;
		if (size == 1)
			head = h;
	}
	size++;
}
int List::popFront()
{
	if (size == 0)
		return 0;
	if (size == 1)
	{
		int t = head->data;
		delete head;
		head->data = 0;
		head->next = NULL;
		head->prev = NULL;
		tail->data = 0;
		tail->next = NULL;
		tail->prev = NULL;
		size--;
		return t;
	}
	if (size == 0)
	{
		int t = head->data;
		delete head;
		return t;
	}
	int t = head->data;
	Element *g = head;
	head = head->next;
	head->prev = NULL;
	delete g;
	size--;
	return t;

}
int List::popBack()
{
	if (size == 0)
		return 0;
	size--;
	if (size == 1)
	{
		int t = tail->data;
		delete tail;
		head->data = 0;
		head->next = NULL;
		head->prev = NULL;
		tail->data = 0;
		tail->next = NULL;
		tail->prev = NULL;
		return t;
	}
	if (size == 0)
	{
		int t = tail->data;
		delete tail;
		return t;
	}
	int t = tail->data;
	Element *g = tail;
	tail = tail->prev;
	tail->next = NULL;
	delete g;
	return t;
}
bool List::isEmpty()
{
	return size == 0;
}
int List::count()
{
	return size;
}
void List::reverse()
{
	if (size > 2)
	{
		int count = size - 1;
		int ts = popFront();
		Element *p = new Element;
		p->data = ts;
		p->prev = tail;
		p->next = NULL;
		tail->next = p;
		while (size > 1)
		{
			ts = popFront();
			Element *p = new Element;
			p->data = ts;
			p->prev = tail;
			p->next = tail->next;
			p->next->prev = p;
			tail->next = p;
		}
		Element	*t = tail;
		while (t != NULL)
		{
			t = t->next;
		}
		tail = p;
		size = count + 1;
	}
	else
	if (size == 2)
	{
		int t = popFront();
		pushBack(t);
	}
}
void List::show()
{
	Element *t = head;
	if (size > 2)
	{
		while (t->next != NULL)
		{
			cout << t->data << " <-> ";
			t = t->next;
		}
		cout << t->data;
	}
	else
	if (size == 2)
	{
		cout << head->data << " <-> " << tail->data;
	}
	else
		cout << head->data;
	cout << endl;
}
void List::clear()
{
	if (size == 0) 
		return;
	Element *h = head;
	while (h->next != NULL)
	{
		h = h->next;
		delete h->prev;
	}
	delete h;
	size = 0;
}
List::~List()
{
	clear();
}

