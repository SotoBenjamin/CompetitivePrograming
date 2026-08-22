#include <bits/stdc++.h>
#define ll long long
#define INF 1e18;
using namespace std;
const int MAX = 2e5 + 5;
int n,m;

ll dp[MAX][2];

vector<int> a;
vector<int> b;
ll f(int i, int op){
	ll &r = dp[i][op];
	if(r != -1) return r;
	if(i == 1){
		return r = op;
	}
	r = INF;
	if(op == 1){
		if((a[i] + 1 + a[i-1]) % 2 == b[i-1]) r = min(r, 1 + f(i-1,0));
		else r = min(r, 1 + f(i-1,1));
		return r;
	}
	if((a[i] + a[i-1]) % 2 == b[i-1]) r = min(r,f(i-1,0));
	else r = min(r, f(i-1,1));
	return r;
}

void slv(){
	a.assign(n+1,0);
	b.assign(n+1,0);
	for(int i = 1 ; i <= n ; i++) cin>>a[i];
	for(int i = 1 ; i <= n-1 ; i++) cin>>b[i];
	memset(dp,0XFFFF,sizeof(dp));
	cout<<min(f(n,1),f(n,0))<<"\n";
}

int main(){
	while(cin >> n >> m) slv();
	return 0;
}
