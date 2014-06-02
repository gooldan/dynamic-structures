#pragma once
class List{
public:
	class iterator;
	List();
	void pushFront(const int &x);
	void pushBack(const int &x);
	int popFront();
	int popBack();
	//int &front();
	//int &back();
	bool isEmpty();
	int count();
	void reverse();
	void show();
	void clear();
	~List();
	iterator begin();
	iterator end();
	iterator insert(iterator position, const int &x);
	iterator erase(iterator position);
private:
	List &operator=(const List &obj){};
	List(const List &obj){};
	struct Element{
		int data;
		Element *next;
		Element *prev;
	};
	int size;
	Element *head;
	Element *tail;
	Element *ftail;
};
class List::iterator
{
	friend class List;
public:
	iterator() : element(0)
	{
	}
	iterator(Element * _element) : element(_element)
	{
	}

	bool operator==(const iterator &it) const;
	bool operator!=(const iterator &it) const;
	iterator operator++();
	iterator operator--();
	int & operator*() const;
	Element * operator->() const;
private:
	Element *element;
};