//
// Created by Duc Vo on 11/13/21.
//

#ifndef LAB6_HASHTABLE_H
#define LAB6_HASHTABLE_H
class HashTable {
public:
    HashTable(int);             // Constructor hash table
    ~HashTable();               // Destructor hash table
    int put(int, int);          // Insert/Update a table bucket
    int get(int);               // Retrieve a bucket value with provided key
    bool contains(int);         // Check if table contains a bucket provided key
    int size();                 // Size of hash table
    bool empty();               // Empty status of hash table
private:
    struct Bucket {             // Bucket struct
        int key;
        int value;
    };
    Bucket** table;             // Hash table array of Bucket pointers
    int capacity;               // Capacity of hash table
    int tableSize;              // Size of hash table
    int hash(int);              // Hashing function
};
/**
 * Initialize a new hash table with provided capacity
 * @param capacity input hash table capacity
 */
HashTable::HashTable(int capacity) {
    this->table = new Bucket*[capacity];
    this->capacity = capacity;
    this->tableSize = 0;
}
/**
 * Destructor delete hash table all all buckets
 */
HashTable::~HashTable() {
    for (int i = 0; i < capacity; i++) {
        if (table[i] != nullptr)
            delete table[i];
    }
    delete [] table;
}
/**
 * get target table index by hashing the input key
 * @param key input key
 * @return target table index
 */
int HashTable::hash(int key) {
    return key % capacity;
}
/**
 * @return size of hash table
 */
int HashTable::size() {
    return tableSize;
}
/**
 * @return Empty status of hash table
 */
bool HashTable::empty() {
    return tableSize == 0;
}
/**
 * Insert/Update bucket with input key and value
 * @param key user input key
 * @param value user input value
 * @return index of new/update bucket or -1 if failed
 */
int HashTable::put(int key, int value) {
    if (tableSize == capacity) return -1; // if table is full;
    if (key <= 0) return -1; // invalid key
    int increment = 0, index;
    do {
        index = hash(key + increment++); // hash/rehash key
        // check table slot at hashed/rehashed key index
        if (table[index] == nullptr) {
            Bucket *bucket = new Bucket; // create new bucket if slot is empty
            bucket->key = key;
            bucket->value = value;
            table[index] = bucket;
            tableSize++;
            return index;
        }
    } while (table[index]->key != key);
    table[index]->value = value;  // update bucket value with same key
    return index;
}

/**
 * Get the value of a bucket from hash table with provided key
 * @param key user input key
 * @return value of the target bucket from hash table
 */
int HashTable::get(int key) {
    if (key <= 0) return -1;
    int increment = 0, index;
    do {
        index = hash(key + increment++);
        if (table[index] == nullptr) {
            return -1;
        }
    } while (table[index]->key != key); // collision -> rehashing
    return table[index]->value; // bucket with same key found
}

/**
 * Check if hash table contains a specific key
 * @param key look up key
 * @return true if key found, false if not
 */
bool HashTable::contains(int key) {
    return get(key) != -1;
}

#endif //LAB6_HASHTABLE_H
