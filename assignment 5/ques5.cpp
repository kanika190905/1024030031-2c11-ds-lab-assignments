#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

Node* getIntersection(Node* headA, Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    int diff = abs(lenA - lenB);
    if (lenA > lenB)
        while (diff--) headA = headA->next;
    else
        while (diff--) headB = headB->next;
    while (headA && headB) {
        if (headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

int main() {
    Node* common = new Node(8);
    common->next = new Node(5);

    Node* listA = new Node(4);
    listA->next = new Node(1);
    listA->next->next = common;

    Node* listB = new Node(5);
    listB->next = new Node(6);
    listB->next->next = new Node(1);
    listB->next->next->next = common;

    Node* intersection = getIntersection(listA, listB);
    if (intersection)
        cout << "Intersected at " << intersection->data << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}
