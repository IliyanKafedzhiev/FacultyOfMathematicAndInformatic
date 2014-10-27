 /*
 * expr.cpp
 *
 *  Last edited: 09.10.2013
 *       Author: trifon
 */

#include <iostream>
using namespace std;

#include "lstack.cpp"

const int MAX = 100;

char input[MAX], rpn[MAX];

int priority(char op)
{
	switch (op)
	{
		case '+':
		case '-':return 0;
		case '*':
		case '/':return 1;
		default:return -1;
	}
}

void read()
{
	cout << "Enter an expression: ";
	cin.getline(input, MAX - 1);
}

void convert()
{
	char* p = input;
	char* q = rpn;
	LStack<char> s;
	while (*p)
	{
		if (*p == '(')
			s.push(*p);
		else
		if (*p >= '0' && *p <= '9')
			*q++ = *p;
		else
		if (*p == '+' || *p == '-' ||
			*p == '*' || *p == '/')
		{
			char op;
			while (s.peek(op) &&
					priority(op) > priority(*p))
			{
				s.pop(op);
				*q++ = op;
			}
			s.push(*p);
		}
		else
		if (*p ==')')
		{
			char op;
			while (s.pop(op) && op != '(')
				*q++ = op;
		}
		p++;
	}
	char op;
	while (s.pop(op))
		*q++ = op;
	*q = '\0';
	cout << rpn << endl;
}

void calculate()
{
	char* p = rpn;
	LStack<int> s;
	while (*p)
	{
		if ('0' <= *p && *p <= '9')
			s.push(*p - '0');
		else
		{
			int a, b;
			s.pop(b);
			s.pop(a);
			switch (*p)
			{
			case '+':s.push(a + b);break;
			case '-':s.push(a - b);break;
			case '*':s.push(a * b);break;
			case '/':s.push(a / b);break;
			default:s.push(0);
			}
		}
		p++;
	}
	int result;
	s.pop(result);
	cout << "Result: " << result << endl;
}

void calculate_direct()
{
	char* p = input;
	LStack<int> sr;
	LStack<char> so;
	while (*p)
	{
		if (*p == '(' ||
			*p == '+' || *p == '-' ||
			*p == '*' || *p == '/')
			so.push(*p);
		else
		if (*p >= '0' && *p <= '9')
			sr.push(*p-'0');
		else
		if (*p == ')')
		{
			char op;
			while (so.pop(op) && op != '(')
			{
				int a, b;
				sr.pop(b);
				sr.pop(a);
				switch (op)
				{
				case '+':sr.push(a + b);break;
				case '-':sr.push(a - b);break;
				case '*':sr.push(a * b);break;
				case '/':sr.push(a / b);break;
				default:sr.push(0);
				}
			}
		}
		p++;
	}
	int result;
	sr.pop(result);
	cout << "Result: " << result << endl;
}

int main()
{
	read();
	//convert();
	//calculate();
	calculate_direct();
}

