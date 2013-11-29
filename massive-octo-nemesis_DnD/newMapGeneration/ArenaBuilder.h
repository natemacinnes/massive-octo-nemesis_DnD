#pragma once
#include "Builder.h" 
#include "chracPosition.h"

class ArenaBuilder : public Builder
{
public:
	virtual void setStart();
	virtual void setEnd();
	virtual void setPlayerOnMap();
	virtual void setMonsterOnMap();
	virtual void setMapLevel();
	virtual void setChestOnMap();
	virtual void setChestLevel();
	virtual void createMap(Map*);
	virtual void arenaDisplay();
	
};