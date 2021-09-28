#include <iostream> 
using namespace std;

int main()
{
  	int num = 5, * numptr = &num;
	cout << *numptr << endl;

	const int SIZE = 3;
  	int vals[] = {1, 2, 3};
   int  * valptr = vals;
	for (int i = 0; i < SIZE; i++)
		cout << valptr[i] << endl;

  	double cost;
  	double * costs = &cost;
  	if (costs)
		cout << "valid address\n";
   else
		cout << "invalid address\n";

}
