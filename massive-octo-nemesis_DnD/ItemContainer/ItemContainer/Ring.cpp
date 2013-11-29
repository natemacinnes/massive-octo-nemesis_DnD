#include "stdafx.h"
#include "Ring.h"

namespace d20Items {

// The number of valid Ring enchantments
const int Ring::SIZE= 5;

// Array of Ring enchantments
const EnchantmentType Ring::ENCHANTMENTS[SIZE] = {ARMOR_CLASS, STRENGTH, CONSTITUTION, WISDOM, CHARISMA};

Ring::Ring(void)
{
	Item("Ring of ");
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();
}

Ring::Ring(std::string newName) 
	: Item(newName) 
{
	name = newName;
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();

}


Ring::~Ring(void)
{
}

std::string Ring::getName() const 
{
	return this->name;
}

Enchantment Ring::getEnchantment() const {
	return enchantment;
}

std::string Ring::toString() const {
	return this->getName() + " " + enchantment.toString();
}
} // namespace d20Items 