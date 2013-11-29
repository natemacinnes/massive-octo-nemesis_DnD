#include "stdafx.h"
#include "BullyFighterBuilder.h"


namespace d20Characters {

	BullyFighterBuilder::BullyFighterBuilder(void)
	{
	}


	BullyFighterBuilder::~BullyFighterBuilder(void)
	{
	}


	Fighter* BullyFighterBuilder::getCharacter() {

		rollDiceForAbilities();

		checkIfDiceWereRolled(); // cannot call getCharacter without rolling the dice first, issues warning and exits.

		Fighter* bully = new Fighter(1); // sets most variables according to rules from assignment 1.

		//bully:
		bully->setStrengthNewRules(this->abilityValuesFromSmallestToGreatest[5]);
		bully->setConstitutionNewRules(this->abilityValuesFromSmallestToGreatest[4]);
		bully->setDexterityNewRules(this->abilityValuesFromSmallestToGreatest[3]);
		bully->setIntelligenceNewRules(this->abilityValuesFromSmallestToGreatest[2]);
		bully->setCharismaNewRules(this->abilityValuesFromSmallestToGreatest[1]);
		bully->setWisdomNewRules(this->abilityValuesFromSmallestToGreatest[0]);

		return bully;
	}
}