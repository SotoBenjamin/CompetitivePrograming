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
 
ll f(ll k , ll a , ll b){
    // a = l1
    // b = r2
    ll ans = 0;
    ll i = a;
    while(i <= b){
        i *= k;
        ans++;
    }
    return ans-1;
}

ll g(ll k , ll a , ll b){
    // a = r1
    // b = l2
    ll ans = 0;
    ll i = a;
    while( true ){
        if( i >= b){
            break;
        }
        i *= k;
        ans++;
    }
    return ans;
}


ll f1(ll l , ll  r , ll k , ll r2){
    ll ans;
    while( l <= r){
        ll mid = l + (r- l)/2;
        if( mid * k <= r2){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return ans;
}

ll f2(ll l , ll r, ll k , ll l2){
    ll ans;
    while( l <= r){
        ll mid = l + (r- l)/2;
        if( mid * k >= l2){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
}



void slv(){ 
    ll k,l1,r1,l2,r2;
    cin>>k>>l1>>r1>>l2>>r2;
    ll nl = g(k,r1,l2);
    ll nr = f(k,l1,r2);
    ll ans = 0;
    ll fi = powl(k,nl);
    for(ll i = nl ; i <= nr ; i++){
        ll l = f2(l1,r1,fi,l2);
        ll r = f1(l1,r1,fi , r2);
        ans += (r-l)+1;
        fi *= k;
    }
    cout<<ans<<"\n";

}
     
int main(){
    //freopen("b.in" , "r" , stdin);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}