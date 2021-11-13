#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>& bitStuffing(vector<int>& str)
{
    int input = 1;
    unsigned int count = 0;
    cout << "Enter 1 or 0, any other number to exit : ";
    while (input >= 0 && input <= 1)
    {
        cin >> input;
        if (input == 0 || input == 1)
        {
            str.push_back(input);
        }
        if (input == 1)
            count++;
        else
            count = 0;
        if (count >= 5)
        {
            count = 0;
            str.push_back(0);
        }
    }
    return str;
}
vector<int> bitUnstuffing(vector<int> str)
{
    unsigned int count = 0;
    for (unsigned int i = 0, count = 0; i < str.size(); ++i)
    {
        if (str[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        if (count >= 5)
        {
            count = 0;
            str.erase(str.begin() + (i+1));
        }
    }
    return str;
}
int main()
{
    vector<int> str;
    vector<int> stuffed;
    stuffed = bitStuffing(str);
    cout << "Stuffed : ";
    for (auto i : stuffed)
        cout << i;
    vector<int> unstuffed;
    cout << endl << "Unstuffed : ";
    unstuffed = bitUnstuffing(stuffed);
    for (auto i : unstuffed)
        cout << i;
}

