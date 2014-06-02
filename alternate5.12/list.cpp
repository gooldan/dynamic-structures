#include "list.h"
#include <iostream>
#include <cstdlib>
using namespace std;

List::List()
{
	size = 0;
	ftail = new Element;
	ftail->next = NULL;
	ftail->prev = tail;
	ftail->data = 117;
	tail = NULL;
	head = NULL;
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
		ftail->prev = tail;
		tail->next = ftail;
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
		ftail->prev = tail;
		tail->next = ftail;
	}
	else
	{
		Element *h = tail;
		tail = p;
		tail->prev = h;
		ftail->prev = tail;
		tail->next = ftail;
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
		head = tail = 0;
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
		ftail->prev = tail;
		tail->next = ftail;
		return t;
	}
	if (size == 0)
	{
		int t = tail->data;
		delete tail;
		head = tail = 0;
		return t;
	}
	int t = tail->data;
	Element *g = tail;
	tail = tail->prev; 
	ftail->prev = tail;
	tail->next = ftail;
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
		ftail->prev = tail;
		tail->next = ftail;
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
		while (t->next != ftail)
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
	while (h->next != ftail)
	{
		h = h->next;
		delete h->prev;
	}
	delete h;
	head = tail = 0;
	size = 0;
}
List::~List()
{
	clear();

	delete ftail;
}


List::iterator List::begin()
{
	return iterator(head);
}
List::iterator List::end()
{
	return iterator(ftail);
}
bool List::iterator::operator==(const List::iterator &it) const
{
	if (element == it.element)
		return true;
	return false;
}
bool List::iterator::operator!=(const List::iterator &it) const
{
	if (element != it.element)
		return true;
	return false;
}
List::iterator List::iterator::operator++()
{
	if (element->next)
		element = element->next;
	iterator copy(element);
	return copy;

}List::iterator List::iterator::operator--()
{
	if (element->prev != nullptr)
		element = element->prev;
	iterator copy(element);
	return copy;

}
int &List::iterator::operator*() const
{
	return element->data;
}
List::Element *List::iterator::operator->() const
{
	return element;
}
List::iterator List::insert(List::iterator position, const int &x)
{
	Element *newElem = new Element;
	newElem->data = x;
	newElem->next = position.operator->();
	newElem->prev = position->prev;
	if (position->prev)
		newElem->prev->next = newElem;
	else
		head = newElem;
	if (position->next)
		newElem->next->prev = newElem;
	else
	{
		tail = newElem;
		ftail->prev = tail;
		tail->next = ftail;
	}

	size++;
	return iterator(newElem);
}

List::iterator List::erase(List::iterator position)
{
	Element * elem = position.operator->();
	//if(elem->next)
	if (elem->prev)
	{
		elem->prev->next = elem->next;
		elem->next->prev = elem->prev;
		if (elem->next == ftail)
			tail = elem->prev;
	}
	else if (size==1)
	{
		position = end();
		size = 0;
		head = tail = 0;
		ftail->prev = tail;
		return position;
	}
	else
		head = position->next;
	elem->next->prev = 0;
	position = iterator(elem);
	++position;
	size--;
	delete elem;
	return position;

}
