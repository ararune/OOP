#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// Push user input strings to a vector of string, reverse each string then sort vector in lexicographic order
using namespace std;

/* take string input (ctrl+z to end)
   reverse the strings
   sort them
   return vector of strings*/
void reverseAndSort(vector<string>& myString)
{
    string temp;
    cout << "Enter strings, Ctrl+z to end input : " << endl;
    while (getline(cin, temp))
    {
        reverse(temp.begin(), temp.end());
        myString.push_back(temp);
    }
    sort(myString.begin(), myString.end());

}

const void printVector(const vector<string>& myString)
{
    for (auto i : myString)
        cout << i << ' ' << endl;
}
//remove all elements from the vector and then reduce container capacity to fit its size.
void vectorObliterate(vector<string>& myVector)
{
    myVector.clear();  myVector.shrink_to_fit();
}
int main()
{
    vector<string> myString;
    reverseAndSort(myString);
    printVector(myString);
    vectorObliterate(myString);
}