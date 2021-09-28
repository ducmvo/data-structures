#include <iostream>
using namespace std;

int main()
{
   const int SIZE = 3;
  	int vals[SIZE];
	cout << "address of array: " << vals << endl; 	// displays address of array

	cout << "assign array using array notation:\n";
	for (int i = 0; i < SIZE; i++) 
	{
		cout << "Enter an integer: ";
		cin >> vals[i];
	}

   cout << "display array using array notation:\n";
   for (int i = 0; i < SIZE; i++)
		cout << vals[i] << endl;

	cout << "assign array using indirection operator:\n"; 
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Enter an integer: ";
		cin >> *(vals + i);
	}

   cout << "display array using indirection operator:\n";
	for (int i = 0; i < SIZE; i++)   
		cout << *(vals + i) << endl;
}
