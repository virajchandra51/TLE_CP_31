#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, h; cin>>n>>h;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i]; //O(n)
 
    int low = 0, high = n-1, ans = 0;
    while(low<=high){ //O(n logn)
 
        int mid = (low+high)>>1;
        vector<int> temp;
        for(int i=0; i<=mid; i++) temp.push_back(v[i]);
 
        sort(temp.begin(), temp.end());
 
        int height_required = 0, p = mid;
        while(p>=0){
            height_required +=temp[p];
            p-=2;
            if(height_required>h){
                break;
            }
        }
        if(height_required>h){
            high = mid-1;
        }
        else{
            ans = mid;
            low = mid+1;
        }
 
    }
 
    cout<<ans+1<<endl;
    return 0;
}

// TC = O(nlogn)
// SC = O(n)