#include <iostream>
#include <algorithm>
#include "TemplatesSort.h"
using std::cout;
using std::cin;
using std::endl;


int main()
{
    int intarray[] = { 3, 1, 5, 2, 0, 8, 6, 9, 4, 7 };
    size_t intsize = sizeof(intarray) / sizeof(intarray[0]);
    double darray[] = { 3.2, 1.7, 5.4, 2.6, 8.5, 6.4, 9.1, 4.4, 7.8 };
    size_t dsize = sizeof(darray) / sizeof(darray[0]);
    char charray[] = "CaBAbc";
    size_t chsize = sizeof(charray) / sizeof(charray[0]);

    mySort(intarray, intsize);
    for (auto& i : intarray)
        cout << i << " ";
    cout << "\n";

    mySort(darray, dsize);
    for (auto& i : darray)
        cout << i << " ";
    cout << "\n";

    mySort(charray, chsize);
    for (auto& i : charray)
        cout << i << " ";
}