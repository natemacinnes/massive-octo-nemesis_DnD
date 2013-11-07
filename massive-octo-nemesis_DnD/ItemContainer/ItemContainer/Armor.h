#pragma once
#include "item.h"

// Armor class

class Armor :
	public Item
{
public:
	Armor(void);
	
	Armor(string);

	virtual ~Armor(void);

	virtual string toString() const;

	//bool equal(Item*) const;

private:
	Enchantment enchantment;
	string name;
	static const int SIZE;
	static const int ENCHANTMENTS[1];
};
