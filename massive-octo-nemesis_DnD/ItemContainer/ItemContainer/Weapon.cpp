#include "stdafx.h"
#include "Weapon.h"
#include <ctime>
#include <cstdlib>



const int Weapon::SIZE= 2;
const int Weapon::ENCHANTMENTS[SIZE] = {7, 8};

Weapon::Weapon(void)
{
	Item();
}

Weapon::Weapon(string newName) 
	: Item(newName) 
{
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();

}


Weapon::~Weapon(void)
{
}

Enchantment Weapon::getEnchantment() const {
	return enchantment;
}

string Weapon::toString() const {
	return this->getName() + " " + enchantment.toString();
}