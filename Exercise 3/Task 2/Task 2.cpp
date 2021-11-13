#include <iostream>
#include <vector>

using namespace std;
// a program to find vector set difference using functions from the previous task
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
/* function to push elements to a vector until input is outside of range parameters */
void vectorRangePushBack(vector<int>& myVector2, const int lowLimit, const int highLimit)
{
    cout << "\nEnter integers in range of " << lowLimit << " and " << highLimit << " :";
    int input = lowLimit;
    while (input >= lowLimit && input <= highLimit)
    {
        cin >> input;
        if (input >= lowLimit && input <= highLimit)
        {
            myVector2.push_back(input);
        }

    }
    cout << "Input outside of range parameters, loop ended" << endl;
}
/* function to find vector set difference and push to third vector*/
void vectorSetDifference(const vector<int>& myVector1, const vector<int>& myVector2, vector<int>& myVector3)
{
    const int vSize1 = myVector1.size();
    const int vSize2 = myVector2.size();
    for (int i = 0; i < vSize1; ++i)
    {
        bool flag = false;
        for (int j = 0; j < vSize2; ++j)
        {
            if (myVector1[i] == myVector2[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            myVector3.push_back(myVector1[i]);

    }

}

const void vectorPrint(const vector<int>& myVector)
{
    for (auto i : myVector)
        cout << i << ' ';
}
//remove all elements from the vector and then reduce container capacity to fit its size.
void vectorEmpty(vector<int>& myVector)
{
    myVector.clear();  myVector.shrink_to_fit();
}

int main()
{
    vector<int> myVector1, myVector2, myVector3;
    // vector with n elements test
    cout << "Enter number of elements of the first vector: ";
    int n;
    cin >> n;
    vectorPushBack(myVector1, n);

    // vector in range test
    int lowLimit, highLimit;
    cout << "\nEnter lower limit : ";
    cin >> lowLimit;
    cout << "\nEnter upper limit: ";
    cin >> highLimit;
    vectorRangePushBack(myVector2, lowLimit, highLimit);


    // vector set difference test
    vectorSetDifference(myVector1, myVector2, myVector3);
    cout << "\nVector set difference : ";
    vectorPrint(myVector3);

    // clear vectors
    vectorEmpty(myVector1);
    vectorEmpty(myVector2);
    vectorEmpty(myVector3);
}