#include <iostream>
#include <vector>
#include <algorithm>
// Bit stuffing & unstuffing using vector push and erase method

std::vector<int>& bitStuffing(std::vector<int>& str)
{
    int input = 1;
    unsigned int count = 0;
    std::cout << "Enter 1s or 0s, any other number to exit : ";
    while (input >= 0 && input <= 1)
    {
        std::cin >> input;
        if (input == 0 || input == 1) 
            str.push_back(input);

        (input == 1) ? count++ : count = 0;
        
        if (count >= 5)
        {
            count = 0;
            str.push_back(0);
        }
    }
    return str;
}
std::vector<int>& bitUnstuffing(std::vector<int>& str)
{
    unsigned int count = 0;
    for (unsigned int i = 0, count = 0; i < str.size(); ++i)
    {
        (str[i] == 1) ? count++ : count = 0;
        if (count >= 5)
        {
            count = 0;
            str.erase(str.begin() + (i + 1));
        }
    }
    return str;
}
int main()
{
    std::vector<int> str;
    std::vector<int> stuffed;
    stuffed = bitStuffing(str);
    std::cout << "Stuffed : ";
    for (auto const& i : stuffed)
        std::cout << i;
    std::vector<int> unstuffed;
    std::cout << std::endl << "Unstuffed : ";
    unstuffed = bitUnstuffing(stuffed);
    for (auto const& i : unstuffed)
        std::cout << i;
}

