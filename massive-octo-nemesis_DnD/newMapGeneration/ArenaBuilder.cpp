#include "stdafx.h"
#include  "ArenaBuilder.h"


void ArenaBuilder::createMap(Map * mapBuilder)
{
	//fill up map
	//vector <vector <int > >& mapVect = _result->fillUpMap();
	//int row = _result->numRows0;
	//int col = _result->numCols1;
	//_result= new Map(mapVect, row, col);
	Map * tempMap = getResultMapBuilder();
	tempMap= mapBuilder;

}
void ArenaBuilder::setStart()
{
	//done on fillUpMap method
}

void ArenaBuilder::setEnd()
{
	//done on fillUpMap method
}

void ArenaBuilder::setPlayerOnMap()
{   //done on the move
	/*Map *map = getResultMapBuilder();
	chracPosition pos  = map->getPosition();
	map->setPlayerPos(pos.getRow(),pos.getCol());*/
}

void ArenaBuilder::setMonsterOnMap()
{   //done on fillUpMap
	//sets monster on the map
	//Map *map = getResultMapBuilder();
	//map->setMonsterPos();
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