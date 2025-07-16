#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,x,m; cin>>n>>x>>m;
        int p1 = x, p2 = x;
        for(int i = 0; i<m; i++){
            int l,r; cin>>l>>r;
            if(r>=p1 and l<=p2)
            {
                p1 = min(p1,l);    
                p2 = max(p2,r);
            }
        }
        cout<<p2-p1+1<<endl;
    }
}

// TC - O(t*m)
// SC - O(1)