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
#include "character.h"
#include "Fighter.h"

#include "Observer.h"

using namespace std;

class Map: public MapObservable, public d20Characters::Observer {

public:


	Map(void);

	virtual ~Map(void);

	//Map constructor
	Map(vector <vector<int> >&,int, int);


	//mapconstruction
	vector < vector <int> >& fillUpMap();//(vector <vector <int> >&, int, int );

	//map desing--print
	//void static displayMap();// (vector < vector <int> >, int, int);
	void  mapDesign();// (vector < vector <int> >, int, int);

	//map validation
	bool validatingMap();//(vector < vector <int> >&, int, int);

	//map modification
	bool setCell ( int, int);//vector < vector <int> >&,

	//map movement
	void gameLoop();
	bool moveInMap(int, int, int,int,int); 

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
	map<d20Characters::Fighter*, chracPosition> getLocation();
	chracPosition getPosition();

	d20Items::Item* addItem2Map() const;

	//charcater location map
	//void characterPosition(string name, chracPosition p);
	//chracPosition getCharacterPosition(string);


	//class Validation{
	//public:

	//geters
	int  getRow(int);
	int  getCol(int);

	//validation
	int  validateRowInput(int);
	int  validateColInput(int);
	bool  checkingPositionAssigned( int, int); //vector < vector <int> >,
	bool  checkingEndAssigned( int, int);//vector < vector <int> >,
	//bool static validationNewStart(vector<vector<int>>&, int, int, int, int);

	//setting start and end points
	bool setBegin( int, int); //vector < vector <int> >&,
	bool  setEnd( int, int);//vector < vector <int> >&,
	void setMapLvl();
	//};
	void setPlayerPos(int, int);
	d20Characters::Fighter *bob; // TODO: make a public getter instead ... no big deal.
	void createOrReloadACharacterBob();

	//for the Observer "interface":

	//register to watch and reflect changes on fighter, and keep a reference to that fighter to print its changes later:
	void registerToObservable(d20Characters::character *obs); // optional really, must be done anyways from the main.
	//using Observer::onEvent;
	virtual void onEvent();

	void saveMapToFile();
	static Map* LoadMapFromFile();
	Map* returnedMap; // used only by the savetofile function (?)
	//info for load
	//static std::vector<int> MapParams; // only used by the loadMapFromFile() function

	static Map* createMapByPromptingUser();
	static Map* createOrReloadAMap();

	int numRows0; // TODO change to non static. and make constructors instead that initialize them.
	int numCols1;
	vector< vector <int> > used;
	static const int myint = 2;
	int mapLevel;

private:
	std::vector<d20Characters::character*> listOfObservables_vector;
	std::vector<d20Characters::character*>::iterator iter;



protected:
	// Current character position
	chracPosition currentPosition;

	//d20Characters::Fighter* bob = new d20Characters::Fighter(2);

	//d20Characters::Fighter bob =  d20Characters::Fighter();

	// hash map of all character's positions on map
	typedef map<d20Characters::Fighter*, chracPosition>  CharacterLocation;
	CharacterLocation characterLocation;

	// hash map of all item positions on the map, key = item, value = position
	typedef std::map<chracPosition*, d20Items::Item*> ItemLocation;
	ItemLocation itemLocation;
	//map<const d20Items::Item*, chracPosition> itemLocation;

	// vector containing the map
	//vector< vector <int> > myMap;

	// Map row & column
	//int row;
	//int col;

	// Vector of map observers
	vector<Map *> myObs; //vector containing mapObserver pointer 

};