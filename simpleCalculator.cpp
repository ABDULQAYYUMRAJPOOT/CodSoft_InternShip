#include <iostream>
#include <conio.h>
using namespace std;

class calculator
{
public:
    static double sum(double first, double second)
    {
        return first + second;
    }
    static double div(double divident, double divisor)
    {
        return divident / divisor;
    }
    static double multi(double first, double second)
    {
        return first * second;
    }
    static double sub(double first, double second)
    {
        return first - second;
    }
};

void goOn()
{
    cout << "Press any key to continue...";
    getch();
}

int main()
{
    string input, f, s;
    double first, second;
    while (true)
    {
        system("cls");
        cout << "Enter your action: " << endl;
        cout << " 1. Sum\n 2. Multiply\n 3. Divide.\n 4. Subtraction\n 5. Exit\n";
        cout << "Enter your choice: ";
        cin >> input;
        if (input == "5")
        {
            break;
        }
        cout << "First number: ";
        cin >> f;
        cout << "Second number: ";
        cin >> s;

        try
        {
            first = stod(f);
            second = stod(s);
            if (input == "1")
            {
                cout << "Answer is: " << calculator::sum(first, second) << endl;
                goOn();
            }
            else if (input == "2")
            {
                cout << "Answer is: " << calculator::multi(first, second) << endl;
                goOn();
            }
            else if (input == "3")
            {
                cout << "Answer is: " << calculator::div(first, second) << endl;
                goOn();
            }
            else if (input == "4")
            {
                cout << "Answer is: " << calculator::sub(first, second) << endl;
                goOn();
            }
            else
            {
                cout << "No operation Found...";
                goOn();
            }
        }
        catch (const std::exception &e)
        {
            cerr << "Enter number in digit" << endl;
            goOn();
        }
    }
    return 0;
}
