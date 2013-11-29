#pragma once
#include "characterbuilderabstract.h"

namespace d20Characters {

class TankFighterBuilder :
	public CharacterBuilderAbstract
{
public:
	TankFighterBuilder(void);
	~TankFighterBuilder(void);
	Fighter* getCharacter(); 
};

}