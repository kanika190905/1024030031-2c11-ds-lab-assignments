#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int countPairs(vector<int> &arr, int k) {
    int n = arr.size();
    int cnt = 0;
  
    sort(arr.begin(), arr.end());
    int i = 0, j = 0;
  
    while(j < n) {
        
    	if(arr[j] - arr[i] < k) 
        	j++;
        else if(arr[j] - arr[i] > k)
        	i++;
        else {
			int ele1 = arr[i], ele2 = arr[j];
            int cnt1 = 0, cnt2 = 0;
          
            while(j < n && arr[j] == ele2) {
                j++;
                cnt2++;
            }
          
            while(i < n && arr[i] == ele1) {
                i++;
                cnt1++;
            }
          
            if(ele1 == ele2) 
            	cnt += (cnt1 * (cnt1 - 1))/2;
          
            else 
            	cnt += (cnt1 * cnt2);
        }
    }
    return cnt;
}

int main() {
    int temp[] = {1, 3, 5, 2, 2, 6};
    vector<int> arr(temp, temp + 6);   

    int k = 4;

    cout << countPairs(arr, k);
    return 0;
}