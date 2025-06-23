#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--) {
        int n, x, y;
        cin>>n>>x>>y;
        vector<int> a(n, 0);
        map<int, vector<int>> mp;

        for(int i = 0; i<n; i++){ //O(nLogn)
            cin>>a[i];
            mp[a[i]%y].push_back(a[i]); //O(logn)
        }

        long long int ans = 0;
        for(auto it: mp){
            vector<int> v = it.second;
            map<int, long long int> mp1;
            for(int i = 0; i<v.size(); i++){ //O(nlogn)
                mp1[v[i]%x]++;
            }

            for(auto it: mp1){ //O(nlogn)
                if(it.first == 0 || (it.first ==x/2 and x%2 == 0)){
                    long long int cnt = it.second;
                    ans += (cnt * (cnt - 1)) / 2; // Combination of pairs
                    it.second = 0;
                } else {
                    long long int cnt1 = it.second;
                    long long int cnt2 = mp1[x - it.first];
                    ans += cnt1 * cnt2; // Pairs from different remainders
                    mp1[x - it.first] = 0; // Avoid double counting
                }
            }
        }
        cout<<ans<<endl;
    }
}


// TC = O(nlogn)
// SC = O(n)