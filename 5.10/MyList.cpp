#include "MyList.h"
#include <iostream>
#include <cstdlib>
using namespace std;

List::List()
{
	
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
	}
	size++;
}
int List::popFront()
{
	if (size == 0)
		return 0;
	size--;
	if (size == 1)
	{
		int t = head->data;
		delete head;
		head = tail;
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
		tail = head;
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
		head = t;
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
	if (size == 1)
		cout << head->data;
	else
		cout << "List is empty.";
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

