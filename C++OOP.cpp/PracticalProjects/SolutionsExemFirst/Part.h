#ifndef PART_H
#define PART_H
class Part
{
public:
	Part(void);
	Part(int,double,char*);
	Part(const Part&);
	int getSerNum() const;
	double getPrice()const;
	char* getNamePart()const;
	void setSerNum(const int);
	void setPrice(const double);
	void setNamePart(const char*);
	void couta();
	~Part(void);
private:
	int serNum;
	double price;
	char* namePart;
};

#endif  PART_H