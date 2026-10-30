#include<bits/stdc++.h>
using namespace std;

struct node
{
    string title;
    string artist;
    node* next=NULL;
};
    //initialise front=0
    node* front=NULL;
void add_song(string title, string artist)
{
    //create a new node
    node* newnode = new node;
    newnode->title=title;
    newnode->artist=artist;
    if(front==NULL)
    {
        front = newnode;
    }
    else
    {
        node* trv_ptr = front;
        while(trv_ptr->next!=NULL)
        {
            trv_ptr = trv_ptr->next;
        }
        trv_ptr->next=newnode;
    }
    cout<<"\nSong added successfully\n";
}

void remove_song(string title)
{
    node* trv_ptr=front;
    while(trv_ptr->next->title!=title)
    {
        trv_ptr=trv_ptr->next;
    }
    if(trv_ptr==NULL) //song not present
    {
        cout<<"Song not present!\n";
    }
    else
    {
        node* store_ptr=trv_ptr->next;
        trv_ptr->next=trv_ptr->next->next;
        cout<<"\nSong "<<store_ptr->title<<" removed!\n";
        delete store_ptr;
    }
}

void display()
{
    if(front==NULL) //no song present
    {
        cout<<"\nPlaylist empty!\n";
    }
    else
    {
        node* trv_ptr=front;
        cout<<"\nPlaylist\n";
        while(trv_ptr!=NULL)
        {
            cout<<trv_ptr->title<<"\n";
            trv_ptr=trv_ptr->next;
        }
    }
}

void play_song(string title)
{
    if(front==NULL)
    {
        cout<<"\nPLAylist empty!\n";
    }
    else
    {
        node* trv_ptr=front;
        while(trv_ptr->title!=title)
        {
            trv_ptr=trv_ptr->next;
        }
        if(trv_ptr==NULL)
        {
            cout<<"\nSong not found in the playlist\n";
        }
        else
        {
            cout<<"PLaying "<<trv_ptr->title<<"\n";
        }
    }
}
int main()
{
    while(choice!=5)
    {
        cout<<"\nMusic Player\n";
    cout<<"1.Add song\n";
    cout<<"2.Remove song\n";
    cout<<"3.Display entire playlist\n";
    cout<<"4.Play specific song\n";
    cout<<"5.Exit\n";
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1: cout<<"\nEnter song name: ";
                string title;
                cin>>title;
                cout<<"\nEnter artist name: ";
                string artist;
                cin>>artist;
                add_song(title,artist);
                break;

        case 2: cout<<"\nEnter song name: ";
                string title;
                cin>>title;
                remove_song(title);
                break;

        case 3: display();
                break;
        
        case 4: cout<<"\nEnter song name: ";
                string title;
                cin>>title;
                play_song(title);
                break;

        case 5: cout<<"\nProgram exited!\n";
                break;
        
        default: cout<<"\nEnter valid choice!\n"
    }
    }
    return 0;
}