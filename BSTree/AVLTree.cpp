#include "AVLTree.h"
#include <iostream>
int AVLTree::balanceFactor(const Node* p)
{
	return getHeight(p->Right) - getHeight(p->Left);
}
//
//				p				q
//			   / \             / \
//			  q   3   =>	  1	   p
//			 / \                  / \
//			1	2			     2    3
Tree::Node* AVLTree::rotateRight(Node* p) // правый поворот вокруг p
{
	Node* q = p->Left;
	if (q->Right)
		q->Right->Parent = p;
	p->Left = q->Right;
	q->Parent = p->Parent;
	if (p->Parent)
	if (p->Parent->Left == p)
		p->Parent->Left = q;
	else
		p->Parent->Right = q;
	if (p == root)
		root = q;
	q->Right = p;
	p->Parent = q;
	updateHeight(p);
	updateHeight(q);
	return q;
}
//                             
//				p				q
//			   / \             / \
//			  q   3   <=	  1	   p
//			 / \                  / \
//			1	2			     2    3
Tree::Node* AVLTree::rotateLeft(Node* q) // левый поворот вокруг q
{
	Node* p = q->Right;
	if (p->Left)
		p->Left->Parent = q;
	q->Right = p->Left;	
	p->Parent = q->Parent;
	if (q->Parent)
	if (q->Parent->Left == q)
		q->Parent->Left = p;
	else
		q->Parent->Right = p;
	p->Left = q;
	if (q == root)
		root = p;
	q->Parent = p;
	updateHeight(q);
	updateHeight(p);
	return p;
}
// 
//          p                                s
//         / \                            /     \
//        1   q       =>                 p       q
//           / \                       /  \     /  \
//          s   4                     1    2   3    4
//         / \ 
//        2   3
Tree::Node* AVLTree::balance(Node* p) // балансировка узла p
{
	updateHeight(p);
	while (p)
	{
		int bal = balanceFactor(p);
		if (bal == 2)
		{
			if (balanceFactor(p->Right) < 0)
				p->Right = rotateRight(p->Right);
			rotateLeft(p);
		}
		if (bal== -2)
		{
			if (balanceFactor(p->Left) > 0)
				p->Left = rotateLeft(p->Left);
			rotateRight(p);
		}
		p = updateHeight(p)->Parent;
	}
	return p;
}

AVLTree::AVLTree()
{
	root = nullptr;
}
void AVLTree::insert(int x)
{
	if (find(x) != nullptr)
		return;
	Node *p = new Node;
	p->Left = nullptr;
	p->Right = nullptr;
	p->data = x;
	p->height = 0;
	if (!root)
	{
		p->height = 0;
		p->Parent = nullptr;
		root = p;
		return;
	}
	Node *t = root;
	Node *pt = nullptr;
	while (t)
	{
		pt = t;
		t = x > t->data ? t->Right : t->Left;
	}
	if (x > pt->data)
		pt->Right = p;
	else
		pt->Left = p;
	p->Parent = pt;
	balance(p);
}
void AVLTree::remove(Node *p)
{
	if (!p)
		return;
	Node *temp = nullptr;
	Node *tempChild = nullptr;
	temp = p->Right ? minimum(p->Right) : p;
	tempChild = temp->Right ? temp->Right : temp->Left;
	if (temp == root)
		root = NULL;
	if (tempChild)
	{
		if (!temp->Parent)
			root = tempChild;
		tempChild->Parent = temp->Parent;
	}
	if (temp->Parent)
	{
		if (temp->Parent->Left == temp)
			temp->Parent->Left = tempChild;
		else
			temp->Parent->Right = tempChild;
	}
	p->data = temp->data;
	temp->Left = nullptr;
	temp->Right = nullptr;
	balance(temp);
	delete temp;
	return;
}
void AVLTree::postOD(Node *p)
{
	if (p != nullptr)
	{
		postOD(p->Left);
		postOD(p->Right);
		delete p;
	}
}
AVLTree::~AVLTree()
{
	postOD(root);
}