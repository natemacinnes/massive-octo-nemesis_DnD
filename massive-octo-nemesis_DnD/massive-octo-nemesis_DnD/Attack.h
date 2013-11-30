#pragma once
#include "character.h"
#include "Fighter.h"


class Attack
{
public:
	Attack(void);
	~Attack(void);
	void whoWon();
	void PlayerAttack(d20Characters::Fighter* Player, d20Characters::Fighter* Monster);
	void MonsterAttack(d20Characters::Fighter* Player, d20Characters::Fighter* Monster);

protected:

	int d8;
	int d20;
	int playerLevel;
	int monsterLevel;
	int aPerR;
	int monsterHealth;
	int playerHealth;
	int damage;
	int userChoice;

private:

};

