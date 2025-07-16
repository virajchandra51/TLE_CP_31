#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>> t;
    while(t--){
        int n; cin >> n;
        vector<int> factors;
        for(int i = 2; i*i <= n; i++) { //O(sqrt(n))
            if(n % i != 0) continue;
            factors.push_back(i);
            n/=i;
            if(factors.size() == 2) {
                break;
            }
        }
        if(n==1 || factors.size() < 2 || n==factors[0] || n==factors[1]) {
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            cout<<factors[0]<<" "<<factors[1]<<" "<<n<<endl;
        }
    }
}

// TC = O(t * sqrt(n))
// SC = O(1)