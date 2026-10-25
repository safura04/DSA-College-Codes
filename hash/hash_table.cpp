#include <iostream>
using namespace std;

const int SIZE = 10;
const int EMPTY = -1;

class HashTable {
    int table[SIZE];

    int hashFunction(int key) const {
        int index = key % SIZE;
        if (index < 0) index += SIZE;
        return index;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; ++i) table[i] = EMPTY;
    }

    void insert(int key) {
        int start = hashFunction(key);
        for (int step = 0; step < SIZE; ++step) {
            int index = (start + step) % SIZE;
            if (table[index] == EMPTY) {
                table[index] = key;
                cout << "Inserted " << key << " at index " << index << ".\n";
                return;
            }
            if (table[index] == key) {
                cout << "Duplicate key already exists.\n";
                return;
            }
        }
        cout << "Hash table is full; cannot insert " << key << ".\n";
    }

    void search(int key) const {
        int start = hashFunction(key);
        for (int step = 0; step < SIZE; ++step) {
            int index = (start + step) % SIZE;
            if (table[index] == EMPTY) {
                cout << "Key not found.\n";
                return;
            }
            if (table[index] == key) {
                cout << "Key found at index " << index << ".\n";
                return;
            }
        }
        cout << "Key not found.\n";
    }

    void display() const {
        cout << "\nIndex\tValue\n";
        for (int i = 0; i < SIZE; ++i) {
            cout << i << "\t";
            if (table[i] == EMPTY) cout << "EMPTY";
            else cout << table[i];
            cout << '\n';
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\n--- HASH TABLE (LINEAR PROBING) ---\n"
             << "1. Insert key\n2. Search key\n3. Display table\n4. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter integer key (-1 is reserved as EMPTY): ";
                cin >> key;
                if (key == EMPTY)
                    cout << "-1 is reserved; choose another key.\n";
                else
                    ht.insert(key);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                ht.search(key);
                break;
            case 3: ht.display(); break;
            case 4: cout << "Exiting.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
