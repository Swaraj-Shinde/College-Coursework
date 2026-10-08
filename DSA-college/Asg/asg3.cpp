#include<bits/stdc++.h>
using namespace std;

class node
{
  public: string data; //name or url of the page
          node* next;
           
          node(string d) //parameterized constructor
          {
            data=d;
            next=NULL;
          }
};

class history
{
 private: node* top; //top pointer of stack
          node* current; //pointer to show current position 
 
 public: history()
         {
          top=NULL; 
          current=NULL;
         }
         
         void add_page(string s)
         {
          node* newnode = new node(s);
          if(top==NULL)
          {
            top=newnode;
            current=newnode;
            cout<<"Page: "<<s<<" added!"<<endl;
          }
          else
          {
          	newnode->next = top;
            top = newnode;
            current = newnode;
            cout<<"Page: "<<s<<" added!"<<endl;
          }
         }
           
         void navigate_back(int pos)
         {
            if(top==NULL)
            {
                cout<<"Page not found!"<<endl;
            }
            else{
          node* trv_ptr = top; //used to count no.of pages everytime
          int no_of_pages = 0;
          while(trv_ptr!=NULL)
          {
            trv_ptr = trv_ptr->next;
            no_of_pages++;
          }
          if(pos>=no_of_pages)
          {
            cout<<"Page not found!"<<endl;
            return;
          }
          else
          {
            trv_ptr = top;
            for(int i=0;i<pos;i++)
            {
                trv_ptr = trv_ptr->next;
            }
            current = trv_ptr;
            cout<<"Navigated back by "<<pos<<endl;
          }
         }
        }

        void view_current_page()
        {
            if(current==NULL)
            {
                cout<<"Page not found!"<<endl;
            }
            else
            {
                cout<<"Current page: "<<current->data<<endl;
            }
        }

        void check()
        {
            if(top==NULL)
            {
                cout<<"History is empty!"<<endl;
            }
            else
            {
                cout<<"History is present!"<<endl;
            }
        }             
};

int main()
{
    history h;
    int choice,pos;
    string s;
    do
    {
    cout<<"\n--History--"<<endl;
    cout<<"1.Add visited page"<<endl;
    cout<<"2.Navigate back"<<endl;
    cout<<"3.View current page"<<endl;
    cout<<"4.Check if history is empty or not"<<endl;
    cout<<"5.Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    
    switch(choice)
    {
        case 1: cout<<"Enter page: ";
                cin>>s;
                h.add_page(s);
                break;
                
        case 2: cout<<"Enter position: ";
                cin>>pos;
                h.navigate_back(pos);
                break;
                
        case 3: h.view_current_page(); 
        break;
        
        case 4: h.check();
        break;

        case 5: return 0;

        default: cout<<"Error!"<<endl; 
        break;
    }
    }
    while(choice!=5);
  return 0;
}
