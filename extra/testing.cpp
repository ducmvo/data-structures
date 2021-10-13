
#include <iostream>
using namespace std;
void mistery(int n)
{
    if (n <= 1)
        cout << "_";
    else
    {
        cout << n % 2 << "_";
        mistery(n / 2);
        cout << n << "_";
    }
}
int main()
{
    mistery(25);
    // 1 0 0 1 1 3 6 12 25
}
