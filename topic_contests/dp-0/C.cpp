#include <bits/stdc++.h>
#define ll long long 
#define INF 1e18
using namespace std;
int n;
ll a[101][101];

ll max_subarray(vector<ll>& v){
	vector<ll> dp(n+1,0);
	dp[1] = v[1];
	for(int i = 2 ; i <= n ; i++){
		dp[i] = max(v[i],v[i] + dp[i-1]);
	}
	return *max_element(dp.begin() +1 , dp.end());
}

void slv(){
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++) cin>>a[i][j];
	}
	
	vector<vector<ll>> P(n+1,vector<ll>(n+1,0));
	
	for(int j = 1 ; j <= n ; j++){
		for(int i = 1 ; i <= n ; i++){
			P[i][j] = P[i-1][j] + a[i][j];
		}
	}
	
	ll ans = -INF;
	for(int i = 1 ; i <= n ; i++){
		for(int j = i ; j <= n ; j++){
			vector<ll> v(n+1,0);
			for(int k = 1 ; k <= n ; k++) v[k] = P[j][k] - P[i-1][k];
			ans = max(ans , max_subarray(v));
		}
	}
	cout<<ans<<"\n";
}

int main(){
	while(cin >> n) slv();
	return 0;
}
