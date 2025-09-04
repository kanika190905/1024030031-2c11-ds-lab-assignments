#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> stk;

    for (int i = n - 1; i >= 0; i--) {

        while (!stk.empty() && stk.top() <= arr[i]) {
            stk.pop();
        }

        if (!stk.empty()) {
            res[i] = stk.top();
        }

        stk.push(arr[i]);
    }

    return res;
}

int main() {

    vector<int> arr;
    arr.push_back(6);
    arr.push_back(8);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(3);

    vector<int> res = nextLargerElement(arr);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}