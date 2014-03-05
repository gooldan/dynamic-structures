#include <iostream>

using namespace std;
int countx = 1;
class who{
public:
	who();
	who(char c);
	~who();
	char get_ch();
private:
	char ch;
};
who::who()
{
	ch = 23;
	cout << "Creating object who" << endl;
}
who::who(char c)
{
	ch = c;
	cout << "Creating object who <" << ch << ">" << endl;
}
who::~who()
{
	cout << "Deleting object who <" << ch << ">" << endl;
}
char who::get_ch()
{
	return ch;
}
who make_who(char c)
{
	who w(c);
	return w;
}
void f_value(who a)
{
}
void f_address(who &a)
{
}
void f_pointer(who *a)
{
}
int main()
{
	who a('a');
	who b('b');
	who c('c');
	who d = make_who('d');
	f_value(a);
	f_address(b);
	f_pointer(&c);
	who mas[10];
	for (int i = 0; i < 10; ++i)
	{
		mas[i] = make_who('A' + i);
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << mas[i].get_ch() << " ";
	}
	int i;
	cin >> i;
}