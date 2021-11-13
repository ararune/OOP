#include "MyVector.h"
#include <iostream>
#include <vector>

using namespace std;

void MyVector::vectorPushBack(MyVector& myVector1, int n)
{
    cout << "Enter " << n << " integers : ";
    int input;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        myVector1.v.push_back(input);
    }
}


void MyVector::vectorRangePushBack(MyVector& myVector2, int lowLimit, int highLimit)
{
    cout << "\nEnter integers in range of " << lowLimit << " and " << highLimit << " :";
    int input = lowLimit;
    while (input >= lowLimit && input <= highLimit)
    {
        cin >> input;
        if (input >= lowLimit && input <= highLimit)
        {
            myVector2.v.push_back(input);
        }

    }
    cout << "Input outside of range parameters, loop ended" << endl;
}
const void MyVector::vectorPrint(MyVector& myVector)
{
    for (auto i : myVector.v)
        cout << i << ' ';
}
void MyVector::vectorObliterate(MyVector& myVector)
{
    myVector.v.clear();  myVector.v.shrink_to_fit();
}