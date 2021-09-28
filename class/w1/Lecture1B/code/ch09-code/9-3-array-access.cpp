#include <iostream>
using namespace std;

int main()
{
   //const int SIZE = 3;
  	int vals[] = {4, 7, 11};
	cout << "address of array: " << vals << endl; 	
	// displays address of array

   cout << "display using array notation:\n";
	cout << &vals[0] << endl; 	// displays 4
	cout << &vals[1] << endl;	// displays 7
	cout << &vals[2] << endl;	// displays 11
/*
   cout << "display using loop (and array notation):\n";
   for (int i = 0; i < SIZE; i++)
		cout << vals[i] << endl;

	cout << "display using indirection operator:\n";
	cout << *(vals + 0) << endl; 	// displays 4
   cout << *(vals + 1) << endl;	// displays 7
	cout << *(vals + 2) << endl;	// displays 11

   cout << "display using loop (and indirection operator):\n";
	for (int i = 0; i < SIZE; i++)   
		cout << *(vals + i) << endl;
*/
}










