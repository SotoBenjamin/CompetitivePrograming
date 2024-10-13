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
     
     
signed slv() {
    int n; scanf("%d",&n);
    vector<ll> v(n);
    for(int i = 0 ; i < n ; i++) scanf("%lld",&v[i]);
    ll s=0;
    ll t = -1;
    for(int i = 0 ; i < n ; i++) {s+=v[i]; t = max(t,v[i]);} 
    if( s%2 == 0 && 2*t <= s){
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}
     
signed main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}