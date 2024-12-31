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
 
int n,m,k;
ll t;

const int N = 1e6;

ll a[N];

bool go(ll k){
    ll s  = 0;
    for(int i = 0 ; i < n ; i++){
        s += k/a[i];
        if( s >= t){
            return true;
        }
    }
    return false;
}


void slv(){ 
    cin>>n>>t;
    ll l = 1 , r = 1e18;
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    ll ans;
    while( l <= r){
        ll mid = l + (r-l)/2;
        if( go(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid +1;
        }
    }

    cout<<ans<<"\n";

    
}
     
int main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}