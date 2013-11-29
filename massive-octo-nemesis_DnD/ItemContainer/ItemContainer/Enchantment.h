#pragma once
#include <string>
#include <iostream>

namespace d20Items {
const static enum EnchantmentType {STRENGTH, DEXTERITY, CONSTITUTION, INTELLIGENCE, WISDOM, CHARISMA, ARMOR_CLASS, ATTACK_BONUS, DAMAGE_BONUS, _NULL};

// Maximum allowable enchantment value
static int MAX_ENCHANTMENT = 5;

// Enchantment class
// can be attached to objects
class Enchantment
{
public:
	
	Enchantment(void);

	Enchantment(EnchantmentType, int);

	Enchantment(const EnchantmentType[], const int);

	~Enchantment(void);
	
	void setEnchantmentValue(void);

	void setEnchantmentValue(int);

	void setEnchantmentType(const EnchantmentType[], const int size);

	int getEnchantmentValue(void) const;

	EnchantmentType getEnchantmentType(void) const;

	std::string toString(void) const;

	bool equal(Enchantment) const;

private:
	int eValue;
	EnchantmentType eType;
};
} // namespace d20Items 

