#include "bits/stdc++.h"
#define sz(x) (int)x.size()
#define fi first
#define se second
#define DBG(x) cout << #x << " = " << x << '\n';
#define DBGS(x) cout << #x << " = " << x << ", ";
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const ll mod = 1e9+7;
 
int nxt() {
    int x; cin >> x;
    return x;
}
 
const int inf = INT_MAX;
 
template<typename T>
T sign(T a){
	if(a > 0) return 1;
	else if(a < 0) return -1;
	return 0;
}
 
ll rec(ll x,ll y , ll k){
	if(k == 0) return x;
	
	if(x == 1){
		return x + k%(y-1);
	}
	
	
	ll t; 
	if( (x+1) % y == 0) t = 1;
	else t = y - (x+1)%y + 1;
	
	if(k < t) t = k;
		
	x += t;
	while(x%y == 0){
		x = x/y;
	}
	k -= t;
	return rec(x,y,k);
}
        
signed slv() {
	ll x,y,k; cin>>x>>y>>k;
	cout<<rec(x,y,k)<<"\n";
    return 0;
}
 
signed main(){
	freopen("b.in","r",stdin);
    int t; cin>>t;
    while(t--) slv();
    return 0;
}
