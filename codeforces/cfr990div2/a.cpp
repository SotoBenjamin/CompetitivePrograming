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
 



        
signed slv() {
	int n; cin>>n;
    ll x;
    ll s = 0;
    ll a = 1;
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        cin>>x;
        s += x;
        ll k = sqrtl(s);
        if( s == k*k && k % 2 == 1){
            ans++;
        }
    }
    
    cout<<ans<<"\n";

    return 0;
}
 
signed main(){
    //freopen("a.in","r",stdin);
    int t; cin>>t;
    while(t--) slv();
    return 0;
}