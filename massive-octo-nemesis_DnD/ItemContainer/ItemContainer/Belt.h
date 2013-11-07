#pragma once
#include "item.h"
#include "Enchantment.h"

// Belt class

class Belt :
	public Item
{
public:
	Belt(void);
	
	Belt(string);

	virtual ~Belt(void);

	virtual string toString() const;

private:
	Enchantment enchantment;
	int enchantmentValue;
	static const int SIZE;
	static const int ENCHANTMENTS[2];
};