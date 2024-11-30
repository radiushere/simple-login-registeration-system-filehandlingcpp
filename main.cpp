// HEADER
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// GLOBAL VARIABLES
int userid;

// FUNCTION PROTOTYPES
void menu();
void regist();
void login();
void postlogin(); // add your required functions from this function onward

// MAIN
int main()
{
    menu();

    return 0;
}

// DECLARATION
void menu()
{
    int choice1;

    system("cls"); // to clear the console

    cout << "\n\t\t\t------------------------------";
    cout << "\n\t\t\t                              ";
    cout << "\n\t\t\t     WELCOME TO THE MENU      ";
    cout << "\n\t\t\t                              ";
    cout << "\n\t\t\t------------------------------";
    cout << "\n\t\t\t                              ";
    cout << "\n\t\t\t|   PRESS \"1\" TO LOG IN      |";
    cout << "\n\t\t\t|   PRESS \"2\" TO REGISTER    |";
    cout << "\n\t\t\t|   PRESS \"0\" TO EXIT        |\n\n";

    cout << "\n\t\t\tPlease select an option: ";
    cin >> choice1;

    switch (choice1)
    {
    case 1:
        login();
        break;

    case 2:
        regist();
        break;

    case 3:
        exit(0);

    default:
        cout << "\n\t\t\tInvalid Entry" << endl
             << endl;
        break;
    }
}

void regist()
{
    string usernamere;
    int pinreg;

    cout << "\n\n\t\t\t|   WELCOME TO REGISTRATION PAGE   |";

    cout << "\n\n\t\t\tEnter a username: ";
    cin >> usernamere;

    cout << "\n\t\t\tEnter a pin: ";
    cin >> pinreg;

    ofstream f1("userdata.txt", ios::app);
    f1 << usernamere << " " << pinreg << " " << endl;

    system("cls");

    cout << "\t\t\t|	 THANK YOU FOR REGISTERING YOUR ACCOUNT   |";

    login();
}

void login()
{
login:

    string usernamelog, nameFile, pinlog, passFile;
    int check = 0;

    cout << "\n\n\t\t\t|	 WELCOME TO LOGIN PAGE   |";

    cout << "\n\n\t\t\tEnter your username: ";
    cin >> usernamelog;
    cout << "\n\t\t\tEnter your pin: ";
    cin >> pinlog;

    ifstream read("userdata.txt");
    while (read >> nameFile >> passFile)
    {
        if (usernamelog == nameFile && pinlog == passFile)
        {
            check = 1;
            goto checked;
        }
    }

checked:

    read.close();

    if (check == 1)
    {
        system("cls");
        cout << "\n\n\t\t\t|   YOU HAVE SUCCESSFULLY LOGGED IN             |";
        postlogin();
    } 

    else
    {
        system("cls");
        cout << "\n\n\t\t\t|	 YOU HAVE ENTERED THE WRONG USERNAME OR PIN   |";
        goto login;
    }
}

void postlogin()
{
    cout << "\n\n\n\t\t\t|      LOGGED IN      |" << endl;
}
