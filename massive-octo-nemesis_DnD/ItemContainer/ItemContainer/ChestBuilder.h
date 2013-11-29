#pragma once
#include "ItemContainer.h"
#include "Weapon.h"
#include "Helmet.h"
#include "Armor.h"
#include "Shield.h"
#include "Ring.h"
#include "Belt.h"
#include "Boots.h"
#include "Bow.h"
#include "Bracers.h"
#include "Sword.h"
#include <ctime>
#include <cstdlib>

namespace d20Items 
{

class ChestBuilder
{
public:
	ChestBuilder(void);

	virtual ~ChestBuilder(void);

	virtual void fillItemContainer() const;

	ItemContainer* getChest() const;

	void createNewChest();

	virtual void buildRandomItems() = 0;

	virtual Item* createRandomItem();

protected:

	ItemContainer* chest;

};

} // d20Items namespace
