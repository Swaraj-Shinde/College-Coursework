#include<bits/stdc++.h>
using namespace std;

struct node
{
    string key;
    string value;
    node* left = NULL;
    node* right = NULL;
};
node* root = NULL;

void insert_word(string key,string value)
{
    //create newnode
    node* newnode = new node;
    newnode->key = key;
    newnode->value = value;

    if(root==NULL)
    root=newnode; //make root pointing to newnode
    else
    {
        int flag = 0;
        //here flag is used coz there are two cases when trv_ptr becomes null
        //first one when left or right traverse till last available node
        //second one is for duplicate element
        //after traversing i dont want to add node if duplicate found
        //else my connection would be lost with the subtree

        int dixn=1;
        //if left then dixn becomes even else odd

        node* trv_ptr = root;
        while(trv_ptr->left!=NULL || trv_ptr->right!=NULL)
        {
            if(key<trv_ptr->key && trv_ptr->left!=NULL)
            {
                trv_ptr = trv_ptr->left;
                dixn++;

            }
            else if(key>trv_ptr->key && trv_ptr->right!=NULL)
            {
                trv_ptr = trv_ptr->right;
                dixn++;
            }
            else
            {
                cout<<"Duplicate word! Meaning updated\n";
                trv_ptr->value = value;
                flag=1;
                break;
            }
        }
        if(flag!=1) //here i need to add node, my trv_ptr is pointing to node
        //whose left or right i need to add my new node
        {
            if(dixn%2==0) //add node to left
            {
                trv_ptr->left = newnode;
            }
            else
            {
                trv_ptr->right = newnode;
            }
        }
    }
}

void delete_word(string key)
{
    node* trv_ptr = root;
    while(trv_ptr->left!=NULL || trv_ptr->right!=NULL)
        {
            if(key<trv_ptr->key && trv_ptr->left!=NULL)
            {
                trv_ptr = trv_ptr->left;
                

            }
            else if(key>trv_ptr->key && trv_ptr->right!=NULL)
            {
                trv_ptr = trv_ptr->right;
                dixn++;
            }
            else
            {
                cout<<"Duplicate word! Meaning updated\n";
                trv_ptr->value = value;
                flag=1;
                break;
            }
        }

}

int main()
{
    
    return 0;
}