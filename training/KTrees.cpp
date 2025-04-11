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
typedef vector<pair<int,int>> vpii;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vpll;
     
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
int t,n;
const int MAX= 2e5 + 1;
ll fact[MAX];
 
void factorial(){
    fact[0] = 1;
    for(ll i = 1 ; i < MAX ; i++){
        fact[i] = ( fact[i-1] * i ) % cc;
    }
}
 
ll f(int n , vl& coins){
    ll dp[n+1];
    dp[0] = 1;
    for(int i = 1 ; i <= n ; i++){
        ll x = 0;
        for(int j = 0 ; j < sz(coins) ; j++){
            if( i >= coins[j] ){
                x  = (x + dp[i - coins[j]]) % mod;
            }
        }
        dp[i] = x;
    }
    return dp[n];
}
 
 
void slv(){
    int n,k,d; cin>>n>>k>>d;
    vector<ll> coins1 , coins2;
    for(int i = 1 ; i <= k ; i++) {
        coins1.push_back(i);
        if( i < d)coins2.push_back(i);
    }
    ll x1 = f(n,coins1);
    ll x2 = f(n,coins2);
    ll ans = ((x1 - x2) % mod + mod ) % mod;
    cout<<ans<<"\n";
}   
     
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    
    freopen("output.txt","w",stdout);
    #endif
    t = 1;
    //cin>>t;
    while(t--) slv();
    return 0;
}