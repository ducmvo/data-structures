//
// Created by Duc Vo on 11/13/21.
//

#ifndef LAB6_HASHTABLE_H
#define LAB6_HASHTABLE_H
class HashTable {
public:
    HashTable(int capacity);
    ~HashTable();
    int put(int key, int value);
    int get(int key);
    bool contains(int key);
    int size();
    bool empty();
private:
    struct Bucket {
        int key;
        int value;
    };
    Bucket** table;
    int capacity;
    int tableSize;

    int hash(int key);
};

HashTable::HashTable(int capacity) {
    this->table = new Bucket*[capacity];
    this->capacity = capacity;
    this->tableSize = 0;
}

HashTable::~HashTable() {
    for (int i = 0; i < capacity; i++) {
        if (table[i] != nullptr)
            delete table[i];
    }
    delete [] table;
}

int HashTable::hash(int key) {
    return key % capacity;
}

int HashTable::size() {
    return tableSize;
}

bool HashTable::empty() {
    return tableSize == 0;
}

int HashTable::put(int key, int value) {
    int index = hash(key);

    while (table[index] != nullptr
    && table[index]->key != key) {
        index++;
        index = hash(index);
    }

    if (table[index] == nullptr) {
        Bucket *bucket = new Bucket;
        bucket->key = key;
        bucket->value = value;
        table[index] = bucket;
        tableSize++;
    } else if (table[index]->key == key) {
        table[index]->value = value;
    }

    return index;
}


int HashTable::get(int key) {
    int index = hash(key);
    if (table[index] == nullptr)
        return -1;

    while (table[index] != nullptr && table[index]->key != key) {
        index++;
        index = hash(index);
    }
    return table[index]->value;
}

bool HashTable::contains(int key) {
    int index = hash(key);
    if (table[index] == nullptr) return false;
    while (table[index]->key != key) {
        index++;
        index = hash(index);
    }
    return true;
}

#endif //LAB6_HASHTABLE_H
