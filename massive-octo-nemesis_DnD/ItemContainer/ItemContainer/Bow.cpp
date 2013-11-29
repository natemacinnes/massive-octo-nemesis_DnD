#include "stdafx.h"
#include "Bow.h"

namespace d20Items {

Bow::Bow(void)
{
	Weapon("Bow of ");
	this->range = 0;
}

Bow::Bow(int newRange)
{
	this->range = newRange;

}

Bow::Bow(std::string newName, int newRange)
	:Weapon(newName)
{
	this->range = newRange;
}

Bow::~Bow(void)
{
}

int Bow::getRange() const 
{
	return this->range;
}

void Bow::setRange(int newRange) 
{
	this->range = newRange;
}

} // d20Items namespace