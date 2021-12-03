//
// Created by Duc Vo on 12/2/21.
//

#ifndef P4_WORDCOUNTER_H
#define P4_WORDCOUNTER_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class WordCounter {
public:
    WordCounter(int);
    ~WordCounter();
    WordCounter(const WordCounter &);
    const WordCounter &operator=(const WordCounter &);


    void addWord(string);
    void removeWord(string);
    int getWordCount(string);
    int getCapacity();
    int getUniqueWordCount();
    int getTotalWordCount();
    bool empty();

    // TODO: REMOVE THIS
    string to_string();

private:
    struct Bucket {
        string data;
        Bucket* next = nullptr;
    };

    Bucket** table;

    int capacity;
    int size;
    int hash(string);
    void addWord(string, int);
};

/**
 * Constructor initialize hash table with default buckets
 * @param capacity hash table capacity
 */
WordCounter::WordCounter(int capacity) {
    this->table = new Bucket*[capacity];
    this->capacity = capacity;
    this->size = 0;
}

/**
 * Destructor deallocate table from memory
 */
WordCounter::~WordCounter() {
    delete [] table;
    this->capacity = 0;
    this->size = 0;
}

/**
 * Takes in a word. If the word does not exist, add word to hash table,
 * set the word count to 1, and update the unique word count.
 * If the word does exist, increments the count of the given word in the hash table.
 * Update the total word counts, regardless of whether the word does or does not exist.
 * Returns the updated word count (the number of times the word has been added to the hash table)
 */
void WordCounter::addWord(string word) {
    addWord(word, hash(word));
//    addWord(word, 0);

}
void WordCounter::addWord(string word, int index) {
    Bucket bucket;
    bucket.data = word;
//    bucket->next = (table[index] == nullptr) ? nullptr : table[index];
    if (table[index] != nullptr)
        bucket.next = table[index];
    table[index] = &bucket;
    size++;
}

/**
 * Takes in a word.
 * The remove method should completely remove the entry from the hash table.
 * If the entry is part of a linked list, that node should be removed from the list.
 * Update the unique and total word counts if necessary.
 */
void WordCounter::removeWord(string word) {

}

/**
 * Returns the count of the specified (passed in) word.
 * If the word has not been encountered before
 * (i.e. does not exists or never been added to the hash table), returns 0.
 * @return count of the specified (passed in) word
 */
int WordCounter::getWordCount(string word) {
    return 0;
}

/**
 * Get hash table capacity
 * @return capacity of the hash table.
 */
int WordCounter::getCapacity() {
    return capacity;
}

/**
 *
 * Get the number of unique words encountered (i.e. entries in the hash table).
 * @return number of unique words
 */
int WordCounter::getUniqueWordCount() {
    return capacity;
}

/**
 * Get the total number of words encountered, including duplicates.
 * @return total number of words.
 */
int WordCounter::getTotalWordCount() {
    return capacity;
}

/**
 * Returns true if no words have been added to the hash table;
 * otherwise, returns false.
 * @return true if table is empty, false otherwise
 */
bool WordCounter::empty() {
    return size == 0;
}

// TODO: REMOVE
string WordCounter::to_string() {
        cout << table[1]->next->next->data;
//    for (int i = 0; i < capacity; i++) {
//        cout << table[i]->data;
//    }
    return "";
}

/**
 * Hash the input word to table index
 * @param word input word
 * @return hash table index
 */
int WordCounter::hash(string word) {
    return ::hash<string>{}(word) % capacity;
}


#endif //P4_WORDCOUNTER_H
