#pragma once
#include "item.h"
#include "Enchantment.h"

// Boots class

class Boots :
	public Item
{
public:
	Boots(void);

	Boots(string);

	virtual ~Boots(void);

	virtual string toString() const;

	virtual Enchantment getEnchantment() const;

private:
	Enchantment enchantment;
	int enchantmentValue;
	static const int SIZE;
	static const int ENCHANTMENTS[2];
};