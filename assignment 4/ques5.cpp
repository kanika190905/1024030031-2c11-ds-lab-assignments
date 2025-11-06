#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << q1.front() << " popped\n";
        q1.pop();
    }
    void top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << q1.front() << "\n";
    }
    void display() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        queue<int> temp = q1;
        cout << "Stack elements: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "\n";
    }
};

class StackOneQueue {
    queue<int> q;
public:
    void push(int x) {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << q.front() << " popped\n";
        q.pop();
    }
    void top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << q.front() << "\n";
    }
    void display() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        queue<int> temp = q;
        cout << "Stack elements: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "\n";
    }
};

int main() {
    StackTwoQueues s1;
    StackOneQueue s2;
    int choice, val, type;
    cout << "Choose Stack Implementation:\n1. Using Two Queues\n2. Using One Queue\n";
    cin >> type;
    do {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                if (type == 1) s1.push(val); else s2.push(val);
                break;
            case 2:
                if (type == 1) s1.pop(); else s2.pop();
                break;
            case 3:
                if (type == 1) s1.top(); else s2.top();
                break;
            case 4:
                if (type == 1) s1.display(); else s2.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);
    return 0;
}
