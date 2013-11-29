#include "stdafx.h"
#include "Shield.h"

namespace d20Items {

// The number of Shield enchantments
const int Shield::SIZE= 1;
// Array of valid Shield enchantments
const EnchantmentType Shield::ENCHANTMENTS[SIZE] = {ARMOR_CLASS};

Shield::Shield(void)
{
	//Item("Shield of ");
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();
	modifier = 1 + (rand() % 8);
	if(modifier == 3)
		modifier += 1;
	shieldType = SHIELD_TYPE[modifier];
}

Shield::Shield(std::string newName) 
	: Item(newName) 
{
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();
	int tempModifier = 1 + (rand() % 4);
	if(tempModifier == 3)
		modifier += 1;
	shieldType = SHIELD_TYPE[tempModifier];
}

Shield::~Shield(void)
{
}

std::string Shield::getName() const 
{
	return name;
}

Enchantment Shield::getEnchantment() const {
	return enchantment;
}

int Shield::getModifier() const
{
	return modifier;
}

std::string Shield::toString() const {
	return std::string(shieldType) + " " +  name + " " + enchantment.toString();
}
} // namespace d20Items 