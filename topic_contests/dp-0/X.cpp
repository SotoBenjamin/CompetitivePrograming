#include <bits/stdc++.h>
#define ll long long
#define INF 1e18 
using namespace std;

int n;
ll dp[405][405];
ll a[405];
ll f(int i,int j){
	ll& r = dp[i][j];
	if(r != -1) return r;
	if(i >= j) return r = 0;
	r = INF;
	ll s = 0;
	for(int k = i ; k <= j ; k++) s += a[k];
	for(int k = i ; k <= j ; k++) r = min(r , f(i,k) + f(k+1,j) + s);
	return r;
}



void slv(){
	for(int i = 1 ; i <= n ; i++) cin>>a[i];
	memset(dp,0XFF,sizeof(dp));
	cout<<f(1,n)<<"\n";
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while(cin>>n) slv();
	return 0;
}


