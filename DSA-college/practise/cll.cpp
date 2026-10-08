#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* head = NULL;

void insert_at_beg(int data)
{
    node* newnode = new node;
    newnode->data = data;
    if(head==NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        newnode->next = head;
        node* trv_ptr = head;
        while(trv_ptr->next != head)
        {
            trv_ptr = trv_ptr->next;
        }
        trv_ptr->next = newnode;
        head = newnode; 
    }
}

void insert_at_end(int data)
{
    node* newnode = new node;
    newnode->data = data;
    if(head == NULL)
    {
        head = newnode;
        newnode->next  = newnode;
    }
    else
    {
        node* trv_ptr = head;
        while(trv_ptr->next!=head)
        {
            trv_ptr = trv_ptr->next;
        }
        trv_ptr->next = newnode;
        newnode->next = head;
    }
}

void insert_at_pos(int data, int pos)
{
    node* newnode = new node;
    newnode->data = data;
    if(head==NULL && pos==1)
    {
        head = newnode;
        newnode->next = newnode;
    }
    else if(head==NULL && pos!=1)
    {
        cout<<"Invalid position";
    }
    else
    {
        if(pos==1)
        {
            delete newnode; //newnode will be created in insert at beg function;
            insert_at_beg(data);
        }
        else{
        node* trv_ptr = head;
        int counter = 1;
        while(trv_ptr->next!=head)
        {
            trv_ptr = trv_ptr->next;
            counter++;
        }
        if(pos>counter+1)
        {
            cout<<"Invalid position";
        }
        else
        {
            node* trv_ptr = head;
            for(int i=2;i<pos;i++)
            {
                trv_ptr = trv_ptr->next;
            }
            newnode->next = trv_ptr->next;
            trv_ptr->next = newnode; 
        }
    }
    }
}

void delete_at_beg()
{
    if(head==NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        if(head->next==head) //only one element in the list
        {
            node* store_ptr = head;
            delete store_ptr;
            head = NULL;
        }
        else
        {
            node* store_ptr = head;
            node* trv_ptr = head;
            while(trv_ptr->next!=head)
            {
                trv_ptr = trv_ptr->next;
            }
            trv_ptr->next = head->next;  
            head = head->next;
            delete store_ptr;
        }
    }
}

void delete_at_end()
{
    if(head==NULL)
    {
        cout<<"List is empty";
    }
    else if(head!=NULL && head->next == head)
    {
        node* store_ptr = head;
        head=NULL;
        delete store_ptr;
    }
    else{
    node* trv_ptr = head;
    while(trv_ptr->next->next != head)
    {
        trv_ptr = trv_ptr->next;
    }
    node* store_ptr = trv_ptr->next;
    trv_ptr->next = head;
    delete store_ptr;
}
}

void delete_at_pos(int pos)
{
    if(head == NULL)
    {
        cout<<"list empty";
    }
    else
    {
        node* trv_ptr = head;
        int counter = 1;
        while(trv_ptr->next!=head)
        {
            trv_ptr = trv_ptr->next;
            counter++;
        }

        if(pos==1)
        {
            delete_at_beg();
        }
        else if(pos==counter)
        {
            delete_at_end();
        }
        else if(pos>counter || pos<1)
        {
            cout<<"Invalid posn";
        }
        else
        {
            node* trv_ptr = head;
            for(int i=2;i<pos;i++)
            {
                trv_ptr = trv_ptr->next;
            }
            node* store_ptr = trv_ptr->next;
            trv_ptr->next = trv_ptr->next->next;
            delete store_ptr;
        }
    }
}

void search(int data)
{
    if(head==NULL)
    {
        cout<<"list is empty";
    }
    else if(head->next==head)
    {
        if(head->data==data)
        {
            cout<<"data found";
        }
        else
        {
            cout<<"data not found";
        }
    }
    else
    {
        int flag = 0;
        node* trv_ptr = head;
        do
        {
            if(trv_ptr->data==data)
            {
                cout<<"data found";
                flag = 1;
                break;
            }
            else
            {
                trv_ptr = trv_ptr->next;
            }
        }
        while(trv_ptr!= head);
        
        if(flag!=1)
        {
            cout<<"data not found";
        }
    }
}

int main()
{
    
    return 0;
}