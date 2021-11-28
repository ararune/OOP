#include <iostream>
using namespace std;
// a program for standalone custom vector operations
struct MyVector {
    int* arr;
    int logicalSize = 0;  // represents the number of utilized memory locations
    int physicalSize; // represents the allocated memory

    void vectorNew(int n) {
        arr = new int[n];
        physicalSize = n;
    }

    void vectorDelete() {
        delete[] arr;
    }
    const void printVector(MyVector main_arr)
    {
        cout << "Vector elements :  ";
        for (int i = 0; i < main_arr.logicalSize; i++) {
            cout << main_arr.arr[i] << " ";
        }
    }
    /* adds a new element at the end of the vector */
    void vectorPushBack(int x) {
        if (logicalSize == physicalSize) {
            vectorRealloc(physicalSize * 2);
        }
        arr[logicalSize] = x;
        logicalSize++;
    }
    /* removes the last element in the vector */
    void vectorPopBack() {
        if (logicalSize != 0) {
            logicalSize--;
        }
    }
    /* returns a reference to the first element in the vector*/
    const int& vectorFront() {
        int& ref = arr[0];
        return ref;
    }
    /* returns a reference to the last element in the vector */
    const int& vectorBack() {
        int& ref = arr[logicalSize - 1];
        return ref;
    }
    /* returns the number of the elements in the vector */
    const int vectorSize() {
        return logicalSize;
    }
    /* reallocates memory for modified vector*/
private:
    void vectorRealloc(int n) {
        int* newArr = new int[n];
        physicalSize = n;
        for (int i = 0; i < logicalSize; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
};

int main() {
    MyVector main_arr;

    main_arr.vectorNew(3);

    int m;
    cout << "Enter integer, Ctrl+d (linux) or Ctrl+z (win) to end input : " << endl;
    while (cin >> m)
        main_arr.vectorPushBack(m);

    main_arr.printVector(main_arr);

    cout << endl << "Next empty index :  " << main_arr.logicalSize << endl;
    cout << endl << "First element of the vector : " << main_arr.vectorFront() << endl;
    cout << endl << "Last element of the vector : " << main_arr.vectorBack() << endl;

    cout << endl << "Removing last element of the vector" << endl;
    main_arr.vectorPopBack();
    main_arr.printVector(main_arr);
    cout << endl << "\nLogical size of the vector : " << main_arr.vectorSize() << endl;
    cout << endl << "Physical size of the vector :  " << main_arr.physicalSize << endl;

    cout << endl << endl;

    main_arr.vectorDelete();
}
