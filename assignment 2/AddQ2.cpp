#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string str1, string str2) {
    return str2.find(str1) != string::npos;
}

bool checkPossible(string str) {
    int n = str.length();

    for (int i = 1; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string part1 = str.substr(0, i);
            string part2 = str.substr(i, j - i);
            string part3 = str.substr(j);

            if ((isSubstring(part1, part2) && isSubstring(part1, part3)) ||
                (isSubstring(part2, part1) && isSubstring(part2, part3)) ||
                (isSubstring(part3, part1) && isSubstring(part3, part2))) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    
        string str;
        getline(cin,str);

        if (checkPossible(str)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    
    return 0;
}