#pragma once
#include "Fighter.h"

namespace d20Characters {

class CharacterBuilderAbstract
{


public:
	CharacterBuilderAbstract(void);
	~CharacterBuilderAbstract(void);
	void rollDiceForAbilities();
	virtual Fighter* getCharacter() = 0;
protected:

	int abilityValuesFromSmallestToGreatest[6];
	int threeBestOf4d6();
	bool checkIfDiceWereRolled();
};

}