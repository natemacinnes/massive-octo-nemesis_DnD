#include "stdafx.h"
#include "Builder.h"
#include "Map.h";


void Builder::createMap(Map* mapBuilder)
{
	//fill up map
	//vector <vector <int > >& mapVect = _result->fillUpMap();
	//int row = _result->numRows0;
	//int col = _result->numCols1;
	//_result= new Map(mapVect, row, col);
	_result = mapBuilder;
}

Map* Builder::getResultMapBuilder()
{
	return _result;
}