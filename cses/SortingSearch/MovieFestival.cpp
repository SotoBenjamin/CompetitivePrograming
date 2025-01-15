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
ll x;


void slv(){
    vpii a(n);
    for(auto&p : a) cin>>p.fi>>p.se;
    sort(all(a),[&](auto& x, auto& y){
        if (x.se != y.se){
            return x.se < y.se;
        }
        return x.fi < y.fi;
    });
    ll ans = 1;
    int limit = a[0].se;
    for(int i = 1 ; i < n ; i++){
        if(a[i].fi >= limit){
            ans++;
            limit = a[i].se;
        }
    }
    cout<<ans<<"\n";
}   
     
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    
    freopen("output.txt","w",stdout);
    #endif


    while(cin>>n) slv();
    return 0;
}