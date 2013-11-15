//#include "MapObserver.h"
#include "Map.h"
#include "chracPosition.h"



class Display: public MapObserver{

public:
	Display();
	Display(Map*);
	~Display(void);
	void update(MapObservable *);
	void out();
	Map* getMap();
	//void mapOutput(Map &, chracterPosition);

protected:

	Map *_map;


};