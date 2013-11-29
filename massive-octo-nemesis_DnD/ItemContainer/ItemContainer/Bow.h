#pragma once
#include "weapon.h"

namespace d20Items {

class Bow :
	public Weapon
{
public:
	Bow(void);
	
	Bow(int);

	Bow(std::string, int);

	virtual ~Bow(void);

	int getRange(void) const;

	void setRange(int);

private:
	int range;
};

} // d20Items namespace