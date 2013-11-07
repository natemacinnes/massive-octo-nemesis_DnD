#include "stdafx.h"
#include "Ring.h"

const int Ring::SIZE= 5;
const int Ring::ENCHANTMENTS[SIZE] = {6, 0, 2, 4, 5};

Ring::Ring(void)
{
	Item();
}

Ring::Ring(string newName) 
	: Item(newName) 
{
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();

}


Ring::~Ring(void)
{
}

Enchantment Ring::getEnchantment() const {
	return enchantment;
}

string Ring::toString() const {
	return this->getName() + " " + enchantment.toString();
}