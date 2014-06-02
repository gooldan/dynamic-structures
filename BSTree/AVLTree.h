#pragma once
#include "tree.h"
class AVLTree :public Tree{

public:
	AVLTree();
	void insert(int x);
	void remove(Node *p);
	int balanceFactor(const Node *p);
	void resetHeight(Node *p);
	Node* rotateRight(Node *p);
	Node* rotateLeft(Node *p);
	Node* balance(Node *p);
	~AVLTree();
private:
	void postOD(Node *p);
	AVLTree &operator=(const AVLTree &b) {}
	AVLTree(const AVLTree &b) {}

};