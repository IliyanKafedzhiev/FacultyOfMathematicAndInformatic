#include <iostream>
#include <string>
#include <cstring>

using namespace std;



class Cart
{
private:
	int index;
	Cart()
	{
		index = 3;
	}
public:
	friend class Invertory;
	
};

class Inventory
{
private:
	void ExtendCatalog();
	int foundIndexByName (string)const;
	friend class Cart;

	//data
	string* Name;
	double* price;
	int capacity;
	int count;
public:
	
	Inventory(void);
	~Inventory(void);
	void Register (const string,const double);
	void PringAllProducts ()const;
	
	Cart CreateCart()
	{
		Cart d;
		return d;
	}
};



class Storage
{
private:
    int m_nValue;
    double m_dValue;
	 Storage()
    {
        m_nValue = 5;
        m_dValue = 5.33;
    }
public:
   
 
    // Make the Display class a friend of Storage
    friend class Display;
};
 
class Display
{
private:
    bool m_bDisplayIntFirst;
 
public:
    Display(bool bDisplayIntFirst) { m_bDisplayIntFirst = bDisplayIntFirst; }
 
	Storage DisplayItem()
    {
		Storage cStorage;
        if (m_bDisplayIntFirst)
            std::cout << cStorage.m_nValue << " " << cStorage.m_dValue << std::endl;
        else // display double first
            std::cout << cStorage.m_dValue << " " << cStorage.m_nValue << std::endl;
		return cStorage;
    }
};