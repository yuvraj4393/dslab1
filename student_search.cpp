#include <iostream>
using namespace std;

int main() {
    int rollno[5];
    int searchrollno;

    cout << "Enter 5 roll numbers:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Roll Number: ";
        cin >> rollno[i];
    }

    cout << "Enter roll number to search: ";
    cin >> searchrollno;

    for (int i = 0; i < 5; i++) {
        if (rollno[i] == searchrollno) {
            cout << "Student found" << endl;
            return 0;
        }
    }

    cout << "Student is not found" << endl;
    return 0;
}