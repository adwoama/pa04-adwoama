//
// Created by robot on 3/26/2021.
//
#include "catch.hpp"
#include "DSList.h"
#include "DSNode.h"
#include <iostream>

using namespace std;

TEST_CASE("DSList can be accessed") {


    SECTION("testing at()") {
        int h1, h2, h3;
        h1 = 0;
        h2 = 1;
        h3 = 2;
        DSList<int> myList;// = new DSList<int>;
        //cout << "DSList created!" << endl;
        myList.push_back(h1);
        //cout << "pushback 0 complete" << endl;
        myList.push_back(h2);
        //cout << "pushback 1 complete" << endl;
        myList.push_back(h3);
        //cout << "pushback 2 complete" << endl;
        //cout << "check spot 0: " << myList.at(0)->getData() << endl;
        //cout << "check head " << myList.front()->getData() << endl;
        //cout << "check 1: " << (myList.at(1))->getData() << endl;
        //cout << "check 2: " << myList.back()->getData() << endl;
        CHECK((myList.at(1)->getData() == 1));
        cout << "find 1: " << myList.find(1) << endl;
        CHECK((myList.find(1)==1));
        //delete myList;

    }

    SECTION("testing front()") {
        int h1, h2, h3;
        h1 = 0;
        h2 = 1;
        h3 = 2;
        DSList<int> myList;// = new DSList<int>;
        //cout << "DSList created!" << endl;
        myList.push_back(h1);
        //cout << "pushback 0 complete" << endl;
        myList.push_back(h2);
        //cout << "pushback 1 complete" << endl;
        myList.push_back(h3);
        //cout << "pushback 2 complete" << endl;
        //cout << "check spot 0: " << myList.at(0)->getData() << endl;
        //cout << "check head " << myList.front()->getData() << endl;
        //cout << "check 1: " << (myList.at(1))->getData() << endl;
        //cout << "check 2: " << myList.back()->getData() << endl;
        CHECK((myList.front()->getData() == 0));
        //cout << myList->front()->getData() << endl;
        //delete myList;
    }

    SECTION("testing back()"){
        int h1,h2,h3;
        h1 = 0;
        h2 = 1;
        h3 = 2;
        DSList<int> myList;// = new DSList<int>;
        //cout << "DSList created!" << endl;
        myList.push_back(h1);
        //cout << "pushback 0 complete" << endl;
        myList.push_back(h2);
        //cout << "pushback 1 complete" << endl;
        myList.push_back(h3);
        //cout << "pushback 2 complete" << endl;
        //cout << "check spot 0: " << myList.at(0)->getData() << endl;
        //cout << "check head " << myList.front()->getData() << endl;
        //cout << "check 1: " << (myList.at(1))->getData() << endl;
        //cout << "check 2: " << myList.back()->getData() << endl;
        CHECK((myList.back()->getData()==2));
        //delete myList;
    }


}

TEST_CASE("DSList can have elements added") {

    SECTION("testing push_back() method") {
        DSList<int> *myList = new DSList<int>;
        int h1, h2, h3;
        h1 = 0;
        h2 = 1;
        h3 = 2;
        myList->push_back(h2);
        myList->push_back(h3);
        CHECK((myList->back()->getData() == 2));
        //cout << myList->back()->getData() << endl;
        delete myList;
    }SECTION("testing insert_front method") {
        DSList<int> *myList = new DSList<int>;
        int h1, h2, h3;
        h1 = 0;
        h2 = 1;
        h3 = 2;
        myList->insert_front(h1);
        CHECK((myList->front()->getData() == 0));
        //cout << myList->front()->getData() << endl;
        delete myList;
    }
    SECTION("testing insert_after"){
        DSList<int> *myList = new DSList<int>;
        int h1, h2, h3;
        h1 = 0;
        h2 = 1;
        h3 = 2;
        //DSNode<int>* add = (myList->back())->getPrev();
        myList->push_back(h1);
        myList->push_back(h2);
        myList->push_back(h3);
        int h4 = 4;
        myList->insert_after((myList->back())->getPrev(), h4);
        CHECK(((myList->at(2))->getData()==4));
        //cout << myList->at(2)->getData() << endl;
        delete myList;
    }

}

TEST_CASE("DSList can have elements removed"){
    /*
    SECTION("testing remove"){

    }
    SECTION("testing remove all"){

    }
     */
    SECTION("testing clear"){
        DSList<int>* myList = new DSList<int>;
        myList->push_back(0);
        myList->push_back(1);
        myList->push_back(2);
        myList->push_back(3);
        myList->clear();
        CHECK((myList->getSize()==0));
        //CHECK((myList->front()==nullptr));
        delete myList;
    }

}
