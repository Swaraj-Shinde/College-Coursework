#include<bits/stdc++.h>
using namespace std;

struct song
{ 
  string title,artist;
  float duration; //to store as decimals
  song* next; //pointer to store address on next node
};

class playlist
{
  private: song* head; //pointer to store first node
  public:
  playlist() //default constructor
  {
    head=NULL;
  }

  void insert_at_beg()
  {
    song*  newSong = new song;
    cin.ignore(); //ignores newline character
    //so we can use getline func

    cout<<"Enter title: ";
    getline(cin,newSong->title);

    cout<<"Enter artist: ";
    getline(cin,newSong->artist);

    cout<<"Enter duration(min): ";
    cin>>newSong->duration; //getline works with strings

    newSong->next=head;
    head=newSong;
    cout<<"Song added at beginning!"<<endl; 
  }

  void insert_at_end()
  {
    song* newSong = new song;
    cin.ignore();

    cout<<"Enter title: ";
    getline(cin,newSong->title);

    cout<<"Enter artist: ";
    getline(cin,newSong->artist);

    cout<<"Enter duration(min): ";
    cin>>newSong->duration;

    newSong->next=NULL;

    if(head==NULL)
    {
      head=newSong;
    }
    else
    {
        song* trv_ptr = head; //traverse pointer
        while(trv_ptr->next!=NULL)
        {
            trv_ptr=trv_ptr->next;
        }
        trv_ptr->next = newSong;
    }
    cout<<"Song added at end!"<<endl;
  }

  void insert_at_pos()
  {
    int pos,counter=1;
    cin.ignore();
    song* newSong = new song;
    newSong->next=NULL;

    cout<<"Enter title: ";
    getline(cin,newSong->title);

    cout<<"Enter artist: ";
    getline(cin,newSong->artist);

    cout<<"Enter duration(min): ";
    cin>>newSong->duration;

    cout<<"Enter position: ";
    cin>>pos;

    song* trv_ptr = head;
    while(trv_ptr->next!=NULL)
    {
        trv_ptr = trv_ptr->next;
        counter++;
    }

    if(pos==1)
    {
    //cant call insert_at_beg func coz it will take inputs again
     newSong->next=head;
     head=newSong;
     cout<<"Song added at pos "<<pos<<endl;
    }
    else if(pos>1 && pos<=counter+1)
    {
      song* trv_ptr = head;
      for(int i=2;i<pos;i++) //ptr already pointing first node
      //thus start from i=2
      {
        trv_ptr=trv_ptr->next;
      }
      song* store_ptr=trv_ptr->next;
      //it will store address of node at that pos

      trv_ptr->next = newSong;
      newSong->next = store_ptr;
      cout<<"Song added at pos "<<pos<<endl;
    }
    else
    {
        cout<<"Invalid position!"<<endl;
        delete newSong; //release resources
    }
  }

  void delete_at_beg()
  {
    if(head==NULL)
    {
        cout<<"Playlist empty!"<<endl;
    }
    else
    {
        song* store_ptr = head; 
        //to store address of element to be deleted
        head = head->next;
        delete store_ptr;      
    }
    cout<<"Song deleted at beginning!"<<endl;
  }

  void delete_at_end()
  {
    if(head==NULL)
    {
        cout<<"Playlist empty!"<<endl;
    }
    else if(head->next==NULL)
    {
        delete head;
        head=NULL;
    }
    else
    {
    song* trv_ptr = head;
    while(trv_ptr->next->next != NULL)
    {
        trv_ptr = trv_ptr->next;
    }

    song* store_ptr = trv_ptr->next;
    trv_ptr->next = NULL;
    delete store_ptr;
    }
    cout<<"Song deleted at end!"<<endl;
  }

  void delete_at_pos()
  {
    if(head==NULL)
    {
        cout<<"Playlist empty!"<<endl;
    }
    else{
    int pos,counter=1;
    cout<<"Enter position: ";
    cin>>pos;

    song* trv_ptr = head;
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
        song* trv_ptr = head;
        for(int i=2;i<pos;i++)
        {
            trv_ptr = trv_ptr->next;
        }
        song* store_ptr = trv_ptr->next;
        trv_ptr->next = store_ptr->next; //connecting two nodes
        delete store_ptr;
    }
    else
    {
        cout<<"Invalid position!"<<endl;
    }
    }
  }

  void display_playlist()
  {
    if(head==NULL)
    {
        cout<<"Playlist empty!"<<endl;
    }
    else
    {
        cout<<"--PLAYLIST--"<<endl;
        song* trv_ptr = head;
        while(trv_ptr!=NULL)
        {
            cout<<"-----"<<endl;
            cout<<"Title: "<<trv_ptr->title<<endl;
            cout<<"Artist: "<<trv_ptr->artist<<endl;
            cout<<"Duration: "<<trv_ptr->duration<<endl;
            cout<<"-----";
            trv_ptr = trv_ptr->next;
        }
    }
  }

  void search_song()
{
    if(head == NULL)
    {
        cout << "Playlist empty!" << endl;
        return;
    }

    string s;
    int counter = 1;

    cin.ignore();

    cout << "Enter title: ";
    getline(cin, s);

    song* trv_ptr = head;

    while(trv_ptr != NULL && trv_ptr->title != s)
    {
        trv_ptr = trv_ptr->next;
        counter++;
    }

    if(trv_ptr == NULL)
    {
        cout << "Song not in the playlist!" << endl;
    }
    else
    {
        cout << "Song found at position " << counter << endl;
        cout << "Artist   : " << trv_ptr->artist << endl;
        cout << "Duration : " << trv_ptr->duration << " min" << endl;
    }
}
};

int main()
{
    playlist p;
    int choice;
    do
    {
        cout<<"\n--MENU--"<<endl;
        cout<<"1.Add song at beginning"<<endl;
        cout<<"2.Add song at end"<<endl;
        cout<<"3.Add song at position"<<endl;
        cout<<"4.Delete song at beginning"<<endl;
        cout<<"5.Delete song at end"<<endl;
        cout<<"6.Delete song at position"<<endl;
        cout<<"7.Display playlist"<<endl;
        cout<<"8.Search Song"<<endl;
        cout<<"9.Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: p.insert_at_beg();
                    break;

            case 2: p.insert_at_end();
                    break;

            case 3: p.insert_at_pos();
                    break;

            case 4: p.delete_at_beg();
                    break;

            case 5: p.delete_at_end();
                    break;

            case 6: p.delete_at_pos();
                    break;

            case 7: p.display_playlist();
                    break;

            case 8: p.search_song();
                    break;

            case 9: return 0;
            
            default: cout<<"Invalid choice!";
        }
    }
    while(choice!=9);
return 0;
}