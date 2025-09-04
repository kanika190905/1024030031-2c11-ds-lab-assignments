#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
private:
    stack<int> s;
    int minEle;

public:
    SpecialStack() {
        minEle = -1;
    }

    void push(int x) {
        if (s.empty()) {
            minEle = x;
            s.push(x);
        } else if (x < minEle) {
            s.push(2 * x - minEle);
            minEle = x;
        } else {
            s.push(x);
        }
    }

    void pop() {
        if (s.empty()) return;
        int top = s.top();
        s.pop();
        if (top < minEle) {
            minEle = 2 * minEle - top;
        }
    }

    int peek() {
        if (s.empty()) return -1;
        int top = s.top();
        return (top < minEle) ? minEle : top;
    }

    int getMin() {
        if (s.empty()) return -1;
        return minEle;
    }
};

int main() {
    SpecialStack ss;
    ss.push(12);
    ss.push(15);
    cout << ss.peek() << endl;
    ss.pop();
    cout << ss.getMin() << endl;
    ss.push(10);
    cout << ss.getMin() << endl;
    return 0;
}
