#include <iostream>
using namespace std;
int *multiply(int a, int b, int *c)
{
    *c = a * b;
    return c;
}

void print(int *e)
{
    cout << "VALUE: = " << *e << endl;
    cout << "ADDRESS: = " << e << endl;
}
int main()
{
    int *ptr = new int;
    *ptr = 8;
    print (ptr);
    delete ptr;
    *ptr = 9; 
    print(ptr);
    // cout << value << endl;
}
