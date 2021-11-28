#include <iostream>
using namespace std;
// Methods to find the min and max value of an array using reference
void findMax(int* arr, int n, int& maxref)
{
    for (int i = 0; i < n; i++)
        if (arr[i] > maxref)
            maxref = arr[i];
}
void findMin(int* arr, int n, int& minref)
{
    for (int i = 0; i < n; i++)
        if (arr[i] < minref)
            minref = arr[i];
}
int main()
{
    cout << "Enter the size of the array : ";
    int n;  cin >> n;
    cout << "Enter " << n << " elements into the array : ";
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int max = arr[0];   int& maxref = max;
    int min = arr[0];   int& minref = min;

    findMax(arr, n, maxref);    findMin(arr, n, minref);

    cout << "Smallest element in the array =  " << min << endl;
    cout << "Largest element in the array = " << max << endl;
    delete[] arr;
}

