#include "stdafx.h"
#include "Armor.h"

namespace d20Items {

const int Armor::SIZE= 1;
const int Armor::ENCHANTMENTS[SIZE] = {6};

Armor::Armor(void)
{
	Item();
}

Armor::Armor(std::string newName) :
	Item(newName)
{
	name = newName;
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();

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


std::string Armor::toString() const {
	return this->getName() + " " + enchantment.toString();
}
} // namespace d20Items 