#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* prev;
    Node* next;
    Node(string data) {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

void insertAtEnd(Node*& head, Node*& tail, string data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteAllOccurrences(Node*& head, Node*& tail, string value) {
    Node* curr = head;
    while (curr) {
        if (curr->data == value) {
            Node* toDelete = curr;
            if (curr->prev) curr->prev->next = curr->next;
            else head = curr->next;
            if (curr->next) curr->next->prev = curr->prev;
            else tail = curr->prev;
            curr = curr->next;
            delete toDelete;
        } else {
            curr = curr->next;
        }
    }
}

int countElements(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int countOccurrences(Node* head, string value) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        if (temp->data == value) count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int choice;
    string movie;

    do {
        cout << "\n1. Add Movie\n2. Display List\n3. Delete All Occurrences\n4. Count Movies\n5. Count Occurrences\n0. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Enter movie name: ";
                getline(cin, movie);
                insertAtEnd(head, tail, movie);
                break;
            case 2:
                cout << "Movie List: ";
                display(head);
                break;
            case 3:
                cout << "Enter movie name to delete: ";
                getline(cin, movie);
                deleteAllOccurrences(head, tail, movie);
                cout << "All occurrences deleted.\n";
                break;
            case 4:
                cout << "Total movies: " << countElements(head) << endl;
                break;
            case 5:
                cout << "Enter movie name to count: ";
                getline(cin, movie);
                cout << "Occurrences: " << countOccurrences(head, movie) << endl;
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}