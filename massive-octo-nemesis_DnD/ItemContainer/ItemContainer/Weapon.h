#pragma once
#include "Item.h"
#include "Enchantment.h"

// Weapon class
namespace d20Items {

class Weapon :
	public Item
{
public:
	Weapon(void);
	
	Weapon(std::string);

	virtual ~Weapon(void);

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