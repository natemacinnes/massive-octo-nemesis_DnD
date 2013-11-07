#pragma once

#include "Enchantment.h"
#include <string>
#include <vector>

using  namespace std;

// Item class, parent to all items

class Item	
{
public:
	Item(void);

	Item(string);
	
	virtual ~Item(void);

	string getName(void) const;

	void setName(string);

	virtual string toString(void) const;

private:
	string name;
};

