#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<string> generateBinary(int n) {   
    vector<string> res;
    queue<string> q;

    q.push("1");

    for (int i = 0; i < n; i++) {
        string s1 = q.front();
        q.pop();
        res.push_back(s1);

        string s2 = s1; 

        q.push(s1 + "0");

        q.push(s2 + "1");
    }
    return res;
}

int main() {
    int n = 6;

    vector<string> res = generateBinary(n);
    
    for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
}

    
    cout << "\n";
    return 0;
}
