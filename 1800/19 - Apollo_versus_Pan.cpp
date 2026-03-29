#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int N = 500 * 1000 + 7;
const int P = 60;
const int MX = 1e9 + 7;

int n;
LL in[N];
int cnt[P];

void solve(){
	scanf("%d", &n);
	for(int i = 0; i < P; ++i)
		cnt[i] = 0;
	
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &in[i]);
		for(int j = 0; j < P; ++j)
			cnt[j] += in[i] >> j & 1;
	}
	
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		LL exp_or = 0, exp_and = 0;
		for(int j = 0; j < P; ++j){
			if(in[i] >> j & 1){
				exp_or += (1LL << j) % MX * n;
				exp_and += (1LL << j) % MX * cnt[j];
			}
			else
				exp_or += (1LL << j) % MX * cnt[j];
		}
		
		exp_and %= MX, exp_or %= MX;
		ans = (ans + 1LL * exp_or * exp_and) % MX;
	}
	
	printf("%d\n", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}