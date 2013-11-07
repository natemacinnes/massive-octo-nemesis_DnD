#pragma once
#include "item.h"
#include "Enchantment.h"

// Ring class

class Ring :
	public Item
{
public:
	Ring(void);
	
	Ring(string);

	virtual ~Ring(void);

	virtual string toString() const;

	virtual Enchantment getEnchantment() const;

private:
	Enchantment enchantment;
	int enchantmentValue;
	static const int SIZE;
	static const int ENCHANTMENTS[5];
};
