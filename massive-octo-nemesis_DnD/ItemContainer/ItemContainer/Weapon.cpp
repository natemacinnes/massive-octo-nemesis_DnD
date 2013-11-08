#include "stdafx.h"
#include "Weapon.h"
#include <ctime>
#include <cstdlib>

namespace d20Items {

const int Weapon::SIZE= 2;
const int Weapon::ENCHANTMENTS[SIZE] = {7, 8};

Weapon::Weapon(void)
{
	Item();
}

Weapon::Weapon(std::string newName) 
	: Item(newName) 
{
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();
}


Weapon::~Weapon(void)
{
}

std::string Weapon::getName() const 
{
	return this->name;
}

Enchantment Weapon::getEnchantment() const {
	return enchantment;
}

std::string Weapon::toString() const {
	return this->getName() + " " + enchantment.toString();
}
} // namespace d20Items 