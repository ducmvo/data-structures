//
// Created by Duc Vo on 10/23/21.
//

#ifndef PRACTICE_LIST_H
#define PRACTICE_LIST_H

template <class T>
class List {
public:
    List(int);
    ~List();
    void insert(T);
    bool contains(T);
private:
    T *aPtr;
    int capacity;
    int size;
};


#endif //PRACTICE_LIST_H
