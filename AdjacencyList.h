//
// Created by robot on 3/23/2021.
//

#ifndef PA04_AMAZING_ADJACENCYLIST_H
#define PA04_AMAZING_ADJACENCYLIST_H
#include "DSList.h"
#include "DSNode.h"
#include "Room.h"
#include "Iterator.h"

class AdjacencyList {
private:
    DSVector<Room> myList;

public:
    AdjacencyList();
    AdjacencyList(AdjacencyList& toCopy);
    ~AdjacencyList();

    void add_Room(Room& newRoom);
    void add_edge(Room& source, Room& destination);
    DSList<Location> get_adjacent_rooms(Room& someRoom);

    //TODO add print method
    void printRooms();
};


#endif //PA04_AMAZING_ADJACENCYLIST_H
