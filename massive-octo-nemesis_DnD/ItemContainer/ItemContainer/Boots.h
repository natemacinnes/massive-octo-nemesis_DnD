#pragma once
#include "item.h"
#include "Enchantment.h"

// Boots class
namespace d20Items {

class Boots :
	public Item
{
public:
	Boots(void);

	Boots(std::string);

	virtual ~Boots(void);

	virtual std::string getName() const;

	virtual Enchantment getEnchantment() const;

	virtual std::string toString() const;

private:
	Enchantment enchantment;
	std::string name; 
	static const int SIZE;
	static const int ENCHANTMENTS[2];
};
} // namespace d20Items 