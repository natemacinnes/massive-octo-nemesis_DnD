#include "stdafx.h"
#include "Display.h"
#include "MapObservable.h"
#include <vector>
#include "chracPosition.h"
#include <string>



Display::Display(Map * map){

	 _map = map;
	 _map->attach(this);
	 out();

}

void Display::update(MapObservable *aMap)
{

	cout<<"inside update"<<endl;
	//if(aMap==_map){
		
		out();
			
		
	//}

}


Display::~Display(void)
{
	_map->detach(this);
}

void Display::out(){
	//getcharater name later
	string name ="player"; 
	cout << name << endl;
	chracPosition pos = _map->getPosition(); 
	int row = pos.getRow();
	int col = pos.getCol();
	vector<vector<int>> vectMap = _map->getMapVector();

	cout << vectMap[row][col] << " map" <<endl;

	vectMap[row][col] = 5;
	
	_map->mapDesign(vectMap,_map->getMapRow(),_map->getMapCol());

	/*
	for(unsigned int i=0; i < _map->getSize(); i++){
		 
		Map *m =_map->at(i);
		//map<string,chracPosition> loc =m->getLocation();
		chracPosition pos = m->getPosition(); 
		int row = pos.getRow();
		int col = pos.getCol();
		vector<vector<int>> vectMap = m->getMapVector();

		cout << vectMap[row][col] << " map" <<endl;

		vectMap[row][col] = 5;
	
		m->mapDesign(vectMap,row,col);
	}
	*/
}
