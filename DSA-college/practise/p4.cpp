#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* prev = NULL;
    node* next = NULL;
};
node* head = NULL;
void insert_at_end(int data)
{
    node* newnode = new node;
    newnode->data = data;
    if(head==NULL)
    {
        head = newnode;
        newnode->next = head;
        newnode->prev = head;
    }
    else
    {
        node* trv_ptr = head;
        while(trv_ptr->next != head)
        {
            trv_ptr = trv_ptr->next;
        }
        newnode->next = head;
        newnode->prev = trv_ptr;
        trv_ptr->next = newnode; 
        head->prev = newnode;
    }
}

bool is_present(int data)
{
    node* trv_ptr = head;
    do
    {
        if(trv_ptr->data == data)
        {
            return true;
        }
        else
        {
            trv_ptr = trv_ptr->next;
        }
    } 
    while (trv_ptr!=head);
    return false;
}

void display_posn(int data)
{
    node* trv_ptr = head;
    node* count_ptr = head;
    int counter = 1;
    int total_elem=1;
    do
    {
        count_ptr = count_ptr->next;
        total_elem++;
    } while (count_ptr!=head);
    
    do
    {
        if(trv_ptr->data==data)
        {
            cout<<"Found at position "<<counter<<endl;
            cout<<"Prev: "<<trv_ptr->prev->data<<" ";
            if(counter==total_elem)
            {
                cout<<"Next: "<<head->data; 
            }
            else
            {
                cout<<"Next: "<<trv_ptr->next->data;
            }
            return;
        }
        else
        {
            trv_ptr = trv_ptr->next;
            counter++;
        }
    }
    while(trv_ptr!=head);
}

int main()
{
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        insert_at_end(num);
    }
    int elem;
    cin>>elem;
    if(is_present(elem)==true)
    {
        display_posn(elem);
    }
    else
    {
        cout<<"-1";
    }
    return 0;
}