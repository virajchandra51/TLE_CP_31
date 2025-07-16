#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n; cin>>n;
    vector<int> a(n);
    vector<int> counts(1e6+1, 0); // O(1e6)
    int sum = 0;
    for(int i = 0; i < n; i++) { //O(n)
        cin >> a[i];
        counts[a[i]]++;
        sum += a[i];
    }

    vector<int> answers;
    for(int i = 0; i < n; i++) { //O(n)
        int newSum = sum - a[i];
        counts[a[i]]--;
        if(newSum%2==0 and (newSum/2)<=1e6 and counts[newSum/2]>0) {
            answers.push_back(i+1);
        }
        counts[a[i]]++; 
    }
    cout<< answers.size() << endl;
    for(int i : answers) cout << i << " "; //O(n)
    cout << endl;
}

// TC = O(n + 1e6)
// SC = O(n + 1e6)