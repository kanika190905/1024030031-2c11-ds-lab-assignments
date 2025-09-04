#include <iostream>
#include <stack>
using namespace std;

int* prevSmaller(int* A, int n1, int *len1) {
    int* G = new int[n1];  
    stack<int> st;

    for (int i = 0; i < n1; i++) {
        int current = A[i];

        while (!st.empty() && st.top() >= current) {
            st.pop();
        }

        if (st.empty()) {
            G[i] = -1;
        } else {
            G[i] = st.top();
        }

        st.push(current);
    }

    *len1 = n1;  
    return G;
}

int main() {
    int A[] = {4, 5, 2, 10, 8};
    int n = 5;
    int len;

    int* G = prevSmaller(A, n, &len);

    cout << "Output: ";
    for (int i = 0; i < len; i++)
        cout << G[i] << " ";
    cout << endl;

    delete[] G;  
    return 0;
}
