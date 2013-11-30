#include "stdafx.h"
#include "Bracers.h"

namespace d20Items {

const int Bracers::SIZE = 2;
const EnchantmentType Bracers::ENCHANTMENTS[SIZE] = {ARMOR_CLASS, STRENGTH};


Bracers::Bracers(void)
{
	Item("Bracers of ");
}

Bracers::Bracers(std::string newName) :
	Item(newName)
{
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();

}

Bracers::~Bracers(void)
{
}

void Bracers::setEnchantment(EnchantmentType eType, int eValue)
{
	enchantment.setEnchantmentType(eType);
	enchantment.setEnchantmentValue(eValue);
}

Enchantment Bracers::getEnchantment() const 
{
	return this->enchantment;
}


std::string Bracers::toString() const {
	return this->getName() + ", " + enchantment.toString();
}
} // d20Items namespace