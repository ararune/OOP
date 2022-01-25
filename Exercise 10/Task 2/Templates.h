#pragma once
#include <iostream>
#define N 10


template <class T> class Stack {
    T* stack;
    int top;

public:
    Stack();
    ~Stack();
    void push(T element);
    T pop();
    bool isEmpty();

};
template <class T> Stack<T>::Stack() 
{ 
    stack = new T[N];
    top = -1;
}
template <class T> Stack<T>::~Stack()
{
    delete[] stack;
}
template <class T> void Stack<T>::push(T element)
{
    // TO DO : isFull method
    std::cout << "Pushed element : " << element << std::endl;
    top++;
    stack[top] = element;
}

template <class T> bool Stack<T>::isEmpty()
{
    return true ? (top == -1) : false;
}
template <class T> T Stack<T>::pop()
{
    T poppedElement = stack[top];
    top--;
    return poppedElement;
}


