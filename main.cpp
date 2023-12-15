#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include <iostream>
#include "AdjacencyList.h"
#include "Room.h"
#include "Location.h"
#include "MazeCheck.h"
int testFunc(){
    return Catch::Session().run();
}
void testAdjList(){
    AdjacencyList maze;
    //make rooms
    Room room1(1,1);
    Room room2(2,1);
    Room room3(3,1);
    Room room4(4,1);
    Room room5(5,1);
    Room room6(1,2);
    Room room7(2,2);
    Room room8(3,2);
    Room room9(4,2);
    Room room10(5,2);
    //make rooms adjacent to each other


    maze.add_Room(room1);
    maze.add_Room(room2);
    maze.add_Room(room3);
    maze.add_Room(room4);
    maze.add_Room(room5);
    maze.add_Room(room6);
    maze.add_Room(room7);
    maze.add_Room(room8);
    maze.add_Room(room9);
    maze.add_Room(room10);

    /*Right now it adds the edges incorrectly)*/
    maze.add_edge(room1,room2);
    maze.add_edge(room1,room6);

    maze.add_edge(room2,room1);
    maze.add_edge(room2,room3);
    maze.add_edge(room2,room7);

    maze.add_edge(room3,room2);
    maze.add_edge(room3,room4);
    maze.add_edge(room3,room8);

    maze.add_edge(room4,room3);
    maze.add_edge(room4,room5);
    maze.add_edge(room4,room9);

    //print adjacent list
    maze.printRooms();

}
int main(int argc, char** argv) {
    if(argc == 1){
        cout << "Running Catch..." << endl;
        testFunc();
        cout << "Testing Adjacency List..." << endl;
        testAdjList();



        return 0;
    }
    else {
        DSString inputFile = argv[1];
        DSString minOutputFile = argv[2];
        DSString maxOutputFile = argv[3];
        cout << "Check MazeCheck:" << endl;
        MazeCheck myMaze;
        DSString myFile(inputFile);
        myMaze.readMaze(myFile);
        myMaze.makeRoomList();
        myMaze.makeAdjList();
        myMaze.findPaths();
        myMaze.printPaths(minOutputFile, maxOutputFile);
        std::cout << "Time for some Amazing Coding!" << std::endl;
        return 0;
    }
}
