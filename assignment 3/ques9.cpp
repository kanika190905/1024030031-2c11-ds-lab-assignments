#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int> &T) {
    int n = T.size();
    vector<int> res(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && T[i] > T[st.top()]) {
            int idx = st.top();
            st.pop();
            res[idx] = i - idx;
        }
        st.push(i);
    }

    return res;
}

int main() {
    int arr[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> T(arr, arr + n);  

    vector<int> res = dailyTemperatures(T);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
