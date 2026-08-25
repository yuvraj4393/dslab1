#include<iostream>
#include<string>
using namespace std;
int main()
{
int id1,id2,id3;
string Title1,Title2,Title3;

cout<<"Enter Book 1 Id: ";
cin>>id1;

cin.ignore();
cout<<"Enter the Book 1 Title: ";
getline(cin, Title1);


cout<<"Enter Book 2 Id: ";
cin>>id2;

cin.ignore();
cout<<"Enter the Book 2 Title: ";
getline(cin, Title2);




cout<<"Enter Book 3 Id: ";
cin>>id3;

cin.ignore();
cout<<"Enter the Book 3 Title: ";
getline(cin, Title3);

cout<<"\n======== LIBRARY BOOK =========";
cout<<"\nBook ID:"<<id1;
cout<<"\nBook Title : "<<Title1;

cout<<"\nBook ID:"<<id2;
cout<<"\nBook Title : "<<Title2;

cout<<"\nBook ID:"<<id3;
cout<<"\nBook Title : "<<Title3;

return 0;
}
