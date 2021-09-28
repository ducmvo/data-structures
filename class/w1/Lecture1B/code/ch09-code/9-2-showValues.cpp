#include <iostream>
using namespace std;

void showValues(int [], int);

int main() 
{
	const int SIZE = 5;
	int numbers[] = {1, 2, 3, 4, 5};
   //cout << numbers << endl;

	// C++ automatically stores the address of 
	// numbers in the parameter values
	showValues(numbers, SIZE);
}
void showValues(int values[], int size) 
{
	for (int i = 0; i < size; i++)
	cout << values[i] << endl;
}
