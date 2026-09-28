#include<iostream>
using namespace std;
int main()
{
    int stack[5];
    int top=-1;

    cout<<"\n Enter 5 Cancelled Order Numbers: "<<endl;
    for(int i=0;i<5;i++)
    {
        top++;
        cin>>stack[top];

    }
    cout<<"\n Cancelled Orders : "<<endl;
    while(top>=0)
    {
        cout<<"\n Cancelled order: "<<stack[top]<<endl;
        top--;

    }
    return 0;
    
}
