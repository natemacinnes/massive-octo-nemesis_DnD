#include "stdafx.h"
#include "Item.h"




Item::Item(void)
{
	//this->setEnchantment(9,0);
	name = "";
}

Item::Item(string newName) {

	name = newName;
}

Item::~Item(void)
{

}

/*
void Item::setEnchantment(int i, const int j)
{

}
*/

string Item::getName(void) const {
	return name;
}


string Item::toString(void) const {
	return name;// + " " + enchantment.toString();
}

/*
bool Item::equals(Item* item) 
{
	if(this->name.compare(item->getName()) == 0)
	{
		return true;
	}
}
*/