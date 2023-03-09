#include <iostream>
using namespace std;

struct Fraction 
{
    int numerator; 
    int denominator; 

    Fraction()
    { 
        numerator = 0;
        denominator = 1;
    }

    Fraction(int num, int den)
    { 
        numerator = num;
        denominator = den;
        simplify();
    }

    void simplify()
    {
        if (numerator == 0)
        {
            denominator = 1;
        }
        else
        {
            int gcd = findGcd(abs(numerator), denominator);
            numerator /= gcd;
            denominator /= gcd;
        }
    }

    int findGcd(int a, int b)
    {
        if (b == 0) 
        {
            return a;
        }
        return findGcd(b, a % b);
    }

    void print()
    {
        if (denominator == 1)
        {
            cout << numerator;
        }
        else
        {
            cout << numerator << "\n-\n" << denominator;
        }
    }
};

Fraction add(Fraction f1, Fraction f2) 
{
    Fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    result.simplify();
    return result;
}

Fraction subtract(Fraction f1, Fraction f2) 
{
    Fraction result;
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    result.simplify();
    return result;
}

Fraction multiply(Fraction f1, Fraction f2) 
{
    Fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    result.simplify();
    return result;
}

Fraction divide(Fraction f1, Fraction f2)
{
    Fraction result;
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;
    result.simplify();
    return result;
}

int main()
{
    int f11, f12, f21, f22;
    cout << "Enter first fraction: " << endl;
    cin >> f11;
    cout << "-" << endl;
    cin >> f12;
    cout << "Enter second fraction: " << endl;
    cin >> f21;
    cout << "-" << endl;
    cin >> f22;
    Fraction f1(f11, f12);
    Fraction f2(f21, f22);

    Fraction sum = add(f1, f2);
    Fraction sub = subtract(f1, f2);
    Fraction mul = multiply(f1, f2);
    Fraction div = divide(f1, f2);

    int switch_on;
    cout << "----Choose function----" << endl;
    cout << "-      1 - Sum()      -" << endl;
    cout << "-      2 - Sub(       -" << endl;
    cout << "-      3 - Mul()      -" << endl;
    cout << "-      4 - Div()      -" << endl;
    cout << "---------------------------" << endl;
    cout << "-> ";
    cin >> switch_on;

    switch (switch_on)
    {
    case 1:
    {
        cout << "Sum:\n";
        sum.print();
        cout << endl;
    }break;
    case 2:
    {
        cout << "Sub:\n";
        sub.print();
        cout << endl;
    }break;
    case 3:
    {

        cout << "Mul:\n";
        mul.print();
        cout << endl;
    }break;
    case 4:
    {
        cout << "Div:\n";
        div.print();
        cout << endl;
    }break;
    default:
        break;
    }
    return 0;
}