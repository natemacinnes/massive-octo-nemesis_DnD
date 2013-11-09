#pragma once
#include "MapObservable.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "MapObserver.h"
#include "chracPosition.h"
#include "Weapon.h"
#include "Helmet.h"
#include "Armor.h"
#include "Shield.h"
#include "Ring.h"
#include "Belt.h"
#include "Boots.h"
#include "Item.h"
#include "Shield.h"


using namespace std;


class Map: public MapObservable{


public:
  
	
	Map(void);
	
	virtual ~Map(void);

	//Map constructor
	Map(vector <vector<int> >&,int, int);
	

	//mapconstruction
	vector < vector <int> >& fillUpMap(vector <vector <int> >&, int, int );

	//map desing--print
	void static displayMap (vector < vector <int> >, int, int);
	void  mapDesign (vector < vector <int> >, int, int);
	
	//map validation
	bool validatingMap(vector < vector <int> >&, int, int);

	//map modification
	bool setCell (vector < vector <int> >&, int, int);

	//map movement
	bool move(vector<vector<int>>&, int, int);

	Map* at(int) const;
    
	
	//geters
	int getSize() const;
	int getMapRow();
	int getMapCol();
	int getRowStart();
	int getColStart();
	//int getCharRowLocation(string,chracPosition);
	//int getCharColLocation(string, chracPosition);
	vector<vector<int>> getMapVector();
	map<string,chracPosition> getLocation();
	chracPosition getPosition();

	d20Items::Item* addItem2Map() const;

	//charcater location map
	//void characterPosition(string name, chracPosition p);
	//chracPosition getCharacterPosition(string);
	

	class Validation{
	public:

		//geters
		int static getRow(int);
		int static getCol(int);

		//validation
		int static validateRowInput(int);
		int static validateColInput(int);
		bool static checkingPositionAssigned(vector < vector <int> >, int, int);
		bool static checkingEndAssigned(vector < vector <int> >, int, int);
		bool static validationNewStart(vector<vector<int>>&, int, int, int, int);

		//setting start and end points
		bool static setBegin(vector < vector <int> >&, int, int);
		bool static setEnd(vector < vector <int> >&, int, int);
		
	};

	
protected:
	// Current character position
	chracPosition currentPosition;
	
	// hash map of all character's positions on map
	map<string,chracPosition>  location;
	
	// hash map of all item positions on the map, key = item, value = position
	typedef std::map<d20Items::Item*, chracPosition> ItemLocation;
	ItemLocation itemLocation;
	//map<const d20Items::Item*, chracPosition> itemLocation;

	// vector containing the map
	vector< vector <int> > myMap;

	// Map row & column
	int row;
	int col;
    
	// Vector of map observers
	vector<Map *> myObs; //vector containing mapObserver pointer 

};