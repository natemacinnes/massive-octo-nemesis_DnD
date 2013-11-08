#pragma once
#include "item.h"

// Armor class

namespace d20Items {

class Armor :
	public Item
{
public:
	Armor(void);
	
	Armor(std::string);

	virtual ~Armor(void);

	std::string getName(void) const;

	virtual Enchantment getEnchantment() const;

	virtual std::string toString() const;

private:
	Enchantment enchantment;
	std::string name;
	static const int SIZE;
	static const int ENCHANTMENTS[1];
};
} // namespace d20Items {