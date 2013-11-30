#include "stdafx.h"
#include "Attack.h"
#include "ItemContainer.h"
#include "LeveledChestBuilder.h" 
#include "ChestDirector.h"
#include "ChestBuilder.h"
#include <iostream>

Attack::Attack(d20Characters::Fighter* Player, d20Characters::Fighter* Monster)
{
	std::cout << "Welcome to the attack module, good luck!" << std::endl;

	while((Player->getHitPoints() > 0) && (Monster->getHitPoints() > 0))
	{
		std::cout << "Dice rolled" << std::endl;
		int pDie = rand()%20+1;
		int mDie = rand()%20+1;

		if(pDie > mDie)
		{
			PlayerAttack(Player, Monster);
			std::cout << std::endl;
			system("pause");
			MonsterAttack(Player, Monster);
			system("pause");
			
		}
		else if(pDie < mDie)
		{
			MonsterAttack(Player, Monster);
			std::cout << std::endl;
			system("pause");
			PlayerAttack(Player, Monster);
			system("pause");
		}
		else
		{
			std::cout << "You rolled the same number, rerolling!" << std::endl;
		}
	}
	whoWon(Player, Monster);
}

void Attack::PlayerAttack(d20Characters::Fighter* Player, d20Characters::Fighter* Monster)
{

	
		std::cout << "player is attacking!" << std::endl;
		playerLevel = Player->getLevel();
		d8 = rand()%8+1;
		d20 = rand()%20+1;
		

		for(aPerR = Player->getNumAttacksPerRound(); aPerR > 0; aPerR--)
		{
			std::cout << "attack number: " << aPerR << " good luck!" << std::endl;

			if (d20 + Player->getDexterity() > Monster->getArmorClass())
			{
				std::cout << "You rolled: " << d20 << " and have hit your opponent" << std::endl;
				damage = playerLevel * d8;
				monsterHealth = Monster->getHitPoints();
				monsterHealth = monsterHealth - damage;
				Monster->setHP(monsterHealth);

				std::cout << "You dealt: " << damage << " points of damage" << std::endl;
				std::cout << "The Monster still has " << monsterHealth << "hit points left." << std::endl;
			}
			else
			{
				std::cout << "You've missed! and rolled a: " << d20 << std::endl;
			}
		}
}

void Attack::MonsterAttack(d20Characters::Fighter* Player, d20Characters::Fighter* Monster)
{
	
		std::cout << "monster is attacking" << std::endl;
		monsterLevel = Monster->getLevel();
		d8 = rand()%8+1;
		d20 = rand()%20+1;
		
		

		for(aPerR = Monster->getNumAttacksPerRound(); aPerR > 0; aPerR--)
		{
			std::cout << "attack number: " << aPerR << std::endl;

			if (d20 + Monster->getDexterity() > Player->getArmorClass())
			{
				std::cout << "The monster rolled: " << d20 << " and has hit you!" << std::endl;
				damage = monsterLevel * d8;
				playerHealth = Player->getHitPoints();
				playerHealth = playerHealth - damage;
				Player->setHP(playerHealth);

				std::cout << "You were dealt: " << damage << " points of damage" << std::endl;
				std::cout << "You still have " << playerHealth << "hit points remaining." << std::endl;
			}
			else
			{
				std::cout << "He missed! and rolled a: " << d20 << std::endl;
			}
		}

}

void Attack::whoWon(d20Characters::Fighter* Player, d20Characters::Fighter* Monster)
{
	if(Player->getHitPoints() > Monster->getHitPoints())
	{
		std::cout << "You have defeated the enemy! Congratulations!" << std::endl;
		
		Monster->setLevel(0);
		d20Items::ChestBuilder* IChestBuilder = new d20Items::LeveledChestBuilder(monsterLevel);
		d20Items::ChestDirector* chestDirector = new d20Items::ChestDirector();
		chestDirector->setChestBuilder(IChestBuilder);
		chestDirector->constructChest();
		d20Items::ItemContainer* leveledChest = chestDirector->getChest();

		while(true)
		{
			std::cout << "Press 1 to pick up " << leveledChest->at(0)->toString() << std::endl;
			std::cout << "Press 2 to never see it again" << std::endl;
		
			std::cin >> userChoice;
			if(userChoice == 1)
			{
				std::cout << "congratulations on acquiring a new item!" << std::endl;
				Player->addItem(leveledChest->at(0));
				std::cout << std::endl << leveledChest->at(0)->toString() << std::endl;
				break;
			}
			else if(userChoice == 2)
			{
				std::cout << "The item has faded into the darkness, never to be seen again!" << std::endl;
				break;
			}
			else
			{
				std::cout << "You have entered an incorrect value, please try again" << std::endl;
				break;
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
