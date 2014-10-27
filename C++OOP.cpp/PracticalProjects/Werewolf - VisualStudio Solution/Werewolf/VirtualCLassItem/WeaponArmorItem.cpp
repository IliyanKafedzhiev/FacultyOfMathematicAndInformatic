#include "WeaponArmorItem.h"


WeaponArmorItem::WeaponArmorItem(char* ItemName,TypeItem ItemType,double ItemWeight 
	,double damage,weaponType WeaponType,double armor,
	ArmorTypes ArmorType):Item(ItemName,ItemType, ItemWeight)
	,WeaponItem(ItemName,ItemType, ItemWeight , damage, WeaponType)
	,ArmorItem(ItemName,ItemType,ItemWeight 
	,armor,ArmorType)
{

}

WeaponArmorItem::WeaponArmorItem(const WeaponArmorItem& tmp):Item(tmp),WeaponItem(tmp),ArmorItem(tmp)
{
}

WeaponArmorItem& WeaponArmorItem::operator=(const WeaponArmorItem&tmp)
{
	if (this!=&tmp)
	{
		Item::operator=(tmp);
		ArmorItem::operator=(tmp);
		WeaponItem::operator=(tmp);
	}
	return *this;
}

WeaponArmorItem::~WeaponArmorItem(void)
{
}
