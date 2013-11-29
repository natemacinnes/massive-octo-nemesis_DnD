//include "stdafx.h"
#include "MapObservable.h"
#include "Display.h"
#include "chracPosition.h"
#include "Item.h"
#include "ItemContainer.h"
#include "Helmet.h"
#include "ConsoleOut.h"
#include "GUIclass.h"
#include "GUI.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>
#include <limits>
#include <ctype.h>
#include <stdlib.h>

//This is the Driver :)

using std::numeric_limits;
using std::streamsize;
using namespace std;


int main(int argc, char** argv)
{

	SDL_Init(SDL_INIT_EVERYTHING);

	cout << "ITEM CONTAINER CREATION" << endl;

	d20Items::ItemContainer *items = new d20Items::ItemContainer();

	d20Items::ConsoleOut *output  = new d20Items::ConsoleOut(items);

	d20Items::Item *item = new d20Items::Shield("Shield of ");

	items->add(item);

	//TODO this should be a form of factory pattern:
	// a static method that returns an instance of map after prompting the user for the inputs:
	Map* map = Map::createOrReloadAMap();




	map->gameLoop();//(Map::used, Map::numRows0,Map::numCols1); // this is basically: enter play mode, it's a loop until the player exits or wins.



	char end;
	cout << "Enter any LETTER to finish the program!"<< endl;
	cin >> end;

	while(isalpha(end)==false){
		cout << "Not valid input!! You must enter any LETTER to finish the program."<< endl;
		cin >> end;
	}

	//TODO: make this a regular Map::method
	//if we passed this loop: ask to save the character to file:
	string dosavetofile;
	cout << "do you want to save your character to file? (y/n)" << endl;
	cin >> dosavetofile;
	bool isgoodanswer2 = false;
	while(!isgoodanswer2) {
		if(dosavetofile == "y") {
			//save to file:
			map->bob->SaveCharacterToFile();
			isgoodanswer2 = true;
		} else if (dosavetofile =="n") {
			//do nothing
			isgoodanswer2 = true;
		} else {
			cout << "Invalid input. " << endl;	
			isgoodanswer2 = false;
		}
	}

	SDL_Quit();
	//end program:
	return 0;
}
