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
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertBefore(int key, int val) {
        if (head == NULL) return;
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key)
            temp = temp->next;
        if (temp->next == NULL) return;
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) return;
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
        while (temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteSpecific(int key) {
        if (head == NULL) return;
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key)
            temp = temp->next;
        if (temp->next == NULL) return;
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Not found\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    LinkedList list;
    int choice, val, key;
    do {
        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Insert Before\n4. Insert After\n5. Delete from Beginning\n6. Delete from End\n7. Delete Specific Node\n8. Search\n9. Display\n10. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value and key(before which to insert): ";
                cin >> val >> key;
                list.insertBefore(key, val);
                break;
            case 4:
                cout << "Enter value and key(after which to insert): ";
                cin >> val >> key;
                list.insertAfter(key, val);
                break;
            case 5:
                list.deleteFromBeginning();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                cout << "Enter key to delete: ";
                cin >> key;
                list.deleteSpecific(key);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> key;
                list.search(key);
                break;
            case 9:
                list.display();
                break;
            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 10);
    return 0;
}
