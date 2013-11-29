#include "stdafx.h"
#include "Sword.h"

namespace d20Items {

Sword::Sword(void)
{
	Weapon("Sword of ");
}

Sword::Sword(std::string newName) 
	: Weapon(newName)
{

}

Sword::~Sword(void)
{
}

} // d20Items namespace