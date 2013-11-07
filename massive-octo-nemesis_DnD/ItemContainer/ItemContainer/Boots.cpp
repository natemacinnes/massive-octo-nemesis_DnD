#include "stdafx.h"
#include "Boots.h"

const int Boots::SIZE= 2;
const int Boots::ENCHANTMENTS[SIZE] = {6,1};

Boots::Boots(void)
{
	Item();
}

Boots::Boots(string newName) 
	: Item(newName) 
{
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();

}


Boots::~Boots(void)
{
}

Enchantment Boots::getEnchantment() const 
{
	return enchantment;
}

string Boots::toString() const
{
	return this->getName() + " " + enchantment.toString();
}