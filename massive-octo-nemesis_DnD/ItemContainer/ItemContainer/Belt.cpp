#include "stdafx.h"
#include "Belt.h"

namespace d20Items {

const int Belt::SIZE= 2;
const int Belt::ENCHANTMENTS[SIZE] = {0, 2};

Belt::Belt(void)
{
	Item();
}

Belt::Belt(std::string newName) 
	: Item(newName) 
{
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();

}


Belt::~Belt(void)
{

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