#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
// Using STL find the number of occurences of a substring within a given string
unsigned int countOccurences(const string& substr, const string& str)
{
    unsigned int occurrences = 0;
    unsigned int sublen = substr.length();                       //string::size_type  is a type big enough to represent 
    string::size_type pos = 0;                                  //the size of a string, no matter how big that string is.
    while ((pos = str.find(substr, pos)) != string::npos) {     // string::npos means "until the end of the string".
        ++occurrences;
        pos += sublen;                                          
    }
    return occurrences;
}
void stringObliterate(string& myString)
{
    myString.clear();  myString.shrink_to_fit();
}
int main()
{
    string str;
    cout << "Enter string : ";
    getline(cin, str); // function to read a line of text
    string substr;
    cout << "\nEnter substring : ";
    getline(cin, substr);
    cout << "\nSubstring ocurences : " << countOccurences(substr, str) << endl;

    stringObliterate(str);
    stringObliterate(substr);

}