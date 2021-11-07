#include "Sort.h"
#include <random>
#include <algorithm>
#include <vector>
#include <time.h>
#include <iostream>
#include <iomanip>
using namespace std;

int countDigit(int);
vector<int> createVector(int);
void runSort(vector<int> &, int);

int main() {
    const int MIN = 40000;
    const int MAX = MIN * pow(2,9);

    for (int i = 0; i < 3; i++) {
        cout << "\n=================================="
        << "=====================================\n";
        cout <<  "RUN TRIAL "<< i + 1  << endl;
        vector<int> randVector;

        for (int i = 0; i <= countDigit(MAX); i++)
            cout << " ";
        cout << "    MERGE  ";
        cout << "    HEAP   ";
        cout << "    QUICK  ";
        cout << "    INTRO  ";
        cout << "  INSERTION  " << endl;
        for (int n = MIN; n <= MAX; n = n * 2) {
            randVector = createVector(n);
            for (int i = 0; i < countDigit(MAX) - countDigit(n) ; i++)
                cout << " ";
            cout << n << " | ";
            runSort(randVector, n);
        }
    }
    return 0;
}

int countDigit(int number) {
    int count = 0;
    while(number != 0) {
        number = number / 10;
        count++;
    }
    return count;
}

vector<int> createVector(int n) {
    random_device rnd_device;
    mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    uniform_int_distribution<int> dist {1, n};

    auto gen = [&dist, &mersenne_engine](){
        return dist(mersenne_engine);
    };

    vector<int> vec(n);
    generate(begin(vec), end(vec), gen);
    return vec;
}

void runSort(vector<int> &vec, int n) {
    vector<int> copyVec;
    clock_t t;

    copyVec = vec;
    t = clock();
    mergesort(copyVec.begin(), copyVec.end());
    t = clock() - t;
    cout << fixed << setprecision(6)<< ((float)t)/CLOCKS_PER_SEC << " | ";

    copyVec = vec;
    t = clock();
    heapsort(copyVec.begin(), copyVec.end());
    t = clock() - t;
    cout << ((float)t)/CLOCKS_PER_SEC << " | ";

    copyVec = vec;
    t = clock();
    quicksort(copyVec.begin(), copyVec.end());
    t = clock() - t;
    cout << ((float)t)/CLOCKS_PER_SEC << " | ";

    copyVec = vec;
    t = clock();
    sort(copyVec.begin(), copyVec.end());
    t = clock() - t;
    cout << ((float)t)/CLOCKS_PER_SEC << " | ";

    if (n <= 640000) {
        copyVec = vec;
        t = clock();
        insertionSort(copyVec.begin(), copyVec.end());
        t = clock() - t;
        cout << ((float) t) / CLOCKS_PER_SEC;
    }
    cout << endl;
}

