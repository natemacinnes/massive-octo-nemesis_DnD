#include "stdafx.h"
#include  "ArenaBuilder.h"

//void ArenaBuilder::createMap(Map* mapBuilder)
//{
	//Map * tempMap = getResultMapBuilder();
	//tempMap= mapBuilder;
//}
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
	//chracPosition pos  = map->getPosition();
	int r = map->getRowStart();
	int c = map->getColStart();
	map->setPlayerPos(r,c);

}

void ArenaBuilder::setMonsterOnMap()
{
	Map *m = getResultMapBuilder();
	//adds Monster to map
	int i = 1;
	while(i <= m->bob->getLevel())
	{
		bool isFree = m->setMonsterPos();

		if(isFree == true)
		{
			m->setMonsterLvl(1);
			i++;
		}
		
	}
	//will be done on fillupmap
	//sets monster on the map
	//Map *map = getResultMapBuilder();
//	 map->setMonsterPos();
}

void ArenaBuilder::setMonsterLevel()
{

}

void ArenaBuilder::setMapLevel()
{
	Map *m = getResultMapBuilder();
	m->setMapLvl();
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