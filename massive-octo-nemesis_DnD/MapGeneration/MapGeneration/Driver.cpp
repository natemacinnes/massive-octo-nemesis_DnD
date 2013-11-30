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


	map->gameLoopOUTER(); // this plays the game and increases the level after each level.

	map->saveCharacterToFile(); // again, although it's done after each level anyway.


	SDL_Quit();
	//end program:
	return 0;
}
