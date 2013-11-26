#include "stdafx.h"
#include  "ArenaBuilder.h"

void ArenaBuilder::setStart()
{
	//done on fillUpMap method
}

void ArenaBuilder::setEnd()
{
	//done on fillUpMap method
}

void ArenaBuilder::setPlayerOnMap()
{
	Map *map = getResultMapBuilder();
	chracPosition pos  = map->getPosition();
	map->setPlayerPos(pos.getRow(),pos.getCol());
}

void ArenaBuilder::setMonsterOnMap()
{
	//sets monster on the map
}
void ArenaBuilder::setMapLevel()
{
	Map *map = getResultMapBuilder();
	map->setMapLvl();
}

void ArenaBuilder::setChestOnMap()
{
	//done on the fillUpMap()	
}

void ArenaBuilder::setChestLevel()
{
	//do later
}

void ArenaBuilder::arenaDisplay()
{
	//check later
}