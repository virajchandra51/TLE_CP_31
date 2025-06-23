#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++)
    cin>>v[i];
    vector<long long int> prefixEven(n,0), prefixOdd(n,0);
    // 10^9*10^5 = 10^14
    prefixEven[0] = v[0];
    int flag = 0;
    map<long long int,int> mp;
    mp[prefixOdd[0]-prefixEven[0]]++;
    for(int i=1; i<n; i++){ //O(n)
        // carry forward the old values
        prefixOdd[i]+=prefixOdd[i-1];
        prefixEven[i]+=prefixEven[i-1];

        if (i%2) prefixOdd[i]+=v[i];
        else prefixEven[i]+=v[i];

        mp[prefixOdd[i]-prefixEven[i]]++; // O(log n)
        if (mp[prefixOdd[i]-prefixEven[i]]==2 || prefixOdd[i]-prefixEven[i]==0){
            flag=1;break;
        }
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

// TC = O(nlogn)
// SC = O(n)

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}