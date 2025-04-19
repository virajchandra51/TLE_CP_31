#include <bits/stdc++.h>

using namespace std;

long long lcm(long long num1, long long num2) {
    return (num1 * num2) / (gcd(num1, num2)); //? a * b = gcd(a, b) * lcm(a, b)

    //? O(log(min(a, b))) -> O(log(N))
}

long long calculateSum(long long start, long long end) {
    long long sum = ((start + end) * (end - start + 1)) / 2; //? O(1)

    return sum;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        long long n, x, y;
        cin>>n>>x>>y;

        long long count1 = (n / x) - (n / lcm(x, y)); //? O(log N)
        long long count2 = (n / y) - (n / lcm(x, y)); //? O(log N)

        long long ans = calculateSum(n - count1 + 1, n) - calculateSum(1LL, count2); //? O(1)

        cout<<ans<<endl;
    }
}

//? Total time complexity : O(t * (log N))
//? Space complexity : O(t)