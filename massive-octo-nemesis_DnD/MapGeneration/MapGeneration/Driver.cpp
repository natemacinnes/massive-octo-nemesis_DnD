#include "MapObservable.h"
#include "Display.h"
#include "chracPosition.h"
#include "Item.h"
#include "ItemContainer.h"
#include "Helmet.h"
#include <iostream>
#include <vector>
#include <limits>
#include <ctype.h>
#include <stdlib.h>

using std::numeric_limits;
using std::streamsize;
using namespace std;



int main(int argc, char* argv[])
{

	
	cout << "ITEM CONTAINER CREATION" << endl;

	d20Items::ItemContainer items;

	d20Items::Item *item = new d20Items::Helmet("Name");

	items.add(item);

    vector< vector <int> > vMap;
	vector< vector <int> > zeroMap;
	int numRows =0, numCols=0;
	
	//Prompts the user to enter the size of the map he/she wants
	//Take the input enterd and set as arguments of the function mapGenerator();
	cout << "Please enter the size of your map!" << endl;
	cout << "Enter the number of rows: \n";
	cin >> numRows; 
	int temRow =  Map::Validation::validateRowInput(numRows);
	numRows = temRow;
	
	
	cout << "Enter the number of Columns: \n";
	cin >> numCols;
	int temCol = Map::Validation::validateColInput(numCols);
	numCols = temCol;

	//filling up msp with empty spaces
	vector<int> columns;
		for (int i = 0; i < numRows; i++) {
		zeroMap.push_back(columns);
			for (int j = 0; j < numCols; j++) {
				zeroMap[i].push_back('X');
			}
		}

	//displays the empty map
	Map emptyMap(zeroMap, numRows, numCols);
	cout<<"Empty Map"<<endl;
	emptyMap.mapDesign(zeroMap, numRows, numCols);

	//Creates a 2D vector with the specifications (Row and Col) given
	vector< vector <int> >& used = emptyMap.fillUpMap(vMap, numRows, numCols);
	Map* map = new Map(used,numRows,numCols);



	Display* display = new Display(map);

	cout << "Validating Map...." << endl;
	cout << "The validation was...."<< endl;

	
	bool isValid = map->validatingMap(used, numRows, numCols);
	
		while(isValid != true){
			cout << "MAP not valid. Do it again!" << endl;
			vector< vector <int> > newMap;
			 newMap = map->fillUpMap(newMap, numRows, numCols);
			 isValid = map->validatingMap(newMap, numRows, numCols);
			 used=newMap;
		}
	

//	char exit1;
	bool isChanged = map->setCell(used, numRows, numCols);
	while(isChanged != true){
			cout << "Change not valid. Do it again!" << endl;
				isChanged = map->setCell(used, numRows, numCols);
	}

	
	cout<<"Let's play" << endl;
	cout<<"Controls"<<endl;
	cout<<"  e  "<<endl;
	cout<<"s d f"<<endl;
	//Display();
	map->move(used, numRows,numCols);

	char end;
	cout << "Enter any LETTER to finish the program!"<< endl;
	cin >> end;

	while(isalpha(end)==false){
		cout << "Not valid input!! You must enter any LETTER to finish the program."<< endl;
		cin >> end;
	}

	return 0;
}
