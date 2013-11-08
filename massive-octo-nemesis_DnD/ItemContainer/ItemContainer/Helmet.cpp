#include "stdafx.h"
#include "Helmet.h"

namespace d20Items {

const int Helmet::SIZE = 3;
const int Helmet::ENCHANTMENTS[SIZE] = {};

Helmet::Helmet(void)
{
	Item();
}

Helmet::Helmet(std::string newName)
		: Item(newName) 
{
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();

}

Helmet::~Helmet(void)
{
}

std::string Helmet::getName() const 
{
	return this->name;
}

Enchantment Helmet::getEnchantment() const 
{
	return enchantment;
}

std::string Helmet::toString() const {
	return this->getName() + " " + enchantment.toString();
}
} // namespace d20Items 