
#include "BinaryHeap.hpp"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

void BinaryHeap::heapify(int pos)
{
    int l = 2*pos + 1;
    int r = 2*pos + 2;
    
    int smallPos = 0;
    
    if(l <= size-1 && priorArr[itemsArr[l]] < priorArr[itemsArr[pos]])
    {
        smallPos = l;
    }
    
    else
    {
        smallPos = pos;
    }
    
    if(r <= size-1 && priorArr[itemsArr[r]] < priorArr[itemsArr[smallPos]])
    {
        smallPos = r;
    }
    
    if(smallPos != pos)
    {
        int holder = itemsArr[smallPos];
        itemsArr[smallPos] = itemsArr[pos];
        itemsArr[pos] = holder;
        
        int holder2 = posArr[itemsArr[smallPos]];
        posArr[itemsArr[smallPos]] = posArr[itemsArr[pos]];
        posArr[itemsArr[pos]] = holder2;
        
        heapify(smallPos);
    }

}

void BinaryHeap::percolateUp(int pos)
{
    int curPos = pos;
    int parent = (curPos-1)/2;
    
    while(curPos > 0 && priorArr[parent] > priorArr[curPos])
    {
        double holder = priorArr[curPos];
        priorArr[curPos] = priorArr[parent];
        priorArr[parent] = holder;

        curPos = parent;
        parent = (curPos-1)/2;
    }
   
    
}

BinaryHeap::BinaryHeap(const double* priorities, int numItems)
{
    itemsArr = new int[numItems];
    posArr = new int[numItems];
    priorArr = new double[numItems];
    size = numItems;
    
    for(int i = 0; i<numItems; i++)
    {
        priorArr[i] = priorities[i];
        itemsArr[i] = i;
        posArr[i] = i;
    }
    
    for(int i = numItems/2 ; i >= 0; i--)
    {
        heapify(i);
    }
}
BinaryHeap::~BinaryHeap()
{
    delete[] itemsArr;
    delete [] posArr;
    delete [] priorArr;
}

int BinaryHeap::getMin() const
{
    return itemsArr[0];
}

void BinaryHeap::popMin()
{
    
    itemsArr[0] = itemsArr[size-1];
    
    for(int i = 0; i < size; i++)
    {
        heapify(i);
    }
    
    size--;
}

bool BinaryHeap::contains(int item) const
{
    if(itemsArr[posArr[item]] == item)
    {
        return true;
    }
    return false;
}

double BinaryHeap::getPriority(int item) const
{
    return priorArr[item];
}

void BinaryHeap::decreasePriority(int item, double newPriority)
{
    if(itemsArr[posArr[item]] != item)
    {
        
    }
    else if(newPriority >= priorArr[item])
    {
        
    }
    else
    {
        priorArr[item] = newPriority;

        percolateUp(posArr[item]);
 ///       for(int i = size/2 ; i >= 0; i--)
    ///    {
            //percolateUp(i);
            //heapify(i);
       // }
    }
    
}
int BinaryHeap::getSize() const
{
    return size;

}
int BinaryHeap::getItem(int pos) const
{
    return itemsArr[pos];

}
int BinaryHeap::getPos(int item) const
{
    return posArr[item];

}
