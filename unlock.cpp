#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

bool IsloggedIn()
{
    string username, password, un, pw;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    //opening the file
    ifstream read("D:\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);
    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int choice;
    cout << "1.Register \n2.Login \nYour choice: ";
    cin >> choice;
    if (choice == 1)
    {
        string username, password;
        cout << "Select Username: ";
        cin >> username;
        cout << "Select Password: ";
        cin >> password;

        ofstream file;
        file.open("D:\\" + username + ".txt");
        file << username<< endl <<password;
        file.close();
        main();
    }
    else if (choice == 2)
    {
        bool status = IsloggedIn();
        if (!status)
        {
            cout << "Invalid Login Credentials !!" << endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Successfully Logged In" << endl;
            system("PAUSE");
            return 1;
        }
    }
}
