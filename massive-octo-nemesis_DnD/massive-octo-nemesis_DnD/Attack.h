#pragma once
#include "Fighter.h"


class Attack
{
public:
	Attack(d20Characters::Fighter* Player, d20Characters::Fighter* Monster);
	~Attack(void);
	void whoWon(d20Characters::Fighter*, d20Characters::Fighter*);
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

