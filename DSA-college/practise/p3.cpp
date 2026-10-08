#include<bits/stdc++.h>
using namespace std;

struct node
{
    string step;
    node* next = NULL;
    node* prev = NULL;
};

node* head = NULL;

void insert_at_end(string step)
{
    node* newnode = new node;
    newnode->step = step;

    if(head==NULL)
    {
        head = newnode;
    }
    else
    {
        node* trv_ptr = head;
        while(trv_ptr->next!=NULL)
        {
            trv_ptr = trv_ptr->next;
        }
        trv_ptr->next = newnode;
        newnode->prev = trv_ptr;
    }
}

bool check(string after)
{
    node* trv_ptr = head;
    while(trv_ptr!=NULL)
    {
        if(trv_ptr->step==after)
        {
            return true;
        }
        else
        {
            trv_ptr = trv_ptr->next;
        }
    }
    return false;
}

void insert_after(string after, string x)
{
    node* newnode = new node;
    newnode->step = x;
    node* trv_ptr = head;
    while(trv_ptr->step!=after)
    {
        trv_ptr = trv_ptr->next;
    }
    newnode->next = trv_ptr->next;
    trv_ptr->next->prev = newnode;
    trv_ptr->next = newnode; 
}

void display()
{
    node* trv_ptr = head;
    while(trv_ptr!=NULL)
    {
        cout<<trv_ptr->step<<" ";
        trv_ptr = trv_ptr->next;
    }
}

int main()
{
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        string step;
        cin>>step;
        insert_at_end(step);
    }

    string after,x;
    cin>>after>>x;
    if(check(after)==true)
    {
        insert_after(after,x);
        display();
    }
    else
    {
        cout<<"Not Found ";
        display();
    }


    return 0;
}