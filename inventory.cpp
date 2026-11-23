#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Product
{
    int id;
    string name;
    double price;
    int quantity;
    Product* next;
    Product* hashNext;
};

Product* head = NULL;
const int SIZE = 10;
Product* hashTable[SIZE] = {NULL};

int hashFunction(int id)
{
    return id % SIZE;
}

void addProduct()
{
    Product* p = new Product;
    cout << "Enter Product ID : ";
    cin >> p->id;

    int index = hashFunction(p->id);
    Patient_or_temp:
    Product* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->id == p->id)
        {
            cout << "Product ID already exists \n";
            delete p;
            return;
        }
        temp = temp->hashNext;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Product Name : ";
    getline(cin, p->name);

    cout << "Enter Product Price : ";
    cin >> p->price;

    cout << "Enter Product Quantity : ";
    cin >> p->quantity;

    p->next = head;
    head = p;

    p->hashNext = hashTable[index];
    hashTable[index] = p;

    cout << "Product Added Successfully!\n";
}

void searchProduct()
{
    int searchChoice;
    cout << "Search by: 1. Product ID  2. Product Name : ";
    cin >> searchChoice;

    if (searchChoice == 1)
    {
        int id;
        cout << "Enter Product ID to search : ";
        cin >> id;
        int index = hashFunction(id);
        Product* temp = hashTable[index];

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                cout << "\n--- Product Found ---" << endl;
                cout << "ID       : " << temp->id << endl;
                cout << "NAME     : " << temp->name << endl;
                cout << "PRICE    : " << temp->price << endl;
                cout << "QUANTITY : " << temp->quantity << endl;
                return;
            }
            temp = temp->hashNext;
        }
        cout << "PRODUCT NOT FOUND!\n";
    }
    else if (searchChoice == 2)
    {
        string name;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Product Name to search : ";
        getline(cin, name);

        Product* temp = head;
        bool found = false;
        while (temp != NULL)
        {
            if (temp->name == name)
            {
                cout << "\n--- Product Found ---" << endl;
                cout << "ID       : " << temp->id << endl;
                cout << "NAME     : " << temp->name << endl;
                cout << "PRICE    : " << temp->price << endl;
                cout << "QUANTITY : " << temp->quantity << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found)
        {
            cout << "PRODUCT NOT FOUND!\n";
        }
    }
    else
    {
        cout << "Invalid search option!\n";
    }
}

void display_Products()
{
    Product* temp = head;

    if (temp == NULL)
    {
        cout << "NO Product records Available \n";
        return;
    }

    cout << "\n ----------- ALL PRODUCTS ------------- \n";
    while (temp != NULL)
    {
        cout << "Product ID       : " << temp->id << endl;
        cout << "Product NAME     : " << temp->name << endl;
        cout << "Product PRICE    : " << temp->price << endl;
        cout << "Product QUANTITY : " << temp->quantity << endl;
        cout << "-----------------------------------------\n";
        temp = temp->next;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\n ------------ E-COMMERCE CATALOG SYSTEM -------------- \n";
        cout << "1. Add Product  \n";
        cout << "2. Search Product (ID or Name)  \n";
        cout << "3. Show All Products  \n";
        cout << "4. Exit \n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addProduct();
                break;
            case 2:
                searchProduct();
                break;
            case 3:
                display_Products();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
