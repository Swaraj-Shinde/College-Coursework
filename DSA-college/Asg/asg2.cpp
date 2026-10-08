#include<bits/stdc++.h>
using namespace std;

class node
{
 public: string data; //to store character
         node* prev; //to store prev node
         node* next; //to store next node
         
         node(string s) //parameterised constructor to initialise node
         {
           data=s;
           prev=next=NULL;
         }
};

class TextEditor
{
  private: node* head;
           node* tail;
           
  public: TextEditor() //default constructor to initialised head and tail
          { 
           head=tail=NULL;
          }         
          
          void insert_at_beg(string s)
          {
           node* newnode = new node(s); 
           if(head==NULL)
           {
            head=tail=newnode;
           }
           else
           {
             newnode->next = head;
             head->prev = newnode;
             head=newnode;
           }
          }
          
          void insert_at_end(string s)
          {
          node* newnode = new node(s);
           if(tail==NULL)
           {
            head=tail=newnode;
           }
           else
           {
             tail->next = newnode;
             newnode->prev = tail;
             tail = newnode;
           }
          }
          
          void insert_at_pos(int pos,string s)
          {  
           if(pos==1)
           {
            insert_at_beg(s);
           }
           else
           {
             node* newnode = new node(s);
             node* trv_ptr = head;
             int counter=1;
             while(trv_ptr->next!=NULL)
             {
              trv_ptr = trv_ptr->next;
              counter++;
             }
             
             if(pos==counter+1)
             {
              insert_at_end(s);
             }
             
             else if(pos>1 && pos<=counter)
             {
              node* trvl_ptr = head;
              for(int i=2;i<=pos;i++)
              {
               trvl_ptr = trvl_ptr->next; //pointer will go at desired location
              }
              
              newnode->prev = trvl_ptr->prev;
              newnode->next = trvl_ptr->prev->next;
              trvl_ptr->prev->next = newnode;
              trvl_ptr->prev = newnode;
             }
             else
             {
               cout<<"Invalid position!"<<endl;

             }
           }
          }
          
          void delete_at_beg()
          {
            if(head==NULL)
            {
              cout<<"No text found!\n";
            }
            else
            {
              node* store_ptr = head; //to store first element
              head = head->next; 
              delete store_ptr;
            } 
          }
          
          void delete_at_end()
          {
            if(head==NULL)
            {
              cout<<"No text found!\n";
            }
            else
            {
              node* store_ptr = tail; //to store last element
              tail = tail->prev;
              tail->next = NULL; 
              delete store_ptr;
            }  
          }
          
          void delete_at_pos(int pos)
          {
            if(head==NULL)
            {
              cout<<"No text found!\n";
            }
            else
            {
              int counter=1;
              node* trv_ptr = head;
              while(trv_ptr->next!=NULL)
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
              else if(pos>1 && pos<counter)
              {
              node* trv_ptr = head;
 
               for(int i=2;i<pos;i++)
               {
                  trv_ptr = trv_ptr->next;
               }
               
               node* store_ptr = trv_ptr->next;
               trv_ptr->next = store_ptr->next;
               store_ptr->next->prev = trv_ptr;
               delete store_ptr;
              }
            }
          }
          
          void display()
          {
           if(head==NULL)
           {
            cout<<"No text found!\n";
           }
           else
           {
            node* trv_ptr = head;
            while(trv_ptr!=NULL)
            {
              cout<<trv_ptr->data<<" ";
              trv_ptr = trv_ptr->next;
            }
            cout<<"\n";
           }
          }
          
          void search_text(string text)
          {
            if(head==NULL)
            {
             cout<<"No text found!";
            }
            else
            {
              node* trv_ptr = head;
              int position=1,flag=0;
            
            while(trv_ptr!=NULL)
            {
              if(trv_ptr->data==text)
              {
                cout<<"Text found at position: "<<position<<endl;
                flag=1;
                trv_ptr = trv_ptr->next;
                
              }
              else
              {
                trv_ptr = trv_ptr->next;
              }
            }
            if(flag==0)
            {
             cout<<"No text found!\n";
            }
            }
          }
          
          void print_text_rev()
          {
            if(head==NULL)
            {
             cout<<"No text found!\n";
            }
            else
            {
             node* rev_trv_ptr = tail;
             while(rev_trv_ptr!=NULL)
             {
              cout<<rev_trv_ptr->data<<" ";
              rev_trv_ptr = rev_trv_ptr->prev;
             }
             cout<<endl;
            }
          }
};

int main()
{
 TextEditor obj;
 int choice,pos;
 string s,text;
 
 do{

 cout<<"\n--TEXT EDITOR--\n";
 cout<<"1.Insert at beginning\n";
 cout<<"2.Insert at end\n";
 cout<<"3.Insert at position\n";
 cout<<"4.Delete at beginning\n";
 cout<<"5.Delete at end\n";
 cout<<"6.Delete at position\n";
 cout<<"7.Display text\n";
 cout<<"8.Search text\n";
 cout<<"9.Print text in reverse\n";
 cout<<"10.Exit\n";
 cout<<"Enter choice: ";
 cin>>choice;
 
 switch(choice)
 {
  case 1: cout<<"Enter text: ";
          cin>>s;
          obj.insert_at_beg(s);
          cout<<"Inserted at beginning!\n";
          break;
          
  case 2: cout<<"Enter text: ";
          cin>>s;
          obj.insert_at_end(s);
          cout<<"Inserted at end!\n";
          break;
          
  case 3: cout<<"Enter pos: ";
          cin>>pos;
          cout<<"Enter text: ";
          cin>>s;
          obj.insert_at_pos(pos,s);
          break;
          
  case 4: obj.delete_at_beg();
          cout<<"Deleted at beginning!\n";
          break;   
          
  case 5: obj.delete_at_end();
          cout<<"Deleted at end!\n";
          break;  
          
  case 6: cout<<"Enter position: ";
          cin>>pos;
          obj.delete_at_pos(pos);
          cout<<"Deleted at position "<<pos<<"\n";
          break;                       
          
   case 7: obj.display();
           break;
           
   case 8: cout<<"Enter text to search: ";
           cin>>text;
           obj.search_text(text);
           break;
           
   case 9: obj.print_text_rev();
           break;
   
   case 10: return 0;

   default: cout<<"Invalid choice!";
            break; 
 }
 }
 while(choice!=10);
 
  return 0;
}
