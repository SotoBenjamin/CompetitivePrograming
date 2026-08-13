#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;

ll dp[3001][3001][2];
int n;
ll a[30001];

ll f(int i,int j,int c){
	ll& r = dp[i][j][c];
	if(r != -1) return r;
	if(i == j){
		return r = c == 0 ? a[i] : -1*a[i];
	}
	r = c == 0 ? -INF : INF;
	if(c == 0)
		return r = max(a[i] + f(i+1,j,1) , a[j] + f(i,j-1,1));
	
	return r = min(-1*a[i] + f(i+1,j,0) , -1*a[j] + f(i,j-1,0));
}


void slv(){
	for(int i = 1 ; i <= n ; i++) cin>>a[i];
	memset(dp,0XFF,sizeof(dp));
	cout<<f(1,n,0)<<"\n";
}

int main(){
	while(cin >> n) slv();	
	return 0;
}
