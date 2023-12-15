//
// Created by robot on 3/26/2021.
//

#include "Room.h"

//#pragma onde
using namespace std;
//++++++++++CONSTRUCTORS, DESTRUCTORS, ETC ++++++++++
Room::Room(){
    visited = false;
    explored = false;
    pos.setCost(1);
}
Room::Room(Room& toCopy){
    //pos = toCopy.getLocation();
    pos = toCopy.pos;
    adjRooms = toCopy.getAdjacent();
    visited = toCopy.visited;
    explored = toCopy.explored;
}
Room::~Room(){
    //delete adjRooms;
}
Room::Room(int x, int y){
    pos.setCoordinates(x,y);
}
bool Room::operator==(const Room& val)const{
    if((pos == val.pos))
        return true;
    else
        return false;
}

Room& Room::operator=(const Room& val) {
    pos = val.pos;
    adjRooms = val.adjRooms;
    visited = val.visited;
    explored = val.explored;
    pos.setCost(val.getCost());
    return *this;
}
void Room::setCost(int newCost){
   pos.setCost(newCost);
}
int Room::getCost()const{
    return pos.getCost();
}
void Room::setLocation(int x, int y){
    pos.setCoordinates(x,y);
}
Location Room::getLocation(){
    return pos;
}
int Room::getX(){
    return pos.getX();
}
int Room::getY(){
    return pos.getY();
}
DSList<Location>& Room::getAdjacent(){
    return adjRooms;
}
void Room::addAdjacent(Room someRoom){

    Location toAdd(someRoom.getX(),someRoom.getY());
    toAdd.setCost(someRoom.getCost());

    adjRooms.push_back(toAdd);
}
 /*std::ostream& Room::operator<< (std::ostream& outS, const Room& n){
     DSVector<int> holdLoc = n.getLocation();
     int x = holdLoc[0];
     int y = holdLoc[1];
    outS << "x("<<x<<") y("<<y<<"), ";
    return outS;
}//operator<<
 */
 void Room::print(std::ostream& outS){

     int x = getX();
     int y = getY();
     int c;
     outS << "Room x("<<x<<") y("<<y<<"): ";

     for (int j=0; j<adjRooms.getSize(); j++){
        cout << "print: " << j << endl;
         x = adjRooms.at(j)->getData().getX();
         y = adjRooms.at(j)->getData().getY();
         c = adjRooms.at(j)->getData().getCost();
         outS<< "(" << x << "," << y <<"), "<< "c:"<<c<<", ";
     }
     outS << endl;

 }