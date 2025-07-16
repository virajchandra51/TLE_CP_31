#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin >> t;
    while(t--){
        int n, w; 
        cin >> n >> w;
        vector<int> a(n);
        for(int i = 0; i < n; i++) { //O(n)
            cin >> a[i];
        }
        vector<int> widthCount(21, 0); 
        for(int i = 0; i < n; i++) { //O(n * log(a[i]))
            int logVal = log2(a[i]);
            widthCount[logVal]++;
        }
        int height = 0;
        int countOfUsedBoxes = 0;
        while(countOfUsedBoxes<n){ // O(n * log(a[i]))
            int temp = w;
            for(int i = 20; i >= 0; i--) {
                while(widthCount[i] > 0 && (1 << i) <= temp) {
                    temp -= (1 << i);
                    widthCount[i]--;
                    countOfUsedBoxes++;
                }
            }
            height++;
        }
        cout << height << endl;
    }
}

// TC = O(n * log(a[i]))
// SC = O(n)