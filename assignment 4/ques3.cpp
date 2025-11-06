#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    queue<int> temp;

    int i = 0;
    while (i != n / 2) {
        temp.push(q.front());
        q.pop();
        i++;
    }


    int j = 0;
    while (j != n / 2) {
        q.push(temp.front());
        temp.pop();

        int el = q.front();
        q.push(el);
        q.pop();

        j++;
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

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
