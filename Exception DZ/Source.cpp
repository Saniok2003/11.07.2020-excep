#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
using namespace std;

class BaseException
{
protected:
    string text;

public:
    virtual string what() = 0;
};

class ArithmeticException : public BaseException
{
public:
    ArithmeticException()
    {
        text = "Arithmetic exception";
    }

    ArithmeticException(string te)
    { 
        text = te;
    }

    string what() 
    { 
        return text;
    }
};

class DivideByZero final :public ArithmeticException
{
public:
    DivideByZero() :ArithmeticException()
    {
        text = "Divide by zero"; 
    }
    DivideByZero(string te) : ArithmeticException(te)
    {   }
    string what()
    {
        return text;
    }
};

class NegativeIndex final : public BaseException
{
public:
    NegativeIndex(string te = "Negative Index") 
    {
        text = te; 
    }

    string what() 
    {
        return text;
    }
};

void WrongIndex()
{
    int a[10];
    int index;
    for (int i = 0; i < 10; i++)
    {
        a[i] = i * i;
    }
    cout << "Input index: " << endl;
    cin >> index;
    if (index < 0)
    {
        throw NegativeIndex();
    }
    cout << "a[" << index << "] = " << a[index] << endl;
}

void Divide_0()
{
    int a, b;
    cout << "a/b: " << endl;
    cout << "Enter 'a' = ";
    cin >> a;
    cout << "Enter 'b' = ";
    cin >> b;

    if (b == 0)
    {
        throw DivideByZero("Divide by 0");
    }
    cout << "a / b = " << (double)a / b << endl;
}

int main()
{
    
    try
    {
        WrongIndex();
        Divide_0();
        cout << "Things are good" << endl;
    }
    catch (NegativeIndex e)
    {
        cout << e.what() << endl;
    }
    catch (DivideByZero e)
    {
        cout << e.what() << endl;
    }

    return 0;
}