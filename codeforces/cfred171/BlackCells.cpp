#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define fi first
#define se second
#define DBG(x) cout << #x << " = " << x << '\n';
#define DBGS(x) cout << #x << " = " << x << ", ";
#define all(x) x.begin() , x.end()
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
T minV(T a){
    return a;
}
 
template<typename T, typename ... Args>
T minV(T a , Args... arg){
    T b = minVariadic(arg...);
    return min(a,b);
}
 
 
 
void slv(){ 
	int n; cin>>n;
	vector<ll> v(n+5);
	for(int i = 1 ; i <= n ; i++) cin>>v[i];
	if(n == 1){
		cout<<1<<"\n";
		return;
	}
	
	
	if(n%2 == 0){
		ll ans = 0;
		for(int i = 2 ; i <= n ; i+=2) ans = max(ans,v[i]-v[i-1]);
		cout<<ans<<"\n";
		return;
	}
	
	v[0] = 0;
	v[n+1] = 1e18 +5;
	ll ans = 1e18+5;
	for(int i = 1 ; i <= n	; i+=2){
		if(v[i] - 1 <= v[i-1] && v[i+1] -1 <= v[i] ) continue;
		ll x = 0;
		for(int j = 2 ; j <= i-1 ; j += 2) x = max(x,v[j]-v[j-1]);
		for(int j = i+2 ; j <= n ; j+=2 ) x = max(x,v[j]-v[j-1]);
		ans = min(ans,x);	
	}
	
	cout<<ans<<"\n";	
}
     
int main(){
	//freopen("b.in" , "r" , stdin);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}

