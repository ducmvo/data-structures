#include <iostream>
#include "Date.h"
using namespace std;
struct SDate {
    int month;
    int day;
    int year;
};

int main() {
    SDate dates [8] = {
            {01,01,2012},
            {03,10,1996},
            {06,20,2015},
            {9,22,2000},
            {12,25,1980},
            {11,22,2001},
            {10,31,2017},
            {9,23,2011}
    };

    Date date;
    for (int i = 0; i < sizeof(dates)/sizeof(dates[0]); i++) {
        date.setDate(dates[i].year, dates[i].month, dates[i].day);
        cout << date.getDate() << endl;
        cout << date.getSeason() << endl;
    }

    return 0;
}
