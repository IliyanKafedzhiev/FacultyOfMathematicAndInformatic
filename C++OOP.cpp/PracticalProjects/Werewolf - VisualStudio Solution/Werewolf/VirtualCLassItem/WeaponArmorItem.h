enum TypeItem
{
	noj,
	pistolet,
	kalashnik,
};

class Item
{
	char* ItemName;
	TypeItem ItemType;
	double ItemWeight;
public:
	inline void setName(const char*);
	Item(char* ItemName,TypeItem ItemType,double ItemWeight);
	Item(const Item&);
	Item& operator=(const Item&);
	~Item(void);
};

enum weaponType
{
	lajica,
	vilica,
	kliuchodarjatel,
};

class WeaponItem : virtual public Item
{
	double damage;
	weaponType WeaponType;
public:
	WeaponItem(char* ItemName,TypeItem ItemType,double ItemWeight ,double damage,
	weaponType WeaponType);
	WeaponItem(const WeaponItem&);
	WeaponItem& operator=(const WeaponItem&);
	~WeaponItem(void);
};

enum ArmorTypes
{
	chiniq,
	shtit,
	tendjara,
};

class ArmorItem : virtual public Item
{
	double armor;
	ArmorTypes ArmorType;
public:
	ArmorItem(char* ItemName,TypeItem ItemType,double ItemWeight ,double armor,
	ArmorTypes ArmorType);
	ArmorItem(const ArmorItem&);
	ArmorItem& operator=(const ArmorItem&);
	~ArmorItem(void);
};

class WeaponArmorItem:public WeaponItem,public ArmorItem
{
public:
	WeaponArmorItem(char* ItemName,TypeItem ItemType,double ItemWeight 
		,double damage,weaponType WeaponType,double armor,
		 ArmorTypes ArmorType);
	WeaponArmorItem(const WeaponArmorItem&);
	WeaponArmorItem& operator=(const WeaponArmorItem&);
	~WeaponArmorItem(void);
};

