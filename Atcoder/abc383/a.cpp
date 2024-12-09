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
    int ans = 0;
    int prev = -1;
    for(int i = 0 ;i < n ; i++){
        int t,v; cin>>t>>v;
        if( prev == -1){
            ans += v;
        }
        else{
            ans -= (t-prev);
            ans = max(ans,0);
            ans += v;
            
        }
        prev = t;
    }
    cout<<ans<<"\n";
    return 0;
}
 
signed main(){
    //freopen("a.in","r",stdin);
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}