#pragma once
#include "A.h"
class B:public A
{
private:
	char *name;
protected:
	B(void);
	B(char*);
	B(const B&);
public:
	
	const char * getName () const;
	void setName (char*Name);
	B& operator=(const B& N);
	~B(void);
};

