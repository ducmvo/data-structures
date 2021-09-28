#include <iostream>
using namespace std;

int main()
{
   int num = 25;
	int * intptr;
   intptr = &num;
   cout << "num: " << num << endl;
   cout << "*intptr: " << *intptr << endl;

   cout << "&num: " << &num << endl;
   cout << "intptr: " << intptr << endl;

	cout << "&intptr: " << &intptr << endl;
}
