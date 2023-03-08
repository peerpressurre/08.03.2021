#include <iostream>

using namespace std;

struct Point
{
	int x;
	int y;
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int distance(int x, int y, int x2, int y2)
	{
		int dx = x - x2;
		int dy = y - y2;
		return sqrt(dx * dx + dy * dy);
	}
};
int main()
{
	int x, y, x2, y2;
	cout << "Enter coordinates of first point: " << endl;
	cout << "x-> ";
	cin >> x;
	cout << "y-> ";
	cin >> y;
	cout << "Enter coordinates of second point: " << endl;
	cout << "x-> ";
	cin >> x2;
	cout << "y-> ";
	cin >> y2;
	Point* pt = new Point(x, y);
	Point* pt2 = new Point(x2, y2);
	cout << "Distance between two points (" << pt->x << ", " << pt->y << ") and (" << pt2->x << ", " << pt2->y << "): " << pt->distance(pt->x, pt->y, pt2->x, pt2->y)<< endl;

	return 0;
}