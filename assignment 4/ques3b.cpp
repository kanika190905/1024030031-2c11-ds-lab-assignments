#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueueUsingStack(queue<int>& q) {
    int n = q.size();
    stack<int> st;

    int i = 0;
    while (i != n / 2) {
        st.push(q.front());
        q.pop();
        i++;
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    int j = 0;
    while (j != n / 2) {
        q.push(q.front());
        q.pop();
        j++;
    }

    i = 0;
    while (i != n / 2) {
        st.push(q.front());
        q.pop();
        i++;
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;

    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    interleaveQueueUsingStack(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
