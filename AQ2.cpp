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

    void insertEnd(int val) {
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

    int countAndDelete(int key) {
        int count = 0;
        // Remove key from head
        while (head != NULL && head->data == key) {
            Node* t = head;
            head = head->next;
            delete t;
            count++;
        }
        // Remove from rest
        Node* temp = head;
        while (temp != NULL && temp->next != NULL) {
            if (temp->next->data == key) {
                Node* t = temp->next;
                temp->next = t->next;
                delete t;
                count++;
            } else {
                temp = temp->next;
            }
        }
        return count;
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
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(1);
    list.insertEnd(3);
    list.insertEnd(1);

    cout << "Original List: ";
    list.display();

    int count = list.countAndDelete(1);
    cout << "Count: " << count << endl;

    cout << "Updated List: ";
    list.display();
}
