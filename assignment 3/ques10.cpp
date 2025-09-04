#include <iostream>
#include <stack>
using namespace std;

bool isStackSortable(int A[], int N) {
    stack<int> S;
    int expected = 1;

    for (int i = 0; i < N; i++) {
        while (!S.empty() && S.top() == expected) {
            S.pop();
            expected++;
        }

        if (A[i] == expected) {
            expected++;
        } else {
            if (!S.empty() && S.top() < A[i]) {
                return false;
            }
            S.push(A[i]);
        }
    }

    while (!S.empty()) {
        if (S.top() != expected) return false;
        S.pop();
        expected++;
    }

    return true;
}

int main() {
    
    int test1[] = {4, 1, 3, 2};
    int test2[] = {5, 1, 2, 4, 3};
    
    if (isStackSortable(test1, 4))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    if (isStackSortable(test2, 5))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
