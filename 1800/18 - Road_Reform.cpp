#include<bits/stdc++.h> 
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define x first
#define y second
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frn for(int i=0;i<n;i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
template <typename T>istream&operator>>(istream& in, vector<T>& a){for (int i = 0; i < a.size(); ++i)in >> a[i];return in;}
template <typename T>ostream&operator<<(ostream& out,vector<T>& a){for (int i = 0; i < a.size(); ++i) out << a[i] << " ";out << "\n";return out;}

#ifdef AKLOCAL
#include "dbg.hpp"
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#define endl '\n'
#endif

class dsu_chan
{
    /*
        tc: 
            O(n a(n)) amortized
            O(n log(n)) for rollbackable

        info:
            par[u] stores leader of u
            siz[u] stores size of component with leader u

        modify:
            to make rollbackable, we do not make modifications in get() [which makes the get() function O(log(N))] 
            and store change info in unite()
    */
public:
    int n;
    vector<int> par;
    vector<int> siz;
    dsu_chan(int n) : n(n), par(n), siz(n, 1)
    {
        iota(par.begin(), par.end(), 0);
    };
    
    int get(int x)
    {
        return (par[x] == x ? x : par[x] = get(par[x]));
    }

    void unite(int x, int y)
    {
        x = get(x), y = get(y);
        if(x == y)
            return;
        if(siz[x] > siz[y]) swap(x, y);
        par[x] = y, siz[y] += siz[x];
    }

    vector<vector<int>> group()
    {
        vector<vector<int>> g(n);
        for(int u = 0; u < n; u ++)
            g[get(u)].push_back(u);
        return g;
    }
};

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;

    vector<pair<int,pair<int,int>>> el(m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        int c;
        cin>>c;
        el[i]={c,{a,b}};
    }
    sort(all(el));
    auto el1=el;
    vector<pair<int,pair<int,int>>>el2;
    for(int i=0;i<m;i++)
    {
        el1[i].x=max(0ll,el[i].x-k);
    }
    
    for(int i=0;i<m;i++)
    {   
        if(el[i].x<=k)
        {
            el2.push_back({k-el[i].x,{el[i].y}});
        }
    }   
    int ans1=0, ans2=1e18, ans3=1e18;
    dsu_chan d1(n);
    sort(all(el1));
    for(int i=0;i<m;i++)
    {
        int wt=el1[i].first;
        auto [u,v]=el1[i].y;
        if(wt) ans2=min(ans2,wt);
        if(d1.get(u)!=d1.get(v))
        {
            d1.unite(u,v);
            ans1+=wt;
        }
    }
    dbg(el2);
    if(ans1==0) ans1=ans2;
    int edges=0;
    dsu_chan d2(n);
    sort(all(el2));
    for(int i=0;i<el2.size();i++)
    {
        int wt=el2[i].x;
        auto [u,v]=el2[i].y;
        if(d2.get(u)!=d2.get(v))
        {
            dbg(u,v);
            d2.unite(u,v);
            ans3=min(ans3,wt);
            edges++;
        }
    }
    if(edges==n-1) {}
    else ans3=1e18;
    cout<<min(ans1,ans3)<<endl;
}           

signed main(){
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL); cout.tie(NULL);

    int T = 1;          
    cin>>T;
    for(int i=1;i<=T;i++) solve();

    return 0;
}