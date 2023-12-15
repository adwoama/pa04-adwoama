//
// Created by robot on 3/28/2021.
//

#ifndef PA04_AMAZING_LOCATION_H
#define PA04_AMAZING_LOCATION_H

#include "DSVector.h"

class Location {
private:
    int x;
    int y;
    int cost;
    DSVector<int> coordinates;

public:
    Location();
    Location(Location& toCopy);
    Location(int xspot, int yspot);
    bool operator==(const Location& val)const;
    void operator=(const Location& val);
    DSVector<int> getCoordinates();
    int getX();
    int getY();
    int getCost()const;
    void setCoordinates(DSVector<int> val);
    void setCoordinates(int xspot, int yspot);
    void setCost(int newCost);
};


#endif //PA04_AMAZING_LOCATION_H
