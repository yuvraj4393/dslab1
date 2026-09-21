#include<iostream>
using namespace std;
class Student
{
    public:
        int rollno;

        void get()
        {
            cout << "Enter Roll Number of Student: ";
            cin >> rollno;
        }
        void display()
        {
            cout << "Roll Number of Student: " << rollno << endl;
        }
};
int main()
{
    Student s1, s2, s3, s4, s5;
    s1.get();
    s2.get(); 
    s3.get();
    s4.get();
    s5.get();
    s1.display();
    s2.display();
    s3.display();
    s4.display();
    s5.display();
    return 0;
   
}
