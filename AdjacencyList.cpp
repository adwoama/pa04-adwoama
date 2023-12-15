//
// Created by robot on 3/23/2021.
//

#include "AdjacencyList.h"
#include "DSVector.h"
#include "DSList.h"
#include "DSNode.h"
#include <iostream>

AdjacencyList::AdjacencyList(){

}
AdjacencyList::AdjacencyList(AdjacencyList& toCopy){

        myList = toCopy.myList;
}
AdjacencyList::~AdjacencyList(){
    //delete myList;
}

void AdjacencyList::add_Room(Room& newRoom){
    myList.pushback(newRoom);
}
void AdjacencyList::add_edge(Room& source, Room& destination){
    int spot = myList.contains(source);
    if(spot >= 0){
        (myList.get(spot)).addAdjacent(destination);
    }
    else{
        myList.pushback(source);
        spot = myList.contains(source);
        (myList.get(spot)).addAdjacent(destination);
    }
    //cout << "spot: " << spot << endl;

}
DSList<Location> AdjacencyList::get_adjacent_rooms(Room& someRoom){
    int spot = myList.contains(someRoom);
    DSList<Location> holder = myList.get(spot).getAdjacent();
    return holder;
}
void AdjacencyList::printRooms() {
    cout << "Printing Rooms"<< endl;
    for(int i = 0; i<myList.getSize(); i++){
        cout << "size: " <<myList.get(i).getAdjacent().getSize()<<endl;
        myList.get(i).print();
        //cout << ": " << get_adjacent_rooms(myList->at(i)->getData()) << endl;
    }
}