#include <iostream>
using namespace std;
// A program to find the smallest and largest number in an array of n integers, the functions returns these by reference
void findMax(int* arr, int n, int& maxref)
{
    for(int i = 0; i < n; i++)
        if (arr[i] > maxref)
            maxref = arr[i];
}

void findMin(int* arr, int n, int& minref)
{
    for(int i = 0; i < n; i++)
        if (arr[i] < minref)
            minref = arr[i];
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n; 
    int* arr = new int[n]; 
    cout << "Enter the elements of the array : ";

    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    int max = arr[0];
    int &maxref = max;
    int min = arr[0];
    int &minref = min;

    findMax(arr,n,maxref);
    findMin(arr,n,minref);

    cout << "The lowest value : " << minref << endl;
    cout << "The highest value : " << maxref << endl;
    delete[] arr;
}