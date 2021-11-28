#include <iostream>
using namespace std;
// A function that returns min and max value of a dynamically allocated array using iterative method
struct Pair
{
    int min;
    int max;
};

struct Pair findMinMax(int* arr,int n) {
    struct Pair minmax;
    minmax.max = arr[0], minmax.min = arr[0];
    for (int i = 1; i < n; i++) {
        if (minmax.max < arr[i])
            minmax.max = arr[i];
        if (minmax.min > arr[i])
            minmax.min = arr[i];
  }
    return minmax;

}
int main()
{
    cout << "Enter the size of the array : ";
    int n;  cin >> n;
    cout << "Enter " << n << " elements into the array : ";
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Pair minmax = findMinMax(arr, n);

    cout << "Minimum element is "
        << minmax.min << endl;
    cout << "Maximum element is "
        << minmax.max;
    delete[] arr;
}

