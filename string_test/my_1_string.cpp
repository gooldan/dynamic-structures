#include "my_1_string.h"

///counts new size if size+n+1>volume
int addingVolumeCheck(int newsize, int volume)
{
	int i = 0;
	while (volume*(int)pow(2, i) - 1 < newsize)
		i++;
	if (i == 0)
		return volume;
	return volume*(int)pow(2, i);
}
int max(int a, int b)
{
	return(a > b ? a : b);
}
int deletingVolumeCheck(int newsize, int volume)
{
	int i = 0;
	if (volume >= 2 * (newsize + 1))
	{
		while (volume / (int)pow(2, i) >= max(newsize + 1, cMinSize))
			i++;
	}
	if (i == 0) return volume;
	return volume / (int)pow(2, --i);
}
String::String(int size, int capacity)
{
	volume = addingVolumeCheck(size, capacity);
	p = new char[volume];
	for (int i = 0; i < size; ++i)
	{
		p[i] = '.';
	}
	p[size] = '\0';
}
String::String(const char *str)
{
	int len = strlen(str);
	volume = addingVolumeCheck(len, cMinSize);
	p = new char[volume];
	size = len;
	for (int i = 0; i < size; ++i)
	{
		p[i] = str[i];
	}
	p[size] = '\0';
}
String::~String()
{
	delete[]p;
	p = NULL;
}
String::String(const String &obj)
{
	size = obj.size;
	volume = obj.volume;
	p = new char[volume];
	for (int i = 0; i <= size; ++i)
		p[i] = obj.p[i];
}
String &String:: operator=(const String &obj)
{
	if (this != &obj)
	{
		size = obj.size;
		volume = obj.volume;
		p = new char[volume];
		for (int i = 0; i <= size; ++i)
			p[i] = obj.p[i];
	}
	return *this;
}
int String::lenth()
{
	return size;
}
int String::capacity()
{
	return volume;
}
bool String::isEmpty()
{
	return size == 0;
}
void String::clear()
{
	delete[] p;
	volume = cMinSize;
	size = 0;
	p = new char[volume];
	p[0] = '\0';
}
void String::add(char c)
{
	int newVolume = addingVolumeCheck(size + 1, volume);
	if (newVolume > volume)
	{
		char *t = new char[newVolume];
		for (int i = 0; i < size; ++i)
		{
			t[i] = p[i];
		}
		t[size++] = c;
		t[size] = '\0';
		delete[] p;
		p = t;
		volume = newVolume;
		return;
	}
	p[size++] = c;
	p[size] = '\0';
}
char String::pop_back()
{
	int newVolume = deletingVolumeCheck(size - 1, volume);
	char c = p[size - 1];
	if (newVolume < volume)
	{
		char *t = new char[newVolume];
		for (int i = 0; i < size - 1; ++i)
		{
			t[i] = p[i];
		}
		t[--size] = '\0';
		delete[] p;
		p = t;
		volume = newVolume;
		return c;
	}
	p[--size] = '\0';
	return c;
}
void String::insert(int pos, const char *str)
{
	if (pos > size || pos<0) return;
	int len = strlen(str);
	int newVolume = addingVolumeCheck(size + len, volume);
	if (newVolume > volume)
	{
		char *t = new char[newVolume];
		for (int i = 0; i < pos; ++i)
		{
			t[i] = p[i];
		}
		for (int i = 0; i < len; ++i)
		{
			t[i + pos] = str[i];
		}
		for (int i = pos + len; i < len + size; ++i)
		{
			t[i] = p[i - len];
		}
		volume = newVolume;
		size += len;
		t[size] = '\0';
		delete[] p;
		p = t;
		return;
	}
	char*t = new char[size - pos];
	for (int i = 0; i < size - pos; ++i)
	{
		t[i] = p[i + pos];
	}
	for (int i = pos; i < len + pos; ++i)
	{
		p[i] = str[i - pos];
	}
	for (int i = pos + len; i < len + size; ++i)
	{
		p[i] = t[i - len - pos];
	}
	size += len;
	p[size] = '\0';
	delete[] t;
}
void String::erase(int pos, int len)
{
	if (pos > size || pos<0) return;
	int newVolume = deletingVolumeCheck(size - len, volume);
	if (newVolume < volume)
	{
		char *t = new char[newVolume];
		for (int i = 0; i < pos; ++i)
		{
			t[i] = p[i];
		}
		for (int i = pos + len; i < size; ++i)
		{
			t[i - len] = p[i];
		}
		t[size - len] = '\0';
		size -= len;
		volume = newVolume;
		delete[] p;
		p = t;
		return;
	}
	for (int i = pos; i < size - len; ++i)
	{
		p[i] = p[i + len];
	}
	p[size - len] = '\0';
	size -= len;
}
String String::operator+(String s1)
{
	char* newString = new char[size + s1.size + 1];
	for (int i = 0; i < size; ++i)
	{
		newString[i] = p[i];
	}
	for (int i = 0; i < s1.size; ++i)
	{
		newString[i + size] = s1.p[i];
	}
	newString[size + s1.size] = '\0';
	String s(newString);
	delete[]newString;
	return s;
}
String String::operator+=(String s1)
{
	char* newString = new char[s1.size + 1];
	for (int i = 0; i < s1.size; ++i)
	{
		newString[i] = s1.p[i];
	}
	newString[s1.size] = '\0';
	this->insert(size, newString);
	delete[]newString;
	return *this;
}
char String::operator[](int ind)
{
	if (ind >= 0 && ind < size)
		return p[ind];
	return 'a';
}
ostream &operator<<(ostream &stream, const String &s) {
	for (int i = 0; i < s.size; ++i)
	{
		stream << s.p[i];
	}
	return stream;
}
istream &operator>>(istream &stream, String &s) {
	char c = '2';
	char str[100];
	int i = 0;
	while (c != '\n')
	{
		c = getchar();
		str[i++] = c;
	}
	str[--i] = '\0';
	s.insert(s.size, str);
	return stream;
}