#include "stdafx.h"
#include "Shield.h"

namespace d20Items {

const int Shield::SIZE= 1;
const int Shield::ENCHANTMENTS[SIZE] = {6};

Shield::Shield(void)
{
	Item();
}

Shield::Shield(std::string newName) 
	: Item(newName) 
{
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();
}


Shield::~Shield(void)
{
}

std::string Shield::getName() const 
{
	return this->name;
}

Enchantment Shield::getEnchantment() const {
	return enchantment;
}

std::string Shield::toString() const {
	return this->getName() + " " + enchantment.toString();
}
} // namespace d20Items 