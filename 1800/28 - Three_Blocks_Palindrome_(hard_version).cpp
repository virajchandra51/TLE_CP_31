#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; if(!(cin>>T)) return 0;
    while(T--){
        int n; cin>>n;
        vector<int>a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];

        const int MAXV = 200;
        vector<vector<int>> pos(MAXV+1);
        for(int i=1;i<=n;i++) pos[a[i]].push_back(i);

        // prefix counts: pref[v][i] = occurrences of v in a[1..i]
        vector<vector<int>> pref(MAXV+1, vector<int>(n+1,0));
        for(int v=1; v<=MAXV; ++v)
            for(int i=1;i<=n;++i)
                pref[v][i] = pref[v][i-1] + (a[i]==v);

        int ans = 1; // at least one element
        // baseline: take only middle block (no outer pairs)
        for(int v=1; v<=MAXV; ++v) ans = max(ans, pref[v][n]);

        // try making k pairs of value x on both sides
        for(int x=1; x<=MAXV; ++x){
            int cnt = (int)pos[x].size();
            for(int k=1; k*2<=cnt; ++k){
                int L = pos[x][k-1] + 1;
                int R = pos[x][cnt-k] - 1;
                if(L>R){
                    continue;
                }
                int mid_max = 0;
                for(int v=1; v<=MAXV; ++v){
                    int cur = pref[v][R] - pref[v][L-1];
                    if(cur>mid_max) mid_max = cur;
                }
                ans = max(ans, 2*k + mid_max);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}

/*
Time Complexity:
Overall: O(MAXV * n) per test case.

Space Complexity:
 - O(MAXV * n).
*/