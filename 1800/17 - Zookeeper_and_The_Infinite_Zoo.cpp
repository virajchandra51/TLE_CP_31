#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--){
		int x,y;cin >> x >> y;
		int z=0;
		bool ok=(x<=y);
		for(int i=0; i<30 ;i++){
			if((x>>i)&1) z++;
			if((y>>i)&1) z--;
			if(z<0) ok=false;
		}
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
}