#include <bits/stdc++.h>
#define ll long long int

#define all(x) x.begin(),x.end()

const int MAXN = 2e5 + 5;

using namespace std;

int n;

void slv(){
    cin>>n;
	vector<int> a(n+1) , dp(n+1);
	for(int i = 1 ; i <= n ; i++) cin>>a[i];
	dp[0] = 0;
	map<int,vector<int>> ids;
	for(int i = 1 ; i <= n ; i++) ids[a[i]].push_back(i);
	for(int i = 1 ; i <= n ; i++){
		dp[i] = dp[i-1];
		int e = a[i];
		int j = 0;
		int p = (int) distance(ids[e].begin(),lower_bound(all(ids[e]),i));
		if(p >= a[i]-1) j = ids[e][p - a[i] + 1];
		if(j != 0) dp[i] = max(dp[i],e + dp[j-1]);
	}
	cout<<dp[n]<<"\n";
	
}

signed main(){
	int t = 1; cin>>t;
	while(t--) slv(); 
	return 0;
}
