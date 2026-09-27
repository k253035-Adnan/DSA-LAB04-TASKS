#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularSingly {
public:
    Node* head;
    Node* tail;

    CircularSingly() {
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            tail->next = head; 
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; 
        }
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head; 
        }
    }

    void insertAtPosition(int val, int position) {
        if (position == 1) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        int count = 1;

        while (count < position - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if (temp == tail) {
            tail = newNode; 
        }
    }

    void deleteNode(int val) {
        if (head == NULL)
            return;

        if (head == tail && head->data == val) {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        Node* curr = head;
        Node* prev = tail;

        do {
            if (curr->data == val) {
                prev->next = curr->next;

                if (curr == head)
                    head = curr->next;
                if (curr == tail)
                    tail = prev;

                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }
};

int main() {
    CircularSingly list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    cout << "After inserting 10, 20, 30 at end: ";
    list.display();

    list.insertAtBeginning(5);
    cout << "After inserting 5 at beginning: ";
    list.display();

    list.insertAtPosition(15, 3);
    cout << "After inserting 15 at position 3: ";
    list.display();

    list.deleteNode(20);
    cout << "After deleting node with value 20: ";
    list.display();

    return 0;
}
