#include <iostream>

using namespace std;

int main()
{
    int queue[5];
    int front = 0;
    int rear = 0;

    cout << "=== ENTER 5 TOKEN IDS ===\n\n";

    // Ask for each token individually
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter Token " << (i + 1) << ": ";
        cin >> queue[rear];
        rear++;
    }

    cout << "\n=== TOKENS IN LINE ===";

    // Process tokens in FIFO (First-In, First-Out) order
    while (front < rear)
    {
        cout << "\nTOKEN IN WORK :: " << queue[front];
        front++;
    }

    cout << endl;
    return 0;
}
