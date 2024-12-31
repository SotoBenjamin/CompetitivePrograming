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
 
 
 
 
 
int n;
void slv(){ 
    cin>>n;
    ll a[n+1];
    a[0] = 0;
    for(int i = 1 ; i <= n ; i++) cin>>a[i];
    ll pref[n+1];
    pref[0] = 0;
    for(int i = 1 ; i <= n ; i++) pref[i] = pref[i-1] + a[i];
    ll ans = INT64_MIN;
    for(int i = 1 ; i <= n ; i++){
        ll s1 = pref[i] - pref[0];
        ll s2 = pref[n] - pref[i];
        ans = max(ans , abs(s1) + s2);

    }
    cout<<ans<<"\n";
}
     
int main(){
    freopen("c.in" , "r" , stdin);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}