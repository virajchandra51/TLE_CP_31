#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int k = n/2;
    long long int ans = 0;
    if(n%2 == 0){
        ans = (k+1)*(k+1);
    }
    else{
        ans = 2*(k+1)*(k+2);
    }
    cout<<ans<<endl;
    return 0;
}

// TC = O(1)
// SC = O(1)