#include <iostream>
#include "BookList.h"
using namespace std;

int main() {
    BookList books;
    string fileName;

    // Input book file path
    cout << "Enter books file: ";
    getline(cin, fileName);
    // Load books from file
    if(books.load(fileName)) {
        cout << "Failed to load file" << endl;
        return -1;
    };

    // Print loaded books
    cout << "# of books: " + to_string(books.size()) << endl;
    cout << books.to_string() << endl;

    // Add a new book
    books.add("Invest in crypto", "Duc Vo", "2021");
    return 0;
}
