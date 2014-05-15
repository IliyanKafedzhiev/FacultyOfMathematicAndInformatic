#include <iostream>
#include "Inventory.h";

using namespace std;

void testInventory()
{
	Inventory inv;
	inv.Register("Milka",2.10);
	inv.Register("Vodka Flirt",7.80);
	inv.Register("Milka",5.50);
	inv.PringAllProducts();
}
int main ()
{
	
    Display cDisplay(false);
 
    cDisplay.DisplayItem();
	return 0;
}
