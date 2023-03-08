#include <iostream>
using namespace std;

struct Fraction {
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
    
    void reduce()
    {
        if (numerator > denominator)
        {
            int integer = numerator / denominator;
            numerator -= denominator;
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
            cout << numerator << "/" << denominator;
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
    Fraction f1(2, 3);
    Fraction f2(3, 4);

    Fraction sum = add(f1, f2);
    Fraction sub = subtract(f1, f2);
    Fraction mul = multiply(f1, f2);
    Fraction div = divide(f1, f2);
    cout << "Sum: ";
    sum.print();
    cout << endl;

    cout << "Sub: ";
    sub.print();
    cout << endl;

    cout << "Mul: ";
    mul.print();
    cout << endl;

    cout << "Div: ";
    div.print();
    cout << endl;

    return 0;
}