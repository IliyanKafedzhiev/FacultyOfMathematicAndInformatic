#include "WeaponArmorItem.h"
#include <cstring>


Item::Item(char* ItemName,TypeItem ItemType,double ItemWeight):ItemWeight(ItemWeight),ItemType(ItemType)
{
	setName(ItemName);
}

Item::Item(const Item& tmp):ItemWeight(tmp.ItemWeight),ItemType(tmp.ItemType)
{
	delete [] ItemName;
	setName(tmp.ItemName);
}

Item::~Item(void)
{
	delete [] ItemName;
}

void Item::setName(const char* ItemName)
{
	this->ItemName=new char[strlen(ItemName)+1];
	for (int i = 0; i <=strlen(ItemName); i++)
	{
		this->ItemName[i]=ItemName[i];
	}

}

Item& Item::operator=(const Item& tmp)
{
	if (this!=&tmp)
	{
		delete [] ItemName;
		setName(tmp.ItemName);
		ItemWeight=tmp.ItemWeight;
		ItemType=tmp.ItemType;
	}
	
	return *this;
}
