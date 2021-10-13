//
// Created by Duc Vo on 10/12/21.
//

#ifndef P1_BOOKLIST_H
#define P1_BOOKLIST_H
#include <string>
using namespace std;

class BookList {
public:
    BookList(int);              // Constructor
    BookList();                 // Empty constructor
    ~BookList();                // Destructor

    void add(string, string, string);             // add a book to array
    int get(int isbn);
    int getIsbn (int index);    // get book isbn from index
    int size() const;           // number of books in array
    string to_string() const;   // return string representation
                                // of BooList class
    int load(string);           // load books from file

private:
    struct Book {
        int isbn;
        string title;
        string author;
        string year;
    };
    static const int DEFAULT_CAPACITY = 100;
    Book* bookList;             // pointer to books array
    int capacity;               // array capacity
    int numBooks;               // number of books
    void resize();              // resize array when full

};


#endif //P1_BOOKLIST_H
