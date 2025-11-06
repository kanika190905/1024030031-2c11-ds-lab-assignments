#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
};

class Polynomial {
    Node* head;
public:
    Polynomial() { head = NULL; }

    void insertTerm(int c, int p) {
        Node* newNode = new Node;
        newNode->coeff = c;
        newNode->pow = p;
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

    static Polynomial add(Polynomial& p1, Polynomial& p2) {
        Polynomial result;
        Node* t1 = p1.head;
        Node* t2 = p2.head;
        while (t1 && t2) {
            if (t1->pow == t2->pow) {
                result.insertTerm(t1->coeff + t2->coeff, t1->pow);
                t1 = t1->next;
                t2 = t2->next;
            } else if (t1->pow > t2->pow) {
                result.insertTerm(t1->coeff, t1->pow);
                t1 = t1->next;
            } else {
                result.insertTerm(t2->coeff, t2->pow);
                t2 = t2->next;
            }
        }
        while (t1) {
            result.insertTerm(t1->coeff, t1->pow);
            t1 = t1->next;
        }
        while (t2) {
            result.insertTerm(t2->coeff, t2->pow);
            t2 = t2->next;
        }
        return result;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->coeff << "x^" << temp->pow;
            if (temp->next && temp->next->coeff >= 0) cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Polynomial p1, p2, result;
    int n1, n2, c, p;

    cout << "Enter number of terms in first polynomial: ";
    cin >> n1;
    cout << "Enter coefficient and power: ";
    for (int i = 0; i < n1; i++) {
        cin >> c >> p;
        p1.insertTerm(c, p);
    }

    cout << "Enter number of terms in second polynomial: ";
    cin >> n2;
    cout << "Enter coefficient and power: ";
    for (int i = 0; i < n2; i++) {
        cin >> c >> p;
        p2.insertTerm(c, p);
    }

    cout << "First Polynomial: ";
    p1.display();
    cout << "Second Polynomial: ";
    p2.display();

    result = Polynomial::add(p1, p2);

    cout << "Resultant Polynomial: ";
    result.display();

    return 0;
}
