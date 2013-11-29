#pragma once
#include "Builder.h"

class ArenaConstructor
{
public:
	void setBuilder(Builder*);
	Map* getMap();
	void construct();

private:
	Builder *_builder;
};