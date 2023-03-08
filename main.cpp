#include <iostream>
//#include <Windows.h>
//#include <thread>

using namespace std;

struct Rectangle
{
	double width;
	double length;
	double x;
	double y;

	Rectangle()
	{
		width = 0;
		length = 0;
		x = 0;
		y = 0;
	}
	Rectangle(double width, double length, double x, double y)
	{
		this->width = width;
		this->length = length;
		this->x = x;
		this->y = y;
	}
	void DrawRec()
	{
		for (size_t i = 0; i < length; i++)
		{
			cout << "|";
			for (size_t j = 0; j < width - 1; j++)
			{
				if (i == 0 || i == length - 1)
				{
					cout << "--";
				}
				else
				{
					cout << "  ";
				}
			}
			cout << "|";
			cout << endl;
		}
	}
	void About()
	{
		cout << "Width: " << width << endl;
		cout << "Length: " << length << endl;
	}
	void SizeChange(double width, double length)
	{
		this->width = width;
		this->length = length;
	}
	void Move(double dx, double dy)
	{
		x += dx;
		y += dy;
	}

};

int main()
{
	double w, l;
	cout << "Enter widgth-> ";
	cin >> w;
	cout << "Enter length-> ";
	cin >> l;
	Rectangle* rec = new Rectangle(w, l, 0, 0);
	int switch_on = -1;

	while (switch_on != 0)
	{
		cout << "------Choose function------" << endl;
		cout << "-     0 - To exit          -" << endl;
		cout << "-     1 - DrawRec()       -" << endl;
		cout << "-     2 - About()         -" << endl;
		cout << "-     3 - SizeChange()    -" << endl;
		cout << "-     4 - Move()          -" << endl;
		cout << "---------------------------" << endl;
		cout << "-> ";
		cin >> switch_on;
		if (switch_on < 0 || switch_on > 4)
		{
			cout << "Operation out of range, try again" << endl;
		}
		else
		{
			switch (switch_on)
			{
			case 1:
			{
				rec->DrawRec();
			}break;
			case 2:
			{
				rec->About();
			}break;
			case 3:
			{
				int w1, l1;
				cout << "Enter new sizes:" << endl;
				cout << "Widgth-> ";
				cin >> w1;
				cout << "Length-> ";
				cin >> l1;
				rec->SizeChange(w1, l1);
				cout << "Size changed succesfully" << endl;
			}break;
			case 4:
			{
				double x, y;
				cout << "Enter new positions:\n x-> ";
				cin >> x;
				cout << "Enter y-> ";
				cin >> y;
				std::cout << "Initial rectangle position: (" << rec->x << ", " << rec->y << ")" << std::endl;
				rec->Move(x, y);
				std::cout << "New rectangle position: (" << rec->x << ", " << rec->y << ")" << std::endl;
			}break;
			}
			if (switch_on != 0)
			{
				system("pause");
				system("cls");
			}
		}	
	}
	exit(0);
	return 0;
}