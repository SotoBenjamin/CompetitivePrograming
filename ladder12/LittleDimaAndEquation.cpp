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


ll sum_cif(ll x){
    ll ans = 0;
    while( x > 0){
        ans += x%10;
        x = x/10;
    }
    return ans;
}

void slv(){
    ll a,b,c; cin>>a>>b>>c;
    vector<ll> ans;
    for(ll i = 1 ; i <= 81 ; i++){
        ll x = powl(i,a);
        if( x >= 1e9){
            continue;
        }
        x = x*b + c;
        if( x >= 1e9){
            continue;
        }
        if( sum_cif(x) == i){
            ans.push_back(x);
        } 
    }
    cout<<ans.size()<<"\n";
    for(ll& i : ans) cout<<i<<" ";
    cout<<"\n";
    
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