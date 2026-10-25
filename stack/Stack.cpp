#include <iostream>
using namespace std;

const int MAX = 100;

class Stack {
    int arr[MAX];
    int topIndex;

public:
    Stack() { topIndex = -1; }

    void push(int value) {
        if (topIndex == MAX - 1) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++topIndex] = value;
        cout << value << " pushed.\n";
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow! Stack is empty.\n";
            return;
        }
        cout << "Popped: " << arr[topIndex--] << '\n';
    }

    void peek() {
        if (topIndex == -1) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top element: " << arr[topIndex] << '\n';
    }

    void display() {
        if (topIndex == -1) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = topIndex; i >= 0; --i)
            cout << arr[i] << ' ';
        cout << '\n';
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- STACK MENU ---\n"
             << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;
            case 2: s.pop(); break;
            case 3: s.peek(); break;
            case 4: s.display(); break;
            case 5: cout << "Exiting.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
