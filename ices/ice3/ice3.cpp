// ice3.cpp
// assume n >= 1

/**
 * @authors Duc Vo, Jou Ho,
 */

#include <iostream>
using namespace std;

int sumI(int);
int sumR(int);
int sumI(int, int);
int sumR(int, int);
int findMinI(int [], int);
int findMinR(int [], int);
int findSumI(int [], int);
int findSumR(int [], int);

int main() {
    const int SIZE = 4;
    int arr[] = {2, 4, 1, 5};
    cout << "array contents: ";
    for (int i : arr)
        cout << i << " ";
    cout << "\narray size: " << SIZE << endl;

    cout << "\niterative tests:\n";
    cout << "sum(5) = " << sumI(5) << endl;
    cout << "sum(5, 7) = " << sumI(5, 7) << endl;
    cout << "findMin(a, 4) = " << findMinI(arr, SIZE) << endl;
    cout << "findSum(a, 4) = " << findSumI(arr, SIZE) << endl;

    cout << "\nrecursive tests:\n";
    cout << "sum(5) = " << sumR(5) << endl;
    cout << "sum(5, 7) = " << sumR(5, 7) << endl;
    cout << "sum(7, 5) = " << sumR(7, 5) << endl;;
    cout << "findMin(a, 4) = " << findMinR(arr, SIZE) << endl;
    cout << "findSum(a, 4) = " << findSumR(arr, SIZE) << endl;
}

int sumI(int n) {
    int sum = 1;
    for (int i = 2; i <= n; i++)
        sum += i;
    return sum;
}

int sumR(int n) {
    if (n == 0) return n;
    return n + sumR(n-1);
}

int sumI(int a, int b) {
    int sum = a;
    for (int i = a + 1; i <= b; i++)
        sum += i;
    return sum;
}

int sumR(int a, int b) {
    if ((a - b) == 0) return a;
    return a<b ? a + sumR(a + 1, b): b + sumR(b + 1 , a);
}

int findMinI(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int findMinR(int arr[], int n) {
    if (n == 1) return arr[n];
    return min(arr[n-1], findMinR(arr, n - 1));
}

int findSumI(int arr[], int n) {

    int sum = arr[0];
    for (int i = 1; i < n; i++)
        sum += arr[i];
    return sum;
}

int findSumR(int arr[], int n) {
    if  (n == 0) return 0;
    return arr[n-1] + findSumR(arr, n - 1);
}