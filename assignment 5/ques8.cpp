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

    void insertAtEnd(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void rotateLeft(int k) {
        if (!head || k == 0) return;
        Node* temp = head;
        int len = 1;
        while (temp->next) {
            temp = temp->next;
            len++;
        }
        temp->next = head;
        k = k % len;
        for (int i = 0; i < k; i++)
            head = head->next;
        Node* newTail = head;
        for (int i = 1; i < len; i++)
            newTail = newTail->next;
        newTail->next = NULL;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }
};

int main() {
    LinkedList list;
    int n, val, k;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }
    cout << "Enter k: ";
    cin >> k;
    cout << "Original list: ";
    list.display();
    list.rotateLeft(k);
    cout << "List after left rotation by " << k << ": ";
    list.display();
    return 0;
}
