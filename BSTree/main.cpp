#include "AVLTree.h"
#include "BSTree.h"
#include <iostream>
#include "my_1_string.h"
using namespace std;
int stoi(String s)
{
	int len = s.lenth() - 2;
	char *ts = new char[len + 1];
	ts[len] = '\0';
	int i = len - 1;
	while (s[s.lenth() - 1] != ' ')
	{
		ts[i--] = s.pop_back();
	}
	int k = atoi(ts);
	delete[] ts;
	return k;
}
int ninepointone()
{
	BSTree *t=new BSTree;
	for (int i = 0; i < 20; i++)
	{
		int e = rand() % 100 + 1;
		t->insert(e);
		cout << e << " ";
		
	}
	cout << endl;
	t->breadthFirstTraversal();
	t->inOrderTraversal();
	t->postOrderTraversal();
	t->preOrderTraversal();
	Tree::Node *v = t->minimum(t->root);
	for (;;)
	{
		v = t->successor(v);
		if (!v)
			break;
		else
		if (v->data%2==0)
			cout <<v->data<<" ";
	}

	cout << endl;
	v = t->maximum(t->root);
	for (;;)
	{
		v = t->predecessor(v);
		if (!v)
			break;
		else
		if (v->data % 2 != 0)
			cout << v->data << " ";
	}
	v = t->minimum(t->root);
	Tree::Node *nextv = t->successor(v);
	for (;;)
	{
		
		if (!v)
			break;
		else
		if (v->data % 3 == 0)
		{
			t->remove(v);
			if (!nextv) break;
			v = nextv;
			nextv = t->successor(v);
		}
		else
		{
			v = nextv;
			nextv = t->successor(v);
		}
	}
	cout << endl;
	t->breadthFirstTraversal();

	delete t;

	t = new BSTree;
	t->insert(4);
	t->insert(2);
	t->insert(6);
	t->insert(1);
	t->insert(3);
	t->insert(5);
	t->insert(7);
	t->breadthFirstTraversal();
	t->remove(t->find(4));
	t->breadthFirstTraversal();
	return 0;
}
int ninepointtwo()
{
	String s;
	//ifstream in("tree.in");
	//ofstream out("tree.out");
	cin >> s;

	if (s[0] == '0')
	{
		BSTree bst;
		while (s != "exit")
		{
			cin >> s;
			if (s[0]=='i')
			if (s[1] == ' ')
				bst.insert(stoi(s));
			else
				bst.inOrderTraversal();
			if (s[0] == 'd')
				bst.remove(bst.find(stoi(s)));
			if (s[0] == 'p')
			if (s[1] == 'r')
				bst.preOrderTraversal();
			else
				bst.postOrderTraversal();
			if (s[0] == 'b')
				bst.breadthFirstTraversal();
			if (s[0] == 'h')
				cout<<bst.getHeight(bst.getRoot())<<endl;
		}
	}
	else
	{
		AVLTree avlt;
		while (s != "exit")
		{
			cin >> s;
			if (s[0] == 'i')
			if (s[1] == ' ')
				avlt.insert(stoi(s));
			else
				avlt.inOrderTraversal();
			if (s[0] == 'd')
				avlt.remove(avlt.find(stoi(s)));
			if (s[0] == 'p')
			if (s[1] == 'r')
				avlt.preOrderTraversal();
			else
				avlt.postOrderTraversal();
			if (s[0] == 'b')
				avlt.breadthFirstTraversal();
			if (s[0] == 'h')
				cout << avlt.getHeight(avlt.getRoot()) << endl;
		}
	}
	return 0;
}

int main()
{
	//ninepointone();
	ninepointtwo();
	/*AVLTree *t=new AVLTree;
	for (int i = 0; i < 10; i++)
	{
		t->insert(rand() % 117 * 3);
	}
	t->breadthFirstTraversal();
	Tree::Node *v = t->minimum(t->root);
	int nextv = t->successor(v)->data;
	for (;;)
	{

		if (!v)
			break;
		else
		if (v->data % 3 == 0)
		{
			t->remove(v);
			if (!nextv) break;
			v = t->find(nextv);
			if (!t->successor(v))
				break;
			nextv = t->successor(v)->data;
		}
	}
	t->remove(v);
	cout << endl;
	t->breadthFirstTraversal();*/

	int i;
	cin >> i;
}