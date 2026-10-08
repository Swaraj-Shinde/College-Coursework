#include<bits/stdc++.h>
using namespace std;

struct node
{
    string party_name;
    node* next = NULL;
};

node* front = NULL;
node* rear = NULL;

void add_party(string party_name)
{
    //create a new node
    node* newnode = new node;
    newnode->party_name = party_name;

    //element will be added from rear end
    if(rear==NULL)
    {
        rear = newnode;
        front = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    cout<<"Party "<<rear->party_name<<" added!"<<endl;
    cout<<endl;
}

void seat_party() //node will be removed from front end 
{
    if(front==NULL) //no element present inside the queue
    {
        cout<<"Waitlist is empty!"<<endl;
        cout<<endl;
    }
    else
    {
        node* store_ptr = front;
        front = front->next;
        if(front==NULL)
        {
            rear=NULL;
        }
        delete store_ptr;
        cout<<"Party Seated!"<<endl;
        cout<<endl;
    }
}

void display()
{
    if(front==NULL)
    {
        cout<<"Waitlist is empty!"<<endl;
    }
    else
    {
        node* trv_ptr = front;
        cout<<"--WAITLIST--"<<endl;
        while(trv_ptr!=NULL)
        {
            cout<<trv_ptr->party_name<<endl;
            trv_ptr = trv_ptr->next;
        }
        cout<<endl;
    }
}

int main()
{
    int choice;
    do{
    cout<<"--WAITLIST SYSTEM--"<<endl;
    cout<<"1.Add party"<<endl;
    cout<<"2.Seat party"<<endl;
    cout<<"3.Display Waitlist"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;

    switch(choice)
    {
        case 1 : {string party_name;
                 cout<<"Enter party name: ";
                 cin>>party_name;
                 add_party(party_name);
                 break;}

        case 2: seat_party();
                break;

        case 3: display();
        break;

        case 4: return 0;

        default: cout<<"Invalid choice!"<<endl;
                 break;
    }
    }while(choice!=4);
    return 0;
}