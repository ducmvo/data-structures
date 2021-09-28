#include <iostream>
using namespace std;

int main()
{
  	double * dptr = nullptr;
   cout << dptr << endl;

  	dptr = new double;
  	*dptr = 12;
  	cout << "*dptr: " << *dptr << endl;  
   cout << dptr << endl;
   cout << &dptr << endl; 

	delete dptr;

  	int size;
   cout << "Enter size of array: ";
   cin >> size;
  	double * arrayPtr = new double[size];
 
	cout << "assign array...\n";
  	for(int i = 0; i < size; i++)
	 	*(arrayPtr + i) = i * i;
  
	cout << "print array...\n";
   for(int i = 0; i < size; i++) 
		cout << arrayPtr[i] << endl;

	delete [] arrayPtr;

}
