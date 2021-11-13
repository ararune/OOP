#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <vector>
using namespace std;

class MyVector {
    vector<int> v;
public:
    void vectorPushBack(MyVector& myVector1, int n);  // adds an integer at the end of the vector
    void vectorRangePushBack(MyVector& myVector2, int lowLimit, int highLimit); // adds an integer in a range at the end of the vector
    const void vectorPrint(MyVector& myVector);
    void vectorObliterate(MyVector& myVector);

};


#endif
