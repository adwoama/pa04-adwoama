//
// Created by robot on 3/26/2021.
//

#ifndef PA04_AMAZING_ROOM_H
#define PA04_AMAZING_ROOM_H

//#pragma onde
#include "DSList.h"
#include "DSNode.h"
#include "DSVector.h"
#include "Location.h"
#include <iostream>
#include <fstream>
using namespace std;

class Room {
private:
    Location pos;
    DSList<Location> adjRooms;
    bool visited;
    bool explored;

public:
    Room();
    Room(Room &toCopy);
    ~Room();
    Room(int x, int y);
    bool operator==(const Room& val)const;
    Room& operator=(const Room& val);
    void setCost(int newCost);
    int getCost()const;
    void setLocation(int x, int y);
    Location getLocation();
    int getX();
    int getY();
    DSList<Location>& getAdjacent();
    void addAdjacent(Room someRoom);
    //friend std::ostream& operator<< (std::ostream& outS, const Room& n);
    void print(std::ostream& outS = cout);

};
#endif //PA04_AMAZING_ROOM_H
