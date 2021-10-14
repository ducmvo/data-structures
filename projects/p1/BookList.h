/**
 * Created on 10/12/21.
 * @author Duc Vo
 */
#ifndef P1_BOOKLIST_H
#define P1_BOOKLIST_H
#include <string>
using namespace std;

class BookList {
public:
    BookList(int);                  // Constructor
    BookList();                     // Empty constructor
    ~BookList();                    // Destructor

    int add(string, string, string);// add a book to array, return isbn
    int get(int isbn);              // get index of a book from isbn
    int getIsbn (int index);        // get book isbn from index
    string getAuthor(int index);    // get author from index
    string getTitle(int index);     // get title from index
    string getYear(int index);      // get year from index
    int size() const;               // number of books in array
    string to_string() const;       // return string representation
                                    // of BooList class
    int load(string);               // load books from file

private:
    struct Book {
        int isbn;
        string author;
        string title;
        string year;
    };
    static const int DEFAULT_CAPACITY = 60;
    Book* bookList;                 // pointer to books array
    int capacity;                   // array capacity
    int numBooks;                   // number of books
    void resize();                  // resize array when full

};


#endif //P1_BOOKLIST_H
