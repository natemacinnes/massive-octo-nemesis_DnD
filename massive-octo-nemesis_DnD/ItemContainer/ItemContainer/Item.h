#pragma once

#include "Enchantment.h"
#include <string>
#include <vector>

// Item class, parent to all items

namespace d20Items {

	static int currentItemID = 0;

class Item	
{
public:
	Item(void);

	Item(std::string);
	
	virtual ~Item(void);

	virtual std::string getName(void) const;

	void setName(std::string);

	int getID() const;

	virtual Enchantment getEnchantment() const;

	virtual std::string toString(void) const;

private:
	std::string name;
	Enchantment enchantment;
	int itemID;
};
} // namespace d20Items 
