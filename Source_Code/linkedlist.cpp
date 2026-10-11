#include <iostream>
#include <string>
using namespace std;

// Singly Linked List
struct SNode {
    int id;
    string name, food;
    SNode *next;
};

SNode *sHead = NULL;

// Doubly Linked List
struct DNode {
    int id;
    string name, food;
    DNode *prev, *next;
};

DNode *dHead = NULL;

// Circular Linked List
struct CNode {
    int id;
    string name, food;
    CNode *next;
};

// Common input function
void inputOrder(int &id, string &name, string &food) {
    cout << "Enter Order ID: ";
    cin >> id;

    cout << "Enter Student Name: ";
    getline(cin >> ws, name);

    cout << "Enter Food Item: ";
    getline(cin, food);
}

// ================= SINGLY LINKED LIST =================

void sInsertPosition() {
    int pos, id;
    string name, food;

    cout << "Enter position: ";
    cin >> pos;

    if (pos < 1) {
        cout << "Invalid position!\n";
        return;
    }

    inputOrder(id, name, food);

    SNode *n = new SNode{id, name, food, NULL};

    if (pos == 1) {
        n->next = sHead;
        sHead = n;
        cout << "Order inserted successfully.\n";
        return;
    }

    SNode *temp = sHead;

    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Invalid position!\n";
        delete n;
        return;
    }

    n->next = temp->next;
    temp->next = n;

    cout << "Order inserted successfully.\n";
}

void sDisplay() {
    SNode *temp = sHead;

    if (temp == NULL) {
        cout << "List is empty.\n";
        return;
    }

    cout << "\nID\tStudent\t\tFood\n";

    while (temp != NULL) {
        cout << temp->id << "\t"
             << temp->name << "\t\t"
             << temp->food << "\n";
        temp = temp->next;
    }
}

void sSearch() {
    int id;
    cout << "Enter Order ID to search: ";
    cin >> id;

    SNode *temp = sHead;

    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Order Found: "
                 << temp->name << " - "
                 << temp->food << "\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Order not found.\n";
}

void sDeleteID() {
    int id;
    cout << "Enter Order ID to delete: ";
    cin >> id;

    SNode *temp = sHead, *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Order not found.\n";
        return;
    }

    if (prev == NULL)
        sHead = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Order deleted successfully.\n";
}

void sDeletePosition() {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    if (pos < 1 || sHead == NULL) {
        cout << "Invalid position or empty list.\n";
        return;
    }

    SNode *temp = sHead;

    if (pos == 1) {
        sHead = sHead->next;
        delete temp;
        cout << "Order deleted successfully.\n";
        return;
    }

    SNode *prev = NULL;

    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Order deleted successfully.\n";
}

// ================= DOUBLY LINKED LIST =================

void dInsertPosition() {
    int pos, id;
    string name, food;

    cout << "Enter position: ";
    cin >> pos;

    if (pos < 1) {
        cout << "Invalid position!\n";
        return;
    }

    inputOrder(id, name, food);

    DNode *n = new DNode{id, name, food, NULL, NULL};

    if (pos == 1) {
        n->next = dHead;

        if (dHead != NULL)
            dHead->prev = n;

        dHead = n;
        cout << "Order inserted successfully.\n";
        return;
    }

    DNode *temp = dHead;

    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Invalid position!\n";
        delete n;
        return;
    }

    n->next = temp->next;
    n->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = n;

    temp->next = n;

    cout << "Order inserted successfully.\n";
}

void dForward() {
    DNode *temp = dHead;

    if (temp == NULL) {
        cout << "List is empty.\n";
        return;
    }

    cout << "\nForward Traversal:\n";

    while (temp != NULL) {
        cout << temp->id << " - "
             << temp->name << " - "
             << temp->food << "\n";
        temp = temp->next;
    }
}

void dBackward() {
    DNode *temp = dHead;

    if (temp == NULL) {
        cout << "List is empty.\n";
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    cout << "\nBackward Traversal:\n";

    while (temp != NULL) {
        cout << temp->id << " - "
             << temp->name << " - "
             << temp->food << "\n";
        temp = temp->prev;
    }
}

void dSearch() {
    int id;
    cout << "Enter Order ID to search: ";
    cin >> id;

    DNode *temp = dHead;

    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Order Found: "
                 << temp->name << " - "
                 << temp->food << "\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Order not found.\n";
}

void dDeleteID() {
    int id;
    cout << "Enter Order ID to delete: ";
    cin >> id;

    DNode *temp = dHead;

    while (temp != NULL && temp->id != id)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Order not found.\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        dHead = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
    cout << "Order deleted successfully.\n";
}

void dDeletePosition() {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    if (pos < 1 || dHead == NULL) {
        cout << "Invalid position or empty list.\n";
        return;
    }

    DNode *temp = dHead;

    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Invalid position!\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        dHead = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
    cout << "Order deleted successfully.\n";
}

// ================= CIRCULAR LINKED LIST =================

CNode *cHead = NULL;

void cInsertPosition() {
    int pos, id;
    string name, food;

    cout << "Enter position: ";
    cin >> pos;

    if (pos < 1) {
        cout << "Invalid position!\n";
        return;
    }

    inputOrder(id, name, food);

    CNode *n = new CNode{id, name, food, NULL};

    if (cHead == NULL) {
        if (pos != 1) {
            cout << "Invalid position!\n";
            delete n;
            return;
        }

        n->next = n;
        cHead = n;
        cout << "Order inserted successfully.\n";
        return;
    }

    if (pos == 1) {
        CNode *last = cHead;

        while (last->next != cHead)
            last = last->next;

        n->next = cHead;
        last->next = n;
        cHead = n;

        cout << "Order inserted successfully.\n";
        return;
    }

    CNode *temp = cHead;

    for (int i = 1; i < pos - 1 && temp->next != cHead; i++)
        temp = temp->next;

    if (pos > 1 && temp->next == cHead && pos - 1 > 1) {
        cout << "Invalid position!\n";
        delete n;
        return;
    }

    n->next = temp->next;
    temp->next = n;

    cout << "Order inserted successfully.\n";
}

void cDisplay() {
    if (cHead == NULL) {
        cout << "List is empty.\n";
        return;
    }

    CNode *temp = cHead;

    cout << "\nCircular Traversal:\n";

    do {
        cout << temp->id << " - "
             << temp->name << " - "
             << temp->food << "\n";
        temp = temp->next;
    } while (temp != cHead);
}

void cSearch() {
    if (cHead == NULL) {
        cout << "List is empty.\n";
        return;
    }

    int id;
    cout << "Enter Order ID to search: ";
    cin >> id;

    CNode *temp = cHead;

    do {
        if (temp->id == id) {
            cout << "Order Found: "
                 << temp->name << " - "
                 << temp->food << "\n";
            return;
        }
        temp = temp->next;
    } while (temp != cHead);

    cout << "Order not found.\n";
}

void cDeleteID() {
    if (cHead == NULL) {
        cout << "List is empty.\n";
        return;
    }

    int id;
    cout << "Enter Order ID to delete: ";
    cin >> id;

    CNode *temp = cHead, *prev = NULL;

    do {
        if (temp->id == id)
            break;

        prev = temp;
        temp = temp->next;
    } while (temp != cHead);

    if (temp->id != id) {
        cout << "Order not found.\n";
        return;
    }

    if (temp->next == temp) {
        cHead = NULL;
    } else {
        if (temp == cHead) {
            CNode *last = cHead;

            while (last->next != cHead)
                last = last->next;

            cHead = cHead->next;
            last->next = cHead;
        } else {
            prev->next = temp->next;
        }
    }

    delete temp;
    cout << "Order deleted successfully.\n";
}

void cDeletePosition() {
    if (cHead == NULL) {
        cout << "List is empty.\n";
        return;
    }

    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    if (pos < 1) {
        cout << "Invalid position!\n";
        return;
    }

    CNode *temp = cHead;

    if (pos == 1) {
        if (cHead->next == cHead) {
            delete cHead;
            cHead = NULL;
        } else {
            CNode *last = cHead;

            while (last->next != cHead)
                last = last->next;

            CNode *oldHead = cHead;
            cHead = cHead->next;
            last->next = cHead;
            delete oldHead;
        }

        cout << "Order deleted successfully.\n";
        return;
    }

    CNode *prev = NULL;

    for (int i = 1; i < pos && temp->next != cHead; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == cHead || prev == NULL) {
        cout << "Invalid position!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Order deleted successfully.\n";
}

// ================= MAIN MENU =================

int main() {
    int choice, op;

    do {
        cout << "\n===== CANTEEN ORDER PROCESSING =====\n";
        cout << "1. Singly Linked List\n";
        cout << "2. Doubly Linked List\n";
        cout << "3. Circular Linked List\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            do {
                cout << "\n--- SINGLY LINKED LIST ---\n";
                cout << "1. Insert at Beginning/End/Position\n";
                cout << "2. Display\n";
                cout << "3. Search by ID\n";
                cout << "4. Delete by ID\n";
                cout << "5. Delete by Position\n";
                cout << "6. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> op;

                if (op == 1) {
                    int p;
                    cout << "1. Beginning  2. End  3. Position\n";
                    cin >> p;

                    if (p == 1) {
                        cout << "Enter position 1 to insert at beginning.\n";
                        sInsertPosition();
                    } else if (p == 2) {
                        int pos = 1;
                        SNode *t = sHead;
                        while (t != NULL) {
                            pos++;
                            t = t->next;
                        }
                        cout << "Inserting at end (position "
                             << pos << ").\n";
                        // Insert at the calculated end position
                        int id;
                        string name, food;
                        inputOrder(id, name, food);
                        SNode *n = new SNode{id, name, food, NULL};
                        if (sHead == NULL)
                            sHead = n;
                        else {
                            t = sHead;
                            while (t->next != NULL)
                                t = t->next;
                            t->next = n;
                        }
                        cout << "Order inserted successfully.\n";
                    } else if (p == 3) {
                        sInsertPosition();
                    }
                } else if (op == 2) sDisplay();
                else if (op == 3) sSearch();
                else if (op == 4) sDeleteID();
                else if (op == 5) sDeletePosition();

            } while (op != 6);

        } else if (choice == 2) {
            do {
                cout << "\n--- DOUBLY LINKED LIST ---\n";
                cout << "1. Insert at Beginning/End/Position\n";
                cout << "2. Forward Traversal\n";
                cout << "3. Backward Traversal\n";
                cout << "4. Search by ID\n";
                cout << "5. Delete by ID\n";
                cout << "6. Delete by Position\n";
                cout << "7. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> op;

                if (op == 1) {
                    int p;
                    cout << "1. Beginning  2. End  3. Position\n";
                    cin >> p;

                    if (p == 1) {
                        dInsertPosition();
                    } else if (p == 2) {
                        int pos = 1;
                        DNode *t = dHead;
                        while (t != NULL) {
                            pos++;
                            t = t->next;
                        }
                        cout << "Inserting at end (position "
                             << pos << ").\n";
                        int id;
                        string name, food;
                        inputOrder(id, name, food);
                        DNode *n = new DNode{id, name, food, NULL, NULL};
                        if (dHead == NULL)
                            dHead = n;
                        else {
                            t = dHead;
                            while (t->next != NULL)
                                t = t->next;
                            t->next = n;
                            n->prev = t;
                        }
                        cout << "Order inserted successfully.\n";
                    } else if (p == 3) {
                        dInsertPosition();
                    }
                } else if (op == 2) dForward();
                else if (op == 3) dBackward();
                else if (op == 4) dSearch();
                else if (op == 5) dDeleteID();
                else if (op == 6) dDeletePosition();

            } while (op != 7);

        } else if (choice == 3) {
            do {
                cout << "\n--- CIRCULAR LINKED LIST ---\n";
                cout << "1. Insert at Beginning/End/Position\n";
                cout << "2. Display Circular List\n";
                cout << "3. Search by ID\n";
                cout << "4. Delete by ID\n";
                cout << "5. Delete by Position\n";
                cout << "6. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> op;

                if (op == 1) {
                    int p;
                    cout << "1. Beginning  2. End  3. Position\n";
                    cin >> p;

                    if (p == 1 || p == 3) {
                        cInsertPosition();
                    } else if (p == 2) {
                        int pos = 1;
                        if (cHead != NULL) {
                            CNode *t = cHead;
                            do {
                                pos++;
                                t = t->next;
                            } while (t != cHead);
                        }
                        cout << "Inserting at end (position "
                             << pos << ").\n";
                        int id;
                        string name, food;
                        inputOrder(id, name, food);
                        CNode *n = new CNode{id, name, food, NULL};

                        if (cHead == NULL) {
                            n->next = n;
                            cHead = n;
                        } else {
                            CNode *t = cHead;
                            while (t->next != cHead)
                                t = t->next;
                            t->next = n;
                            n->next = cHead;
                        }
                        cout << "Order inserted successfully.\n";
                    }
                } else if (op == 2) cDisplay();
                else if (op == 3) cSearch();
                else if (op == 4) cDeleteID();
                else if (op == 5) cDeletePosition();

            } while (op != 6);
        }

    } while (choice != 4);

    cout << "Program ended.\n";
    return 0;
}
