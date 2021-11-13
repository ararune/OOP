#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
// A program to sort vector using STL functions, insert O before lowest element and insert sum of all elements after final element
/* function to push n elements to a vector*/
void vectorPushBack(vector<int>& myVector1, const int n)
{
    cout << "Enter " << n << " integers : ";
    int input;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        myVector1.push_back(input);
    }
}
const void vectorPrint(const vector<int>& myVector)
{
    for (auto i : myVector)
        cout << i << ' ';
}
int main()
{
    vector<int> myVector;
    //VECTOR INPUT
    cout << "Enter number of elements of the first vector: ";
    int n;
    cin >> n;
    vectorPushBack(myVector, n);
    // VECTOR SORT

    sort(myVector.begin(), myVector.end());
    cout << "Sorted vector : " << endl;
    vectorPrint(myVector);
    // VECTOR INSERT  0

    myVector.insert(myVector.begin(), 0);
    cout << "\nVector 0 inserted : " << endl;
    vectorPrint(myVector);

    // VECTOR INSERT SUM
    myVector.insert(myVector.end(), accumulate(myVector.begin(), myVector.end(), 0));
    cout << "\nSorted vector with 0 and sum : " << endl;
    vectorPrint(myVector);

}

