#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) count++;
        }

        int i = n - 1;
        int j = n + count - 1;

        while (i >= 0 && j >= 0) {
            if (arr[i] != 0) {
                if (j < n) arr[j] = arr[i]; 
                j--;
                i--;
            } else {
                if (j < n) arr[j] = 0;
                j--;
                if (j < n) arr[j] = 0;
                j--;
                i--;
            }
        }
    }
};

int main() {
    int temp[] = {1, 0, 2, 3, 0, 4, 5, 0};
    vector<int> arr(temp, temp + 8);

    cout << "Before: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    Solution s;
    s.duplicateZeros(arr);

    cout << "After:  ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
    
