#include <iostream>
#include <conio.h>
using namespace std;
const int numberOfSeats = 20;
bool seats[numberOfSeats] = {false};

void showList()
{
    cout << "Available Seats ::" << endl;
    for (int i = 0; i < numberOfSeats; i++)
    {
        if (!seats[i])
        {
            cout << "Seat number: " << i + 1 << endl;
        }
    }
}

void pressKey()
{
    cout << "Enter any key to continue..." << endl;
    getch();
}
void menu()
{
    cout << "1. check available seats" << endl;
    cout << "2. book seat" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}
int main()
{
    while (true)
    {
        system("cls");
        menu();
        string input;
        cin >> input;
        if (input == "1")
        {
            showList();
            pressKey();
        }
        else if (input == "2")
        {
            showList();
            string num;
            cout << "Enter Seat Number: ";
            cin >> num;
            try
            {
                int book = stoi(num);
                if (book - 1 < 0 || book - 1 >= numberOfSeats)
                {
                    cout << "You entered wrong seat number..." << endl;
                    pressKey();
                }
                else
                {

                    if (seats[book - 1] == false)
                    {
                        seats[book - 1] = true;
                        cout << "Your seat is booked..." << endl;
                        pressKey();
                    }
                    else
                    {
                        cout << "This seat is already booked...";
                        pressKey();
                    }
                }
            }
            catch (exception &e)
            {
                cerr << "Enter number in digit..." << endl;
                pressKey();
            }
        }
        else if (input == "3")
        {
            break;
        }
        else
        {
            cerr << "Wrong option...";
            pressKey();
        }
    }
    return 0;
}