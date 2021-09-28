#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <ctime>
using namespace std;

int * getRandomNums(int);

int main()
{
  int num;
  cout << "We will generate random numbers between 1-100\n";
  cout << "How many random numbers do you want? ";
  cin >> num;
  
  int * nums = getRandomNums(num);
  if (num)
  {
	 for (int i = 0; i < num; i++)
	   cout << nums[i] << endl;
    delete [] nums;
  }
  else
    cout << "You entered an invalid number\n";
}

int * getRandomNums(int num)
{
  int * arr = nullptr;
  if (num > 0)
  {
    arr = new int[num];
    srand(time(0));
    for (int i = 0; i < num; i++)
		arr[i] = rand() % 100 + 1;
  }
  return arr;
}
