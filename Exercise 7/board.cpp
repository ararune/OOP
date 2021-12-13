#include <iostream>
#include "board.h"
#include <math.h>

Board::Board()
{
    board = new char* [row];

    for (int i = 0; i < row; i++)
        board[i] = new char[column];
    Border();
}
Board::Board(int a, int b)
{
    row = b;
    column = a;

    board = new char* [row];
    for (int i = 0; i < row; i++)
    {
        board[i] = new char[column];
    }

    Border();
}
Board::Board(const Board& b)
{
    row = b.row;
    column = b.column;
    board = new char* [row];
    for (int i = 0; i < row; i++)
        board[i] = new char[column];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            board[i][j] = b.board[i][j];
}
void Board::Border()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            (i == 0 || i == row - 1 || j == 0 || j == column - 1) ? board[i][j] = 'o' : board[i][j] = ' ';
        }
    }
}

void Board::display()
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
Board::~Board()
{
    for (int i = 0; i < row; i++)
        delete[] board[i];

    row = 0;
    column = 0;
    delete[] board;
    std::cout << "Matrix destructor called" << std::endl;
}

void Board::drawChar(int x, int y, char ch)
{
    if (x >= (double)row - 1 || y >= (double)column - 1)
    {
        return;
    }
    board[x][y] = ch;
}
void Board::drawLineUp(Point& p0, Point& p1, char ch)
{
    roundDouble(p0.x); roundDouble(p0.y);  roundDouble(p1.x);  roundDouble(p1.y);                               //round points to nearest integer

    (abs(p1.y - p0.y) < abs(p1.x - p0.x))                                                                       // if y-diff < x-diff
        ? (p1.x < p0.x) ? plotLineLow(p1.x, p1.y, p0.x, p0.y, ch) : plotLineLow(p0.x, p0.y, p1.x, p1.y, ch)     // if x1 < x0 plot x-axis, else plot inverse x-axis
        : (p1.y < p0.y) ? plotLineHigh(p1.x, p1.y, p0.x, p0.y, ch) : plotLineHigh(p0.x, p0.y, p1.x, p1.y, ch);  // else if y1 < y0 plot y-axis, else plot inverse y-axis

}

void Board::drawLine(Point& p0, Point& p1, char ch)
{
    roundDouble(p0.x); roundDouble(p0.y); roundDouble(p1.x); roundDouble(p1.y);                                   //round points to nearest integer

    (abs(p1.y - p0.y) < abs(p1.x - p0.x))                                                                        // if diff y < diff x
        ? (p1.x < p0.x) ? plotLineLow(p1.x, p1.y, p0.x, p0.y, ch) : plotLineLow(p0.x, p0.y, p1.x, p1.y, ch)     // x-axis
        : (p1.y < p0.y) ? plotLineHigh(p1.x, p1.y, p0.x, p0.y, ch) : plotLineHigh(p0.x, p0.y, p1.x, p1.y, ch);  // y-axis

}

// Bresenham line algorithm
void Board::plotLineHigh(int x0, int y0, int x1, int y1, char ch)       // plot y-axis
{
    int xDiff = abs(x1 - x0);
    int yDiff = abs(y1 - y0);
    int xi = 1;                 // x-inverse
    if (xDiff < 0)
    {
        xi = -1;
        xDiff *= -1;
    }
    int diff = (2 * xDiff) - yDiff;
    int x = x0;

    for (int y = y0; y < y1; ++y)       // go from y0 to y1 and plot, if difference > 0 then inverse x
    {
        drawChar(x, y, ch);
        if (diff > 0)
        {
            x += xi;
            diff = diff + (2 * (xDiff - yDiff));
        }
        else
            diff = diff + (2 * xDiff);
    }
}

void Board::plotLineLow(int x0, int y0, int x1, int y1, char ch)    // plot x-axis
{
    int xDiff = abs(x1 - x0);
    int yDiff = abs(y1 - y0);
    int yi = 1;                 // y-inverse
    if (yDiff < 0)
    {
        yi = -1;
        yDiff *= -1;
    }
    int diff = (2 * yDiff) - xDiff;
    int y = y0;

    for (int x = x0; x < x1; ++x) {         // go from x0 to x1 and plot, if difference > 0 then inverse y
        drawChar(x, y, ch);
        if (diff > 0)
        {
            y += yi;
            diff = diff + (2 * (yDiff - xDiff));
        }
        else
            diff = diff + (2 * yDiff);
    }

}
int roundDouble(double x)
{
    return (x - ((int)x >= 0.5)) ? ++x : x;     // if remainder >= 0.5 round up to int, else round down
}
double distance2D(Point& p1, Point& p2)
{
    return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
}
