#pragma once
#include "weapon.h"

namespace d20Items {

class Sword :
	public Weapon
{
public:
	Sword(void);

	Sword(std::string);
	
	virtual ~Sword(void);
};

} // d20Items namespace