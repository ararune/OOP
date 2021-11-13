#include "MyVector.h"
#include <iostream>
#include <vector>
/* program for vector input and print, first function's parameters are reference to the vector and the number of elements
the second function takes integers in an interval specified in function parameters and takes input until input is outside of interval*/
using namespace std;

int main()
{
    // push n integers to vector test
    int n;
    cout << "Enter n : ";
    cin >> n;
    MyVector myVector1, myVector2;
    myVector1.vectorPushBack(myVector1, n);
    myVector1.vectorPrint(myVector1);

    // push integers to vector while within parameters test
    int lowLimit, highLimit;
    cout << "\nEnter lower limit : ";
    cin >> lowLimit;
    cout << "\nEnter upper limit: ";
    cin >> highLimit;
    myVector2.vectorRangePushBack(myVector2, lowLimit, highLimit);
    myVector2.vectorPrint(myVector2);

    // erasing vectors
    myVector1.vectorObliterate(myVector1);
    myVector2.vectorObliterate(myVector2);


}