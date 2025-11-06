#include <iostream>
#include <queue>
#include <string>
using namespace std;

string firstNonRepeating(string s) {
    int count[26] = {0};   
    queue<char> q;         
    string ans = "";

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        q.push(ch);
        count[ch - 97]++;

        while (!q.empty() && count[q.front() - 97] > 1) {
            q.pop();
        }

        if (q.empty()) {
            ans.push_back('-');
            ans.push_back('1');
            ans.push_back(' ');  
        } 
         else {
        ans.push_back(q.front());
        ans.push_back(' ');
       }

    }

    return ans;
}

int main() {
    string s1 = "aabc";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << firstNonRepeating(s1) << endl;

    string s2 = "abadbc";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << firstNonRepeating(s2) << endl;

    return 0;
}
