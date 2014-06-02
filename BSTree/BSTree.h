#pragma once
#include "tree.h"
class BSTree :public Tree{
public:
	BSTree();
	void insert(int x);
	void remove(Node *p);
	~BSTree();
private:
	void postOD(Node *p);
	BSTree &operator=(const BSTree &b) {}
	BSTree(const BSTree &b) {}

};