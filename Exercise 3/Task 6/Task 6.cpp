#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// Push user input strings to a vector of string, reverse each string then sort vector in lexicographic order

/* take string input (ctrl+z to end)
   reverse the strings
   sort them */
void reverseAndSort(std::vector<std::string>& myString)
{
    std::string temp;
    std::cout << "Enter strings, Ctrl+z to end input : " << std::endl;
    while (std::getline(std::cin, temp))
    {
        reverse(temp.begin(), temp.end());
        myString.push_back(temp);
    }
    sort(myString.begin(), myString.end());

}

const void printVector(const std::vector < std::string > & myString)
{
    for (auto& i : myString)
        std::cout << i << ' ' << std::endl;
}
int main()
{
    std::vector<std::string> myString;
    reverseAndSort(myString);
    printVector(myString);
}
