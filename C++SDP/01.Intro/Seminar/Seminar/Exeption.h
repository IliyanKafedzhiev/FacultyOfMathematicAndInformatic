#pragma once
class Exeption
{
	char* reason;
	void setReason(const char*);
public:
	Exeption(const char*);
	virtual ~Exeption(void);
	Exeption& operator=(const Exeption&);
	Exeption(const Exeption&);
	virtual void print() const;
	const char* getReason()const;
};

