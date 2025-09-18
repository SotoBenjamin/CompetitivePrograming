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
 * https://atcoder.jp/contests/dp/tasks/dp_c
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
int a[MAX][3];
int dp[MAX][3];
int n;

int f(int i,int k){
	// f(i,a) = max points considerando 
	// los dias 1...i siendo la actividad del dia
	//i acttividad k
	if(dp[i][k] != -1){
		return dp[i][k];
	}
	
	if(i == 0){
		return a[0][k];
	}
	for(int j = 0 ; j < 3 ; j++){
		if(j == k) continue;
		dp[i][k] = max(dp[i][k], a[i][k] + f(i-1,j));
	}
	return dp[i][k];
}

void slv(){
	for(int i = 0 ; i < n ; i++){
		for(int k = 0 ; k < 3 ; k++) {cin>>a[i][k]; dp[i][k] = -1;}
	}
	int ans = max(f(n-1,0),f(n-1,1));
	ans = max(ans, f(n-1,2));
	cout<<ans<<"\n";
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
