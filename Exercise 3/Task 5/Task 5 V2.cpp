#include <string>
#include <iostream>
using namespace std;

unsigned int countFreq(const string& substr, const string& str)
{
    int M = str.length();
    int N = substr.length();
    int count = 0;

    /* A loop to traverse substr*/
    for (int i = 0; i <= M - N; ++i)
    {
        /* For current index i, check for
           substr match */
        int j;
        for (j = 0; j < N; ++j)
            if (str[i + j] != substr[j])
                break;

        // if substr[0...N-1] = str[i, i+1, ...i+N-1]
        if (j == N)
        {
            ++count;
            j = 0;
        }
    }
    return count;
}

int main()
{
    string str;
    cout << "Enter string : ";
    getline(cin, str); // function to read a line of text
    string substr;
    cout << "Enter substring : ";
    getline(cin, substr);
    cout << countFreq(substr, str);
}