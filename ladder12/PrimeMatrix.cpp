#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <vector>
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
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vpll;
typedef vector<pair<int,int>> vpii;

const ll mod = 1e9+7;
const ll cc =  998244353;
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
int t,n,m;
const ll MAX= 1e5 + 5;

vector<bool> is_prime(MAX+1,true);
vector<ll> primes;

void compute(){
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= MAX; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= MAX; j += i)
                is_prime[j] = false;
        }
    }
    for(ll i = 2 ; i <= MAX ; i++){
        if(is_prime[i]) primes.push_back(i);
    }
}

void slv(){
    cin>>n>>m;
    ll a[n][m];
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++) cin>>a[i][j];

    ll ans = INT64_MAX;
    for(int i = 0 ; i < n ; i++){
        ll x = 0;
        for(int j = 0 ; j < m ; j++){
            ll target = a[i][j];
            auto it = lower_bound(all(primes) , target);
            if( it != end(primes)){
                x += (*it - target);
            }
        }
        ans = min(ans,x);
    }
    
    for(int j = 0 ; j < m ; j++){
        ll x = 0;
        for(int i = 0 ; i < n ; i++){
            ll target = a[i][j];
            auto it = lower_bound(all(primes) , target);
            if( it != end(primes)){
                x += (*it - target);
            }
        }
        ans = min(ans,x);
    }
    cout<<ans<<"\n";
    
}   
     
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    
    freopen("output.txt","w",stdout);
    #endif
    t = 1;
    compute();
    //cin>>t;
    while(t--) slv();
    return 0;
}