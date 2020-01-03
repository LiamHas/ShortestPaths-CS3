
#ifndef BinaryHeap_hpp
#define BinaryHeap_hpp

#include <stdio.h>

class BinaryHeap
{
    private:
        int* itemsArr;
        int* posArr;
        double* priorArr;
        int size;
        void percolateUp(int pos);
        void heapify(int pos);
    
    public:
        BinaryHeap(const double* priorities, int numItems);
        ~BinaryHeap();
        int getMin() const;
        void popMin();
        bool contains(int item) const;
        double getPriority(int item) const;
        void decreasePriority(int item, double newPriority);
        int getSize() const;
        int getItem(int pos) const;
        int getPos(int item) const;
};
    
    
#endif /* BinaryHeap_hpp */
