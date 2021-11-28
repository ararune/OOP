#include <iostream>
using namespace std;
// A program to return a reference to the input index and increment the return as lvalue
int& retref(int* arr, int i)
{
    return arr[i];
}

int main()
{
    cout << "Enter the size of the array : ";
    int n;  cin >> n;
    cout << "Enter " << n << " elements into the array : ";
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter index of the element : ";  int i;  cin >> i;

    cout << "\nValue after the index = " << ++retref(arr, i);

    delete[] arr;
}


