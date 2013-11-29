#pragma once
#include "Map.h"
#include <vector>

class Builder
{
public:
	Builder() {};
	virtual void setStart() = 0;
	virtual void setEnd() = 0;
	virtual void setPlayerOnMap () = 0;
	virtual void setMonsterOnMap() = 0;
	virtual void setMapLevel () = 0;
	virtual void setChestOnMap() = 0;
	virtual void setChestLevel() = 0;
	virtual void setMonsterLevel() = 0;
	 void createMap(Map*);
	Map* getResultMapBuilder();

private:
	Map *_result;
};