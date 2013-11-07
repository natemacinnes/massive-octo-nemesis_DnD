#pragma once
#include "Item.h"
#include <string>
#include <iostream>

using namespace std;

//enum EnchantmentType {STRENGTH, DEXTERITY, CONSTITUTION, INTELLIGENCE, WISDOM, CHARISMA, ARMOR_CLASS, ATTACK_BONUS, DAMAGE_BONUS, _NULL};

// Maximum allowable enchantment value
static int MAX_ENCHANTMENT = 5;

// Enchantment class
// can be attached to objects
class Enchantment
{
public:
	
	Enchantment(void);

	Enchantment(int, int);

	Enchantment(const int[], const int);

	~Enchantment(void);
	
	void setEnchantmentValue(void);

	void setEnchantmentType(const int[], const int size);

	int getEnchantmentValue(void) const;

	int getEnchantmentType(void) const;

	string toString(void) const;

	bool equal(Enchantment) const;

private:
	int eValue;
	int eType;
};

