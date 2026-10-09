#include <iostream>
using namespace std;

struct Node
{
    int orderID;
    string studentName;
    string foodItem;
    Node *next;
};

Node *head = NULL;

// Insert order at beginning
void insertBeginning()
{
    Node *newNode = new Node;

    cout << "Enter Order ID: ";
    cin >> newNode->orderID;

    cout << "Enter Student Name: ";
    cin >> newNode->studentName;

    cout << "Enter Food Item: ";
    cin >> newNode->foodItem;

    newNode->next = head;
    head = newNode;

    cout << "Order added successfully!\n";
}

// Insert order at end
void insertEnd()
{
    Node *newNode = new Node;

    cout << "Enter Order ID: ";
    cin >> newNode->orderID;

    cout << "Enter Student Name: ";
    cin >> newNode->studentName;

    cout << "Enter Food Item: ";
    cin >> newNode->foodItem;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Order added successfully!\n";
}

// Display pending orders
void displayOrders()
{
    if (head == NULL)
    {
        cout << "No pending orders!\n";
        return;
    }

    Node *temp = head;

    cout << "\n--- Pending Orders ---\n";

    while (temp != NULL)
    {
        cout << "Order ID: " << temp->orderID << endl;
        cout << "Student Name: " << temp->studentName << endl;
        cout << "Food Item: " << temp->foodItem << endl;
        cout << "----------------------\n";

        temp = temp->next;
    }
}

// Search order
void searchOrder()
{
    int id;
    cout << "Enter Order ID to search: ";
    cin >> id;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->orderID == id)
        {
            cout << "Order Found!\n";
            cout << "Student Name: " << temp->studentName << endl;
            cout << "Food Item: " << temp->foodItem << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Order not found!\n";
}

// Delete completed order
void deleteOrder()
{
    int id;

    cout << "Enter completed Order ID: ";
    cin >> id;

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL && temp->orderID != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Order not found!\n";
        return;
    }

    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;

    cout << "Completed order deleted successfully!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n=== Smart Canteen Order Management ===\n";
        cout << "1. Insert Order at Beginning\n";
        cout << "2. Insert Order at End\n";
        cout << "3. Display Pending Orders\n";
        cout << "4. Search Order\n";
        cout << "5. Delete Completed Order\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                displayOrders();
                break;

            case 4:
                searchOrder();
                break;

            case 5:
                deleteOrder();
                break;

            case 6:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
