// Heap.cpp
// max heap
#include "Heap.h"
#include <cassert>
#include <sstream>
//using namespace std;


//*********************
// PUBLIC FUNCTIONS   *
//*********************

Heap::Heap(int cap) {
    capacity = cap;
    heapSize = 0;
    data = new int[cap];
}

Heap::~Heap() {
    delete [] data;
}

void Heap::add(int item) {
    if (heapSize == capacity)
        resize();
    data[heapSize++] = item;
    siftUp(heapSize - 1);
}

void Heap::remove() {
    assert(!empty());
    data[0] = data[--heapSize];
    if (heapSize > 1)
        siftDown(0);
}

int Heap::peek() const {
    assert(!empty());
    return data[0];
}

bool Heap::empty() const {
    return heapSize == 0;
}

string Heap::getLevelTraversal() const {
    stringstream ss;
    for (int i = 0; i < heapSize; i++)
        ss << data[i] << " ";
    ss << "\n";
    return ss.str();
}


//*********************
// PRIVATE FUNCTIONS  *
//*********************

void Heap::siftUp(int index) {
    int parentIdx, temp;
    if (index != 0) {
        parentIdx = getParent(index);
        if (data[parentIdx] < data[index]) {
            temp = data[parentIdx];
            data[parentIdx] = data[index];
            data[index] = temp;
            siftUp(parentIdx);
        }
    }
}

void Heap::siftDown(int index) {
    int leftIdx, rightIdx, maxIdx, temp;
    leftIdx = getLeftChild(index);
    rightIdx = getRightChild(index);

    // find minIdx
    if (rightIdx >= heapSize) {
        if (leftIdx >= heapSize)
            return;
        else
            maxIdx = leftIdx;
    } else {
        if (data[leftIdx] >= data[rightIdx])
            maxIdx = leftIdx;
        else
            maxIdx = rightIdx;
    }

    // swap?
    if (data[index] < data[maxIdx]) {
        temp = data[maxIdx];
        data[maxIdx] = data[index];
        data[index] = temp;
        siftDown(maxIdx);
    }
}

int Heap::getParent(int index) const {
    return (index - 1) / 2;
}

int Heap::getLeftChild(int index) const {
    return 2 * index + 1;
}

int Heap::getRightChild(int index) const {
    return 2 * index + 2;
}

void Heap::resize() {
    // TODO
}