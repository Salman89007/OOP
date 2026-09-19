#include <iostream>
#include <string>
using namespace std;

struct Engine
{
    int hp;
};
struct Car
{
    Engine e;
    string model;
    int year;
    float price;
};

int main()
{
    Car cars[30];
    int choice;
    int count = 0;
    do
    {
        cout << "\n===== CAR SHOWROOM =====\n";
        cout << "1. Add car\n";
        cout << "2. Display all cars\n";
        cout << "3. Display by price range\n";
        cout << "4. Display by horsepower\n";
        cout << "5. Display by year\n";
        cout << "6. Search by model\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (count >= 30)
            {
                cout << "showroom full" << endl;
            }
            else
            {
                cout << "Enter model: ";
                cin >> cars[count].model;
                cout << "Enter year: ";
                cin >> cars[count].year;
                cout << "Enter price: ";
                cin >> cars[count].price;
                cout << "Enter horsepower: ";
                cin >> cars[count].e.hp;

                count++;
            }
        }
        else if (choice == 2)
        {
            for (int i = 0; i < count; i++)
            {
                cout << "\nModel: " << cars[i].model;
                cout << "\nYear: " << cars[i].year;
                cout << "\nPrice: " << cars[i].price;
                cout << "\nHorsepower: " << cars[i].e.hp << endl;
            }
        }
        else if (choice == 3)
        {
            bool found = false;
            int Price;
            cout << "enter the price range you want your car to be" << endl;
            cin>>Price;
            for (int i = 0; i < count; i++)
            {
                if (cars[i].price == Price)
                {
                    found = true;
                    cout << "\nModel: " << cars[i].model;
                    cout << "\nYear: " << cars[i].year;
                    cout << "\nPrice: " << cars[i].price;
                    cout << "\nHorsepower: " << cars[i].e.hp << endl;
                }
            }
            if (found!= true)
            {
                cout<<"no car available in that range"<<endl;
            }
            
        }
        else if (choice == 4)
        {
            bool found = false;
            int Horspower;
            cout << "enter the Horsepower range you want your car to be" << endl;
            for (int i = 0; i < count; i++)
            {
                if (cars[i].price == Horspower)
                {
                    found = true;
                    cout << "\nModel: " << cars[i].model;
                    cout << "\nYear: " << cars[i].year;
                    cout << "\nPrice: " << cars[i].price;
                    cout << "\nHorsepower: " << cars[i].e.hp << endl;
                }
            }
            if (found!= true)
            {
                cout<<"no car available in that range"<<endl;
            }
        }
        else if (choice == 5)
        {
            bool found = false;
            int Year;
            cout << "enter the Year you want your car to be" << endl;
            for (int i = 0; i < count; i++)
            {
                if (cars[i].price == Year)
                {
                    found = true;
                    cout << "\nModel: " << cars[i].model;
                    cout << "\nYear: " << cars[i].year;
                    cout << "\nPrice: " << cars[i].price;
                    cout << "\nHorsepower: " << cars[i].e.hp << endl;
                }
            }
            if (found!= true)
            {
                cout<<"no car available in that range"<<endl;
            }
        }
        else if (choice == 6)
        {
            bool found = false;
            string Model;
            cout << "enter model to search for : " << endl;
            cin >> Model;
            for (int i = 0; i < count; i++)
            {
                if (cars[i].model == Model)
                {
                    found = true;
                    cout << "\nModel: " << cars[i].model;
                    cout << "\nYear: " << cars[i].year;
                    cout << "\nPrice: " << cars[i].price;
                    cout << "\nHorsepower: " << cars[i].e.hp << endl;
                }
            }
            if (found!= true)
            {
                cout<<"no car available in that range"<<endl;
            }
        }
        else if (choice == 7)
        {
            cout<<"Exiting ..."<<endl;
            break;
        }
        else
        {
            cout << "enter within the given options " << endl;
        }
    }

    while (choice != 7);

    return 0;
}