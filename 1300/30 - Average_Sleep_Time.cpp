#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin>>n>>k;
    vector<int> v(n, 0);
    long long total_sum = 0;
    for(int i = 0; i<n; i++){ //o(n)
        cin>>v[i];
    }
    long long sum = 0;
    for(int i = 0; i < k; i++){ //O(k)
        sum += v[i];
    }
    total_sum = sum;
    int p1 = 0, p2 = k;
    while(p2 < n){ //O(n-k)
        sum -= v[p1];
        sum += v[p2];
        total_sum += sum;
        p1++;
        p2++;
    }
    cout << fixed << setprecision(6) << 1.0 * total_sum / (n - k + 1) << endl;
}

// TC = O(n+k)
// SC = O(n)