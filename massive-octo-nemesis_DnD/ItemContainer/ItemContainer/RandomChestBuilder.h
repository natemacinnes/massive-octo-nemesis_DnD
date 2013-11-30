#pragma once
#include "chestbuilder.h"

namespace d20Items 
{

class RandomChestBuilder :
	public ChestBuilder
{
public:
	RandomChestBuilder(void);

	virtual ~RandomChestBuilder(void);

	void buildRandomItems();
};

} // d20Items namespace
