#pragma once
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <limits>
#include <ctype.h>
#include <string>
#include <iterator>
#include <map>
#include "Map.h"
#include "MapObservable.h"
#include "chracPosition.h"
#include "GUIclass.h"

// for the loadMap functionality:
#include <fstream>
#include "Display.h"

using namespace std;

int rowStart;
int colStart;
int rowEnd;
int colEnd;

Map::Map (void) : used(1,std::vector<int>(1,0))
{
	//{{0,0},{0,0}}; // =  = new vector<vector<int>>
}

Map::~Map(void)
{
}


Map::Map (vector<vector<int>> &v,int r, int c) {

	r = this->validateRowInput(r);
	c = this->validateColInput(c);

	this->numRows0 = r;
	this->numCols1 = c;
	this->used = v;
	this->myObs;

	//this validation is just done 
	//in the static methods (LoadMapFromFile() 
	//and createMapByPromptingUser()) 
	// ... that call this constructor we're in.

	//if(!this->validatingMap()) {
	//	this 
	//}


}

void Map::createOrReloadACharacterBob() {
	//ask the user if he wants to reload a character previously saved in a file or create a new one:
	bool isgoodanswer = false;
	//cin.clear();
	//cin.ignore((numeric_limits<streamsize>::max)(), '\n' ); //ignores whatever apeared after the previous input
	string doLoadChar;
	while(cin >> doLoadChar && !isgoodanswer){
		cout << "Load a character from file? (y/no) --> (enter \"n\" to create a new character)" << endl;
		cin.clear();
		//TODO: test to see if this loop works. it used to break because of cin.ignore()
		//cin.ignore((numeric_limits<streamsize>::max)(), '\n' ); //ignores whatever apeared after the previous input
		if(doLoadChar == "y") {
			bob = new d20Characters::Fighter(1);
			bob = bob->LoadCharacterFromFile(); // TODO this should be static, but works for now.
			isgoodanswer = true;
		} else if(doLoadChar == "n") {
			bob = new d20Characters::Fighter(1);
			isgoodanswer = true;
		} else {
			cout << "Invalid input." << endl;
			isgoodanswer = false;
		}
	}


	//create GUI class that knows what what to do on fighter changes (e.g. refresh screen, but here just re-print):
	//d20Characters::GUIclass* gui = new d20Characters::GUIclass(); // now Map is an Observer itself, how it should be ...

	//plug the two together -- the observer (GUI object) and observable (Fighter object):
	this->registerToObservable(bob);
}

//kind of like a factory getInstance -- but it could just be a constructor too.
//TODO this should be a constructor: (or should it?)
Map* Map::createOrReloadAMap() {
	//ask the user if he wants to reload a character previously saved in a file or create a new one:
	bool isgoodanswer = false;
	Map* map = new Map();
	while(!isgoodanswer){
		cout << "Load a Map from file? (y/n) --> (enter \"n\" to create a new Map)" << endl;
		string doLoadMap;
		cin.clear();
		cin >> doLoadMap;
		if(doLoadMap == "y") {
			//load a map from file
			map = LoadMapFromFile();
			isgoodanswer = true;
		} else if(doLoadMap == "n") {
			//create a map with user:
			map = createMapByPromptingUser();
			isgoodanswer = true;
		} else {
			cout << "Invalid input." << endl;
			isgoodanswer = false;
		}
	}


	//create GUI class that knows what what to do on fighter changes (e.g. refresh screen, but here just re-print):
	//d20Characters::GUIclass* gui = new d20Characters::GUIclass(); // now Map is an Observer itself, how it should be ...

	//plug the two together -- the observer (GUI object) and observable (Fighter object):
	//this->registerToObservable(bob);

	return map;
}


int Map::getRowStart(){
	return rowStart;
}
int Map::getColStart(){
	return colStart;
}


chracPosition Map::getPosition() 
{
	return currentPosition;
}

int Map::getSize() const{

	return myObs.size();
}

Map* Map::at(int i) const{
	return myObs.at(i);
}

int  Map::getMapRow(){
	return numRows0;//row;
}
int  Map::getMapCol(){
	return numCols1;//col;
}
vector<vector<int>> Map::getMapVector(){
	return used;//myMap;
}



vector < vector<int> >& Map::fillUpMap(){//(vector<vector <int>> &m, int row, int col){

	vector<int> columns;
	//chracPosition* pos = new chracPosition();

	cout << "Let's build up your map!" <<endl;
	cout << "Enter \'1\' to fill your map with empty space (free path)" << endl;
	cout << "Enter \'2\' to fill your map with wall" << endl;
	cout << "Enter \'3\' to fill your map" << endl;

	for (int i = 0; i < numRows0; i++) {

		used.push_back(columns);

		for (int j = 0; j < numCols1; j++) {



			int pathChoice; //this variable will hold the user input with the required actu=ion to fill the mao with the elemented wanted
			while (!(cin >> pathChoice) || (pathChoice < 1 || pathChoice > 3) || isalpha(pathChoice)) {

				cout << "Not a valid input!\n";
				cout << "Enter 1 for free path, 2 for wall or 3 for occupied: \n";
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n' ); //ignores whatever apeared after the previous input

			}
			/*
			if(pathChoice==3){
			pos->setChracterPosition(i,j);
			//const d20Items::Item *tempItem = 
			itemLocation.insert(ItemLocation::value_type(pos, addItem2Map()));
			}*/
			used[i].push_back(pathChoice);
		}
	}

	bool isSetStart = Map::setBegin(numRows0, numCols1);//(m, row, col);
	while (isSetStart != true) {
		isSetStart = Map::setBegin(numRows0, numCols1);
	}

	bool isSetEnd = Map::setEnd( numRows0, numCols1);
	while (isSetEnd != true){ 
		isSetEnd = Map::setEnd( numRows0, numCols1);
	}


	//displayMap(m, row, col);
	//mapDesign(m,row,col);
	return used;

}

int Map::validateRowInput(int row){


	while ((isalpha(row)) || (row < 1)) {
		cout << "Not a valid input!\n";
		cout << "Enter the number of rows: \n";
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(),'\n'); //ignores whatever apeared after the previous input
		cin >> row;
	}
	return row;
}

int Map::validateColInput(int col){

	while ((isalpha(col)) || (col <= 1)) {
		cout << "Not a valid input!\n";
		cout << "Enter the number of columns: \n";
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n' ); //ignores whatever apeared after the previous input
		cin >> col;
	}

	return col;
}
//
//void Map::displayMap(){// (vector < vector <int> > myMap, int row, int col){
//
//	int i=0, j=0;
//
//	cout << "Displaying Map" << endl;	
//	cout << "****************************************************************" << endl;
//
//	cout << "+ ";
//	while (i < numCols1) {
//		cout << "+ ";
//		i++;
//	}
//	cout << "+";
//	cout << endl;
//	//delimitation of the map
//
//
//	for (int i = 0 ; i < numRows0; i++) {
//		cout << "+ ";
//		for (int j = 0 ; j <  numCols1; j++) {
//			cout << used[i][j] << " ";
//		}
//		cout << "+";
//		cout << endl;
//	}
//
//	cout << "+ ";
//	while (j < numCols1) {
//		cout << "+ ";
//		j++;
//	}
//	cout << "+";
//	cout << endl;
//}

void Map::mapDesign () { //vector < vector <int> > myMap, int row, int col;


	int i = 0,j = 0;
	cout << "Displaying Map" << endl;	
	cout << "****************************************************************" << endl;


	cout << "+ ";
	while (i < numCols1) {
		cout << "+ ";
		i++;
	}
	cout << "+";
	cout << endl;
	//delimitation of the map
	//chracPosition* pos = new chracPosition();
	for (int i = 0 ; i < numRows0; i++) {
		cout << "+ ";
		for (int j = 0 ; j <  numCols1; j++) {
			if (used[i][j] == 1) {
				cout << " " << " ";
			}else if (used[i][j] == 2) {
				cout << "|" << " ";
			}else if (used[i][j] == 3){
				//pos->setChracterPosition(i,j);
				//itemLocation.find(pos)->second;
				cout << "B" << " ";
				//const d20Items::Item *tempItem = 
				//itemLocation.insert(ItemLocation::value_type(pos, addItem2Map()));
			}else if(used[i][j] == 0) {
				cout << "S" << " "; // starting point;  '+' sign, where it limits the map
			}else if(used[i][j] == 4){
				cout << "E" << " "; // ending point; '+' sign, where it limits the map
			}else if(used[i][j] == 'X'){
				cout << "O" << " "; //  empty map; '+' sign, where it limits the map
			}else{
				cout << "P" << " "; //start point when player leaves
			}
		}
		cout << "+";
		cout << endl;
	}

	cout << "+ ";
	while (j < numCols1) {
		cout << "+ ";
		j++;
	}
	cout << "+";
	cout << endl;
}

bool Map::setBegin(int row, int  col){ //vector < vector <int> >& myMap, 

	//keeps the value of the varibles cal ad row unchanged
	//int const sizeRow = row;
	//int const sizeCol = col;
	int r, c;


	cout << endl;
	cout << "Where is the start point of your map?\n";
	cout << "Please, enter its first coordinate.\n";
	cout << "Remember: your first parameter has to be between: 0 and " << (numRows0-1) << " :"<< endl;

	while (!(cin >> r) || (r < 0 || r > (numRows0-1)) || isalnum(r)) {

		cout << endl;
		cout << "Not a valid input!\n";
		cout << "Enter a number between 0 and " << (numRows0-1)<< " :"<< endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n' ); //ignores whatever apeared after the previous input

	}

	cout << endl;
	cout << "Please, enter its second coordinate.\n";
	cout << "And your seoncd parameter has to be between: 0 and " << (numCols1-1)<< " :" << endl;

	while (!(cin >> c) || (c < 0 || c > (numCols1-1)) || isalpha(c)) {

		cout << endl;
		cout << "Not a valid input!\n";
		cout << "Enter a number between 0 and " << (numCols1-1) <<" :" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n' ); //ignores whatever apeared after the previous input

	}

	bool checkStartPoint = Map::checkingEndAssigned(r,c);//used,
	if (checkStartPoint == true) {
		cout << "Your START position is: [" <<r <<"][" << c <<"]" << endl;
		used[r][c] = 0; // zero will refer to the START point

		rowStart = Map::getRow(r);
		colStart = Map::getCol(c);


		return true;
	}else{
		return false;
	}
}

bool Map::setEnd(int endRow, int  endCol){ //vector < vector <int> >& myMap, 

	//keeps the value of the varibles cal ad row unchanged
	//int const sizeRow = endRow;
	//int const sizeCol = endCol;
	int r, c;


	cout << endl;
	cout << "Where is the END point of your map?\n";
	cout << "Please, enter its first coordinate.\n";
	cout << "Remember: your first parameter has to be between: 0 and " << (numRows0-1) << " :"<< endl;

	while (!(cin >> r) || (r < 0 || r > (numRows0-1)) || isalnum(r)) {

		cout << endl;
		cout << "Not a valid input!\n";
		cout << "Enter a number between 0 and " << (numRows0-1)<< " :"<< endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n' ); //ignores whatever apeared after the previous input

	}

	cout << endl;
	cout << "Please, enter its second coordinate.\n";
	cout << "And your seoncd parameter has to be between: 0 and " << (numCols1-1)<< " :" << endl;

	while (!(cin >> c) || (c < 0 || c > (numCols1-1)) || isalpha(c)) {

		cout << endl;
		cout << "Not a valid input!\n";
		cout << "Enter a number between 0 and " << (numCols1-1) <<" :" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n' ); //ignores whatever apeared after the previous input

	}


	bool checkEndPoint = Map::checkingEndAssigned(r,c);//used,
	if (checkEndPoint == true) {
		cout << "Your END position is: [" << r <<"][" << c <<"]" << endl;
		used[r][c] = 4;// four will refer to the END point
		rowEnd = Map::getRow(r);
		colEnd = Map::getCol(c);
		return true;
	}else{
		return false;
	}

}

bool Map::checkingEndAssigned(int row, int col){//vector < vector <int> > myMap, 


	if (used[row][col] == 0) {
		cout << endl;
		cout << "There is the STARTING point of your map. Sorry! Try again!\n" << endl;
		return false;
	}else{
		return true;
	}

}

bool Map::checkingPositionAssigned(int row, int col){//vector < vector <int> > myMap, 


	if (used[row][col] == 2) {
		cout << endl;
		cout << "There is a wall in it. Sorry! Try again!\n" << endl;
		return false;
	}else if (used[row][col] == 3) {
		cout << endl;
		cout << "This place is occupied already. Sorry! Try again!\n" << endl;
		return false;
	}else{
		return true;
	}

}

int Map::getRow(int row1){
	return row1;
}

int Map::getCol(int col1)
{
	return col1;
}	

bool Map::setCell(int rowChange, int colChange) { // (vector < vector <int> >& myMap, int rowChange, int colChange){
	//keeps the value of the varibles cal ad row unchanged
	int sizeRow = rowChange;
	int sizeCol = colChange;
	int r, c;
	int change;

	cout<< endl;

	//cout << ">>>PLEASE PRESS \'E\' if DO NOT want to change anything<<<\n"<<endl;
	cout << "Enter any letter to finish the changing cells or any digit to continue!"<< endl;
	/*cout << "Please, enter its first coordinate.\n";
	cout << "Remember: your first parameter has to be between: 0 and " << (sizeRow-1) << " :"<< endl;*/

	if(!(cin >> change) || isalpha(change)){
		cout << "Exiting changing mode!" << endl;
		//notifyObs();
		return true;
	}else{
		cout << "CONTINUING..." << endl;
		cout << "Which location of the map you would like to change?\n"<<endl;
		cout << "Please, enter its first coordinate.\n";
		cout << "Remember: your first parameter has to be between: 0 and " << (sizeRow-1) << " :"<< endl;
		while (!(cin >> r) || (r < 0 || r > (sizeRow-1)) || isalnum(r)) {

			cout << endl;
			cout << "Not a valid input!\n";
			cout << "Enter a number between 0 and " << (sizeRow-1)<< " :"<< endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n' ); //ignores whatever apeared after the previous input

		}


		cout << endl;
		cout << "Please, enter its second coordinate.\n";
		cout << "And your second parameter has to be between: 0 and " << (sizeCol-1)<< " :" << endl;

		while (!(cin >> c) || (c < 0 || c > (sizeCol-1)) || isalpha(c)) {

			cout << endl;
			cout << "Not a valid input!\n";
			cout << "Enter a number between 0 and " << (sizeCol-1) <<" :" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n' ); //ignores whatever apeared after the previous input

		}

	}


	if((used[r][c] == 0) || (used[r][c] == 4) ){

		if(used[r][c] == 0){
			cout << endl;
			cout << "Sorry, this is yor STARTING point. Please try again!" << endl;
		}else{
			cout << endl;
			cout << "Sorry, this is yor END point. Please try again!" << endl;
		}

		return false;
	}else{

		int chageValue;

		cout << endl;
		cout << "What do you want to insert there?"<<endl;

		while (!(cin >> chageValue) || (chageValue < 1 || chageValue > 3) || isalpha(chageValue)) {

			cout << endl;
			cout << "Not a valid input!\n";
			cout << "Enter 1 for free path, 2 for wall or 3 for occupied: \n";
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n' ); //ignores whatever apeared after the previous input

		}

		int previousVal = used[r][c]; //record previous value
		used[r][c] = chageValue;
		bool isValid1 = validatingMap();//used, rowChange, colChange
		if (isValid1 == false) {
			used[r][c] = previousVal;
			return false;
		}else{
			cout << endl;
			cout << "Your changed position: ["<< r <<"][" << c <<"] " << endl;
			used[r][c] = chageValue;
			mapDesign();//(used, rowChange, colChange);
			//notify();
			return true;
		}
	}

}

bool Map::validatingMap() { //(vector < vector <int> >& myMap, int row, int col){

	// keeps the size of the 2D vector without changing it
	int rowValue = numRows0;
	int colValue = numCols1;


	int currentRow = rowStart, currentCol = colStart;
	vector<vector<int>> tempMap=used;

	//end point where we want to get
	int endR = rowEnd;
	int endC = colEnd;

	vector <int> valR;
	vector <int> valC;

	bool upS=false, downS=false, leftS=false, rightS=false; 
	bool upE=false, downE=false, leftE=false, rightE=false;

	//checking start point
	if(currentRow + 1 <= rowValue-1){
		if(used[currentRow+1][currentCol] == 2){
			downS = false;
		}else{
			if(used[currentRow+ 1][currentCol] == 4){
				cout << "MAP IS VALID!!" << endl;
				downS = true;
				return true;
			}else if((used[currentRow+1][currentCol] == 1)||(used[currentRow+ 1][currentCol] == 3)){
				downS = true;
			}
		}
	}else{
		downS = false;
	}

	if(currentRow-1 >= 0){
		if(used[currentRow-1][currentCol] == 2){
			upS = false;
		}else{
			if(used[currentRow-1][currentCol] == 4){
				cout << "MAP IS VALID!!" << endl;
				upS = true;
				return true;
			}else if((used[currentRow-1][currentCol] == 1)||(used[currentRow-1][currentCol] == 3)){
				upS = true;
			}
		}
	}else{
		upS = false;
	}


	if(currentCol+1 <= colValue-1){
		if(used[currentRow][currentCol+1] == 2){
			rightS = false;
		}else{
			if(used[currentRow][currentCol+1] == 4){
				cout << "MAP IS VALID!!" << endl;
				rightS = true;
				return true;
			}else if((used[currentRow][currentCol+1] == 1)||(used[currentRow][currentCol+1] == 3)){
				rightS = true;
			}
		}
	}else{
		rightS = false;
	}

	if(currentCol-1 >= 0){
		if(used[currentRow][currentCol- 1] == 2){
			leftS = false;
		}else{
			if(used[currentRow][currentCol-1] == 4){
				cout << "MAP IS VALID!!" << endl;
				leftS = true;
				return true;
			}else if((used[currentRow][currentCol-1] == 1) || (used[currentRow][currentCol-1] == 3)) {
				leftS = true;
			}
		}
	}else{
		leftS = false;
	}




	//checking end point
	if(endR + 1 <= rowValue-1){
		if(used[endR+1][endC] == 2){
			downE = false;
		}else{
			if(used[endR+1][endC] == 4){
				cout << "MAP IS VALID!!" << endl;
				downE = true;
				return true;
			}else if((used[endR+1][endC] == 1)||(used[endR+1][endC] == 3)){
				downE = true;
			}
		}
	}else{
		downE = false;
	}

	if(endR-1 >= 0){
		if(used[endR-1][endC] == 2){
			upE = false;
		}else{
			if(used[endR-1][endC] == 0){
				cout << "MAP IS VALID!!" << endl;
				upE = true;
				return true;
			}else if((used[endR-1][endC] == 1)||(used[endR- 1][endC] == 3)){
				upE = true;
			}
		}
	}else{
		upE = false;
	}


	if(endC+1 <= colValue-1){
		if(used[endR][endC+1] == 2){
			rightE = false;
		}else{
			if(used[endR][endC+1] == 0){
				cout << "MAP IS VALID!!" << endl;
				rightE = true;
				return true;
			}else if((used[endR][endC+1] == 1)||(used[endR][endC+1] == 3)){
				rightE = true;
			}
		}
	}else{
		rightE = false;
	}

	if(endC-1 >= 0){
		if(used[endR][endC-1] == 2){
			leftE = false;
		}else{
			if(used[endR][endC-1] == 0){
				cout << "MAP IS VALID!!" << endl;
				leftE = true;
				return true;
			}else if((used[endR][endC-1] == 1) || (used[endR][endC-1] == 3)) {
				leftE = true;
			}
		}
	}else{
		leftE = false;
	}


	//if either the end point or the start point is block the map is not valid
	if(((upS==false)&&(downS==false)&&(leftS==false)&&(rightS==false))||((upE==false)&&(downE==false)&&(leftE==false)&&(rightE==false))){
		cout<<"Map not not valid"<< endl;
		return false;
	}else{ //checks the map depending on the position of the start and end points
		int count=0, count2=0,count3=0, count4=0, count5=0, count6=0,count7=0, count8=0;
		if(currentRow<rowEnd){
			while(currentRow+1<=rowEnd){
				if(currentCol<colEnd){
					while(currentCol <colEnd){//+1no col =
						if(used[currentRow][currentCol+1]==2){
							count++;
							if(count==numRows0-1){
								return false;
							}else{
								break;
							}
						}else if(used[currentRow][currentCol+1]==4){
							cout <<"MAP VALID!"<< endl;
							return true;
						}else{
							currentCol++;
						}
					}
				}else{ //currentCol>colEnd
					while(currentCol> colEnd){//-1 no col=
						if(used[currentRow][currentCol-1]==2){
							count++;//er2
							if(count==numRows0-1){
								return false;
							}else{
								break;
							}
						}else if(used[currentRow][currentCol-1]==4){
							cout <<"MAP VALID!"<< endl;
							return true;
						}else{
							currentCol--;
						}
					}
				}
				currentRow++;
			}
		}else if(currentRow>rowEnd){
			while(currentRow-1>=rowEnd){
				if(currentCol<colEnd){
					while(currentCol<colEnd){//+1 no col =
						if(used[currentRow][currentCol+1]==2){
							count3++;
							if(count3==numRows0-1){
								return false;
							}else{
								break;
							}
						}else if(used[currentRow][currentCol+1]==4){
							cout <<"MAP VALID!"<< endl;
							return true;
						}else{
							currentCol++;
						}
					}

				}else{ //currentCol >colEnd
					while(currentCol>colEnd){//-1 no col=
						if(used[currentRow][currentCol-1]==2){
							count3++;//era 4
							if(count3==numRows0-1){
								return false;
							}else{
								break;
							}
						}else if(used[currentRow][currentCol-1]==4){
							cout <<"MAP VALID!"<< endl;
							return true;
						}else{
							currentCol--;
						}
					}

				}
				currentRow--;
			}

		}else{ //rowStart=rowEnd
			while(currentRow+1<numRows0){
				if(colStart<colEnd){
					while(currentCol<colEnd){//+1 no col =
						if(used[currentRow][currentCol+1]==2){
							count5++;
							if(count5==numCols1-1){
								return false;
							}else{

								break;
							}
						}else if(used[currentRow][currentCol+1]==4){
							cout <<"MAP VALID!"<< endl;
							return true;
						}else{
							currentCol++;
						}
					}

				}else{// colStart>colEnd
					while(currentCol>colEnd){//=-1 no col
						if(used[currentRow][currentCol-1]==2){
							count5++;
							if(count5==numCols1-1){
								return false;
							}else{
								break;
							}
						}else if(used[currentRow][currentCol-1]==4){
							cout <<"MAP VALID!"<< endl;
							return true;
						}else{
							currentCol--;
						}
					}
				}
				currentRow++;
			}


			//cjecks up and down
			while(currentRow-1>=0){
				if(colStart<colEnd){
					while(currentCol<colEnd){//+1 no col =
						if(used[currentRow][currentCol+1]==2){
							count7++;
							if(count7==numCols1-1){
								return false;
							}else{

								break;
							}
						}else if(used[currentRow][currentCol+1]==4){
							cout <<"MAP VALID!"<< endl;
							return true;
						}else{
							currentCol++;
						}
					}

				}else{// colStart>colEnd
					while(currentCol>colEnd){//-1 col=
						if(used[currentRow][currentCol-1]==2){
							count7++;//era8
							if(count7==numCols1-1){
								return false;
							}else{
								break;
							}
						}else if(used[currentRow][currentCol-1]==4){
							cout <<"MAP VALID!"<< endl;
							return true;
						}else{
							currentCol--;
						}
					}
				}
				currentRow--;
			}
		}
	}


	cout<<"Map valid!" << endl;
	return true;

}
//
//bool Map::Validation::validationNewStart(vector<vector<int>>& tempMap, int row, int col, int currentRow, int currentCol){
//
//	int newStartRowPoint = currentRow;
//	int newStartColPoint = currentCol;
//	bool upS, downS, leftS, rightS; 
//
//
//	//checking start point
//	if(newStartRowPoint + 1 <= row-1){
//		if((tempMap[newStartRowPoint+1][newStartColPoint] == 2) ||(tempMap[newStartRowPoint+1][newStartColPoint] == 5)){
//			downS = false;
//		}else{
//			if(tempMap[currentRow+1][currentCol] == 4){ 
//				cout << "MAP IS VALID!!" << endl;
//				downS = true;
//				return true;
//			}else{
//				downS = true;
//			}
//		}
//	}else{
//		downS = false;
//	}
//
//	if(newStartRowPoint-1 >= 0){
//		if((tempMap[newStartRowPoint-1][newStartColPoint] == 2)||(tempMap[newStartRowPoint-1][newStartColPoint] == 5)){
//			upS = false;
//		}else{
//			if(tempMap[newStartRowPoint- 1][newStartColPoint] == 4){
//				cout << "MAP IS VALID!!" << endl;
//				upS = true;
//				return true;
//			}else{
//				upS = true;
//			}
//		}
//	}else{
//		upS = false;
//	}
//
//
//	if(newStartColPoint+1 <= col-1){
//		if((tempMap[newStartRowPoint][newStartColPoint+1] == 2)||(tempMap[newStartRowPoint][newStartColPoint+1] == 5)){
//			rightS = false;
//		}else{
//			if(tempMap[newStartRowPoint][newStartColPoint+1] == 4){
//				cout << "MAP IS VALID!!" << endl;
//				rightS = true;
//				return true;
//			}else{
//				rightS = true;
//			}
//		}
//	}else{
//		rightS = false;
//	}
//
//	if(newStartColPoint-1 >= 0){
//		if((tempMap[newStartRowPoint][newStartColPoint-1] == 2)||(tempMap[newStartRowPoint][newStartColPoint-1] == 5)){
//			leftS = false;
//		}else{
//			if(tempMap[newStartRowPoint][newStartColPoint-1] == 4){
//				cout << "MAP IS VALID!!" << endl;
//				leftS = true;
//				return true;
//			}else{
//				leftS = true;
//			}
//		}
//	}else{
//		leftS = false;
//	}
//
//	if((upS==false)&&(downS==false)&&(leftS==false)&&(rightS==false)){
//		return false;
//	}else{
//		return true;
//	}
//}

bool Map::moveInMap(int currentRow, int currentCol,int previousRow, int previousCol, int previousVal)
{
	//location of item
	chracPosition *tempItemLoc = new chracPosition();
	bool tempBool;

	if(used[currentRow][currentCol] == 3)
	{

		
		tempItemLoc->setChracterPosition(currentRow, currentCol);
		tempBool = bob->pickUp(itemLocation[tempItemLoc]);
		if(tempBool==true) 
		{
			previousVal=1;
			used[previousRow][previousCol] = 1;
			used[currentRow][currentCol]=5;
		
		}
		else
		{

			used[previousRow][previousCol] = previousVal;
			used[currentRow][currentCol] = 5;
		
		}
			
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n' );
			return true;
	}
	else if(used[currentRow][currentCol] == 4)
	{				
		used[currentRow][currentCol] = 5; //set player new position
		used[previousRow][previousCol] = previousVal; //set the position player left with its old value;
		notify();
		cout << "YOU HAVE REACHED THE END OF THE MAP!!" << endl;
		cout <<"END OF THE GAME!" << endl;
		system("pause");
		exit(0);
		//return false;
						
	}
	else //if(vectorMap[row][col] == 1) //empty cell
	{
		used[currentRow][currentCol] = 5; //set player new position
		used[previousRow][previousCol] = previousVal; //set the position player left with its old value;
		return false;
	}
	


}


void Map::gameLoop() //(vector<vector<int>>& used, int row, int col)
{


	/*
	e--> represents up key --> ASCII value 101
	s--> represents left key --> ASCII value 115
	f--> represents right key --> ASCII value 102
	d--> represents key down --> ASCII value 100
	*/

	vector <vector <int>> mapTracker = Map::getMapVector();
	int static currentRowPosition = rowStart;
	int static currentColPosition = colStart;	
	int static  val; // value on the preivous cell entered
	int previousValRow;
	int previousValCol;
	chracPosition *tempItemLoc = new chracPosition();
	bool tempBool;

	//Map nMap(used,currentRowPosition,currentColPosition);

	
	//position object holding row and collumn value
	currentPosition.setChracterPosition(currentRowPosition,currentColPosition);

	//saving charcater current position on map
	characterLocation.insert(CharacterLocation::value_type(bob, currentPosition));

	
	vector<vector<int>> actualMap =Map::getMapVector();
	actualMap[rowStart][colStart] =5;
	notify();
	

	char key;
	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n' );

	while(!(cin >> key) || (key != 101)||(key != 115)||(key != 100)||(key != 102))
	{

		if(key=='e')
		{
				if((currentRowPosition-1)>=0)
				{

					//stores previous row and col position
					previousValRow = currentRowPosition;
					previousValCol = currentColPosition;

					val = mapTracker[previousValRow][previousValCol]; //saves previous value on the position the player was

					//checks if it is a wall before moving the player
					if(actualMap[currentRowPosition-1][currentColPosition]==2)
					{
						cout<<"Sorry you cannot move there. There is a wall 2!"<<endl;
						cin.clear();
						cin.ignore((numeric_limits<streamsize>::max)(), '\n' );
					}
					else
					{
						currentRowPosition = currentRowPosition-1;
						currentColPosition = currentColPosition;
					


					

						if(moveInMap(currentRowPosition,currentColPosition,previousValRow,previousValCol,val)==true)
						{
							//means you have reached the end point of the map. if it is false you do nothing and keep moving.
							currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
							characterLocation.at(bob) = currentPosition; //update player position
							//currentPosition.print();
							val=1;
							actualMap[previousValRow][previousValCol] =val;
							//actualMap[currentRowPosition][currentColPosition]=5;
							notify();
							//return true;

						}
						else
						{
							
							currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
							characterLocation.at(bob) = currentPosition; //update player position
							currentPosition.print();
							notify();
						}
				  }
				}//end if currentRow-1
				else
				{
					cout<<"You cannot move up!"<<endl;
				}
		}//end ifstatment for key=='e'
		

		else if(key=='s') //tries to move left
		{
				if((currentColPosition-1)>=0)
				{

					//stores previous row and col position
					previousValRow = currentRowPosition;
					previousValCol = currentColPosition;

					val =  mapTracker[previousValRow][previousValCol]; //saves previous value on the position the player was
					////stores the current position of the player
					if(actualMap[currentRowPosition][currentColPosition-1]==2)
					{
						cout<<"Sorry you cannot move there. There is a wall!"<<endl;
						cin.clear();
						cin.ignore((numeric_limits<streamsize>::max)(), '\n' );
					}
					else
					{
						
						currentRowPosition = currentRowPosition;
						currentColPosition = currentColPosition-1;


						if(moveInMap(currentRowPosition,currentColPosition,previousValRow,previousValCol,val)==true)
						{
							//means you have reached the end point of the map. if it is false you do nothing and keep moving.
							currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
							characterLocation.at(bob) = currentPosition; //update player position
							//currentPosition.print();
							val=1;
							actualMap[previousValRow][previousValCol] =val;
							actualMap[currentRowPosition][currentColPosition]=5;
							notify();
							//notify();
							//return true;

						}
						else
						{
							currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
							characterLocation.at(bob) = currentPosition; //update player position
							currentPosition.print();
							notify();
						}
					}
				}//end if currentcol-1
				else
				{
					cout<<"You cannot move left!"<<endl;
				}
		}//end else if statment for key=='s'
		



		else if(key=='f') //tries to move right
		{
			if((currentColPosition+1)<numCols1)
				{

					//stores previous row and col position
					previousValRow = currentRowPosition;
					previousValCol = currentColPosition;


					val =  mapTracker[previousValRow][previousValCol]; //saves previous value on the position the player was

					//stores the current position of the player
					if(actualMap[currentRowPosition][currentColPosition+1]==2)
					{
						cout<<"Sorry you cannot move there. There is a wall!"<<endl;
						cin.clear();
						cin.ignore((numeric_limits<streamsize>::max)(), '\n' );
					
					}
					else
					{
						currentRowPosition = currentRowPosition;
						currentColPosition = currentColPosition+1;

					if(moveInMap(currentRowPosition,currentColPosition,previousValRow,previousValCol,val)==true)
						{
							//means you have reached the end point of the map. if it is false you do nothing and keep moving.
							currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
							characterLocation.at(bob) = currentPosition; //update player position
							//currentPosition.print();
							val=1;
							actualMap[previousValRow][previousValCol] =val;
							actualMap[currentRowPosition][currentColPosition]=5;
							notify();
							//notify();
							//return true;

						}
						else
						{
							currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
							characterLocation.at(bob) = currentPosition; //update player position
							//currentPosition.print();
							notify();
						}
					}
				}//end if currentCol+1
				else
				{
					cout<<"You cannot move right!"<<endl;
				}
		}//end else if statment for key=='f'



		else if(key=='d')//tries to go down
		{
			if((currentRowPosition+1)<numRows0)
				{

					//stores previous row and col position
					previousValRow = currentRowPosition;
					previousValCol = currentColPosition;


					val =  mapTracker[previousValRow][previousValCol]; //saves previous value on the position the player was


					////stores the current position of the player
					if(actualMap[currentRowPosition+1][currentColPosition]==2)
					{
						cout<<"Sorry you cannot move there. There is a wall!"<<endl;
						cin.clear();
						cin.ignore((numeric_limits<streamsize>::max)(), '\n' );
					}
					else
					{
						
						currentRowPosition = currentRowPosition+1;
						currentColPosition = currentColPosition;
					
		


						if(moveInMap(currentRowPosition,currentColPosition,previousValRow,previousValCol,val)==true)
						{
							//means you have reached the end point of the map. if it is false you do nothing and keep moving.
							currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
							characterLocation.at(bob) = currentPosition; //update player position
							//currentPosition.print();
							val=1;
							actualMap[previousValRow][previousValCol] =val;
							actualMap[currentRowPosition][currentColPosition]=5;
							notify();

							//notify();
							//return true;

						}
						else
						{
							currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
							characterLocation.at(bob) = currentPosition; //update player position
							//currentPosition.print();
							notify();
						}
				
					}
				}//end if currentRow+1
				else
				{
					cout<<"You cannot move down!"<<endl;
				}
		}//end if/else statment for key=='d'
		else
		{
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n' );
			cout << "Cannot move there. Out of bound" << endl;
			cin >> key;
		}


	








	//	if(key=='e'){ //tries to move up
	//		if((currentRowPosition-1)>=0)
	//		{//you can move up
	//			if(used[currentRowPosition-1][currentColPosition] == 1)
	//			{
	//				//tempItemLoc->setChracterPosition(currentRowPosition-1, currentColPosition);
	//				previousValRow = currentRowPosition;
	//				previousValCol = currentColPosition;

	//				val = mapTracker[previousValRow][previousValCol]; //previous position
	//				used[previousValRow][previousValCol] = val; //set previous row with old value

	//				//walk in the new cell
	//				currentRowPosition = currentRowPosition-1;
	//				currentColPosition = currentColPosition;

	//				//set to player
	//				used[currentRowPosition][currentColPosition] = 5; //moving player up

	//				currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
	//				characterLocation.at(bob) = currentPosition; //update player position
	//				notify();

	//				cin.clear();
	//				cin.ignore((numeric_limits<streamsize>::max)(), '\n' );

	//			} else if(used[currentRowPosition-1][currentColPosition] == 4) {

	//				val = mapTracker[currentRowPosition][currentColPosition]; //preivous position
	//				used[currentRowPosition][currentColPosition] = val;

	//				used[currentRowPosition-1][currentColPosition] = 5;

	//				currentPosition.setChracterPosition(currentRowPosition-1,currentColPosition);
	//				characterLocation.at(bob) = currentPosition; //update player position

	//				notify();

	//				cout<<"YOU HAVE REACHED THE END OF THE MAP"<<endl;
	//				return true;
	//			} else if(used[currentRowPosition-1][currentColPosition] == 3) { //found something position =3
	//				system("pause");
	//				//tempItemLoc->setChracterPosition(currentRowPosition-1, currentColPosition);
	//				previousValRow = currentRowPosition-1; //save value on cell into
	//				previousValCol = currentColPosition;
	//				val = mapTracker[previousValRow][previousValCol];
	//				used[currentRowPosition-1][currentColPosition] =5;
	//				notify();

	//				system("pause");
	//				// if true pick up item


	//				//cout << "We made it!" << endl;
	//				//map<chracPosition,d20Items::Item*>::iterator it = itemLocation.find(tempItemLoc);

	//				tempItemLoc->setChracterPosition(previousValRow, previousValCol);
	//				tempBool = bob->pickUp(itemLocation[tempItemLoc]);
	//				if(tempBool)
	//				{

	//					//val = mapTracker[currentRowPosition-1][currentColPosition]; //previous position
	//					//val =1;
	//					used[currentRowPosition-1][currentColPosition] = 1;


	//				} else {
	//					val = mapTracker[previousValRow][previousValCol]; //previous position
	//					used[previousValRow][previousValCol] = val;
	//				}


	//				currentRowPosition = currentRowPosition-1;
	//				currentColPosition = currentColPosition;
	//				used[currentRowPosition][currentColPosition] = 5; //moving player up

	//				currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
	//				characterLocation.at(bob) = currentPosition; //update player position

	//				notify();

	//				cin.clear();
	//				cin.ignore((numeric_limits<streamsize>::max)(), '\n' );

	//				//system("cls");

	//			} else {
	//				cout<<"here"<<endl;
	//			}
	//		} else {
	//			cout<<"You cannot move up! There is a wall"<<endl;
	//		}

	//	} else if(key=='s') { //tries to move left
	//		//tempItemLoc->setChracterPosition(currentRowPosition-1, currentColPosition);
	//		if(used[currentRowPosition][currentColPosition-1]==1){
	//			previousValRow = currentRowPosition;
	//			previousValCol = currentColPosition;

	//			val = mapTracker[previousValRow][previousValCol]; //previous position
	//			used[previousValRow][previousValCol] = val; //set previous row with old value

	//			//walk in the new cell
	//			currentRowPosition = currentRowPosition-1;
	//			currentColPosition = currentColPosition;

	//			//set to player
	//			used[currentRowPosition][currentColPosition] = 5; //moving player up

	//			currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
	//			characterLocation.at(bob) = currentPosition; //update player position
	//			notify();

	//			cin.clear();
	//			cin.ignore((numeric_limits<streamsize>::max)(), '\n' );

	//		}else if(used[currentRowPosition][currentColPosition-1] == 4)
	//		{

	//			val = mapTracker[currentRowPosition][currentColPosition]; //preivous position
	//			used[currentRowPosition][currentColPosition] = val;

	//			used[currentRowPosition][currentColPosition-1] = 5;

	//			currentPosition.setChracterPosition(currentRowPosition,currentColPosition-1);
	//			characterLocation.at(bob) = currentPosition; //update player position

	//			notify();

	//			cout<<"YOU HAVE REACHED THE END OF THE MAP"<<endl;
	//			return true;

	//		}else if(used[currentRowPosition][currentColPosition-1] == 3)
	//		{ //found something position =3
	//			system("pause");
	//			//tempItemLoc->setChracterPosition(currentRowPosition-1, currentColPosition);
	//			previousValRow = currentRowPosition; //save value on cell into
	//			previousValCol = currentColPosition-1;
	//			val = mapTracker[previousValRow][previousValCol];
	//			used[currentRowPosition][currentColPosition-1] =5;
	//			notify();

	//			system("pause");
	//			// if true pick up item


	//			//cout << "We made it!" << endl;
	//			//map<chracPosition,d20Items::Item*>::iterator it = itemLocation.find(tempItemLoc);

	//			tempItemLoc->setChracterPosition(previousValRow, previousValCol);
	//			tempBool = bob->pickUp(itemLocation[tempItemLoc]);
	//			if(tempBool)
	//			{

	//				//val = mapTracker[currentRowPosition-1][currentColPosition]; //previous position
	//				//val =1;
	//				used[currentRowPosition][currentColPosition-1] = 1;


	//			} else {
	//				val = mapTracker[previousValRow][previousValCol]; //previous position
	//				used[previousValRow][previousValCol] = val;
	//			}


	//			currentRowPosition = currentRowPosition;
	//			currentColPosition = currentColPosition-1;
	//			used[currentRowPosition][currentColPosition] = 5; //moving player up

	//			currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
	//			characterLocation.at(bob) = currentPosition; //update player position

	//			notify();

	//			cin.clear();
	//			cin.ignore((numeric_limits<streamsize>::max)(), '\n' );

	//			//system("cls");

	//			//}else{
	//			cout<<"here"<<endl;

	//		}else{
	//			cout<<"You cannot move up! There is a wall"<<endl;
	//		}
	//	}else if(key=='f'){ //checks if can move right
	//		if((currentColPosition+1)<numCols1){//you can move right
	//			if(used[currentRowPosition][currentColPosition+1] == 1){
	//				//tempItemLoc->setChracterPosition(currentRowPosition, currentColPosition+1);
	//				previousValRow = currentRowPosition;
	//				previousValCol = currentColPosition;
	//				val = mapTracker[previousValRow][previousValCol]; //preivous position
	//				used[previousValRow][previousValCol]=val;

	//				currentRowPosition = currentRowPosition;
	//				currentColPosition = currentColPosition+1;
	//				used[currentRowPosition][currentColPosition] = 5;

	//				currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
	//				characterLocation.at(bob) = currentPosition; //update player position
	//				notify();

	//				cin.clear();
	//				cin.ignore((numeric_limits<streamsize>::max)(), '\n' );
	//			}else if(used[currentRowPosition][currentColPosition+1] == 4){
	//				val = mapTracker[currentRowPosition][currentColPosition]; //preivous position
	//				used[currentRowPosition][currentColPosition]=val;

	//				used[currentRowPosition][currentColPosition+1] = 5;

	//				currentPosition.setChracterPosition(currentRowPosition,currentColPosition+1);
	//				characterLocation.at(bob) = currentPosition; //update player position

	//				notify();

	//				cout<<"YOU HAVE REACHED THE END OF THE MAP"<<endl;
	//				return true;
	//			} else if(used[currentRowPosition][currentColPosition+1]==3){ //used[currentRowPosition][currentColPosition+1] == 3) {

	//				previousValRow = currentRowPosition; //save value on cell into
	//				previousValCol = currentColPosition+1;
	//				val = mapTracker[previousValRow][previousValCol];
	//				used[currentRowPosition][currentColPosition+1] =5;
	//				notify();

	//				system("pause");
	//				// if true pick up item


	//				//cout << "We made it!" << endl;
	//				//map<chracPosition,d20Items::Item*>::iterator it = itemLocation.find(tempItemLoc);

	//				tempItemLoc->setChracterPosition(previousValRow, previousValCol);
	//				tempBool = bob->pickUp(itemLocation[tempItemLoc]);
	//				if(tempBool)
	//				{

	//					//val = mapTracker[currentRowPosition-1][currentColPosition]; //previous position
	//					//val =1;
	//					used[currentRowPosition][currentColPosition+1] = 1;


	//				} else {
	//					val = mapTracker[previousValRow][previousValCol]; //previous position
	//					used[previousValRow][previousValCol] = val;
	//				}


	//				currentRowPosition = currentRowPosition;
	//				currentColPosition = currentColPosition+1;
	//				used[currentRowPosition][currentColPosition] = 5; //moving player up

	//				currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
	//				characterLocation.at(bob) = currentPosition; //update player position

	//				notify();

	//				cin.clear();	
	//				cin.ignore((numeric_limits<streamsize>::max)(), '\n' );
	//			}else{
	//				cout<<"here t"<<endl;

	//			}

	//		}else{
	//			cout<<"You cannot move right!There is a wall"<<endl;
	//		}

	//	}else if(key=='d'){ //checks if can go down
	//		if((currentRowPosition+1)<numRows0){//you can move down
	//			if(used[currentRowPosition+1][currentColPosition] == 1){
	//				//tempItemLoc->setChracterPosition(currentRowPosition+1, currentColPosition);

	//				previousValRow = currentRowPosition;
	//				previousValCol = currentColPosition;

	//				val = mapTracker[previousValRow][previousValCol]; //preivous position
	//				used[previousValRow][previousValCol]=val;

	//				currentRowPosition = currentRowPosition+1;
	//				currentColPosition = currentColPosition;
	//				used[currentRowPosition][currentColPosition] = 5; //moving player down


	//				currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
	//				characterLocation.at(bob) = currentPosition; //update player position
	//				notify();

	//				cin.clear();
	//				cin.ignore((numeric_limits<streamsize>::max)(), '\n' );
	//			}else if(used[currentRowPosition+1][currentColPosition] == 4){
	//				val = mapTracker[currentRowPosition][currentColPosition]; //preivous position
	//				used[currentRowPosition][currentColPosition]=val;

	//				used[currentRowPosition+1][currentColPosition] = 5;

	//				currentPosition.setChracterPosition(currentRowPosition+1,currentColPosition);
	//				characterLocation.at(bob) = currentPosition; //update player position

	//				notify();

	//				cout<<"YOU HAVE REACHED THE END OF THE MAP"<<endl;
	//				return true;
	//			}else if (used[currentRowPosition+1][currentColPosition]==3){
	//				previousValRow = currentRowPosition+1; //save value on cell into
	//				previousValCol = currentColPosition;
	//				val = mapTracker[previousValRow][previousValCol];
	//				used[currentRowPosition+1][currentColPosition] =5;
	//				notify();

	//				system("pause");
	//				// if true pick up item


	//				//cout << "We made it!" << endl;
	//				//map<chracPosition,d20Items::Item*>::iterator it = itemLocation.find(tempItemLoc);

	//				tempItemLoc->setChracterPosition(previousValRow, previousValCol);
	//				tempBool = bob->pickUp(itemLocation[tempItemLoc]);
	//				if(tempBool)
	//				{

	//					//val = mapTracker[currentRowPosition-1][currentColPosition]; //previous position
	//					//val =1;
	//					used[currentRowPosition+1][currentColPosition] = 1;


	//				} else {
	//					val = mapTracker[previousValRow][previousValCol]; //previous position
	//					used[previousValRow][previousValCol] = val;
	//				}


	//				currentRowPosition = currentRowPosition+1;
	//				currentColPosition = currentColPosition;
	//				used[currentRowPosition][currentColPosition] = 5; //moving player up

	//				currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
	//				characterLocation.at(bob) = currentPosition; //update player position

	//				notify();

	//				cin.clear();	
	//				cin.ignore((numeric_limits<streamsize>::max)(), '\n' );


	//			}else{
	//				cout<<"here"<<endl;
	//			}
	//		}else{
	//			cout<<"You cannot move down! There is a wall"<<endl;
	//		}
	//	}else{
	//		cout<<"You cannot move!"<<endl;
	//		cin >> key;
	//	}
	}//end while loop

}

void Map::onEvent() {
	//every time there's a change in one fighter, refresh the whole list.

	for (int i = 0; i < listOfObservables_vector.size(); i++) {
		listOfObservables_vector[i]->printCharacterStats();
	}
}

void Map::registerToObservable(d20Characters::character *obs) {

	this->listOfObservables_vector.push_back(obs);
	obs->registerObserver(this);

}




/*
chracPosition Map::getCharacterPosition(string name){//changed
map<string,chracPosition> temLoc =getLocation();
std::map<string,chracPosition>::iterator it;
it = temLoc.find(name);
chracPosition pos = it->second;
return pos;

}
*/
/*
int Map::getCharColLocation(string name, chracPosition p){ //changed
// p = getCharacterPosition(name);
return p.getCol();
}

int Map::getCharRowLocation(string name,chracPosition p){
//chracPosition pos = getCharacterPosition(name);
return p.getRow();
}
*/
map<d20Characters::Fighter*,chracPosition> Map::getLocation(){
	return characterLocation;
}

/*** FIX create a void method to print correct item ***
d20Items::Item* Map::addItem2Map() const
{
int rNumber;
rNumber = 1 + rand() % 7;

switch(rNumber) 
{
case 0: 
//std::cout << 'A'<< " ";
return new d20Items::Armor("Dragonmail Armor");
break;
case 1: 
//std::cout << 'O'<< " ";
return new d20Items::Belt("Dragonmail Belt");
case 2: 
//std::cout << 'B'<< " ";
return new d20Items::Boots("Dragonmail Boots");
break;
case 3:
//std::cout << 'H' << " ";
return new d20Items::Helmet("Dragonmail Helmet");
break;
case 4:
//std::cout << 'R' << " ";
return new d20Items::Ring("Dragonmail Ring");
break;
case 5:
//std::cout << 'S' << " ";
return new d20Items::Shield("Dragonmail Shield");
break;
case 6:
//std::cout << 'W'<< " ";
return new d20Items::Weapon("Dragonmail Weapon");
break;
default: 
cout << '*'<< " ";
return new d20Items::Item();
break;
}
}*/


void Map::saveMapToFile() {

}

//TODO this method, along with the createMapWithUserInput() one, 
// ... should both be constructors.
// ... and numRows0 and numCols1 should both be private members. not static as it is now.
//int Map::numRows0=0; // TODO change to non static. and make constructors instead that initialize them.
//int Map::numCols1;
//vector< vector <int> >& used(2,0); //{{0,0},{0,0}}; // init it?
Map* Map::LoadMapFromFile() {

	//used.resize( 2 , vector<int>( 2 , 0 ));


	std::string CharName;
	std::string InformationTextFile;
	std::string characterNames;
	std::string characterNamesFile;
	std::string HELDSTRING;
	std::string HS2;

	std::string inputs;

	std::ifstream myStream;
	std::ifstream mySecondStream;

	std::vector<std::string> tempArray;
	std::vector<std::string> NameArray;
	std::vector<int> valueArray;
	std::vector<std::string> ItemTypeArray;
	std::vector<std::string> EnhancementTypeArray;
	//std::vector<int> HS2;
	std::string k;
	std::string s;


	//std::vector<int> characterParams(30);
	std::vector<int> MapParams;


	cout << endl;//make it cleaner

	myStream.open("C:\\massive-octo-nemesis_DnD\\Names\\MapNames.txt");
	if(!myStream.is_open())
	{
		cout << "Error opening file, you will now create new Map instead. " << endl;
		//system("Pause");
		//return 0;
		Map* returnedMap = Map::createMapByPromptingUser();
		//Map* returnedMap = new Map(); // this Map should be empty and discarded, 
		//this return statement is just to exit.

		return returnedMap;
	}
	else
	{
		cout << "Select a Map Name to Load" << endl;

		while(getline(myStream, HELDSTRING, '\n'))
		{
			cout << HELDSTRING << endl;
		}
		myStream.close();

		while(true)
		{
			cout << "Select a Map Name to Load" << endl;
			cin >> inputs;
			CharName = (inputs + "_Map.txt");
			myStream.open("C:\\massive-octo-nemesis_DnD\\Maps\\" + CharName);
			if(myStream.good())
			{
				int i=0;
				while(getline(myStream, HS2, '\n'))
				{
					//cout << "DERP DERP" << HS2 << endl;
					MapParams.push_back(stoi(HS2)); // NOTE: not a map but a vector !!!
					i++;
				}
				//getline(myStream, HELDSTRING, '\n');
				//cout << HELDSTRING << endl;
				myStream.close();
				break;

				/*THIS IS WHERE WE GET INFORMATION FOR THE GAME */
			}
		}
		//returnedMap = new Map(MapParams, 1);
		//go through all the steps to create a map, as done in the driver:
		vector< vector <int> > used_;
		vector< vector <int> > zeroMap;
		int numRows0_ =0, numCols1_=0;
		// keep the same order to read and write to the file.
		numRows0_ = MapParams[0];
		//int temRow0 =  Map::validateRowInput(numRows0_); // those checks should be in the constructor
		//numRows0_ = temRow0;


		//filling up msp with empty spaces
		vector<int> columns;
		for (int i = 0; i < numRows0_; i++) {
			zeroMap.push_back(columns);
			for (int j = 0; j < numCols1_; j++) {
				zeroMap[i].push_back('X');
			}
		}

		//displays the empty map
		Map emptyMap(zeroMap, numRows0_, numCols1_);
		//cout<<"Empty Map"<<endl;
		//emptyMap.mapDesign(zeroMap, numRows0, numCols1);

		//map that will hod the custom map built by the user
		Map newMap(used_,numRows0_, numCols1_);

		//Creates a 2D vector with the specifications (Row and Col) given
		used_ = newMap.fillUpMap();//vMap, numRows0, numCols1

		//Creates a 2D vector with the specifications (Row and Col) given
		//used_ = emptyMap.fillUpMap();//vMap, numRows0, numCols1
		Map* returnedMap = new Map(used_,numRows0_,numCols1_);



		Display* display = new Display(returnedMap);

		//cout << "Validating Map...." << endl;
		//cout << "The validation was...."<< endl;


		bool isValid = returnedMap->validatingMap();//used, numRows0, numCols1



		//while(isValid != true){
		if(!isValid) {
			cout << "MAP loaded from file was not valid. You will now create a new map. " << endl;
			Map::createMapByPromptingUser();
		}//vector< vector <int> > newMap;
		//newMap = map->fillUpMap(newMap, numRows0, numCols1);
		//isValid = map->validatingMap(newMap, numRows0, numCols1);
		//used=newMap;
		//}

		//
		return returnedMap;
	}
}

Map* Map::createMapByPromptingUser() {

	//create map by user interaction:
	vector< vector <int> > used_;
	vector< vector <int> > zeroMap;
	int numRows0_ = 0, numCols1_ = 0;

	//Prompts the user to enter the size of the map he/she wants
	//Take the input enterd and set as arguments of the function mapGenerator();
	cout << "Please enter the size of your map!" << endl;
	cout << "Enter the number of rows: \n";
	cin >> numRows0_; 
	//int temRow =  Map::validateRowInput(numRows0_);
	//numRows0 = temRow;

	cout << "Enter the number of Columns: \n";
	cin >> numCols1_;
	//int temCol = Map::validateColInput(numCols1_); // will be put in the constructor
	//numCols1 = temCol;

	//filling up msp with empty spaces
	vector<int> columns;
	for (int i = 0; i < numRows0_; i++) {
		zeroMap.push_back(columns);
		for (int j = 0; j < numCols1_; j++) {
			zeroMap[i].push_back('X');
		}
	}

	//displays the empty map
	Map emptyMap(zeroMap, numRows0_, numCols1_);
	cout<<"Empty Map"<<endl;
	emptyMap.mapDesign();//zeroMap, numRows0, numCols1

	//map that will hod the custom map built by the user
	Map newMap(used_,numRows0_, numCols1_);

	//Creates a 2D vector with the specifications (Row and Col) given
	used_ = newMap.fillUpMap();//vMap, numRows0, numCols1
	

	Map* map = new Map(used_,numRows0_,numCols1_);
	Display* display = new Display(map);

	cout << "Validating Map...." << endl;
	cout << "The validation was...."<< endl;


	bool isValid = map->validatingMap();//used, numRows0, numCols1

	while(isValid != true){
		cout << "MAP not valid. Do it again!" << endl;
		vector< vector <int> > nMap;
		map = new Map(nMap,numRows0_,numCols1_);
		nMap = map->fillUpMap();//newMap, numRows0, numCols1
		isValid = map->validatingMap();//newMap, numRows0, numCols1
		used_= nMap;
	}

	//	char exit1;
	bool isChanged = map->setCell( numRows0_, numCols1_);//used,
	while(isChanged != true){
		cout << "Change not valid. Do it again!" << endl;
		isChanged = map->setCell(numRows0_, numCols1_);
	}
	// ... end create map by user interaction.

	//create a character bob:
	//causing code to break
//	map->createOrReloadACharacterBob();
//	map->bob->printCharacterStats();

	cout<<"Let's play !! " << endl;
	cout<<"Controls are: "<<endl;
	cout<<"  e  "<<endl;
	cout<<"s d f"<<endl;
	//Display();

	// ... end create map by user interaction.

	return map;


}