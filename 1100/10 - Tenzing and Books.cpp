#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> pre[3];
        for (int i = 0; i < 3; i++) {//n*3
            int s = 0;
            pre[i].push_back(s);
            for (int j = 0; j < n; j++) {
                int a;
                cin >> a;
                if ((s | a) != s){
                    s |= a;
                    pre[i].push_back(s);
                }
            }
        }
        bool ans = 0;
        for (int A : pre[0]){//(31^3)
            for (int B : pre[1]) {
                for (int C : pre[2]){
                    if((A | B | C )== x){
                        ans=true;
                    }
                }
            }
        } 
            
        cout << (ans ? "YES\n" : "NO\n");
    }
    // T.C :- max(3*n,(31^3))
    // S.C :- 3*31
}