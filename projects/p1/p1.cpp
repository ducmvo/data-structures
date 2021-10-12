#include <iostream>
#include "BookList.h"
#include "MemberList.h"
#include "RatingList.h"
using namespace std;

int main() {
    BookList books(100);
    MemberList members(100);
    RatingList ratings(100);
    string fileName;
    const string DEFAULT_BOOKS_FILE = "books.txt";
    const string DEFAULT_RATINGS_FILE = "ratings.txt";
        
    // Load books from file
    if(books.load(DEFAULT_BOOKS_FILE)) {
        // Input book file path
        cout << "Enter books file: ";
        getline(cin, fileName);
        if(books.load(fileName)) {
            cout << "Failed to load file" << endl;
            return -1;
        };
    };

    // Load members and ratings from file
    if(ratings.load(DEFAULT_RATINGS_FILE, members, books)) {
        // Input book file path
        cout << "Enter ratings file: ";
        getline(cin, fileName);
        if(books.load(fileName)) {
            cout << "Failed to load file" << endl;
            return -1;
        };
    };

    // Print loaded books
    cout << "# of books: " + to_string(books.size()) << endl;
    cout << books.to_string() << endl << endl;
    cout << "# of members: " + to_string(members.size()) << endl;
    cout << members.to_string() << endl << endl;
    cout << "# of ratings: " + to_string(ratings.size()) << endl;
    cout << ratings.to_string() << endl << endl;

    // Add a new book
//    books.add("Invest in crypto", "Duc Vo", "2021");
    return 0;
}