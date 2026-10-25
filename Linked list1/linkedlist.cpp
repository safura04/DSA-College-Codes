#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(NULL) {}
};

class LinkedList {
    Node* head;

public:
    LinkedList() : head(NULL) {}

    void insertBeginning(int value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
        cout << "Inserted at beginning.\n";
    }

    void insertEnd(int value) {
        Node* node = new Node(value);
        if (head == NULL) {
            head = node;
        } else {
            Node* current = head;
            while (current->next != NULL)
                current = current->next;
            current->next = node;
        }
        cout << "Inserted at end.\n";
    }

    void deleteBeginning() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Deleted: " << temp->data << '\n';
        head = head->next;
        delete temp;
    }

    void display() const {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* current = head;
        cout << "List: ";
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    ~LinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\n--- SINGLY LINKED LIST ---\n"
             << "1. Insert at beginning\n2. Insert at end\n"
             << "3. Delete from beginning\n4. Display\n5. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertEnd(value);
                break;
            case 3: list.deleteBeginning(); break;
            case 4: list.display(); break;
            case 5: cout << "Exiting.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
