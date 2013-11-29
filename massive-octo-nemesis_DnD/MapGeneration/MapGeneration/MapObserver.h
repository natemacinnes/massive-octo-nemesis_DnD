#pragma once
#include "MapObservable.h"
#include "chracPosition.h"
#include <vector>
//#include "Map.h"


class MapObserver {

public:
	virtual ~MapObserver();
	virtual void update(MapObservable *) = 0;

protected:
	MapObserver();

};