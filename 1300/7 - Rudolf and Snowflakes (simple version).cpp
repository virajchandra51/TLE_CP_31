#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;

    // Precompute the results for all possible values of n
    vector<int> isPossible(1e6+1, 0);
    for(long long int i = 2; i <= 10000; i++){ //10^4
        long long int current = i*i*i;
        long long int current1 = (current-1)/(i-1);
        while (current1 <= 1e6){ // logn
            isPossible[current1] = 1;
            current *= i;
            current1 = (current-1)/(i-1);
        }
    }

    while(t--){ //O(t)
        int n; cin>>n;
        if(isPossible[n]){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}

// TC = (t + 10^4*logn)
// SC = O(n)