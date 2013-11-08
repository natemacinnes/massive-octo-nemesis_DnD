#include "stdafx.h"
#include "Ring.h"

namespace d20Items {

const int Ring::SIZE= 5;
const int Ring::ENCHANTMENTS[SIZE] = {6, 0, 2, 4, 5};

Ring::Ring(void)
{
	Item();
}

Ring::Ring(std::string newName) 
	: Item(newName) 
{
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