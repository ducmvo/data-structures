//
// Created by Duc Vo on 10/5/21.
//

#ifndef LAB2_BOOKLIST_H
#define LAB2_BOOKLIST_H
#include <string>
using namespace std;

class BookList {
public:
    BookList(int);              // Constructor
    BookList();                 // Empty constructor
    ~BookList();                // Destructor

    void add(string, string, string);             // add a book to array
    int size() const;           // number of books in array
    string to_string() const;   // return string representation
                                // of BooList class
    int load(string);           // load books from file

private:
    struct Book {
        string title;
        string author;
        string year;
        int isbn;
    };
    static const int DEFAULT_CAPACITY = 100;
    Book* bookList;             // pointer to books array
    int capacity;               // array capacity
    int numBooks;               // number of books
    void resize();              // resize array when full

};


#endif //LAB2_BOOKLIST_H
