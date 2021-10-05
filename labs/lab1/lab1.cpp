#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
/**
 * This main method opens and read file contain
 * member, book info and book ratings of a book club,
 * then loads the info into dynamic arrays in memory.
 * @author Duc Vo
 * @version 1.0
 */
int main() {
    const string BOOK_FILE = "books.txt";
    const string RATING_FILE = "ratings.txt";
    const int CAPACITY = 100; // Initial array capacity
    int memberSize = 0; // total number of members read from file
    const int BOOK_SIZE = 55; // total number of books read from file
    // dynamically allocate memory
    string* members = new string[CAPACITY];
    int** ratings = new int*[CAPACITY];
    int rating; // member rating for single book
    string line; // member name line
    string line2; // ratings line
    ifstream inputFile;
    stringstream ss;

    // open and save member names and ratings to arrays
    inputFile.open(RATING_FILE);
    if(inputFile.is_open()) {
        while(getline(inputFile, line)) {
            members[memberSize] = line;
            getline(inputFile, line2);
            ss.str(line2);
            ratings[memberSize] = new int[BOOK_SIZE];
            for (int j = 0; j < BOOK_SIZE; j++) {
                ss >> rating;
                ratings[memberSize][j] = rating;
            } 
            memberSize++; 
        }    
    } else {
        cout << "Failed to open file " << RATING_FILE << endl;
        return -1;
    }
    inputFile.close();

    // print member names and ratings
    for (int i = 0; i < memberSize; i++) {
        cout << members[i] << endl;
        for (int j = 0; j < BOOK_SIZE; j++) {
            cout << ratings[i][j] << " ";
        }
        cout << endl;
    }

    // deallocate memory
    for (int i = 0; i < CAPACITY; i++)
        delete [] ratings[i];
    delete [] ratings;
    delete [] members;

    return 0;
}

