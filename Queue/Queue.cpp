#include <iostream>
using namespace std;

const int MAX = 100;

class Queue {
    int arr[MAX];
    int frontIndex, rearIndex;

public:
    Queue() : frontIndex(0), rearIndex(-1) {}

    bool isEmpty() const { return rearIndex < frontIndex; }
    bool isFull() const { return rearIndex == MAX - 1; }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full.\n";
            return;
        }
        arr[++rearIndex] = value;
        cout << value << " inserted.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Removed: " << arr[frontIndex++] << '\n';
        if (frontIndex > rearIndex) {
            frontIndex = 0;
            rearIndex = -1;
        }
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front to rear): ";
        for (int i = frontIndex; i <= rearIndex; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- QUEUE MENU ---\n"
             << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 4: cout << "Exiting.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
