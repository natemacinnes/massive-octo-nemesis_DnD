#include "stdafx.h"
#include "Boots.h"

namespace d20Items {

// The numner of valid Boot enchantments
const int Boots::SIZE= 2;

// Array
const EnchantmentType Boots::ENCHANTMENTS[SIZE] = {ARMOR_CLASS, DEXTERITY};

Boots::Boots(void)
{
	Item("Boots of ");
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();
}

Boots::Boots(std::string newName) 
	: Item(newName) 
{
	name = newName;
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();

}


Boots::~Boots(void)
{
}

void Boots::setEnchantment(EnchantmentType eType, int eValue)
{
	enchantment.setEnchantmentType(eType);
	enchantment.setEnchantmentValue(eValue);
}

std::string Boots::getName() const 
{
	return this->name;
}

Enchantment Boots::getEnchantment() const 
{
	return enchantment;
}

std::string Boots::toString() const
{
	return this->getName() + " " + enchantment.toString();
}
} // namespace d20Items 