#include "Inventory.h"


Inventory::Inventory(void):count(0),capacity(1)
{
	Name = new string[1];
	price = new double[1];
}


Inventory::~Inventory(void)
{
	delete[] this->Name;
	delete[] this->price;
}


int Inventory::foundIndexByName(string searchedName)const
{
	for (int i = 0; i < count; i++)
	{
		if (Name[i] == searchedName)
		{
			return i;
		}
	}
	return -1;
}


void Inventory::ExtendCatalog()
{
	if (capacity == 0)
	{
		capacity = 1;
	}
	this->capacity *= 2;
	string* newNameCatalog = new string[capacity];
	double* newPriceCatalog = new double[capacity];
	for (int i = 0; i < count; i++)
	{
		newNameCatalog[i] = Name[i];
		newPriceCatalog[i] = price[i];
	}
	delete[] Name;
	delete[] price;
	Name = newNameCatalog;
	price = newPriceCatalog;
}


void Inventory::PringAllProducts()const
{
	for (int i = 0; i < count; i++)
	{
		cout<<"Name :"<<Name[i]<<endl;
		cout<<"Price :"<<price[i]<<endl<<endl;
	}
}


void Inventory::Register(const string NameOfTheNewProduct, const double PriceOfTheNewProduct)
{
	int index = foundIndexByName(NameOfTheNewProduct);
	if (index == -1)
	{
		if (count >= capacity)
		{
			ExtendCatalog();
		}
		Name[count] = NameOfTheNewProduct;
		price[count] = PriceOfTheNewProduct;
		count++;
	}
	else
	{
		this->price[index] = PriceOfTheNewProduct;
	}
}


