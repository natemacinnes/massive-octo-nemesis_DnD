#pragma once

#include "MapObserver.h"
#include <SDL.h>//<SDL.h>
#include <SDL_image.h>//<SDL_image.h>


class UIMap : public MapObserver
{
public:
	UIMap(void);

	//UIMap(Map *);

	virtual ~UIMap(void);

	void update(MapObservable *);
	
	void out();
	
	//Map* getMap();

protected:

	//Map *_map;

};


