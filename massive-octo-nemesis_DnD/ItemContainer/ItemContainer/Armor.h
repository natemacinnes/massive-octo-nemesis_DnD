#pragma once
#include "item.h"
#include <map>

// Armor class

namespace d20Items {

	const static char * ARMOR_TYPE[] = {"NONE", "Padded", "Leather", "Studded Leather", "Chain Mail", "Breast Plate", "Banded Mail", "Half Plate", "Full Plate"};

class Armor :
	public Item
{
public:
	Armor(void);
	
	Armor(std::string);

	//Armor(std::string, ARMOR_TYPE);

	virtual ~Armor(void);

	virtual void setEnchantment(EnchantmentType, int);

	std::string getName(void) const;

	virtual Enchantment getEnchantment() const;

	virtual int getModifier() const;

	virtual std::string toString() const;

private:
	Enchantment enchantment;
	std::string name;
	static const int SIZE;
	static const EnchantmentType ENCHANTMENTS[1];
	int modifier;
	const char * armorType;
};
} // namespace d20Items {