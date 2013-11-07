#include "stdafx.h"
#include "Helmet.h"

const int Helmet::SIZE = 3;
const int Helmet::ENCHANTMENTS[SIZE] = {};

Helmet::Helmet(void)
{
	Item();
}

Helmet::Helmet(string newName)
		: Item(newName) 
{
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();

}

Helmet::~Helmet(void)
{
}

Enchantment Helmet::getEnchantment() const 
{
	return enchantment;
}

string Helmet::toString() const {
	return this->getName() + " " + enchantment.toString();
}