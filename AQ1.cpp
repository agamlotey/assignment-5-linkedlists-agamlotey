#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = NULL; }

    void insertAtBeginning(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp != NULL && temp->data != key) temp = temp->next;
        if (temp == NULL) return;
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void insertBefore(int key, int val) {
        if (head == NULL) return;
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key) temp = temp->next;
        if (temp->next == NULL) return;
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void deleteFromBeginning() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void deleteFromEnd() {
        if (head == NULL) return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }
    void deleteValue(int key) {
        if (head == NULL) return;
        if (head->data == key) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key) temp = temp->next;
        if (temp->next == NULL) return;
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
    void searchValue(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Not found" << endl;
    }
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, val, key;

    while (1) {
        cout << "\n1.Insert Beg\n2.Insert End\n3.Insert After\n4.Insert Before\n5.Delete Beg\n6.Delete End\n7.Delete Specific\n8.Search\n9.Display\n10.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cin >> val; list.insertAtBeginning(val); break;
            case 2: cin >> val; list.insertAtEnd(val); break;
            case 3: cin >> key >> val; list.insertAfter(key, val); break;
            case 4: cin >> key >> val; list.insertBefore(key, val); break;
            case 5: list.deleteFromBeginning(); break;
            case 6: list.deleteFromEnd(); break;
            case 7: cin >> key; list.deleteValue(key); break;
            case 8: cin >> key; list.searchValue(key); break;
            case 9: list.display(); break;
            case 10: return 0;
        }
    }
}