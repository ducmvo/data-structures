#include <iostream>
#include "LinkedList.cpp"
using namespace std;

int mystery(int n) {
    if (n < 10)
        return n;
    else {
        int a = n / 10;
        int b = n % 10;
        return mystery(a + b);
    }
}

int findMin(int arr[], int size, int min) {
    if (size <= 0) return min;
    if (min > arr[size - 1])
        min = arr[size - 1];
    return findMin(arr, size - 1, min);
}


int findMin(int arr[], int size) {
    int min = arr[size - 1];
    return findMin(arr, size - 1, min);
}

int search(int arr[], int size, int key) {
    if (size <= 0) return -1;
    if (arr[size - 1] == key) return size - 1;
    return search(arr, size - 1, key);
}

bool ordered(string str, int idx) {
    if(idx <= 0) return true;
    if (str[idx] < str[idx-1]) return false;
    return ordered(str, idx -1);
}

bool ordered(string str){
    return ordered(str, str.size() - 1);
}
int bs(int arr[], int key, int left, int right) {
    int mid = (left + right) / 2;
    if (left > right) return -1;
    if(arr[mid] == key) return mid;
    else if (key < arr[mid]) right = mid;
    else left = mid;
    return bs(arr, key, left, right);
}

int bs(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    return bs(arr, key, left, right);
}
int main() {
//    cout << mystery(648) << endl;
//    int arr[] = {-6, 0, 2, 4, 5, 6, 12, 18, 29};
//    int size = sizeof(arr) / sizeof (*arr);
//    cout << findMin(arr, size) << endl;
//    cout << bs(arr, 8, 12) << endl;
//    string str = "abdgwz";
//    cout << (ordered(str) ? "true" : "false") << endl;
//    cout << (11/2) << endl;

    LinkedList<int> ll;
    int arr[] = {1, 2, 3, 4, 5, 7, 8, 9, 12, 13};
    for (int num : arr) {
        ll.append(num);
    }
    int min, max;
    ll.getMinMax(min, max);
    cout << "MIN: " << min << endl;
    cout << "MAX: " << max << endl;

    LinkedList<double> dl;
    double arr2[] = {-3.2,  2.14,  -5.7, -12.01, -2.99, 4.6, 5.2};
    for (double num : arr2) {
        dl.append(num);
    }

    double d = dl.getLastNegative();
    cout.precision(2);
    cout << "LAST NEGATIVE NUMBER: " << fixed << d  << endl;
    cout << dl.to_string() << endl;
    dl.deleteNode(2.99);
    cout << dl.to_string() << endl;
    dl.insert(11.2321);
    cout << dl.to_string() << endl;

}




/**
m(648)
  a = 64
  b = 8
  return m(72)
      a = 7
      b = 2
      return m(9)
          return 9

            5
        /       \
       3          8
    /    \      /   \
   1      4    7    12
    \               /  \
     2            9    13
     5, 3, 1, 2, 4, 8, 7,  12, 9,  13
PRE: 5  3  1  2  4  8  7   12  9   13

     1, 2, 3, 4, 5, 7, 8,  9,  12, 13
IN:  1  2  3  4  5  7  8   9   12  13

     2, 1, 4, 3, 7, 9, 13, 12, 8,  5
PST: 2  1  4  3  7  9  13  12  8   5

*/