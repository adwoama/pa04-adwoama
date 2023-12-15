//
// Created by robot on 3/30/2021.
//

#ifndef PA04_AMAZING_MAZECHECK_H
#define PA04_AMAZING_MAZECHECK_H

#include "Location.h"
#include "Room.h"
#include "AdjacencyList.h"
#include "DSStack.h"
#include "DSList.h"
#include "Iterator.h"
#include "DSNode.h"
#include "DSVector.h"
#include "DSString.h"

class MazeCheck {
private:
    AdjacencyList connections;
    Location start;
    Location end;
    int rows;//number of rows in maze
    int cols;//number of columns
    int** maze;
    DSVector<Room> portals;
    DSVector<Room> roomList;
    //path making vars
    int mostPoints;
    int leastPoints;
    DSStack<Room> bestPath;
    DSVector<DSStack<Room>> allPaths;


public:
    MazeCheck();
    void readMaze(DSString file);
    void makeRoomList();
    void makeAdjList();
    void findPaths();
    void printPaths(DSString outMin, DSString outMax);
};


#endif //PA04_AMAZING_MAZECHECK_H
