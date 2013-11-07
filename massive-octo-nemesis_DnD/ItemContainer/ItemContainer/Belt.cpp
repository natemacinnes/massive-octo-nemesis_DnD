#include "stdafx.h"
#include "Belt.h"

const int Belt::SIZE= 2;
const int Belt::ENCHANTMENTS[SIZE] = {0, 2};

Belt::Belt(void)
{
	Item();
}

Belt::Belt(string newName) 
	: Item(newName) 
{
	enchantment.setEnchantmentType(ENCHANTMENTS,SIZE);
	enchantment.setEnchantmentValue();

}


Belt::~Belt(void)
{

}

string Belt::toString() const {
	return this->getName() + " " + enchantment.toString();
}