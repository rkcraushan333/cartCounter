#include <iostream>
#include <fstream> // from this we do file handling stuff
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t_________________________________________________\n";
    cout << "\t\t\t\t                                                 \n";
    cout << "\t\t\t\t                                                 \n";
    cout << "\t\t\t\t                MAIN_MENU                         \n";
    cout << "\t\t\t\t                                                 \n";
    cout << "\t\t\t\t_________________________________________________\n";
    cout << "\t\t\t\t                                                 \n";
    cout << "\t\t\t\t|        1) Administrator                        |\n";
    cout << "\t\t\t\t|        2) Buyer                                |\n";
    cout << "\t\t\t\t|        3) Exit                                 |\n";
    cout << "\t\t\t\t Please selct any of the above option!";

    cin >> choice;

    switch (choice)
    {
    case 1:
    {

        cout << "\t\t\t Please Login \n";
        cout << "\t\t\t Enter Email \n";
        cin >> email;
        cout << "\t\t\t Enter Password \n";
        cin >> password;

        if (email == "inforkc@gmail.com" && password == "inforkc@1234")
        {
            administrator();
        }
        else
        {
            cout << "\t\t\t Invalid Email/Password :( \n";
        }
    }
    case 2:
    {

        buyer();
    }
    case 3:
    {

        exit(0);
    }
    default:
    {

        cout << "\t\t\t Please Select From The Given Options \n";
    }
    }

    goto m;
}

void shopping ::administrator()
{
m:
    int choice;
    cout << "\n\n\n\t\t\t Administrator Menu";
    cout << "\n\t\t\t|___1) Add the Product_________|";
    cout << "\n\t\t\t|                                |";
    cout << "\n\t\t\t|___2) Modify the Product______|";
    cout << "\n\t\t\t|                                |";
    cout << "\n\t\t\t|___3) Delete the Product______|";
    cout << "\n\t\t\t|                                |";
    cout << "\n\t\t\t|___4) Back to main menu_______|";

    cout << "\n\n\t Please Enter Your Choice";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "Invalid Choice!";
    }
    goto m;
}

void shopping::buyer()
{
m:
    int choice;
    cout << "\t\t\t    Buyer              \n";
    cout << "\t\t\t_______________________\n";
    cout << "                             \n";
    cout << "\t\t\t   1) Buy Product      \n";
    cout << "                             \n";
    cout << "\t\t\t   2) Go Back          \n";
    cout << "\t\t\t                       \n";
    cout << "\t\t\t   Enter Your Choice   \n";

    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu();

    default:
        cout << "\t\t\t   Invalid Choice   \n";
    }

    goto m;
}

void shopping ::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t Add New Product";
    cout << "\n\n\t Product Code of the Product ";
    cin >> pcode;
    cout << "\n\n\t Name of the Product";
    cin >> pname;
    cout << "\n\n\t Price of the Product";
    cin >> price;
    cout << "\n\n\t Discount on Product";
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;

        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
    }

    cout << "\n\n\t\t Record Inserted !";
}

void shopping ::edit()
{
    fstream data, data1;
    int pkey; // initial pcode
    int token = 0;
    int c;    // prod code
    float p;  // prod price
    float d;  // discount
    string n; // prod name

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product Code";
    cin >> pkey;

    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "\n\nFile doesn't exist! ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product new code :";
                cin >> c;
                cout << "\n\t\t Name of the product :";
                cin >> n;
                cout << "\n\t\t Price :";
                cin >> p;
                cout << "\n\t\t Discount :";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Record edited";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found sorry!";
        }
    }
}

void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete Product";
    cout << "\n\n\t Product code :";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File doesn't exist";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product deleted successfully";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found";
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|_______________________________________________________________\n";
    cout << "ProNo\t\tName\t\tPrice\n";
    cout << "\n\n|_______________________________________________________________\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    string choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Empty database";
    }
    else
    {
        data.close();
        list();
        cout << "\n____________________________________________________________________\n";
        cout << "\n|                                                                   |\n";
        cout << "\n                  PLEASE PLACE THE ORDER                            \n";
        cout << "\n|                                                                   |\n";
        cout << "\n____________________________________________________________________\n";
        do
        {
        m:
            cout << "\n\nEnter Product Code : ";
            cin >> arrc[c];
            cout << "\n\nEnter the Product Quantity :";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate Product code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? press y for yes and n for no";
            cin >> choice;
        } while (choice == "y");

        cout << "\n\n\t\t\t_______________________RECEIPT______________________________\n";
        cout << "\nProduct No\t Product Name\t Product quamtity\ttpice\tAmount with discount\n";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n"
                         << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n\n_________________________________________________________________________";
    cout << "\n TOTAL AMOUNT : " << total;
}

int main()
{
    shopping s;
    s.menu();
}