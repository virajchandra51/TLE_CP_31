#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) { //? (O(t * (N log N)))
        int n;
        cin>>n;

        long long arr[n];

        for(int i = 0; i < n; i++) cin>>arr[i]; //? O(N)

        long long ans = 0;

        for(int i = 1; i <= 60; i++) { //! 2^1 -> 2^60
            //? O(60) -> O(1)

            set<long long> distinctVals;
            long long k = 1LL << i; //? O(1)

            for(int ind = 0; ind < n; ind++) {
                distinctVals.insert(arr[ind] % k); //? O(log N)
            } //? O(N log N)

            if(distinctVals.size() == 2) {
                ans = k;
                break;
            }
        } //? O(N log N)

        cout<<ans<<endl;
    }

}

//? Total time complexity -> O(t * (N log N))
//? Total space complexity -> O(t * N)