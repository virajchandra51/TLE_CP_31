#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        map<int,int> mp; // Map to store prime factors and their counts
        for(int i=0; i<n; i++) { //O(n root(a[i]))
            for(int j = 2; j*j <= a[i]; j++) { // root(a[i])
                while(a[i] % j == 0) {
                    mp[j]++;
                    a[i] /= j;
                }
            }
            // 13
            if(a[i] > 1) {
                mp[a[i]]++;
            }
        }
        int flag = 1;
        for(auto it : mp) { // 
            if(it.second % n != 0) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

// TC = O(n*root(a[i]))
// SC = O(n)