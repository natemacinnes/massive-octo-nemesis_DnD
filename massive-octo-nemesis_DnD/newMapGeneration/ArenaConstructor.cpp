#include "stdafx.h"
#include "ArenaConstructor.h"

void ArenaConstructor::setBuilder(Builder* b)
{
	_builder = b;
}

Map* ArenaConstructor::getMap()
{
	return _builder->getResultMapBuilder();
}

void ArenaConstructor::construct()
{
	//put the map together
	//_builder ->createMap();
	_builder->setChestLevel();
	_builder->setMapLevel();
	_builder->setMonsterOnMap();
}