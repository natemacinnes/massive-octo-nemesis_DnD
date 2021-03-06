#pragma once
#include "item.h"
#include "Enchantment.h"

// Belt class
namespace d20Items {

class Belt :
	public Item
{
public:
	Belt(void);
	
	Belt(std::string);

	virtual ~Belt(void);

	virtual void setEnchantment(EnchantmentType eType, int eValue);

	std::string getName(void) const;

	virtual Enchantment getEnchantment() const;

	virtual std::string toString() const;

private:
	Enchantment enchantment;
	std::string name;
	static const int SIZE;
	static const EnchantmentType ENCHANTMENTS[2];
};
} // namespace d20Items 