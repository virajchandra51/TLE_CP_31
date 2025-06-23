#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n), b(n), diff(n);
        int maxDiff = INT_MIN;
        for(int i = 0; i < n; i++) { //O(n)
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) { //O(n)
            cin >> b[i];
            diff[i] = a[i] - b[i];
            maxDiff = max(maxDiff, diff[i]);
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) { //O(n)
            if(diff[i] == maxDiff) {
                ans.push_back(i + 1); // Store 1-based index
            }
        }
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++) { //O(n)
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}

// TC = O(n)
// SC = O(n)