#include <iostream>
#include <algorithm>
using namespace std;

string checkAnagram(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return "NO";
    }
    
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    if (str1 == str2) {
        return "YES";
    }
    return "NO";
}

int main() {
    
        string str1, str2;
        getline(cin,str1);
        getline(cin,str2);
        cout << checkAnagram(str1, str2) << endl;
    
    
    return 0;
}