#include <iostream>
#include <string>
using namespace std;

// Singly Linked List Node
struct SNode
{
    int id;
    string name, food;
    SNode *next;
};

// Doubly Linked List Node
struct DNode
{
    int id;
    string name, food;
    DNode *prev, *next;
};

// Circular Linked List Node
struct CNode
{
    int id;
    string name, food;
    CNode *next;
};

SNode *sHead = NULL;
DNode *dHead = NULL;
CNode *cHead = NULL;

// Input order details
void inputOrder(int &id, string &name, string &food)
{
    cout << "Enter Order ID: ";
    cin >> id;

    cout << "Enter Student Name: ";
    cin >> name;

    cout << "Enter Food Item: ";
    cin >> food;
}

// ================= SINGLY LINKED LIST =================

// Insert at beginning
void sInsertBeginning()
{
    SNode *n = new SNode;

    inputOrder(n->id, n->name, n->food);

    n->next = sHead;
    sHead = n;

    cout << "Order added successfully!\n";
}

// Insert at end
void sInsertEnd()
{
    SNode *n = new SNode;

    inputOrder(n->id, n->name, n->food);
    n->next = NULL;

    if (sHead == NULL)
    {
        sHead = n;
    }
    else
    {
        SNode *t = sHead;

        while (t->next != NULL)
            t = t->next;

        t->next = n;
    }

    cout << "Order added successfully!\n";
}

// Display orders
void sDisplay()
{
    SNode *t = sHead;

    if (t == NULL)
    {
        cout << "No orders found!\n";
        return;
    }

    while (t != NULL)
    {
        cout << "\nOrder ID: " << t->id
             << "\nStudent: " << t->name
             << "\nFood: " << t->food << endl;

        t = t->next;
    }
}

// Search order
void sSearch()
{
    int id;
    cout << "Enter Order ID to search: ";
    cin >> id;

    SNode *t = sHead;

    while (t != NULL)
    {
        if (t->id == id)
        {
            cout << "Order Found: "
                 << t->name << " - " << t->food << endl;
            return;
        }

        t = t->next;
    }

    cout << "Order not found!\n";
}

// Delete order
void sDelete()
{
    int id;
    cout << "Enter Order ID to delete: ";
    cin >> id;

    SNode *t = sHead, *p = NULL;

    while (t != NULL && t->id != id)
    {
        p = t;
        t = t->next;
    }

    if (t == NULL)
    {
        cout << "Order not found!\n";
        return;
    }

    if (p == NULL)
        sHead = t->next;
    else
        p->next = t->next;

    delete t;
    cout << "Order deleted successfully!\n";
}

// ================= DOUBLY LINKED LIST =================

// Insert at end
void dInsertEnd()
{
    DNode *n = new DNode;

    inputOrder(n->id, n->name, n->food);
    n->prev = NULL;
    n->next = NULL;

    if (dHead == NULL)
    {
        dHead = n;
    }
    else
    {
        DNode *t = dHead;

        while (t->next != NULL)
            t = t->next;

        t->next = n;
        n->prev = t;
    }

    cout << "Order added successfully!\n";
}

// Insert at beginning
void dInsertBeginning()
{
    DNode *n = new DNode;

    inputOrder(n->id, n->name, n->food);

    n->prev = NULL;
    n->next = dHead;

    if (dHead != NULL)
        dHead->prev = n;

    dHead = n;

    cout << "Order added successfully!\n";
}

// Forward traversal
void dForward()
{
    DNode *t = dHead;

    if (t == NULL)
    {
        cout << "No orders found!\n";
        return;
    }

    while (t != NULL)
    {
        cout << "\nOrder ID: " << t->id
             << "\nStudent: " << t->name
             << "\nFood: " << t->food << endl;

        t = t->next;
    }
}

// Backward traversal
void dBackward()
{
    DNode *t = dHead;

    if (t == NULL)
    {
        cout << "No orders found!\n";
        return;
    }

    while (t->next != NULL)
        t = t->next;

    while (t != NULL)
    {
        cout << "\nOrder ID: " << t->id
             << "\nStudent: " << t->name
             << "\nFood: " << t->food << endl;

        t = t->prev;
    }
}

// Search order
void dSearch()
{
    int id;
    cout << "Enter Order ID to search: ";
    cin >> id;

    DNode *t = dHead;

    while (t != NULL)
    {
        if (t->id == id)
        {
            cout << "Order Found: "
                 << t->name << " - " << t->food << endl;
            return;
        }

        t = t->next;
    }

    cout << "Order not found!\n";
}

// Delete order
void dDelete()
{
    int id;
    cout << "Enter Order ID to delete: ";
    cin >> id;

    DNode *t = dHead;

    while (t != NULL && t->id != id)
        t = t->next;

    if (t == NULL)
    {
        cout << "Order not found!\n";
        return;
    }

    if (t->prev != NULL)
        t->prev->next = t->next;
    else
        dHead = t->next;

    if (t->next != NULL)
        t->next->prev = t->prev;

    delete t;
    cout << "Order deleted successfully!\n";
}

// ================= CIRCULAR LINKED LIST =================

// Insert at end
void cInsertEnd()
{
    CNode *n = new CNode;

    inputOrder(n->id, n->name, n->food);

    if (cHead == NULL)
    {
        cHead = n;
        n->next = cHead;
    }
    else
    {
        CNode *t = cHead;

        while (t->next != cHead)
            t = t->next;

        t->next = n;
        n->next = cHead;
    }

    cout << "Order added successfully!\n";
}

// Insert at beginning
void cInsertBeginning()
{
    CNode *n = new CNode;

    inputOrder(n->id, n->name, n->food);

    if (cHead == NULL)
    {
        cHead = n;
        n->next = cHead;
    }
    else
    {
        CNode *t = cHead;

        while (t->next != cHead)
            t = t->next;

        n->next = cHead;
        t->next = n;
        cHead = n;
    }

    cout << "Order added successfully!\n";
}

// Circular traversal
void cDisplay()
{
    if (cHead == NULL)
    {
        cout << "No orders found!\n";
        return;
    }

    CNode *t = cHead;

    do
    {
        cout << "\nOrder ID: " << t->id
             << "\nStudent: " << t->name
             << "\nFood: " << t->food << endl;

        t = t->next;

    } while (t != cHead);
}

// Search order
void cSearch()
{
    if (cHead == NULL)
    {
        cout << "No orders found!\n";
        return;
    }

    int id;
    cout << "Enter Order ID to search: ";
    cin >> id;

    CNode *t = cHead;

    do
    {
        if (t->id == id)
        {
            cout << "Order Found: "
                 << t->name << " - " << t->food << endl;
            return;
        }

        t = t->next;

    } while (t != cHead);

    cout << "Order not found!\n";
}

// Delete order
void cDelete()
{
    if (cHead == NULL)
    {
        cout << "No orders found!\n";
        return;
    }

    int id;
    cout << "Enter Order ID to delete: ";
    cin >> id;

    CNode *t = cHead, *p = NULL;

    do
    {
        if (t->id == id)
            break;

        p = t;
        t = t->next;

    } while (t != cHead);

    if (t->id != id)
    {
        cout << "Order not found!\n";
        return;
    }

    // Only one node
    if (t->next == t)
    {
        delete t;
        cHead = NULL;
    }
    else
    {
        if (t == cHead)
        {
            CNode *last = cHead;

            while (last->next != cHead)
                last = last->next;

            cHead = cHead->next;
            last->next = cHead;
        }
        else
        {
            p->next = t->next;
        }

        delete t;
    }

    cout << "Order deleted successfully!\n";
}

// ================= MAIN MENU =================

int main()
{
    int mainChoice, choice;

    do
    {
        cout << "\n=== Canteen Order Processing ===\n";
        cout << "1. Singly Linked List\n";
        cout << "2. Doubly Linked List\n";
        cout << "3. Circular Linked List\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> mainChoice;

        if (mainChoice == 1)
        {
            do
            {
                cout << "\n--- Singly Linked List ---\n";
                cout << "1. Insert at Beginning\n";
                cout << "2. Insert at End\n";
                cout << "3. Display Orders\n";
                cout << "4. Search Order\n";
                cout << "5. Delete Order\n";
                cout << "6. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> choice;

                switch (choice)
                {
                    case 1: sInsertBeginning(); break;
                    case 2: sInsertEnd(); break;
                    case 3: sDisplay(); break;
                    case 4: sSearch(); break;
                    case 5: sDelete(); break;
                    case 6: break;
                    default: cout << "Invalid choice!\n";
                }

            } while (choice != 6);
        }
        else if (mainChoice == 2)
        {
            do
            {
                cout << "\n--- Doubly Linked List ---\n";
                cout << "1. Insert at Beginning\n";
                cout << "2. Insert at End\n";
                cout << "3. Forward Traversal\n";
                cout << "4. Backward Traversal\n";
                cout << "5. Search Order\n";
                cout << "6. Delete Order\n";
                cout << "7. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> choice;

                switch (choice)
                {
                    case 1: dInsertBeginning(); break;
                    case 2: dInsertEnd(); break;
                    case 3: dForward(); break;
                    case 4: dBackward(); break;
                    case 5: dSearch(); break;
                    case 6: dDelete(); break;
                    case 7: break;
                    default: cout << "Invalid choice!\n";
                }

            } while (choice != 7);
        }
        else if (mainChoice == 3)
        {
            do
            {
                cout << "\n--- Circular Linked List ---\n";
                cout << "1. Insert at Beginning\n";
                cout << "2. Insert at End\n";
                cout << "3. Display Orders\n";
                cout << "4. Search Order\n";
                cout << "5. Delete Order\n";
                cout << "6. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> choice;

                switch (choice)
                {
                    case 1: cInsertBeginning(); break;
                    case 2: cInsertEnd(); break;
                    case 3: cDisplay(); break;
                    case 4: cSearch(); break;
                    case 5: cDelete(); break;
                    case 6: break;
                    default: cout << "Invalid choice!\n";
                }

            } while (choice != 6);
        }
        else if (mainChoice == 4)
        {
            cout << "Thank you!\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }

    } while (mainChoice != 4);

    return 0;
}
