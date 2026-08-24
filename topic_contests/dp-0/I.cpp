#include <bits/stdc++.h>
#define ll long long
#define int long long 
using namespace std;

int n,W;
vector<int> v, w;

int f(vector<vector<int>>& dp, int i, int j){
	int& r = dp[i][j];
	if(r != -1) return r;
	if(i == 0) return r = 0;
	if(j == 0) return r = 0;
	r = f(dp,i-1,j);
	if(j>=w[i]) r = max(r, v[i] + f(dp,i-1,j-w[i]) );
	return r;
}

void slv(){
	v.clear();
	w.clear();
	v.push_back(0);
	w.push_back(0);
	for(int i = 0 ; i < n ; i++){
		int vi,wi,mi;
		cin>>vi>>wi>>mi;
		int c = 1;
		int s = 0;
		while(s + c < mi){
			s += c;
			v.push_back(c*vi);
			w.push_back(c*wi);
			c*= 2;
		}
		c = mi - s;
		if(c > 0){
			v.push_back(c*vi);
			w.push_back(c*wi);
		}
	}
	n = (int) v.size() - 1;
	vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
	cout<<f(dp,n,W)<<"\n";
}


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while(cin>>n>>W) slv();
	return 0;
}

