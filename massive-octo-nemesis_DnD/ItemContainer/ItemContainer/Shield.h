#pragma once
#include "item.h"
#include "Enchantment.h"

// Shield class
namespace d20Items {

class Shield :
	public Item
{
public:
	Shield(void);
	
	Shield(std::string);

	virtual ~Shield(void);
	
	virtual std::string getName() const;

	virtual Enchantment getEnchantment() const;

	virtual std::string toString() const;

private:
	Enchantment enchantment;
	std::string name;
	static const int SIZE;
	static const int ENCHANTMENTS[1];
};
} // namespace d20Items 