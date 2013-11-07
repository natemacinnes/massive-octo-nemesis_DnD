#include "stdafx.h"
#include "Shield.h"


const int Shield::SIZE= 1;
const int Shield::ENCHANTMENTS[SIZE] = {6};

Shield::Shield(void)
{
	Item();
}

Shield::Shield(string newName) 
	: Item(newName) 
{
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();

}


Shield::~Shield(void)
{
}

Enchantment Shield::getEnchantment() const {
	return enchantment;
}

string Shield::toString() const {
	return this->getName() + " " + enchantment.toString();
}