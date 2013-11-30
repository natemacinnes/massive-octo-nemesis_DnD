#include "stdafx.h"
#include "Weapon.h"
#include <ctime>
#include <cstdlib>

namespace d20Items {

// The number of valid Weapon enchantments
const int Weapon::SIZE= 2;
// Array of valid Weapon enchantments
const EnchantmentType Weapon::ENCHANTMENTS[SIZE] = {ATTACK_BONUS, DAMAGE_BONUS};

Weapon::Weapon(void)
{
	Item("Weapon of ");
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();
}

Weapon::Weapon(std::string newName) 
	: Item(newName) 
{
	name = newName;
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();
}


Weapon::~Weapon(void)
{
}

void Weapon::setEnchantment(EnchantmentType eType, int eValue)
{
	enchantment.setEnchantmentType(eType);
	enchantment.setEnchantmentValue(eValue);
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