#pragma once
#include "MapObserver.h"
#include "MapObservable.h"

class display : public MapObserver
{
public:
    display(Map &,vector<vector<int>> , int, int); //defalut contructor of the class display
    void update(Map &);
public:
    ~display(void);
};
