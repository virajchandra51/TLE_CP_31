#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int m = (n * (n - 1)) / 2;

        vector<int> v(m); //! array b
        for(int i = 0; i < m; i++) cin>>v[i]; //? O(m)

        sort(v.begin(), v.end()); //? O(m log m)

        int x = n-1, i = 0;

        while(x > 0) {
            cout<<v[i]<<" ";

            i += x;
            x--;
        } //? O(n)

        cout<<"1000000000\n";
    }

    return 0;
}

//! Total time complexity : O(m log m)
//! Total space complexity : O(m)