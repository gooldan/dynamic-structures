
#include <iostream>
#include <cmath>

using namespace std;

class Expression
{
public:
	Expression()
	{
		count++;
	}

	virtual ~Expression()
	{
		count--;
	}
	virtual void print() const = 0;
	virtual Expression *copy() const = 0;
	virtual Expression *derivative() const = 0;
	virtual double evaluate(const double NotUsed) const = 0;
	static void showCount()
	{
		cout <<count << endl;
	}
private:

	static int count;
};


class Const : public Expression
{
public:
	Const(double _a) : a(_a) {}
	~Const() {};
	void print() const 
	{
		cout << a;
	}
	Expression *copy() const
	{
		return new Const(a);
	}
	Expression *derivative() const
	{
		return new Const(0);
	}
	double evaluate(const double notUsed) const
	{
		return a;
	}

private:
	double a;

};

class Var : public Expression
{
public:
	void print() const
	{
		cout << 'x';
	}
	~Var() {};
	Expression *copy() const
	{
		return new Var;
	}
	Expression *derivative() const
	{
		return new Const(1);
	}
	double evaluate(const double x) const
	{
		return x;
	}

};

class Sum :public Expression
{
public:

	Sum(Expression *_a, Expression *_b) : a(_a), b(_b) {}
	~Sum()
	{
		delete a;
		delete b;
	}
	void print() const
	{
		a->print();
		cout << '+';
		b->print();
	}
	Expression *copy() const
	{
		return new Sum(a->copy(), b->copy());
	}
	Expression *derivative() const
	{
		return new Sum(a->derivative(), b->derivative());
	}
	double evaluate(const double x) const
	{
		return a->evaluate(x) + b->evaluate(x);
	}
protected:
	Expression *a, *b;

};

class Subs :public Expression
{
public:

	Subs(Expression *_a, Expression *_b) : a(_a), b(_b) {}
	~Subs()
	{
		delete a;
		delete b;
	}
	void print() const
	{
		a->print();
		cout << '-';
		b->print();
	}
	Expression *copy() const
	{
		return new Subs(a->copy(), b->copy());
	}
	Expression *derivative() const
	{
		return new Subs(a->derivative(), b->derivative());
	}
	double evaluate(const double x) const
	{
		return a->evaluate(x) - b->evaluate(x);
	}
protected:
	Expression *a, *b;

};

class Mult :public Expression
{

public:

	Mult(Expression *_a, Expression *_b) : a(_a), b(_b) {}
	~Mult()
	{
		delete a;
		delete b;
	}
	void print() const
	{
		a->print();
		cout << '*';
		b->print();
	}
	Expression *copy() const
	{
		return new Mult(a->copy(), b->copy());
	}
	Expression *derivative() const
	{
		return new Sum(new Mult(a->derivative(), b->copy()), new Mult(a->copy(), b->derivative()));
	}
	double evaluate(const double x) const
	{
		return a->evaluate(x) * b->evaluate(x);
	}
protected:
	Expression *a, *b;

};

class Div :public Expression
{
public:
	Div(Expression *_a, Expression *_b) : a(_a), b(_b) {}
	~Div()
	{
		delete a;
		delete b;
	}
	void print() const
	{
		a->print();
		cout << '/';
		b->print();
	}
	Expression *copy() const
	{
		return new Div(a->copy(), b->copy());
	}
	Expression *derivative() const
	{
		return new Div(new Subs(new Mult(a->derivative(), b->copy()), new Mult(a->copy(), b->derivative())), new Mult(b->copy(), b->copy()));
	}
	double evaluate(const double x) const
	{
		return a->evaluate(x) / b->evaluate(x);
	}
protected:
	Expression *a, *b;

};
class Sin :public Expression
{
public:
	Sin(Expression *_a) : a(_a) {}
	~Sin()
	{
		delete a;
	}
	void print() const
	{
		cout << "sin(";
		a->print();
		cout << ')';
	}
	Expression *copy() const
	{
		return new Sin(a->copy());
	}
	Expression *derivative() const;
	double evaluate(const double x) const
	{
		return sin(a->evaluate(x));
	}
protected:
	Expression *a;

};

class Cos :public Expression
{
public:
	Cos(Expression *aa) : a(aa) {}
	~Cos()
	{
		delete a;
	}
	void print() const
	{
		cout << "cos(";
		a->print();
		cout << ')';
	}
	Expression *copy() const
	{
		return new Cos(a->copy());
	}
	Expression *derivative() const
	{
		return new Mult(new Const(-1), new Mult(new Sin(a->copy()), a->derivative()));
	}
	double evaluate(const double x) const
	{
		return cos(a->evaluate(x));
	}
protected:
	Expression *a;

};

Expression *Sin::derivative() const
{
	return new Mult(new Cos(a->copy()), a->derivative());
}

int Expression::count = 0;

int main()
{
	Expression::showCount();
	Expression *v = new Var;
	Expression *c = new Const(2);
	Expression *m = new Mult(c->copy(), v->copy());
	Expression *c2 = new Const(7);
	Expression *s = new Sum(v->copy(), c2->copy());
	Expression *si = new Sin(s->copy());
	Expression *co = new Cos(m->copy());
	Expression *e;

	si->print();
	cout << endl;
	cout << si->evaluate(9);
	cout << endl;

	co->print();
	e = co->derivative();
	cout << endl;
	e->print();
	cout << endl;
	cout << e->evaluate(2);
	cout << endl;

	Expression::showCount();

	delete co;
	delete si;
	delete v;
	delete c;
	delete m;
	delete c2;
	delete s;
	delete e;

	Expression::showCount();
	int i;
	cin >> i;
}