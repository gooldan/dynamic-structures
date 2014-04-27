#include <cstdlib>
#include <iostream>
#include "my_1_string.h"
#include <fstream>
using namespace std;
//medium complexity is Î(1)
void print(String s)
{
	cout << s;
}
int main()
{
	ifstream in("a.txt");
	String s("avcddd");
	cout << s << endl;
	s.add('a');
	s.add('a');
	s.add('a');
	s.add('a');
	s.add('b');
	cout << s << endl;
	s.pop_back();
	s.pop_back();
	s.pop_back();
	s.pop_back();
	s.pop_back();
	s.pop_back();
	s.pop_back();
	cout << s << endl;
	s.insert(1, "abcde\0");
	cout << s << endl;
	String ss("assasd");
	s += ss;
	cout << s << endl;
	s.erase(3, 9);
	cout << s << endl;
	in >> ss;
	String t=ss + s;
	cout << t<<endl;
	print(t);
	String sss("avdcd");
	cout << "  " << ( sss!="avcd");
	int i;
	cin >> i;
}