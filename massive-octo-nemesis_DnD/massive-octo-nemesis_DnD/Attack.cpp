#include "stdafx.h"
#include "Attack.h"
#include "character.h"
#include "Fighter.h"
#include "ItemContainer.h"
//#include "LeveledChestBuilder.h" // nate will put this in
//#include "ChestDirector.h" //nate will put this in
#include <iostream>

Attack::Attack(void)
{
	std::cout << "Welcome to the attack module, good luck!" << std::endl;
}

void Attack::PlayerAttack(d20Characters::Fighter* Player, d20Characters::Fighter* Monster)
{
	std::cout << "Welcome to the attack module, prepare for battle!" << std::endl;

	while((Player->getHitPoints() && Monster->getHitPoints())>0) //makes sure one person wins
	{
		std::cout << "player is attacking!" << std::endl;
		playerLevel = Player->getLevel();
		d8 = rand()%9+1;
		d20 = rand()%21+1;
		
		

		for(aPerR = Player->getAttacksPerRound(); aPerR > 0; aPerR--)
		{
			std::cout << "attack number: " << aPerR << " good luck!" << std::endl;

			if (d20 + Player->getDexterity() > Monster->getArmorClass())
			{
				std::cout << "You rolled: " << d20 << " and have hit your opponent" << std::endl;
				damage = playerLevel * d8;
				monsterHealth = Monster->getHitPoints();
				monsterHealth-= damage;
				Monster->setHitPoints(monsterHealth);

				std::cout << "You dealt: " << damage << " points of damage" << std::endl;
				std::cout << "The Monster still has " << monsterHealth << "hit points left." << endl;
			}
			else
			{
				std::cout << "You've missed! and rolled a: " << d20 << std::endl;
			}
		}
		

	}

	whoWon();
}

void Attack::MonsterAttack(d20Characters::Fighter* Player, d20Characters::Fighter* Monster)
{
	std::cout << "Welcome to the attack module, prepare for battle!" << std::endl;

	while((Player->getHitPoints() && Monster->getHitPoints())>0) //makes sure one person wins
	{
		std::cout << "monster is attacking" << std::endl;
		monsterLevel = Monster->getLevel();
		d8 = rand()%9+1;
		d20 = rand()%21+1;
		
		

		for(aPerR = Monster->getAttacksPerRound(); aPerR > 0; aPerR--)
		{
			std::cout << "attack number: " << aPerR << std::endl;

			if (d20 + Monster->getDexterity() > Player->getArmorClass())
			{
				std::cout << "The monster rolled: " << d20 << " and has hit you!" << std::endl;
				damage = monsterLevel * d8;
				playerHealth = Player->getHitPoints();
				playerHealth-= damage;
				Player->setHitPoints(monsterHealth);

				std::cout << "You were dealt: " << damage << " points of damage" << std::endl;
				std::cout << "You still have " << playerHealth << "hit points remaining." << std::endl;
			}
			else
			{
				std::cout << "He missed! and rolled a: " << d20 << std::endl;
			}
		}
		

	}

	whoWon();

}

void Attack::whoWon()
{
	if(playerHealth > monsterHealth)
	{
		std::cout << "You have defeated the enemy! Congratulations!" << std::endl;
		
		ChestBuilder* IChestBuilder = new LevelChestBuilder(monsterLevel);
		cDirector.setChestBuilder(IChestBuilder);
		cDirector.constructChest();
		ItemContainer* leveledChest = cDirector.getChest();

		while(true)
		{
			std::cout << "Press 1 to pick up " << leveledChest->at(0)->toString() << std::endl;
			std::cout << "Press 2 to never see it again" << std::endl;
		
			std::cin >> userChoice;
			if(userChoice == 1)
			{
				std::cout << "congratulations on acquiring a new item!" << std::endl;
			}
			else if(userChoice == 2)
			{
				std::cout << "The item has faded into the darkness, never to be seen again!" << std::endl;
			}
			else
			{
				std::cout << "You have entered an incorrect value, please try again" << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Unfortunately you died to a pitiful enemy and have embarassed yourself, please play again and prove your true honor" << std::endl;
	}
}


Attack::~Attack(void)
{
}
