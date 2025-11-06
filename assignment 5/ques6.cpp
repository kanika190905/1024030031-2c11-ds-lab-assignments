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

    Node* reverseK(Node* head, int k) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        int count = 0;
        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next)
            head->next = reverseK(next, k);
        return prev;
    }

    void reverseInGroups(int k) {
        head = reverseK(head, k);
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << endl;
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
    cout << "Enter K: ";
    cin >> k;
    cout << "Original list: ";
    list.display();
    list.reverseInGroups(k);
    cout << "Reversed in groups of " << k << ": ";
    list.display();
    return 0;
}
