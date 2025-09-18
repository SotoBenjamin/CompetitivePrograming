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
 * https://atcoder.jp/contests/dp/tasks/dp_a
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

void slv(){
	//dbg(n);
	int h[n];
	for(int i = 0 ; i < n ; i++) cin>>h[i];
	int dp[n];
	dp[0] = 0;
	dp[1] = abs(h[1] - h[0]);
	for(int i = 2 ; i < n ; i++){
		dp[i] = min(abs(h[i] - h[i-2]) + dp[i-2] , abs(h[i] - h[i-1]) + dp[i-1]);
	}
	cout<<dp[n-1]<<"\n";
}
     
int main(){
    //int t = 1; //cin>>t;
   #ifndef ONLINE_JUDGE
	 freopen("input.txt","r",stdin);    	
	 freopen("output.txt","w",stdout);
   #endif
    while(cin>>n) {
		slv();
    }
    return 0;
}
