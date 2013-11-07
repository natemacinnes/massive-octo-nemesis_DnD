#pragma once

class Map;



class MapObserver
{
public:
     MapObserver();
    virtual void update(Map &myMap)= 0;
public:
    ~MapObserver(void);
};


