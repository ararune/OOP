#include <iostream>
using namespace std;
// function that returns reference to an array element, using return as lvalue increment the n-th element by 1
int &retref(int i, int *arr)
{
    return arr[i];
}

int main()
{
    int n, i;
    cout << "Enter the size of the array : ";
    cin >> n; 
    int* arr = new int[n]; 

    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];;
    }
    cout << "Enter i : ";
    cin >> i;

	int x = 5;

	cout << "++x: " << ++x;
	cout << "x++: " << x++;

    cout << "\ni + 1 = " << ++retref(i, arr);

}
