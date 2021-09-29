//
// Created by Duc Vo on 9/28/21.
//

#ifndef ICE1_DATE_H
#define ICE1_DATE_H
using namespace std;
#include <string>
#include <cstring>

class Date {
public:
    Date();
    Date(int, int, int);
    void setDate(int, int, int);
    string getDate() const;
    string getSeason() const;
private:
    int year;
    int month;
    int day;
};


#endif //ICE1_DATE_H
