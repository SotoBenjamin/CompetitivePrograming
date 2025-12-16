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
 * https://codeforces.com/problemset/problem/813/C
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

int dp[MAX];
int p[MAX];

int dfs(int u){
    bool ok = 0;
	int ans = 0;
	for(int v : adj[u]){
		if(v != p[u]){
            ok = 1;
			p[v] = u;
			ans = max(ans,dfs(v));
		}
	}
    if(!ok){
        dp[u] = 0;
        return dp[u];
    }
	dp[u] = 1 + ans;
	return dp[u];
}

void slv(){
    int x; cin>>x;
    x--;
    for(int i = 0 ; i < n-1 ; i++){
		int u,v;  cin>>u>>v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);
	int curr = x;
	vector<int> a;
	while(p[curr] != curr){
		a.push_back(curr);
		curr = p[curr];
	}
	a.push_back(0);
	reverse(all(a));
	int l = 0 , r = sz(a) - 1;
	ll ans = 2*(dp[x] + sz(a) - 1);
	while(r - l >= 1){
		ans = max(ans , (ll)  2*l + 2 * (r-l + dp[a[r]]) );
		r--;
		l++;
	}
	cout<<ans<<"\n";
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
			dp[i] = 0;
		}
		slv();
    }
    return 0;
}
