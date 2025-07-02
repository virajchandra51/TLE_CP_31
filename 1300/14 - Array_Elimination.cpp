#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        map<int,int> mp;
        for(int i = 0; i < n; i++){ //O(nlogai)
            int temp; cin>>temp;
            for(int j = 0; j<31; j++){
                if(temp & (1 << j)){
                    mp[j]++;
                }
            }
        }
        int gcd = 0;
        int f = 1;
        for(auto i : mp){ // log(ai)*log(n)
            f = 0;
            if(gcd == 0){
                gcd = i.second;
            }else{
                gcd = __gcd(gcd, i.second);
            }
        }
        if(f){
            for(int i = 0; i < n; i++){ //O(n)
                cout<<i+1<<" ";
            }
            cout<<"\n";
            continue;
        }

        vector<int> factors;
        for(int i = 1; i*i <= gcd; i++){ //O(sqrt(n))
            if(gcd % i == 0){
                factors.push_back(i);
                if(i != gcd/i) // To avoid adding the square root twice
                factors.push_back(gcd/i);
            }
        }
        sort(factors.begin(), factors.end());
        for(int f : factors){ //O(n)
            cout << f << " ";
        }
        cout << "\n";
    }
}

// TC = O(nloga_i)
// SC = O(loga_i+cubeRoot(n))