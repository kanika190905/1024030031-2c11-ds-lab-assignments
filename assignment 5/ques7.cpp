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

    void createLoop(int pos) {
        if (pos == 0) return;
        Node* loopNode = head;
        Node* temp = head;
        int count = 1;
        while (count < pos && loopNode) {
            loopNode = loopNode->next;
            count++;
        }
        while (temp->next)
            temp = temp->next;
        temp->next = loopNode;
    }

    void removeLoop() {
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (slow != fast) return;
        slow = head;
        if (slow == fast) {
            while (fast->next != slow)
                fast = fast->next;
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
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
    int n, val, pos;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }
    cout << "Enter position to create loop (0 for no loop): ";
    cin >> pos;
    list.createLoop(pos);
    list.removeLoop();
    cout << "Linked list after removing loop: ";
    list.display();
    return 0;
}
