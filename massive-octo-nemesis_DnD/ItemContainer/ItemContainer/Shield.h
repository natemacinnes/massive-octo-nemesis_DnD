#pragma once
#include "item.h"
#include "Enchantment.h"

// Shield class
namespace d20Items {

	const static char * SHIELD_TYPE[] = {"NONE", "Buckler", "Heavy Shield", "Tower Shield"};

class Shield :
	public Item
{
public:
	Shield(void);
	
	Shield(std::string);

	virtual ~Shield(void);
	
	virtual std::string getName() const;

	virtual Enchantment getEnchantment() const;

	virtual int getModifier() const;

	virtual std::string toString() const;

private:
	Enchantment enchantment;
	//std::string name;
	static const int SIZE;
	static const EnchantmentType ENCHANTMENTS[1];
	int modifier;
	const char * shieldType;
};
} // namespace d20Items 