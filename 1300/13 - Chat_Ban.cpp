#include<bits/stdc++.h>>
using namespace std;

long long calculateSumOfFirstX(int x) {
    return x * 1ll * (x + 1) / 2;
}

int main(){
    int t; cin>>t;
    while(t--){ //O(tlogk)
        long long int k, x; cin>>k>>x;
        long long int lo = 1, hi = 2*k-1, ans = 2*k-1;
        while(lo <= hi){ //O(logk)
            long long int mid = (lo + hi) / 2;
            long long int cnt;
            if(mid >= k){
                cnt = calculateSumOfFirstX(k) + calculateSumOfFirstX(k-1) - calculateSumOfFirstX(2*k-1-mid);
            }
            else{
                cnt = calculateSumOfFirstX(mid);
            }
            if(cnt >= x){ //we get banned
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        cout << ans << endl;
    }
}

// TC = O(t * log(k))
// SC = O(1)