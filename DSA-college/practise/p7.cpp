#include<bits/stdc++.h>
using namespace std;

struct node
{
    string msgid;
    node* next = NULL;
    node* prev = NULL;
};
node* head = NULL;

void insert_at_end(string s)
{
    node* newnode = new node;
    newnode->msgid = s;
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
       newnode->prev = trv_ptr;
       trv_ptr->next = newnode;
    }
}

void insert_after_pos(string after, string s)
{
    node* newnode = new node;
    newnode->msgid = s;
    node* trv_ptr = head;
    while(trv_ptr->msgid!=after)
    {
        trv_ptr = trv_ptr->next;
    }
    newnode->prev = trv_ptr;
    newnode->next = trv_ptr->next;
    newnode->next->prev = newnode;
    trv_ptr->next = newnode;
}

bool compare(string after)
{
    node* trv_ptr = head;
    do
    {
        if(trv_ptr->msgid==after)
        {
            return true;
        }
        else
        {
            trv_ptr = trv_ptr->next;
        }
    }
    while(trv_ptr!=NULL);
    return false;
}

void display()
{
    node* trv_ptr = head;
    while(trv_ptr != NULL)
    {
        cout<<trv_ptr->msgid<<" ";
        trv_ptr = trv_ptr->next;
    }
}

int main()
{
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        insert_at_end(s);
    }
    string after,x;
    cin>>after>>x;
    
    if(compare(after)==true)
    {
        insert_after_pos(after,x);
        display();
    }
    else
    {
        cout<<"Not Found"<<" ";
        display();
    }
    return 0;
}