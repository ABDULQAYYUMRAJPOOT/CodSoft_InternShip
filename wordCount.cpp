#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
using namespace std;

string readData(string &fileName)
{
    string data = "";
    fstream read;
    read.open(fileName, ios::in);
    if (!read.is_open())
        return data;
    while (!(read.eof()))
    {
        string temp;
        getline(read, temp);
        data += temp;
        temp.clear();
    }
    read.close();
    return data;
}

string removeExtraSpaces(const string &input)
{
    istringstream iss(input);
    ostringstream oss;
    string token;
    while (iss >> token)
    {
        oss << token << ' ';
    }
    return oss.str().substr(0, oss.str().size() - 1);
}

int countLetters(string str)
{
    int count = 0;
    while (str.length() != 0)
    {
        int temp = str.find(' ');
        if (temp != -1)
        {
            count++;
            str = str.substr(temp + 1, str.length());
        }
        else
        {
            count++;
            break;
        }
    }
    return count;
}

void menu()
{
    cout << "1. Count words in file." << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your choice : ";
}

void output()
{
    string fileName;
    cout << "Enter File name: ";
    // getline(cin, fileName);
    cin >> fileName;
    string data = readData(fileName);
    cout << "Total Number of letters are: " << countLetters(data) << endl;
    cout << "Press any key to continue...";
    getch();
}

int main()
{
    string input;
    while (true)
    {
        system("cls");
        menu();
        cin >> input;
        if (input == "1")
        {
            output();
        }
        else if (input == "2")
        {
            break;
        }
        else
        {
            cerr << "You entered wrong choice..." << endl;
            cout << "Press any key to continue...";
            getch();
        }
    }
    return 0;
}
