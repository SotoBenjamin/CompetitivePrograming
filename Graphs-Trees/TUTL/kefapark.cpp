#include <bits/stdc++.h>
#include <cmath>
#include <iterator>
#include <string>
#define sz(x) (int)x.size()
#define fi first
#define se second
#define dbg(x) cout << #x << " = " << x << '\n';
#define DBGS(x) cout << #x << " = " << x << ", ";
#define all(x) x.begin() , x.end()
using namespace std;


/*
 * Link:
 * https://codeforces.com/problemset/problem/580/C
 * 
 * */

 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vpll;

const int MAX = (int) 2e5+5;
vector<int> adj[MAX];
int n;
int m;

int dp[MAX];
int cnt[MAX];
int p[MAX];
int c[MAX];

vector<int> leafs;
vector<int> topo_sort;

void dfs(int u){
    bool ok = 0;
    for(int v : adj[u]){
		if( v != p[u] ){
			ok = 1;
			p[v] = u;
			dfs(v);
		}
	}
	if(!ok){
		leafs.push_back(u);
	}
	topo_sort.push_back(u);
}

bool f(int u){
	int curr = u;
	vector<int> v;
	while(p[curr] != curr){
		v.push_back(curr);
		curr = p[curr];
	}
	v.push_back(0);
	reverse(all(v));
	int cnt = 0;
	int ans = 0;
	if(c[v[0]]) {cnt = 1; ans = 1;}
	for(int i = 1 ; i < sz(v) ; i++){
		if(c[v[i]]){
			cnt++;
		}
		else{
			ans = max(ans,cnt);
			cnt = 0;
		}
	}
	ans = max(ans,cnt);
	return ans <= m;
}


void slv(){
    cin>>m;
    for(int i = 0 ; i < n ; i++) cin>>c[i];
    for(int i = 0 ; i < n-1 ; i++){
		int u,v; cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);
	reverse(all(topo_sort));
	dp[0] = 0;
	cnt[0] = 0;
	if(c[0]){
		dp[0] = 1;
		cnt[0] = 1; 
	}
	for(int u : topo_sort){
		if(u == 0) continue;
		if(c[u]){
			int prev = p[u];
			cnt[u] = cnt[prev] + 1;
			dp[u] = max(dp[prev] , cnt[u]);
		}
		else{
			int prev = p[u];
			dp[u] = max(dp[prev] , cnt[prev]);
			cnt[u] = 0;
		}
	}
	int ans = 0;
	for(int i : leafs){
		if(dp[i] <= m) ans++;
		//dbg(i);
		//dbg(dp[i]);
	}
	
	cout<<ans<<"\n";
	//cout<<"-------"<<"\n";
}
     
int main(){
    //int t = 1; //cin>>t;
    #ifndef ONLINE_JUDGE
	 freopen("input.txt","r",stdin);    
	 freopen("output.txt","w",stdout);
   #endif
    while(cin>>n) {
		for(int i = 0 ; i < n ; i++) {
			adj[i].clear();
			p[i] = i;
			dp[i] = -1;
		}
		leafs.clear();
		topo_sort.clear();
		slv();
    }
    return 0;
}
