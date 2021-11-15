#include <iostream>
using namespace std;
// A program to find the smallest and largest elements in an array using iterative method
void findMinMax(int arr[], int n, int* max, int* min)
{
    *max = arr[0], * min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (*max < arr[i])
            *max = arr[i];
        if (*min > arr[i])
            *min = arr[i];
    }

}
int main()
{
    int n, max, min;
    cout << "Enter the size of the array : ";
    cin >> n; // n je broj elemenata niza
    int* arr = new int[n](); //dinamicka alokacija niza
    cout << "Enter the elements of the array : ";

    for (int i = 0; i < n; i++) //petlja za unosenje elemenata niza od korisnika
        cin >> arr[i];

    findMinMax(arr, n, &max, &min);
    cout << "Largest element in the array  = " << max << "\n";
    cout << "Smallest element in the array = " << min;
    delete[] arr;
}