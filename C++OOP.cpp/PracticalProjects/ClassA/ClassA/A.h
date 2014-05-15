#pragma once
#include "B.h"
class A
{
private:
	char *name;
protected:
	A(void);
	A(char*);
	A(const A&);
public:
	
	const char * getName () const;
	void setName (char*Name);
	A& operator=(const A& N);
	~A(void);
};



