#include "bits/stdc++.h"
using namespace std;
int n;

void solve(){
    cin >> n;
    vector<int>b(n / 2), p(n);
    vector<bool>isUsed(n + 1, false);
    set<int>unused;

    for(int i = 0; i < n / 2; i++){
        cin >> b[i];
        p[i * 2 + 1] = b[i];
        isUsed[b[i]] = true;
    }
    for(int i = 1; i <= n; i++){
        if(!isUsed[i]) unused.insert(i);
    }


    if(int(unused.size()) != n / 2){
        cout << "-1\n";
        return;
    }

    for(int i = n / 2 - 1; i >= 0; i--){
        auto k = unused.upper_bound(p[2 * i + 1]);
        if(k == unused.begin()){
            cout << "-1\n";
            return;
        }

        k--;


        if(*k < p[2 * i + 1]){
            p[2 * i] = *k;
            unused.erase(k);
        }
        else{
            cout << "-1\n";
            return;
        }
    }
    for(auto i : p) cout << i << ' ';
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

}

// TC : O(nlogn)
// SC : O(n)