#pragma once
#include "item.h"
#include "Enchantment.h"

// Shield class

class Shield :
	public Item
{
public:
	Shield(void);
	
	Shield(string);

	virtual ~Shield(void);

	virtual string toString() const;

	virtual Enchantment getEnchantment() const;

private:
	Enchantment enchantment;
	int enchantmentValue;
	static const int SIZE;
	static const int ENCHANTMENTS[1];
};