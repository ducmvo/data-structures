#include <iostream>
#include "Date.h"
using namespace std;

struct SDate {
    int month;
    int day;
    int year;
};

int main() {
    SDate dates[8] = {
        {1, 01, 2012},
        {3, 10, 1996},
        {6, 20, 2015},
        {9, 22, 2000},
        {12, 25, 1980},
        {11, 22, 2001},
        {10, 31, 2017},
        {9, 23, 2011}
    };
    Date date;
    for (int i = 0; i < 8; i++)
    {
        date.setDate(dates[i].year, dates[i].month, dates[i].day);
        cout << date.getDate() << " - " << date.getSeason() << endl;
    }
    return 0;
}
