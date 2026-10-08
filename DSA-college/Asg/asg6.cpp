#include<bits/stdc++.h>
using namespace std;

struct Node
{
    string name;
    Node* next;
};

Node* rear = NULL;

void customerArrival(string name)
{
    Node* newNode = new Node;
    newNode->name = name;

    if (rear == NULL)
    {
        rear = newNode;
        newNode->next = rear;
    }
    else
    {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }
    cout << name << " joined the queue."<<endl;
}

void customerCheckout()
{
    if (rear == NULL)
    {
        cout << "Queue is empty.\n";
        return;
    }

    Node* front = rear->next;
    cout << front->name << " is checking out.\n";

    if (front == rear)
    {
        rear = NULL;
    }
    else
    {
        rear->next = front->next;
    }
    delete front;
}

void closeCounter()
{
    if (rear == NULL)
    {
        cout << "Counter is already empty.\n";
        return;
    }

    Node* front = rear->next;
    Node* temp = front;

    cout << "\nRemaining customers:\n";

    do
    {
        cout << temp->name << endl;
        temp = temp->next;

    } while (temp != front);

    temp = front;

    while (temp != rear)
    {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    delete rear;
    rear = NULL;
    cout << "Checkout counter closed. Queue cleared.\n";
}

void viewCustomer()
{
    if (rear == NULL)
    {
        cout << "Queue is empty.\n";
        return;
    }
    Node* front = rear->next;
    cout << "Customer at front: " << front->name << endl;
}

void display()
{
    if (rear == NULL)
    {
        cout << "Queue is empty.\n";
        return;
    }
    Node* temp = rear->next;
    cout << "Customers in queue: ";

    do
    {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != rear->next);
    cout << endl;
}
int main()
{
    int choice;
    string name;

    do
    {
        cout << "\n--CHECKOUT--\n";
        cout << "1. Customer Arrival\n";
        cout << "2. Customer Checkout\n";
        cout << "3. Close Checkout Counter\n";
        cout << "4. View Customer\n";
        cout << "5. Display All Customers\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter customer name: ";
                cin >> name;
                customerArrival(name);
                break;

            case 2:
                customerCheckout();
                break;

            case 3:
                closeCounter();
                break;

            case 4:
                viewCustomer();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);
    return 0;
}