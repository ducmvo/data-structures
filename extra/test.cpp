#include <iostream>
using namespace std;
int *multiply(int a, int b, int *c)
{
    *c = a * b;
    return c;
}

void print(string *e)
{
    cout << "VALUE: = " << *e << endl;
    cout << "ADDRESS: = " << e << endl;
}
int main()
{
    int *ptr = new int;
    *ptr = 8;
    // print (ptr);
    delete ptr;
    *ptr = 9; 
    // print(ptr);
    // cout << value << endl;
    const int SIZE = 3;
    string* members = new string[SIZE];
    int numbers[SIZE][SIZE] = {{1,2},{3,4,5},{6,7,8}}; 
    
    print(members);
    print(&members[0]);
    print(&members[1]);
    print(&members[2]);

}
