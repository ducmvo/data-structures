// overloaded functions (input, swap, print)
#include <iostream>
#include <string>
using namespace std;

void input(double &, double &);
void input(double *, double *); // get user input using pointers
void swap(double &, double &);
void swap(string &, string &);
void swap(double *, double *);  // swap doubles using pointers
void print(double, double);
void print(string, string);

int main() {
    double x, y;
    string s1 = "hello", s2 = "goodbye";

    // get user input
    input(x, y);

    // test swap of doubles - pass by ref
    cout << "swap doubles by ref\n";
    print(x, y);
    swap(x, y);
    print(x, y);

    // test swap of strings - pass by ref
    cout << "\nswap strings by ref\n";
    print(s1, s2);
    swap(s1, s2);
    print(s1, s2);

    // get user input
    cout << endl;
    input(&x, &y);

    // test swap of doubles - using pointers
    cout << "swap doubles using pointers\n";
    print(x, y);
    swap(&x, &y);
    print(x, y);
}

void input(double &x, double &y) {
    cout << "Enter two doubles, separated by a space: ";
    cin >> x >> y;
}

void input(double *ptr1, double *ptr2) {
    cout << "Enter two doubles, separated by a space: ";
    cin >> *ptr1 >> *ptr2;
}

void swap(double &x, double &y) {
    double temp = x;
    x = y;
    y = temp;
}

void swap(string &str1, string &str2) {
    string temp = str1;
    str1 = str2;
    str2 = temp;
}

void swap(double *ptr1, double *ptr2) {
    double temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void print(double x, double y) {
    cout << "x: " << x << ", y: " << y << endl;
}

void print(string str1, string str2) {
    cout << "string 1: " << str1 << ", string 2: " << str2 << endl;
}
