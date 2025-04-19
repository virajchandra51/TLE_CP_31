#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>weight(n);//N
    for(int i=0;i<n;i++){//n
        cin>>weight[i];
    }
    vector<int>suffix_sum(n);//N
    map<int,int>index;//N
    int sum=0;
    for(int i=n-1;i>=0;i--){//nlogn
        sum+=weight[i];
        index[sum]=i;
        suffix_sum[i]=sum;
    }
    int ans=0;
    int prefix_sum=0;
    for(int i=0;i<n;i++){//nlogn
        index.erase(suffix_sum[i]);
        prefix_sum+=weight[i];
        if(index.find(prefix_sum)!=index.end()){
            ans=max(ans,(i+1)+(n-index[prefix_sum]));
        }
    }
    cout<<ans<<endl;
    // T.C:- O(NlogN)
    // S.C :- O(N)
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
}

 