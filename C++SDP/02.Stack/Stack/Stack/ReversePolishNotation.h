#ifndef REVERSEPOLISHNOTATION_H
#define REVERSEPOLISHNOTATION_H
#include <cstring>
#include <stack>

using namespace std;

class ReversePolishNotation
{
	char* primExpr;
public:
	char* exprToPolishNotation() ;
	bool isToken(char&);
	int priority(const char&);


	ReversePolishNotation(char* expr);
	~ReversePolishNotation(void);
};
#endif

