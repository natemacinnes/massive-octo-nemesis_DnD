#include "stdafx.h"
#include "Armor.h"


const int Armor::SIZE= 1;
const int Armor::ENCHANTMENTS[SIZE] = {6};

Armor::Armor(void)
{
	Item();
}

Armor::Armor(string newName) :
	Item(newName)
{
	name = newName;
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();

}

Armor::~Armor(void)
{

}

string Armor::toString() const {
	return this->getName() + " " + enchantment.toString();
}