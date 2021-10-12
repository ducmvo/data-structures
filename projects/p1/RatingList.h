//
// Created by Duc Vo on 10/12/21.
//

#ifndef P1_RATINGLIST_H
#define P1_RATINGLIST_H
#include "MemberList.h"
#include "BookList.h"
#include <string>
using namespace std;
class RatingList {
public:
    RatingList(int);            // Constructor
    RatingList();               // Empty constructor
    ~RatingList();              // Destructor

    void add(int*, int*, int);                // add a rating to array
    int size() const;                       // number of ratings in array
    string to_string() const;                // return string representation
                                            // of RatingList class
    int load(string, MemberList &, BookList &); // load ratings from database
private:
    struct Rating {
        int* book;
        int* account;
        int rating;
    };
    static const int DEFAULT_CAPACITY = 100;
    Rating* ratingList;             // pointer to ratings array
    int capacity;               // array capacity
    int numRatings;               // number of ratings
    void resize();              // resize array when full

};


#endif //P1_RATINGLIST_H
