#pragma once

struct Point
{
	double x;
	double y;

	Point() {
		x = 0;
		y = 0;
	}
	Point(double y, double x) {
		this->x = x;
		this->y = y;
	}
};

class Board
{
	char** board;
	int row;
	int column;

public:
	Board();
	Board(const Board& b);
	Board(int a, int b);
	~Board();
	void Border();
	void display();
	void drawChar(int x, int y, char ch);
	void drawLineUp(Point& p1,Point& p2, char ch);					// draw a horizontal line
	void drawLine(Point& p0, Point& p1, char ch);					// draw a line between 2 points
	void plotLineHigh(int x0, int y0, int x1, int y1, char ch);  // y-axis plot
	void plotLineLow(int x0, int y0, int x1, int y1, char ch);	// x-axis plot

};

double distance2D(Point& p1, Point& p2);	// return distance between 2 points
int roundDouble(double x); // rounds a double to the nearest integer