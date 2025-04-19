#include <bits/stdc++.h>

using namespace std;

vector<int> findMax3(vector<int> &arr) {
    vector<pair<int, int>> tmp(arr.size());

    for(int i = 0; i < tmp.size(); i++) { //? (val, ind)
        tmp[i].first = arr[i];
        tmp[i].second = i;
    }

    sort(tmp.rbegin(), tmp.rend()); //* O(N log N)

    vector<int> ans(3);

    for(int i = 0; i < 3; i++) ans[i] = tmp[i].second;

    return ans;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<int> a(n), b(n), c(n);

        for(int i = 0; i < n; i++) cin>>a[i]; //* O(N)
        for(int i = 0; i < n; i++) cin>>b[i]; //* O(N)
        for(int i = 0; i < n; i++) cin>>c[i]; //* O(N)

        vector<int> maxa = findMax3(a); //* O(N log N)
        vector<int> maxb = findMax3(b);
        vector<int> maxc = findMax3(c);


        int ans = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 3; k++) {
                    int x = maxa[i], y = maxb[j], z = maxc[k];

                    if((x == y) or (y == z) or (z == x)) continue;

                    ans = max(ans, a[x] + b[y] + c[z]); //* O(1)
                }
            }
        } //* O(3^3) -> O(1)

        cout<<ans<<endl;
    }
}


//* Total time complexity -> O(N log N)
//* Space Complexity -> O(N)