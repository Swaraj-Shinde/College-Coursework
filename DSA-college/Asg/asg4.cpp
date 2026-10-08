#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    node* next = NULL;
};
node* top = NULL;

void push(char ch)
{
    node* newnode = new node;
    newnode->data = ch;
    newnode->next = top;
    top = newnode;
}

char pop()
{
    node* store_ptr = top;
    char value = top->data;
    top = top->next;
    delete store_ptr;
    return value;
}

int precedence(char op)
{
    if(op=='^')
    return 3;
    else if(op=='*' || op=='/')
    return 2;
    else if(op=='+' || op=='-')
    return 1;
    else
    return 0;
}

string infix2postfix(string infix)
{
    string postfix = "";
    for(int i=0;i<infix.length();i++)
    {
        char ch = infix[i];

        if(isalnum(ch)) //character
        {
            postfix+=ch;
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while(top!=NULL && top->data!='(')
            {
                postfix+=pop();
            }
            pop();//to remove (
        }
        else //operator
        {
            while(top!=NULL && top->data!='(' && (precedence(top->data)>precedence(ch) || precedence(top->data)==precedence(ch) && ch!='^'))
            {
                postfix+=pop();
            }
            push(ch);
        }
    }

    //now pop remaining operators
    while(top!=NULL)
    {
        postfix+=pop();
    }
    return postfix;
}

string infix2prefix(string infix)
{
    string rev = "";
    for(int i=infix.length()-1;i>=0;i--)
    {
        if(infix[i]=='(')
        {
            rev+=')';
        }
        else if(infix[i]==')')
        {
            rev+='(';
        }
        else
        {   
            rev+=infix[i];
        }   
    }
    //now apply postfix on reverse string rev
    string postfix="";
    for(int i=0;i<rev.length();i++)
    {
        char ch = rev[i];
        if(isalnum(ch))
        {
            postfix+=ch;
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while(top!=NULL && top->data!='(')
            {
                postfix+=pop();
            }
            pop(); //to remove opening bracket;
        }
        else //for operator
        {
            while(top!=NULL && top->data!='(' && (precedence(top->data)>precedence(ch)||precedence(top->data)==precedence(ch) && ch=='^'))
            {
                postfix+=pop();
            }
            push(ch);
        }
    }
//pop remaining operators
while(top!=NULL)
{
    postfix+=pop();
}

//now reverse postfix to get prefix
string prefix="";
for(int i = postfix.length()-1;i>=0;i--)
{
    prefix+=postfix[i];
}
return prefix;
}

int evaluate_postfix(string postfix)
{
    for(int i=0;i<postfix.length();i++)
    {
        char ch = postfix[i];
        if(isdigit(ch)) //number
        {
            push(ch-'0');
        }
        else //operator
        {
            //i need two operands
            int b = pop(); //order imp
            int a = pop();

            if(ch=='+')
            push(a+b);
            else if(ch=='-')
            push(a-b);
            else if(ch=='*')
            push(a*b);
            else if(ch=='/')
            push(a/b);
            else
            push(pow(a,b));
        }
    }
    return pop(); //finally only one number so pop out
}

int evaluate_prefix(string prefix) //just scan string in reverse
{
    for(int i=prefix.length()-1;i>=0;i--)
    {
        char ch=prefix[i];

        if(isdigit(ch))
        {
            push(ch-'0'); //convert from char to int
        }
        else //operator
        {
            int a=pop();
            int b=pop();
            if(ch=='+')
            push(a+b);
            else  if(ch=='-')
            push(a-b);
            else  if(ch=='*')
            push(a*b);
            else if(ch=='/')
            push(a/b);
            else
            push(pow(a,b));
        }   
    }
    //at last pop the result
    return pop();
}

int main()
{
    int choice;
    do
    {       
        cout<<"--MENU--"<<endl;
        cout<<"1.Infix to Postfix conversion"<<endl;
        cout<<"2.Infix to Prefix conversion"<<endl;
        cout<<"3.Postfix evaluation"<<endl;
        cout<<"4.Prefix evaluation"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        string infix,postfix,prefix;
        switch(choice)
        {
            case 1: 
                    cout<<"Enter infix: ";
                    cin>>infix;
                    cout<<"Postfix: "<<infix2postfix(infix)<<endl;
                    cout<<endl;
                    break;

            case 2: 
                    cout<<"Enter infix: ";
                    cin>>infix;
                    cout<<"Prefix: "<<infix2prefix(infix)<<endl; 
                    cout<<endl;  
                    break;
                    
            case 3: 
                    cout<<"Enter postfix: ";
                    cin>>postfix;
                    cout<<"Postfix: "<<evaluate_postfix(postfix)<<endl;
                    cout<<endl;
                    break;
            
            case 4: 
                    cout<<"Enter prefix: ";
                    cin>>prefix;
                    cout<<"Prefix: "<<evaluate_prefix(prefix)<<endl; 
                    cout<<endl;
                    break;  
                    
            case 5: return 0;
            
            default: cout<<"Invalid choice!"<<endl;
            break;
        }           
    }while(choice!=5);
    return 0;
}