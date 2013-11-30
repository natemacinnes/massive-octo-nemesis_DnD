#include "stdafx.h"
#include "Helmet.h"

namespace d20Items {

// The number of valid Helmet enchantments
const int Helmet::SIZE = 3;

// Array of valid Helmet enchantments
const EnchantmentType Helmet::ENCHANTMENTS[SIZE] = {INTELLIGENCE, WISDOM, ARMOR_CLASS};

Helmet::Helmet(void)
{
	Item("Helmet of ");
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();
}

Helmet::Helmet(std::string newName)
		: Item(newName) 
{
	name = newName;
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();

}

Helmet::~Helmet(void)
{
}

void Helmet::setEnchantment(EnchantmentType eType, int eValue)
{
	enchantment.setEnchantmentType(eType);
	enchantment.setEnchantmentValue(eValue);
}

std::string Helmet::getName() const 
{
	return this->name;
}

Enchantment Helmet::getEnchantment() const 
{
	return enchantment;
}

std::string Helmet::toString() const {
	return this->getName() + " " + enchantment.toString();
}
} // namespace d20Items 