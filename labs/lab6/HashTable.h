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
    if (tableSize == capacity) return -1; // if table is full;

    int increment = 0, index;
    do {
        // hash/rehash key
        index = hash(key + increment++);
        // check table slot at hashed/rehashed key index
        // table slot is empty
        if (table[index] == nullptr) {
            // create new bucket
            Bucket *bucket = new Bucket;
            bucket->key = key;
            bucket->value = value;
            table[index] = bucket;
            tableSize++;
            return index;
        }
    } while (table[index]->key != key); // collision -> rehashing

    // bucket with same key found (table[index]->key == key)
    table[index]->value = value;  // update value
    return index;
}


int HashTable::get(int key) {

}

bool HashTable::contains(int key) {
    if (key < 0) return -1; // invalid key input
    int increment = 0, index;
    do {
        // hash/rehash key
        index = hash(key + increment++);
        // check table slot at hashed/rehashed key index
        // table slot is empty
        if (table[index] == nullptr) {
           return false;
        }
    } while (table[index]->key != key); // collision -> rehashing

    // bucket with same key found (table[index]->key == key)
    return true;

}

#endif //LAB6_HASHTABLE_H
