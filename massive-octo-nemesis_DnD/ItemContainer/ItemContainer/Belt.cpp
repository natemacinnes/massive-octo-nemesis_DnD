#include "stdafx.h"
#include "Belt.h"

namespace d20Items {

// The number of valid  Belt enchantments
const int Belt::SIZE= 2;

// The valid Belt Enchantments
const EnchantmentType Belt::ENCHANTMENTS[SIZE] = {STRENGTH, CONSTITUTION};

Belt::Belt(void)
{
	Item("Belt of ");
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();
}

Belt::Belt(std::string newName) 
	: Item(newName) 
{
	name = newName;
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();

}

Belt::~Belt(void)
{

}

void Belt::setEnchantment(EnchantmentType eType, int eValue)
{
	enchantment.setEnchantmentType(eType);
	enchantment.setEnchantmentValue(eValue);
}

std::string Belt::getName() const 
{
	return this->name;
}

Enchantment Belt::getEnchantment() const 
{
	return this->enchantment;
}

std::string Belt::toString() const {
	return this->getName() + " " + enchantment.toString();
}
} // namespace d20Items 