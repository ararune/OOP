#include <iostream>
#include <math.h>
using namespace std;
// input an array of rectangles and a circle to get the number of rectangles that collide with the circle
struct Rectangle
{
	int rectangleA;
	int rectangleB;
	int rectangleC;
	int rectangleD;

	// User coordinate input for rectangle
	void createRectangle(int n)
	{
		cout << "Rectangle A coordinate input : ";
		cin >> rectangleA;
		cout << "Rectangle B coordinate input : ";
		cin >> rectangleB;
		cout << "Rectangle C coordinate input : ";
		cin >> rectangleC;
		cout << "Rectangle D coordinate input : ";
		cin >> rectangleD;
	}

	//Prints given coordinates
	void printRectangle(int n)
	{
		cout << "(A, B)" << endl;
		cout << "(" << rectangleA << ", " << rectangleB << ")" << endl;

		cout << "(C, D)" << endl;
		cout << "(" << rectangleC << ", " << rectangleD << ")" << endl;
	}

};

struct Circle
{
	int circleX;
	int circleY;
	int radius;
	// User coordinate and radius input for circle
	void createCircle()
	{
		cout << "Circle X axis input : ";
		cin >> circleX;

		cout << "Circle Y axis input : ";
		cin >> circleY;

		cout << "Circle radius input : ";
		cin >> radius;
	}
	// checks for rectangle-circle intersect
	bool intersect(Rectangle& firstRectangle)
	{
		int height = abs(firstRectangle.rectangleD - firstRectangle.rectangleB);
		int width = abs(firstRectangle.rectangleC - firstRectangle.rectangleA);

		int circleDistanceX = abs(circleX - firstRectangle.rectangleA);
		int circleDistanceY = abs(circleY - firstRectangle.rectangleB);

		// equation of the circle
		int diameter = sqrt(pow(abs(circleDistanceX - width), 2) + pow(abs(circleDistanceY - height), 2));

		// intersect conditions
		if (circleDistanceX > (width / 2 + radius))
		{
			return false;
		}
		else if (circleDistanceY > (height / 2 + radius))
		{
			return false;
		}
		else if (circleDistanceX <= (width / 2))
		{
			return true;
		}
		else if (circleDistanceY <= (height / 2))
		{
			return true;
		}
		else (diameter <= (radius ^ 2));
		{
			return true;
		}
	}

};

int main()
{
	Circle firstCircle;
	firstCircle.createCircle();

	cout << "Enter number of rectangles : ";
	int rectCount;
	cin >> rectCount;
	
	Rectangle* rect = new Rectangle[rectCount];

	int i, temp = 0;
	for (i = 0; i < rectCount; i++)
	{
		rect[i].createRectangle(i);
		rect[i].printRectangle(i);
	}

	for (int i = 0; i < rectCount; i++)
	{
		if (firstCircle.intersect(rect[i]))
		{
			temp++;
		}
	}

	cout << "Number of rectangles that collide : " << temp;
}