#include "stdafx.h"
#include "Armor.h"

namespace d20Items {

// The amount of valid Armor enchantments
const int Armor::SIZE= 1;

// Armor's valid encahntments
const EnchantmentType Armor::ENCHANTMENTS[SIZE] = {ARMOR_CLASS};

Armor::Armor(void)
{
	Item("Armor of ");
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();
	modifier = 1 + (rand() % 8);
	armorType = ARMOR_TYPE[modifier];
}

Armor::Armor(std::string newName) :
	Item(newName)
{
	name = newName;
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();
	modifier = 1 + (rand() % 8);
	armorType = ARMOR_TYPE[modifier];

}

Armor::~Armor(void)
{

}

std::string Armor::getName() const 
{
	return this->name;
}

Enchantment Armor::getEnchantment() const 
{
	return this->enchantment;
}

int Armor::getModifier() const 
{
	return mod;
}

std::string Armor::toString() const {
	return std::string(armorType) + "" + name + " " + enchantment.toString();
}
} // namespace d20Items 