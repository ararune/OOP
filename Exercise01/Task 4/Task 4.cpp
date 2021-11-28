#include <iostream>
using namespace std;
// Return the min and max elements of an array using recursive method
int findMax(int* array, int n)
{
    return (n == 1) ?  array[0] : max(array[n - 1], findMax(array, n - 1));   
}
int findMin(int* array, int n)
{
    return (n == 1) ? array[0] : min(array[n - 1], findMin(array, n - 1));
}

int main()
{
    cout << "Enter the size of the array : ";
    int n;  cin >> n;
    cout << "Enter " << n << " elements into the array : ";
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int min = arr[0];   min = findMin(arr, n);
    int max = arr[0];   max = findMax(arr, n);

    cout << "Smallest element in the array =  " << min << endl;
    cout << "Largest element in the array = " << max << endl;
    delete[] arr;
}

