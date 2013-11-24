#include "stdafx.h"
#include "TankFighterBuilder.h"

namespace d20Characters {

	TankFighterBuilder::TankFighterBuilder(void)
	{
	}


	TankFighterBuilder::~TankFighterBuilder(void)
	{
	}


	Fighter* TankFighterBuilder::getCharacter() {

		rollDiceForAbilities();

		checkIfDiceWereRolled(); // cannot call getCharacter without rolling the dice first, issues warning and exits.

		Fighter* tank = new Fighter(1); // sets most variables according to rules from assignment 1.

		//resets 6 abilities according to new rules from assignment 3:
		tank->setConstitutionNewRules(this->abilityValuesFromSmallestToGreatest[4]);
		tank->setDexterityNewRules(this->abilityValuesFromSmallestToGreatest[3]);
		tank->setStrengthNewRules(this->abilityValuesFromSmallestToGreatest[5]);
		tank->setIntelligenceNewRules(this->abilityValuesFromSmallestToGreatest[2]);
		tank->setCharismaNewRules(this->abilityValuesFromSmallestToGreatest[1]);
		tank->setWisdomNewRules(this->abilityValuesFromSmallestToGreatest[0]);

		return tank;
	}

}