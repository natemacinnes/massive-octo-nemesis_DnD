#pragma once
#include "item.h"
#include "Enchantment.h"

// Helmet class
namespace d20Items {

class Helmet :
	public Item
{
public:
	Helmet(void);
	
	Helmet(std::string);

	virtual ~Helmet(void);

	virtual void setEnchantment(EnchantmentType eType, int eValue);

	virtual std::string getName() const;

	virtual Enchantment getEnchantment() const;

	virtual std::string toString() const;

private:
	Enchantment enchantment;
	std::string name;
	static const int SIZE;
	static const EnchantmentType ENCHANTMENTS[3];
};
} // namespace d20Items 