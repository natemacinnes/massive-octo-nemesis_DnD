#pragma once
#include "item.h"

namespace d20Items {

class Bracers :
	public Item
{
public:
	Bracers(void);
	
	Bracers(std::string);

	virtual ~Bracers(void);

	virtual Enchantment getEnchantment() const;

	virtual std::string toString() const;

private:
	Enchantment enchantment;
	static const int SIZE;
	static const EnchantmentType ENCHANTMENTS[2];

};

} // d20Items namespace