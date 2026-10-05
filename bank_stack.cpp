#include<iostream>
using namespace std;
int main()
{
    int stack[5];
    int top=-1;

    cout<<"\n Last 5 Token Served: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<"\n ENter the token "<<(i+1)<<" Served: ";
        top++;
        cin>>stack[top];

    }
    cout<<"\n Cancelled Orders : "<<endl;
    while(top>=0)
    {
        cout<<"\n Cancelled order: "<<stack[top];
        top--;

    }
    return 0;
    
}
