// Heap.h

#ifndef C5910_CODE_HEAP_H
#define C5910_CODE_HEAP_H

#include <string>
using namespace std;

class Heap {
public:
    Heap(int);
    ~Heap();
    void add(int);
    void remove();
    int peek() const;
    bool empty() const;
    string getLevelTraversal() const;
private:
    int * data;
    int heapSize;
    int capacity;

    void siftUp(int);
    void siftDown(int);
    int getParent(int) const;
    int getLeftChild(int) const;
    int getRightChild(int) const;
    void resize();
};


#endif //C5910_CODE_HEAP_H
