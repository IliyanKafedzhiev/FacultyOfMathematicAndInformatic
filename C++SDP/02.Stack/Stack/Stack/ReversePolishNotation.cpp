#include "ReversePolishNotation.h"
#include <stack>

ReversePolishNotation::ReversePolishNotation(char* expr)
{	
	int l = strlen(expr) + 1;
	primExpr = new char[l];
	for (int i = 0; i < l ; i++)
	{
		primExpr[i] = expr[i];
	}
};

ReversePolishNotation::~ReversePolishNotation(void)
{
	delete [] primExpr;
}

bool ReversePolishNotation::isToken(char& symbol)
{
	switch (symbol)
	{
	case '+':
		return true;
		break;
	case '-':
		return true;
		break;
	case '*':
		return true;
		break;
	case '/':
		return true;
		break;
	default:
		break;
	}
	return false;
}

int ReversePolishNotation::priority(const char& token)
{
	switch (token)
	{
	case '+':
	case '-':return 0;
	case '*':
	case '/':return 1;
	default:
		return -1;
	}
}

char* ReversePolishNotation::exprToPolishNotation() 
{
	int length = strlen(this->primExpr);
	stack<char>*tokens= new stack<char>();
	stack<char>*RPN= new stack<char>();
	
	for (int i = 0; i < length; i++)
	{
		if (primExpr[i] >= '0' && primExpr[i] <= '9')
		{
			RPN->push(primExpr[i]);
		}
		else if (primExpr[i] == '(')
		{
			tokens->push(primExpr[i]);
		}
		else if (isToken(primExpr[i]))
		{
			char currToken=tokens->top();
			while (currToken && priority(currToken) > priority(primExpr[i]))
			{
				tokens->pop();
				RPN->push(currToken);
				currToken=tokens->top();
			}
			tokens->push(primExpr[i]);
		}
		else if (primExpr[i] == ')')
		{
			char currToken= tokens->top();
			tokens->pop();
			while (currToken && currToken != '(')
			{
				RPN->push(currToken);
				currToken= tokens->top();
				tokens->pop();
			}
		}
	}
	char currToken= tokens->top();
			tokens->pop();
	while (!tokens->empty())
	{
		RPN->push(currToken);
		currToken= tokens->top();
		tokens->pop();
	}
	
	char* finishedOperation = new char[length];
	char op = RPN->top();
	RPN->pop();
	while (!RPN->empty())
	{
		*finishedOperation++ = op;
		op = RPN->top();
		RPN->pop();
	}
	*finishedOperation = '\0';
	return finishedOperation;
}
