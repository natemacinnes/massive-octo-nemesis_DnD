#pragma once
#include "item.h"
#include "Enchantment.h"

// Helmet class

class Helmet :
	public Item
{
public:
	Helmet(void);
	
	Helmet(string);

	virtual ~Helmet(void);

	virtual string toString() const;

	virtual Enchantment getEnchantment() const;

private:
	Enchantment enchantment;
	int enchantmentValue;
	static const int SIZE;
	static const int ENCHANTMENTS[3];
};

