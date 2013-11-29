#include "stdafx.h"
#include "NimbleFighterBuilder.h"

namespace d20Characters {

	NimbleFighterBuilder::NimbleFighterBuilder(void) : CharacterBuilderAbstract()
	{
	}


	NimbleFighterBuilder::~NimbleFighterBuilder(void)
	{
	}


	Fighter* NimbleFighterBuilder::getCharacter() {

		rollDiceForAbilities();

		checkIfDiceWereRolled(); // cannot call getCharacter without rolling the dice first, issues warning and exits.

		Fighter* nimble = new Fighter(1); // sets most variables according to rules from assignment 1.

		//nimble:		
		nimble->setDexterityNewRules(this->abilityValuesFromSmallestToGreatest[3]);
		nimble->setConstitutionNewRules(this->abilityValuesFromSmallestToGreatest[4]);
		nimble->setStrengthNewRules(this->abilityValuesFromSmallestToGreatest[5]);
		nimble->setIntelligenceNewRules(this->abilityValuesFromSmallestToGreatest[2]);
		nimble->setCharismaNewRules(this->abilityValuesFromSmallestToGreatest[1]);
		nimble->setWisdomNewRules(this->abilityValuesFromSmallestToGreatest[0]);

		return nimble;	
	}

}