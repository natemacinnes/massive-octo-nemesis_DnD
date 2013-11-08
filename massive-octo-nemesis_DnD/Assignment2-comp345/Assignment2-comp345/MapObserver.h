#pragma once

namespace d20Maps {

class Map;



class MapObserver
{
public:
     MapObserver();
    virtual void update(Map &myMap)= 0;
public:
    ~MapObserver(void);
};

} /* namespace d20Maps */ 


