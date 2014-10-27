#pragma once
#include "exeption.h"

class OutOfRange :
	public Exeption
{
	int index;
public:
	OutOfRange(const char* ,int);
	~OutOfRange(void);
	void print();
	int getIndex() const;
};

