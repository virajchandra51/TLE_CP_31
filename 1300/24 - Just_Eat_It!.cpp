#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--) {
        int n; cin>>n;
        vector<int> a(n);
        long long sum = 0;
        for(int i=0; i<n; i++){ //O(n)
            cin>>a[i];
            sum += a[i];
        }
        long long maximum_subarray_sum = 0;
        long long current_sum = 0;
        for(int i=0; i<n-1; i++){  //O(n)
            current_sum += a[i];
            if(current_sum < 0) {
                current_sum = 0; 
            }
            maximum_subarray_sum = max(maximum_subarray_sum, current_sum);    
        }
        current_sum = 0;
        for(int i=1; i<n; i++){ //O(n)
            current_sum += a[i];
            if(current_sum < 0) {
                current_sum = 0; 
            }
            maximum_subarray_sum = max(maximum_subarray_sum, current_sum);    
        }
        if(maximum_subarray_sum >= sum) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}

// TC = O(n)
// SC = O(n)