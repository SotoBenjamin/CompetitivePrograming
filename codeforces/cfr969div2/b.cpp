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
typedef tuple<int,int,int> ti;
 
const ll mod = 1e9+7;
 
int nxt() {
    int x; cin >> x;
    return x;
}
 
const int inf = INT_MAX;
 
 
        
signed slv() {
    int l,r; cin>>l>>r;
    int ans = 0;
    for(int i=l;i<=r;i++){
        if(i%2==1) ans++;
    }
    cout<<(ans/2)<<"\n";

    return 0;
     
}
 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t=1;
    cin>>t;
    while (t--) slv();
    return 0;
}