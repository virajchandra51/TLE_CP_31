#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<int> v(n);
        for(int i = 0; i < n; i++) cin>>v[i]; //? O(n)

        if(v.size() == 1) {
            cout<<"1\n";
            continue;
        }

        vector<int> ans;
        ans.push_back(v[0]);
        ans.push_back(v[1]);

        for(int i = 2; i < n; i++) { //? O(n)
            int currSize = ans.size();

            int x = ans[currSize - 2] - ans[currSize - 1];
            int y = ans[currSize - 1] - v[i]; 

            if(x > 0) {
                if(y > 0) ans[currSize - 1] = v[i];
                else if(y < 0) ans.push_back(v[i]);
            }
            else {
                if(y < 0) ans[currSize - 1] = v[i];
                else if(y > 0) ans.push_back(v[i]);
            }
        }

        int finalSize = ans.size();
        if(ans[0] == ans[1]) finalSize--;

        cout<<finalSize<<"\n";
    }
}

//? Total time complexity : O(N)
//? Total space complexity : O(N)