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
     
int n;     
ll k;

bool go(vector<ll> &v , ll t){
    ll k_c = 0;
    int mid = (n-1)/2;
    if( t <= v[mid]) return true;
    for(int i = mid ; i < n ; i++){
        if( v[i] >= t){
            break;
        }
        k_c += (t-v[i]);
        
    }

    return k_c <= k;
}

signed slv(){ 
    scanf("%d %lld",&n,&k);
    vector<ll> v(n);
    for(int i = 0 ; i < n ; i++) scanf("%lld",&v[i]);
    sort(all(v));
    ll l = 0 , r = k + v[(n-1)/2] + 5;
    ll ans = -1;
    while(l <= r){
        ll mid = (l+r)/2;
        if(go(v,mid)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    printf("%lld\n",ans);

    return 0;
    
}
     
signed main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}