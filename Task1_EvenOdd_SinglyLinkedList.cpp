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

class Singly {
public:
    Node* head;
    Node* tail;

    Singly() {
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL)
                cout << "->";
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }

    void separateEvenOdd() {
        if (head == NULL)
            return;

        Node* evenHead = NULL;
        Node* evenTail = NULL;
        Node* oddHead = NULL;
        Node* oddTail = NULL;

        Node* temp = head;

        while (temp != NULL) {
            if (temp->data % 2 == 0) {
                if (evenHead == NULL) {
                    evenHead = temp;
                    evenTail = temp;
                } else {
                    evenTail->next = temp;
                    evenTail = temp;
                }
            } else {
                if (oddHead == NULL) {
                    oddHead = temp;
                    oddTail = temp;
                } else {
                    oddTail->next = temp;
                    oddTail = temp;
                }
            }
            temp = temp->next;
        }

        if (evenHead == NULL) {
            oddTail->next = NULL;
            head = oddHead;
            tail = oddTail;
            return;
        }

        if (oddHead == NULL) {
            evenTail->next = NULL;
            head = evenHead;
            tail = evenTail;
            return;
        }

        evenTail->next = oddHead;
        oddTail->next = NULL;

        head = evenHead;
        tail = oddTail;
    }
};

int main() {
    Singly list;

    list.insertAtEnd(17);
    list.insertAtEnd(15);
    list.insertAtEnd(8);
    list.insertAtEnd(12);
    list.insertAtEnd(10);
    list.insertAtEnd(5);
    list.insertAtEnd(4);
    list.insertAtEnd(1);
    list.insertAtEnd(7);
    list.insertAtEnd(6);

    cout << "Original list: ";
    list.display();

    list.separateEvenOdd();

    cout << "After separating even and odd: ";
    list.display();

    return 0;
}
