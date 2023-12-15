//
// Created by robot on 3/28/2021.
//

#include "Location.h"
#include "DSVector.h"

Location::Location(){
    x = -1;
    y = -1;
    cost = 1;
    coordinates.pushback(-1);
    coordinates.pushback(-1);
}
Location::Location(Location& toCopy){
    x=toCopy.x ;
    y=toCopy.y;
    cost = toCopy.cost;
    coordinates.pushback(x);
    coordinates.pushback(y);
}
Location::Location(int xspot, int yspot){
    x = xspot;
    y = yspot;
    cost = 1;
    coordinates[0] = x;
    coordinates[1] = y;
}
bool Location::operator==(const Location& val)const{
    //cout <<"x:val.x" << x << ":" << val.x << endl;
    if((x==val.x) && (y==val.y)) {
        return true;
    }
    else {
        return false;
    }
}
void Location::operator=(const Location& val){
    x=val.x ;
    y=val.y;
    cost = val.cost;
    coordinates[0] = x;
    coordinates[1] = y;
}
DSVector<int> Location::getCoordinates(){
    return coordinates;
}
int Location::getX(){
    return x;
}
int Location::getY(){
    return y;
}
int Location::getCost()const{
    return cost;
}
void Location::setCoordinates(DSVector<int> val){
    x = val[0];
    y = val[1];
    coordinates[0] = x;
    coordinates[1] = y;
}
void Location::setCoordinates(int xspot, int yspot){
    x = xspot;
    y = yspot;
    coordinates[0] = x;
    coordinates[1] = y;
}
void Location::setCost(int newCost){
    cost = newCost;
}