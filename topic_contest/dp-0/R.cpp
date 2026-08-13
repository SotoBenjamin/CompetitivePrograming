#include <bits/stdc++.h>
#define ll long long
const ll INF  = 1e18;
using namespace std;
const int MAX = (1<<15) + 5;

ll dp[MAX][15];
ll c[15][15];
int n,m;

vector<int> bits(int mask){
	vector<int> ans;
	for(int i = 0 ; i < 15 ; i++) if( mask & (1<<i) ) ans.push_back(i); 
	return ans;
}

ll f(int mask,int j){
	ll& r = dp[mask][j];
	if(r != -1) return r;
	r = INF;
	vector<int> b = bits(mask);
	if(b.size() == 2) return r = c[0][j];
	
	for(auto& k : b){
		if(k != 0 && k != j){
			ll sub = f(mask & ~(1<<j) , k);
			if(sub != INF && c[k][j] != INF) r = min(r,sub + c[k][j]);
		}
	}
	return r;
}

void slv(){
	for(int i = 0 ; i < 15 ; i++)
		for(int j = 0 ; j < 15 ; j++) c[i][j] = INF;
	
	
	for(int i = 0 ; i < m ; i++){
		int u,v,d; cin >> u >> v >> d;
		c[u][v] = min(c[u][v] ,(ll) d);
	}
	
	
	memset(dp,0XFF,sizeof(dp));
	ll ans = INF;
	
	for(int i = 1 ; i < n ; i++){
		ll x = f((1<<n) - 1,i);
		if(x == INF) continue;
		if(c[i][0] == INF) continue;
		ans = min(ans , x + c[i][0]); 
	}
	if(ans == INF){
		cout<<-1<<"\n";
		return;
	}
	cout<<ans<<"\n";
}



int main(){
	while(cin>>n>>m) slv();
	return 0;
}
