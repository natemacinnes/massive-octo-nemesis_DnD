#include "stdafx.h"
#include "Enchantment.h"
#include <ctime>
#include <cstdlib>

namespace d20Items {

Enchantment::Enchantment(void)
{
}

Enchantment::Enchantment(int newEType, int newEValue) 
{
	eType = newEType;
	eValue = newEValue;
}

Enchantment::Enchantment(const int enchantmentTypes[], const int size) 
{
	this->setEnchantmentType(enchantmentTypes, size);
	this->setEnchantmentValue();
}

Enchantment::~Enchantment(void)
{
}

void Enchantment::setEnchantmentValue() 
{
	eValue = 1 + rand() % MAX_ENCHANTMENT;
}

void Enchantment::setEnchantmentType(const int enchantmentTypes[], const int size) 
{
	int _eType = rand() % size;
	eType = enchantmentTypes[_eType];
}

int Enchantment::getEnchantmentValue() const 
{
	return eValue;
}

int Enchantment::getEnchantmentType() const
{
	return eType;
}\

	std::string Enchantment::toString() const 
{
	std::string eV = std::to_string(eValue);
	switch(eType) 
	{
	case 0: 
		return "Strength, +" + eV;
		break;
	case 1: 
		return "Dexterity, +" + eV;
		break;
	case 2: 
		return "Constition, +" + eV;
		break;
	case 3:
		return "Intelligence, +" + eV;
		break;
	case 4:
		return "Wisdom, +" + eV;
	case 5:
		return "Charisma, +" + eV;
		break;
	case 6:
		return "Armor Class, +" + eV;
		break;
	case 7:
		return "Attack Bonus, +" + eV;
		break;
	case 8:
		return "Damage Bonus, +" + eV;
		break;
	default: 
		return "";
		break;
	}
}

bool Enchantment::equal(Enchantment e) const
{
	return (this->eType == e.getEnchantmentType() && this->eValue == e.eValue);
}
} // namespace d20Items 