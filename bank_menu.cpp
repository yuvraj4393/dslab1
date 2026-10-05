#include <iostream>

using namespace std;

int main()
{
    int queue[5];           
    int front = 0;          
    int rear = 0;           
    int nextTokenId = 101;  
    int choice = 0;

    while (choice != 4)
    {
        
        cout << "    BANK TOKEN MANAGEMENT SYSTEM  \n";
        cout << " 1. Issue a Token\n";
        cout << " 2. Display All Tokens\n";
        cout << " 3. Serve a Customer\n";
        cout << " 4. Exit\n";
        
        cout << "Enter Your Choice : ";
        cin >> choice;

        if (choice == 1)
        {
            // Issue token if queue size limit (5) is not reached
            if (rear < 5)
            {
                queue[rear] = nextTokenId;
                cout << "\n[SUCCESS] Token #" << nextTokenId << " Issued successfully!\n";
                rear++;
                nextTokenId++;
            }
            else
            {
                cout << "\n[ERROR] Queue is FULL! Maximum limit of 5 tokens reached.\n";
            }
        }
        else if (choice == 2)
        {
            // Display tokens waiting in line
            if (front == rear)
            {
                cout << "\n[INFO] No tokens currently in line.\n";
            }
            else
            {
                cout << "\n--- Tokens Currently Waiting ---\n";
                for (int i = front; i < rear; i++)
                {
                    cout << "Token ID: " << queue[i] << endl;
                }
            }
        }
        else if (choice == 3)
        {
            // Serve the customer at the front
            if (front < rear)
            {
                cout << "\n[NOW SERVING] Customer with Token #" << queue[front] << endl;
                front++; // Advance front pointer
            }
            else
            {
                cout << "\n[INFO] No customers in line to serve.\n";
            }
        }
        else if (choice == 4)
        {
            cout << "\nThank you for using the Bank Token System. Goodbye!\n";
        }
        else
        {
            cout << "\n[INVALID] Invalid choice! Please enter 1, 2, 3, or 4.\n";
        }
    }

    return 0;
}
