#include "stdafx.h"
#include "Display.h"
#include "MapObservable.h"
#include <vector>
#include "chracPosition.h"
#include <string>



Display::Display()
{
	
}
Display::Display(Map * map){

	 _map = map;
	 _map->attach(this);
	 out();

}

Map* Display::getMap()
{
	return _map;
}
void Display::update(MapObservable *aMap)
{

		
		out();
}


Display::~Display(void)
{
	_map->detach(this);
}

void Display::out(){
	
	chracPosition pos = _map->getPosition(); 
	int row = pos.getRow();
	int col = pos.getCol();
	vector<vector<int>> vectMap = _map->getMapVector();
	//vectMap[row][col] = 5;
	_map->mapDesign();//vectMap,_map->getMapRow(),_map->getMapCol()

	
}
