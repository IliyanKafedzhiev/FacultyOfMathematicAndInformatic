#include "WeaponArmorItem.h"


WeaponItem::WeaponItem(char* ItemName,TypeItem ItemType,double ItemWeight ,double damage,
					   weaponType WeaponType):Item(ItemName,ItemType,ItemWeight),damage(damage),WeaponType(WeaponType)
{
}

WeaponItem::WeaponItem(const WeaponItem&tmp):Item(tmp),damage(tmp.damage),WeaponType(tmp.WeaponType)
{
}

WeaponItem& WeaponItem::operator=(const WeaponItem&tmp)
{
	if (this!=&tmp)
	{
		Item::operator=(tmp);
	damage=tmp.damage;
	WeaponType=tmp.WeaponType;
	}
	return *this;
}

WeaponItem::~WeaponItem(void)
{
}
