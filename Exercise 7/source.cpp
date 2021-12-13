#include <iostream>
#include "board.h"
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main() {
    Point p1(2, 2), p2(8, 8), p3(2, 8), p4(16, 8);

    Board b(20, 10);

    b.drawLine(p1, p2, 'x');
    b.drawLine(p3, p4, 'x');
    b.display();
}