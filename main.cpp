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

};
int main()
{
	int x, y, w, l;
	cout << "w -> ";
	cin >> w;
	cout << "l -> ";
	cin >> l;
	cout << "x -> ";
	cin >> x;
	cout << "y -> ";
	cin >> y;
	const int size = 20;
	const int size2 = 40;
	char** arr = new char*[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = new char[size2];
	}
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size2; j++)
		{
			if (i == ((size / 2) - 1) && j == size-1)
			{
				arr[i][j] = '+';
			}
			else if (i == ((size / 2) - 1))
			{
				arr[i][j] = '--';
			}
			else if (j == size - 1)
			{
				arr[i][j] = '|';
			}
			else
			{
				arr[i][j] = '  ';
			}
		}
	}


	for (size_t i = y; i < (w + y); i++)
	{
		for (size_t j = x; j < (l + x); j++)
		{
			if (i == y || i == (w + y))
			{
				arr[i][j] = '---';
			}
			if (j == x || j == (l + x))
			{
				arr[i][j] = '|';
			}
		}
	}

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size2; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}


	return 0;
}