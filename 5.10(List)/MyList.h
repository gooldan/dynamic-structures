#pragma once
class List{
public:
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
};