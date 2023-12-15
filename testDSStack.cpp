//
// Created by robot on 3/28/2021.
//
#include "catch.hpp"
#include "DSStack.h"
#include "DSNode.h"
#include <iostream>

using namespace std;

TEST_CASE("DSStscks csn be manipulated"){
    SECTION("Adding to a Stack and Popping"){
        DSStack<int> myStack;
        myStack.push(1);
        myStack.push(2);
        myStack.push(3);
        CHECK((myStack.top()==3));
        CHECK((myStack.bottom()==1));
        //cout<< "pop: " <<myStack.pop() << endl;
        CHECK((myStack.pop()==3));
    }
    SECTION("Clearing a Stack"){
        DSStack<int> myStack;
        myStack.push(1);
        myStack.push(2);
        myStack.push(3);
        myStack.clear();
        CHECK((myStack.getSize()==0));
    }
}