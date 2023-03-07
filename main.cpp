#include <iostream>
using namespace std;

struct Rectangle
{
	double width;
	double length;

	Rectangle()
	{
		width = 0;
		length = 0;
	}
	Rectangle(double width, double length)
	{
		this->width = width;
		this->length = length;
	}
	void SizeChange(double width, double length)
	{
		this->width = width;
		this->length = length;
	}
	void Print()
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
	void move()
	{
		for (size_t i = 0; i < length; i++)
		{
			cout << "          ";
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
};

int main()
{
	Rectangle* rec = new Rectangle(5, 5);
	rec->Print();
	cout << endl;
	rec->SizeChange(5, 6);
	rec->Print();
	cout << endl;
	rec->move();
	return 0;
}