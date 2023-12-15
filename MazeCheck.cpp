//
// Created by robot on 3/30/2021.
//

#include "MazeCheck.h"

#include "Location.h"
#include "Room.h"
#include "AdjacencyList.h"
#include "DSStack.h"
#include "DSList.h"
#include "Iterator.h"
#include "DSNode.h"
#include "DSVector.h"
#include "DSString.h"
#include <fstream>
#include <exception>
#include <iostream>

using namespace std;

MazeCheck::MazeCheck(){
    leastPoints = 1000000;
    mostPoints = 0;
}
void MazeCheck::readMaze(DSString file){
    DSString windowsR("\r");
    int numPortals;
    ifstream inFS;
    int holdInt;
    char holdChar;
    char* holdCString = new char [100];
    DSString holdString;
    inFS.open(file.c_str());
    if(!inFS.is_open()){
        cout << "failed to open: " << file << endl;
        throw ios_base::failure("bad file name");
    }
    //read in # of rows and colums in maze
    inFS >> holdInt;
    rows = holdInt;
    inFS >> holdInt;
    cols = holdInt;
    maze = new int*[rows];
    for(int i = 0; i < rows; i++){//declare memore for maze 2D int array
        maze[i] = new int[cols];
    }
    /*
    while(!inFS.eof() && inFS.good()) {
       //TODO determine stream error
        inFS>>holdCString;
        holdString = holdCString;
        cout << holdString << endl;
    }
     */

     //read in rooms and walls
    for(int r = 0; r < rows; r++){
        inFS>>holdCString;
        holdString = holdCString;
        if(holdString == windowsR){
            inFS>>holdCString;
            holdString = holdCString;
        } else if(holdString.find(windowsR)>0){
            holdString =holdString.substring(0,holdString.getLength()-1);
        }
        for(int c = 0; c < cols; c++){
            holdInt = strtol((holdString.substring(c,1)).c_str(),nullptr, 10);
            maze[r][c] = holdInt;
        }//for each columns
        if(inFS.eof()){
            cout << "end of file!" << endl;
            break;
        }
        //inFS.getline(holdCString, cols+1);
    }//for each row

    //read portals and save to portal list
    inFS >> holdInt;
    numPortals = holdInt;
    for(int i = 0; i < numPortals; i++){
        int r,c,toR,toC,HP;
        inFS >> r;
        inFS >> c;
        inFS >> toR;
        inFS >> toC;
        inFS >> HP;
        Room myRoom(r-1,c-1);
        Room toRoom(toR-1, toC-1);
        toRoom.setCost(HP);
        int spot = portals.contains(myRoom);
        if(spot>=0){
            (portals.get(spot)).addAdjacent(toRoom);
        }
        else{
            portals.pushback(myRoom);
            spot = portals.contains(myRoom);
            (portals.get(spot)).addAdjacent(toRoom);
        }
    }
    //read in start and end
    int holdX=-1;
    int holdY=-1;
    inFS>>holdChar;
    inFS >> holdX;
    inFS >> holdY;
    start.setCoordinates(holdX-1, holdY-1);
    inFS>>holdChar;
    inFS >> holdX;
    inFS >> holdY;
    end.setCoordinates(holdX-1,holdY-1);
    inFS.close();
    //Print Check
    for(int r = 0; r < rows; r++) {

        for (int c = 0; c < cols; c++) {
            cout << maze[r][c];
        }//for each colums
        cout<< endl;
    }//for each row
    cout << "Check Portals:(" <<portals.getSize() << ")" << endl;
    for(int i = 0; i < portals.getSize(); i++){
        portals.get(i).print();
        //cout << endl;
    }
    cout << "Check Start: " << start.getX() << "," << start.getY() << endl;
    cout << "Check End: " << end.getX() << "," << end.getY() << endl;
}//readMaze

void MazeCheck::makeRoomList(){
    cout << "Building Room List" << endl;
    for(int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << "r" << r << " c"<<c << endl;
            //Add room to adjacency list
            if (maze[r][c] == 0) {
                Room myRoom(r, c);
                roomList.pushback(myRoom);
            }
        }
    }
    cout << "finished" << endl;
}

void MazeCheck::makeAdjList(){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            //Add room to adjacency list
            if(maze[r][c]==0) {
                Room myRoom(r, c);
                int findMyRoom = roomList.contains(myRoom);
                //connections.add_Room(myRoom);

                //Check Up
                if ((r - 1) >= 0) {
                    if (maze[r - 1][c] == 0) {
                        Room toAdd(r - 1, c);
                        int findToAdd = roomList.contains(toAdd);
                        roomList.get(findMyRoom).addAdjacent(toAdd);
                        connections.add_edge(roomList.get(findMyRoom), roomList.get(findToAdd));
                    }//if a room (not a wall)
                }//if not out of maze bounds
                //Check Right
                if ((c + 1) < cols) {
                    if (maze[r][c + 1] == 0) {
                        Room toAdd(r, c + 1);
                        int findToAdd = roomList.contains(toAdd);
                        roomList.get(findMyRoom).addAdjacent(toAdd);
                        connections.add_edge(roomList.get(findMyRoom), roomList.get(findToAdd));
                        //connections.add_edge(myRoom, toAdd);
                    }//if a room (not a wall)
                }//if not out of maze bounds
                //Check Down
                if ((r + 1) < rows) {
                    if (maze[r + 1][c] == 0) {
                        Room toAdd(r + 1, c);
                        int findToAdd = roomList.contains(toAdd);
                        roomList.get(findMyRoom).addAdjacent(toAdd);
                        connections.add_edge(roomList.get(findMyRoom), roomList.get(findToAdd));
                        //connections.add_edge(myRoom, toAdd);
                    }//if a room (not a wall)
                }//if not out of maze bounds
                //Check Left
                if ((c - 1) >= 0) {
                    if (maze[r][c - 1] == 0) {
                        Room toAdd(r, c - 1);
                        int findToAdd = roomList.contains(toAdd);
                        roomList.get(findMyRoom).addAdjacent(toAdd);
                        connections.add_edge(roomList.get(findMyRoom), roomList.get(findToAdd));
                        //connections.add_edge(myRoom, toAdd);
                    }//if a room (not a wall)
                }//if not out of maze bounds
                //Check Portals

                int included = portals.contains(myRoom);

                if (included > -1) {
                    DSList<Location> myAdj;
                    myAdj = portals.get(included).getAdjacent();//iterate list of adj rooms from portals
                    int x, y;
                    Iterator<Location> *spot = myAdj.getIteratorAtHead();
                    DSNode<Location> *search;
                    /*while ((search = spot->nextNode()) != nullptr) {
                        x = search->getData().getX();
                        y = search->getData().getY();
                        Room toAdd(x, y);
                        toAdd.setCost(portals.get(included).getCost());
                        connections.add_edge(myRoom, toAdd);

                        roomList.get(findMyRoom).addAdjacent(toAdd);
                    }*/
                    for(int j = 0; j < portals.get(included).getAdjacent().getSize(); j++){
                        x = portals.get(included).getAdjacent().at(j)->getData().getX();
                        y = portals.get(included).getAdjacent().at(j)->getData().getY();
                        Room toAdd(x, y);
                        toAdd.setCost(portals.get(included).getCost());
                        roomList.get(findMyRoom).addAdjacent(toAdd);
                    }

                }//if this room has a portal add them to adjacency list

            }//if it is not a wall

        }//for each column

    }//for each row
    cout << "Print Adjacency List Check..." << endl;
    //connections.printRooms();
    cout << "Check Rooms:(" <<roomList.getSize() << ")" << endl;
    for(int i = 0; i < roomList.getSize(); i++){
        roomList.get(i).print();
        //cout << endl;
    }
}//makeAdjList()
void MazeCheck::findPaths(){
    DSStack<Room> path;
    int points = 0;
    //1.Put start on stack
    Room Begin(start.getX(), start.getY());
    int findMyRoom = roomList.contains(Begin);
    Room End(end.getX(), end.getY());
    //cout << start.getX() << " " << start.getY() << endl;
    //cout << end.getX() << " " << end.getY() << endl;

    path.push(roomList.get(findMyRoom));
    while(path.getSize() != 0) {//2.
        //3.is path.top == end?
        if(path.top() == End) {
            //-yes: store path(if shortest and score if longest) & pop
            allPaths.pushback(path);
            if(points <= leastPoints) {
                bestPath = path;
                leastPoints = points;
            }
            if(points >= mostPoints){
                mostPoints = points;
            }
            path.pop();
            findMyRoom = roomList.contains(path.top());
            roomList.get(findMyRoom).getAdjacent().iterNext();
        }//if end is reached
        else {
            //-no: for connection in stack.top: is connection NULL?
            findMyRoom = roomList.contains(path.top());
            if(roomList.get(findMyRoom).getAdjacent().iterCurrent() == nullptr) {
                //--yes:pop stack.top & reset iter
                //points -= roomList.get(findMyRoom).getAdjacent().iterCurrent()->getData().getCost();
                path.pop();
                roomList.get(findMyRoom).getAdjacent().resetIter();
                roomList.get(findMyRoom).getAdjacent().iterNext();


                if(path.getSize() > 0) {
                    findMyRoom = roomList.contains(path.top());
                    roomList.get(findMyRoom).getAdjacent().iterNext();
                }
            }//if connection on stack has null connection
            if(path.getSize()>0) {
                int check1 = path.top().getX();
                int check2 = path.top().getY();
                int check3 = path.top().getCost();
                int holdX = roomList.get(findMyRoom).getAdjacent().iterCurrent()->getData().getX();
                int holdY = roomList.get(findMyRoom).getAdjacent().iterCurrent()->getData().getY();
                Room findRoom(holdX, holdY);
                if (path.contains(findRoom) >= 0) {//--Is connection on stack?
                    //--Yes: continue, move iter
                    roomList.get(findMyRoom).getAdjacent().iterNext();

                }//if connection is on stack
                else {
                    //--No:  push connection, jump to step 3 , move iter
                    int spot = roomList.contains(findRoom);
                    path.push(roomList.get(spot));
                    points += roomList.get(spot).getCost();
                }//if connection is NOT on stack
            }
        }//path.top != End

    }//while stack not empty
    //cout << "small path size: " << mostPoints << endl;
    //cout << "big path size: " << leastPoints << endl;
    cout << "number of paths: " << allPaths.getSize() << endl;
}//findPaths
void MazeCheck::printPaths(DSString outMin, DSString outMax){
    ofstream outFS;
    DSVector<Room> best;
    DSVector<Room> worst;


    mostPoints = 0;
    leastPoints = 10000;
    int points = 0;
    //1.Iterate through list of paths
    for(int i = 0; i < allPaths.getSize(); i++) {
        //in each path iterate through stack
        DSVector<Room> possible;
        points = 0;
        Room previous;
        previous.setLocation(end.getX(),end.getY());
        while(allPaths.get(i).getSize()>0) {
            //--save each room in possible and add up points
            if(allPaths.get(i).top().getX() >0) {
                Room holder;
                int findScore;
                holder.setLocation(allPaths.get(i).top().getX(), allPaths.get(i).top().getY());
                holder.setCost(allPaths.get(i).top().getCost());
                findScore = portals.contains(holder);

                if(findScore>=0 &&(abs(previous.getX()-holder.getX())>1 || abs(previous.getY()-holder.getY())>1)) {
                    Location findPortal;
                    findPortal.setCoordinates(previous.getX(),previous.getY());
                    int loc = portals.get(findScore).getAdjacent().find(findPortal);
                    points += portals.get(findScore).getAdjacent().at(loc)->getData().getCost();
                }
                else
                    points += holder.getCost();
                possible.pushback(holder);
            }
            allPaths.get(i).pop();
        }//pop to iterate path
        //if points < min: save as best
        if(points < leastPoints){
            leastPoints = points;
            best = possible;
        }
        //if points > max: save as worst
        if(points > mostPoints){
            mostPoints = points;
            worst = possible;
        }
    }//for each path

    //2. Iterate backwards through best and print to min output file
    outFS.open(outMin.c_str());
    if(!outFS.is_open()){
        cout << "failed to open: " << outMin << endl;
        throw ios_base::failure("bad file name");
    }
    outFS << leastPoints << endl;
    outFS << best.getSize() << endl;
    for(int i = best.getSize()-1; i >= 0; i--){
        outFS << (best.get(i).getX()+1) << " " << (best.get(i).getY()+1) << " " << best.get(i).getCost();
        outFS << endl;
    }
    outFS.close();
    //3. Iterate backwards through worst and print to max output file
    outFS.open(outMax.c_str());
    if(!outFS.is_open()){
        cout << "failed to open: " << outMax << endl;
        throw ios_base::failure("bad file name");
    }
    outFS << mostPoints << endl;
    outFS << worst.getSize() << endl;
    for(int i = worst.getSize()-1; i >= 0; i--){
        outFS << (worst.get(i).getX()+1) << " " << (worst.get(i).getY()+1) << " " << worst.get(i).getCost();
        outFS << endl;
    }
    outFS.close();
}//printPaths