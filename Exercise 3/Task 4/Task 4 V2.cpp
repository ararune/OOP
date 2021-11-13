#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Remove all instances of element from vector if the order doesnt matter

vector<int>& vectorPushBack(vector<int>& myVector, int n)
{
    cout << "Enter " << n << " integers : ";
    int input;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        myVector.push_back(input);
    }
    return myVector;
}
const void vectorPrint(const vector<int>& myVector)
{
    for (auto i : myVector)
        cout << i << ' ';
}
void vectorRemoveElement(vector<int>& myVector, int target)
{
    const auto oldSize = myVector.size();                                              
    for (auto it = myVector.begin(); it != myVector.end(); ) {
        if (*it == target) {
            *it = move(myVector.back());                //  move() is a cast that produces an rvalue-reference 
            myVector.pop_back();                        //  to an object, to enable moving from it.
        }
        else {
            ++it;
        }
    }
    const auto deleted = myVector.size();
    if (oldSize == deleted)
        cout << "\nNo such element was found in the vector!\n";
}
//remove all elements from the vector and then reduce container capacity to fit its size.
void vectorEmpty(vector<int>& myVector)
{
    myVector.clear();  myVector.shrink_to_fit();
}

int main()
{
    vector<int> myVector;
    cout << "Enter number of elements of the vector: ";
    int n;
    cin >> n;
    vectorPushBack(myVector, n);
    vectorPrint(myVector);
    int target;
    cout << "\nEnter target element to remove : ";
    cin >> target;
    vectorRemoveElement(myVector, target);
    vectorPrint(myVector);

    vectorEmpty(myVector);

}

