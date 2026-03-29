#include <bits/stdc++.h>
using namespace std;

bool check(long long H,long long W, vector<pair<int,int>> a){
    multiset<pair<int,int>> sh, sw;

    for(auto &p:a){
        sh.insert({p.first,p.second});
        sw.insert({p.second,p.first});
    }

    while(!sh.empty()){
        auto itw = prev(sw.end());
        auto ith = prev(sh.end());

        if(itw->first == W){
            int h = itw->second;
            sw.erase(itw);
            sh.erase(sh.find({h,W}));
            H -= h;
        }
        else if(ith->first == H){
            int w = ith->second;
            sh.erase(ith);
            sw.erase(sw.find({w,H}));
            W -= w;
        }
        else return false;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;

        vector<pair<int,int>> a(n);
        long long area=0;
        int maxh=0,maxw=0;

        for(int i=0;i<n;i++){
            cin>>a[i].first>>a[i].second;
            area += 1LL*a[i].first*a[i].second;
            maxh=max(maxh,a[i].first);
            maxw=max(maxw,a[i].second);
        }

        vector<pair<long long,long long>> ans;

        if(area%maxw==0){
            long long h=area/maxw;
            if(check(h,maxw,a)) ans.push_back({h,maxw});
        }

        if(area%maxh==0){
            long long w=area/maxh;
            if(check(maxh,w,a)) ans.push_back({maxh,w});
        }

        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());

        cout<<ans.size()<<"\n";
        for(auto &p:ans)
            cout<<p.first<<" "<<p.second<<"\n";
    }
}

// TC : O(nlogn)
// SC : O(n)