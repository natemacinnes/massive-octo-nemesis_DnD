#include "stdafx.h"
#include "CharacterBuilderAbstract.h"
#include <time.h>
#include <algorithm>
#include <iostream>


namespace d20Characters {

	CharacterBuilderAbstract::CharacterBuilderAbstract(void)
	{
		for(int i=0; i<6; i++) {
			//std::cout << "\n" << i << ":::" << this->abilityValuesFromSmallestToGreatest[i];
			this->abilityValuesFromSmallestToGreatest[i] = 0;
		}
	}


	CharacterBuilderAbstract::~CharacterBuilderAbstract(void)
	{
	}

	bool CharacterBuilderAbstract::checkIfDiceWereRolled() {
		//check & warn the client that rollDices must be called before getting a character:
		if(this->abilityValuesFromSmallestToGreatest[0] == 0) {
			std::cout << "\nProgrammer Error: a call to rollDiceForAbilities() must be done before getCharacter()";
			std::cout << "\nAborting.";
			system("pause");
			exit(EXIT_FAILURE);
		}
	}

	void CharacterBuilderAbstract::rollDiceForAbilities() {

		//srand(time(0)); // init random seed
		abilityValuesFromSmallestToGreatest[0] = threeBestOf4d6();
		abilityValuesFromSmallestToGreatest[1] = threeBestOf4d6();
		abilityValuesFromSmallestToGreatest[2] = threeBestOf4d6();
		abilityValuesFromSmallestToGreatest[3] = threeBestOf4d6();
		abilityValuesFromSmallestToGreatest[4] = threeBestOf4d6();
		abilityValuesFromSmallestToGreatest[5] = threeBestOf4d6();

		//sort the array:
		std::sort(&abilityValuesFromSmallestToGreatest[0], &abilityValuesFromSmallestToGreatest[6]);// works now, needs to points *after* the last index.
		//for(int i=0; i<6; i++) {
		//	for(int j=i; j<6; j++) {
		//		//find max and put it in first place:
		//		if(orderedListOfAbilityValues[j]>orderedListOfAbilityValues[i]) {
		//			//swap:
		//			int temp = orderedListOfAbilityValues[j];
		//			orderedListOfAbilityValues[j] = orderedListOfAbilityValues[i];
		//			orderedListOfAbilityValues[i] = temp;
		//		}
		//	}
		//}

		//for(int i=0; i<6; i++) {
		//	std::cout << "\n " << i << ":" << abilityValuesFromSmallestToGreatest[i] << " ";
		//}

	}

	int CharacterBuilderAbstract::threeBestOf4d6() {
		const int intsLength = 4;
		int diceResults[4];
		diceResults[0] = (rand() % 5 + 1 ); // between 1 and 6
		diceResults[1] = (rand() % 5 + 1 );
		diceResults[2] = (rand() % 5 + 1 );
		diceResults[3] = (rand() % 5 + 1 );

		//std::cout<< "\nints[0]:" << diceResults[0]; // between 1 and 6
		//std::cout<< "\nints[1]:" << diceResults[1];
		//std::cout<< "\nints[2]:" << diceResults[2];
		//std::cout<< "\nints[3]:" << diceResults[3];

		//find min:
		int min = diceResults[0];
		for(int i=0; i<intsLength; i++) {
			if(min > diceResults[i]) {
				min = diceResults[i];
			}
		}
		//return sum of 3 best:
		return diceResults[0] + diceResults[1] + diceResults[2] + diceResults[3] - min;
	}

}