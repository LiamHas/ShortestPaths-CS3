
#include <stdio.h>
#include <iostream>
#include <fstream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "BinaryHeap.hpp"

using namespace std;

TEST_CASE("Testing Binary Heap class")
{
    SECTION("Testing graph.txt")
    {
        double priorities[] = {2,7,3,13,5};
        int numItems = 5;
        BinaryHeap* bh = new BinaryHeap(priorities, numItems);
        
        REQUIRE(bh->getMin() == 0);
        bh->popMin();
        REQUIRE(bh->contains(0) == false);
        REQUIRE(bh->contains(1) == true);
        REQUIRE(bh->getSize() == 4);

        
        
        double priorities2[] = {15, 21, 3, 6, 11, 8, 5, 7, 13, 12}; 
        int numItems2 = 10;
        BinaryHeap* bh2 = new BinaryHeap(priorities2, numItems2);
        
        REQUIRE(bh2->getMin() == 2);
        REQUIRE(bh2->contains(7) == true);
        REQUIRE(bh2->contains(1) == true);
        REQUIRE(bh2->contains(3) == true);
        REQUIRE(bh2->contains(10) == false);

        REQUIRE(bh2->getPriority(2) == 3);
        REQUIRE(bh2->getPriority(7) == 7);
        REQUIRE(bh2->getPriority(0) == 15);
        REQUIRE(bh2->getPriority(8) == 13);

        bh2->decreasePriority(0, 2);
        bh2->decreasePriority(0, 1000);
        bh2->decreasePriority(10, 1);


        double priorities3[] = {18, 25, 19, 2, 21, 12, 26, 13, 3, 17};
        int numItems3 = 10;
        BinaryHeap* bh3 = new BinaryHeap(priorities3, numItems3);
        
        REQUIRE(bh3->getMin() == 3);
        bh3->decreasePriority(1, 10);
        
        REQUIRE(bh3->getSize() == 10);
        REQUIRE(bh3->getItem(3) == 7);
        
        for(int i = 0; i < 10; i++)
        {
            cout<<bh3->getItem(i)<<" ";
        }
        cout<<endl;
        
        for(int i = 0; i < 10; i++)
        {
            cout<<bh2->getItem(i)<<" ";
        }
        
        REQUIRE(bh3->getPos(5) == 2);



    }
}
