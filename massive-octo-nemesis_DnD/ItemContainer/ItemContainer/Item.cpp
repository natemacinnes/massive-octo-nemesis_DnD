#include "stdafx.h"
#include "Item.h"


namespace d20Items {

Item::Item(void)
{
	//this->setEnchantment(9,0);
	itemID = currentItemID;
	currentItemID++;
	name = " ";
}

Item::Item(std::string newName) {
	itemID = currentItemID;
	currentItemID++;
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

void Item::setEnchantment(EnchantmentType eType, int eValue)
{
	enchantment.setEnchantmentType(eType);
	enchantment.setEnchantmentValue(eValue);
}

int Item::getID() const
{
	return itemID;
}

std::string Item::getName(void) const 
{
	return name;
}

Enchantment Item::getEnchantment() const 
{
	return enchantment;
}

int Item::getModifier() const 
{
	return mod;
}

std::string Item::toString(void) const {
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
}