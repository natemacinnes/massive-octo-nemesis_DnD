#pragma once
#include "item.h"
#include "Enchantment.h"

// Ring class
namespace d20Items {

class Ring :
	public Item
{
public:
	Ring(void);
	
	Ring(std::string);

	virtual ~Ring(void);

	virtual std::string getName() const;

	virtual Enchantment getEnchantment() const;

	virtual std::string toString() const;

private:
	Enchantment enchantment;
	std::string name;
	static const int SIZE;
	static const int ENCHANTMENTS[5];
};
} // namespace d20Items {