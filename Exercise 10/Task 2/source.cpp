#include "Templates.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main()
{
    Stack<int> myStack;

    myStack.push(2);
    myStack.push(5);

    cout << myStack.pop() << " is removed from stack"
        << endl;
    cout << myStack.pop() << " is removed from stack"
        << endl;

    myStack.isEmpty() ? cout << "It's empty" : cout << "It's not empty";
}
