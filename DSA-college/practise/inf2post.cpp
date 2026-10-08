#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    node* next=NULL;
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
    else if(op=='*'||op=='/')
    return 2;
    else if(op=='+'||op=='-')
    return 1;
    else
    return 0;
}

string infix2postfix(string infix)
{
    string postfix="";
    for(int i=0;i<infix.length();i++)
    {
        char ch = infix[i];
        if(isalnum(ch)) //character directly into postfix
        {
            postfix+=ch;
        }
        else if(ch=='(') //opening bracket push into stack
        {
            push(ch);
        }
        else if(ch==')') //pop all unitl we find opening bracket and add to postfix
        {
            while(top!=NULL && top->data!='(')
            {
                postfix+=pop();
            }
            pop(); //to remove '('
        }
        else //for operator
        {
            while(top!=NULL && top->data!='(' && (precedence(top->data)>precedence(ch) || (precedence(top->data)==precedence(ch) && ch!='^')))
            {
                postfix+=pop(); //pop operators into postfix
            }
            push(ch);
        }
    }

        while(top!=NULL) //remaining operators
        {
            postfix+=pop();
        }
    return postfix;
}

string infix2prefix(string infix)
{
    string rev="";
    for(int i=infix.length()-1;i>=0;i--)
    {
        char ch = infix[i];
        if(ch=='(')
        {
            rev+=')';
        }
        else if(ch==')')
        {
            rev+='(';
        }
        else
        {
            rev+=ch;
        }
    }
    //got my rev string
    
    string postfix="";
    for(int i=0;i<rev.length();i++)
    {
        char ch = rev[i];
        if(isalnum(ch)) //character directly into postfix
        {
            postfix+=ch;
        }
        else if(ch=='(') //opening bracket push into stack
        {
            push(ch);
        }
        else if(ch==')') //pop all unitl we find opening bracket and add to postfix
        {
            while(top!=NULL && top->data!='(')
            {
                postfix+=pop();
            }
            pop(); //to remove '('
        }
        else //for operator
        {
            while(top!=NULL && top->data!='(' && (precedence(top->data)>precedence(ch) || (precedence(top->data)==precedence(ch) && ch=='^')))
            {
                postfix+=pop(); //pop operators into postfix
            }
            push(ch);
        }
    }
     while(top!=NULL) //remaining operators
        {
            postfix+=pop();
        }
    //got my postfix, now reverse it

    string prefix="";
    for(int i=postfix.length()-1;i>=0;i--)
    {
        prefix+=postfix[i];
    }
    return prefix;
}

int evaluate_postfix(string postfix)
{
    for(int i=0;i<postfix.length();i++)
    {
        char ch=postfix[i];
        if(isdigit(ch))
        {
            push(ch-'0');
        }
        else
        {
            int b = pop();
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
    return pop();
}

int evaluate_prefix(string postfix)
{
    for(int i=postfix.length()-1;i>=0;i--)
    {
        char ch=postfix[i];
        if(isdigit(ch))
        {
            push(ch-'0');
        }
        else
        {
            int a = pop();
            int b = pop();

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
    return pop();
}


int main()
{
    
    return 0;
}
