#pragma once
#include "Item.h"
#include "Enchantment.h"

// Weapon class

class Weapon :
	public Item
{
public:
	Weapon(void);
	
	Weapon(string);

	virtual ~Weapon(void);

	virtual string toString() const;

	virtual Enchantment getEnchantment() const;

private:
	Enchantment enchantment;
	int enchantmentValue;
	static const int SIZE;
	static const int ENCHANTMENTS[2];
};

