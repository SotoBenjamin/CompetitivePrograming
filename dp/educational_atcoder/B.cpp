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
 * https://atcoder.jp/contests/dp/tasks/dp_b
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
int h[MAX];
int dp[MAX];
int n;
int k;

int f(int i){
	//f(i) : minimo costo para llegar a la piedra i
	// pudiendo venir de i-1,i-2,...i-k
	if(dp[i] != -1){
		return dp[i];
	}
	if(i == 0){
		return 0;
	}
	
	dp[i] = 1e9 + 7;
	
	for(int j = 1 ; j <= k ; j++){
		if(i-j < 0) break;
		dp[i] = min(dp[i], abs(h[i] - h[i-j]) + f(i-j));
	}
	return dp[i];
}

void slv(){
	cin>>k;
	for(int i = 0 ; i < n ; i++) cin>>h[i];
	for(int i = 0 ; i < n ; i++) dp[i] = -1;
	cout<<f(n-1)<<"\n";
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
