#include "WeaponArmorItem.h"



ArmorItem::ArmorItem(char* ItemName,TypeItem ItemType,double ItemWeight ,double armor,
					   ArmorTypes ArmorType):Item(ItemName,ItemType,ItemWeight),armor(armor),ArmorType(ArmorType)
{
}

ArmorItem::ArmorItem(const ArmorItem&tmp):Item(tmp),armor(tmp.armor),ArmorType(tmp.ArmorType)
{
}

ArmorItem& ArmorItem::operator=(const ArmorItem&tmp)
{
	if (this!=&tmp)
	{
		Item::operator=(tmp);
		armor=tmp.armor;
		ArmorType=tmp.ArmorType;
	}
	return *this;
}

ArmorItem::~ArmorItem(void)
{
}

