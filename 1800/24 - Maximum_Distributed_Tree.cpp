#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long LL;

struct H{int x, y;};

int ii, n;
const int q = 1e9 + 7;
LL p[100005], pv[100005], vi[100005], w[100005];
H e[200040];

int C(H a, H b){return a.x < b.x;}
int G(LL a, LL b){return a > b;}

LL dfs(int v)
{
    LL d = 1;

    vi[v] = 1;

    for(int i = pv[v]; i < pv[v+1]; i++)
	if(!vi[e[i].y])
	    d += dfs(e[i].y);

    w[ii] = d * (n - d);
    ii++;

    return d;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    for(;t--;)
    {
	int k = 0, m;
	LL x = 1;

	cin >> n;

	for(int i = 0; i < n - 1; i++)
	{
	    cin >> e[i].x >> e[i].y;
	    e[i + n - 1].x = e[i].y;
	    e[i + n - 1].y = e[i].x;
	}

	int sz = 2 * n - 2;

	sort(e, e + sz, C);

	for(int i = 1; i < sz; i++)
	{
	    if(e[i].x > e[i - 1].x)
	    {
		for(int j = e[i - 1].x + 1; j <= e[i].x; j++)
		    pv[j] = i;
	    }
	}
	for(int j = e[sz - 1].x + 1; j <= n + 2; j++)
	    pv[j] = sz;

	ii = k = 0;
	dfs(1);

	cin >> m;

	for(int i = 0; i < m; i++)
	    cin >> p[i];

	sort(p, p + m, G);
	sort(w, w + n - 1, G);

	if(m < n)
	    for(int i = m; i < n - 1; i++)
		p[i] = 1;
	else
	{
	    int i;

	    for(i = m - 1; i > m - n; k = i, i--)
		w[i] = w[i - m + n - 1];

	    for(; i; i--)
		w[i] = w[0];
	}

	int l = max(m, n - 1);
	
	int i;
	for(i = 0, x = w[0]; i <= k; i++)
	    x = x * p[i] % q;

	for(;i < l; i++)
	    x = (x + w[i] * p[i]) % q;

	cout << x << endl;

	for(int i = 1; i <= n; i++)
	    vi[i] = 0;
    }
}