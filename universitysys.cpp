#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Student
{
    int rollNo;
    string name;
    string course;
    Student* next;
    Student* hashNext;
};

Student* head = NULL;
const int SIZE = 10;
Student* hashTable[SIZE] = {NULL};

int readInt(const string& prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid number.\n";
    }
}

int hashFunction(int rollNo)
{
    int h = rollNo % SIZE;
    return (h < 0) ? -h : h;
}

void enrollStudent()
{
    Student* s = new Student;
    s->rollNo = readInt("Enter Roll Number : ");

    int index = hashFunction(s->rollNo);
    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNo == s->rollNo)
        {
            cout << "Roll Number already exists \n";
            delete s;
            return;
        }
        temp = temp->hashNext;
    }

    cout << "Enter Student Name : ";
    getline(cin, s->name);

    cout << "Enter Course Name : ";
    getline(cin, s->course);

    s->next = head;
    head = s;

    s->hashNext = hashTable[index];
    hashTable[index] = s;

    cout << "Student Enrolled Successfully!\n";
}

void updateStudent()
{
    int rollNo = readInt("Enter Roll Number to update : ");

    int index = hashFunction(rollNo);
    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNo == rollNo)
        {
            cout << "Enter New Student Name : ";
            getline(cin, temp->name);

            cout << "Enter New Course Name : ";
            getline(cin, temp->course);

            cout << "Student Updated Successfully!\n";
            return;
        }
        temp = temp->hashNext;
    }
    cout << "STUDENT NOT FOUND!\n";
}

void removeStudent()
{
    int rollNo = readInt("Enter Roll Number to remove : ");

    int index = hashFunction(rollNo);
    Student* curr = hashTable[index];
    Student* prev = NULL;
    Student* target = NULL;

    while (curr != NULL)
    {
        if (curr->rollNo == rollNo)
        {
            target = curr;
            if (prev == NULL)
            {
                hashTable[index] = curr->hashNext;
            }
            else
            {
                prev->hashNext = curr->hashNext;
            }
            break;
        }
        prev = curr;
        curr = curr->hashNext;
    }

    if (target == NULL)
    {
        cout << "STUDENT NOT FOUND!\n";
        return;
    }

    if (head == target)
    {
        head = target->next;
    }
    else
    {
        Student* listCurr = head;
        while (listCurr != NULL && listCurr->next != target)
        {
            listCurr = listCurr->next;
        }
        if (listCurr != NULL)
        {
            listCurr->next = target->next;
        }
    }

    delete target;
    cout << "Student Removed Successfully!\n";
}

void display_Students()
{
    Student* temp = head;

    if (temp == NULL)
    {
        cout << "NO Student records Available \n";
        return;
    }

    cout << "\n ----------- STUDENTS RECORD ------------- \n";
    while (temp != NULL)
    {
        cout << "Roll Number : " << temp->rollNo << endl;
        cout << "Name        : " << temp->name << endl;
        cout << "Course      : " << temp->course << endl;
        cout << "-----------------------------------------\n";
        temp = temp->next;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\n ------------ UNIVERSITY REGISTRATION SYSTEM -------------- \n";
        cout << "1. Enroll Student  \n";
        cout << "2. Update Student  \n";
        cout << "3. Remove Student  \n";
        cout << "4. Display ALL Students  \n";
        cout << "5. Exit \n";
        choice = readInt("Enter your choice: ");

        switch (choice)
        {
            case 1:
                enrollStudent();
                break;
            case 2:
                updateStudent();
                break;
            case 3:
                removeStudent();
                break;
            case 4:
                display_Students();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
