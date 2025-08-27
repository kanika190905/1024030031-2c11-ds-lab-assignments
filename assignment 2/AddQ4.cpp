#include <iostream>
#include <vector>
using namespace std;

void sort012(vector<int> &arr) {
    int n = arr.size();
    
    int low = 0;
    int high = n - 1;
    int mid = 0;
    
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low++], arr[mid++]);
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high--]);
        }
    }
}

int main() {
    int temp[]={ 0, 1, 2, 0, 1, 2 };
    vector<int> arr(temp,temp+6);  
    int n = arr.size();
    
    sort012(arr); 

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}