#include <iostream>
using namespace std;

// A program to find the smallest and largest element of an array using recursive method
int findMax(int arr[], int index, int n)
{
    int max;
    if (index >= n - 2)
        return (arr[index] > arr[index + 1]) ? arr[index] : arr[index + 1];
    max = findMax(arr, index + 1, n);

    return (arr[index] > max) ? arr[index] : max;
}


int findMin(int arr[], int index, int n)
{
    int min;

    if (index >= n - 2)
        return (arr[index] < arr[index + 1]) ? arr[index] : arr[index + 1];
    min = findMin(arr, index + 1, n);

    return (arr[index] < min) ? arr[index] : min;
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n; // Unesi broj elemenata niza
    int* arr = new int[n](); //dinamicka alokacija niza
    int min = arr[0];
    int max = arr[0];
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    max = findMax(arr, 0, n);
    min = findMin(arr, 0, n);

    cout << "Smallest element in the array =  " << min << endl;
    cout << "Largest element in the array = " << max << endl;
    delete[] arr;

}