#include <bits/stdc++.h>
using namespace std;
#define ll long long  
#define pll pair<ll,ll>
#define vi vector<ll> 
#define vll vector<ll> 
#define vpll vector<pair<ll,ll> >
#define vvll vector<vector<ll> > 
#define pb push_back
#define fs first
#define s second
#define sz(x) (ll)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ld long double
#define f(i, a, b) for (ll i = (a); i < (b); i++)
#define fr(i, a, b) for (ll i = (a); i >= (b); i--)
#define yay(a) if(a)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define mpll map<ll,ll>
#define umpll unordered_map<ll,ll>
#define nl cout<<endl;
#define int long long
ll md = 998244353, mx = 1e6 + 7, pr = 29, m9 = 1e9 + 7;

pair<bool,bool> dfs(int node, int par, vvll& g, vll& maxx, bool& ok){
    if(g[node].size()==1) return {1,0};
    int count=0;
    bool eve=0,odd=0;
    for(auto& xx : g[node]){
        if(xx==par) continue;
        auto it=  dfs(xx,node,g,maxx,ok);
        eve |= it.fs;
        odd |= it.s;
        if(g[xx].size()==1) count++;
    }
    if(eve&odd) ok=1;
    if(count) maxx.pb(count);
    return {odd,eve};
}
int32_t main() {
    ios;
    int n;
    cin>>n;
    vvll g(n+1);
    int str=-1;
    f(i,1,n){
        int x,y;
        cin>>x>>y;
        g[x].pb(y); g[y].pb(x);
        if(g[x].size()>=2) str =x;
        if(g[y].size()>=2) str= y;
    }
    bool ok=0;
    vll maxx;
    auto pp = dfs(str,-1,g,maxx,ok);
    auto sum = accumulate(all(maxx),0ll);
    cout<<(ok ? 3 : 1)<<" "<< n-1 -sum + maxx.size()<<endl;
    return 0;
}