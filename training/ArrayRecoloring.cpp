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
int t,n;


void slv(){
    int k;
    cin>>n>>k;
    ll a[n];
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    if( k == 1){
        ll ans = 0;
        for(int i = 0 ; i < n ; i++){
            if( i == 0){
                ans = max(ans,a[i] + a[n-1]);
            }
            else if( i == n-1){
                ans = max(ans , a[i] + a[0]);
            }
            else{
                ans = max(ans , max(a[i]+a[0],a[i]+ a[n-1]) );
            }
        }
        cout<<ans<<"\n";
        return;
    }
    ll ans = 0;
    sort(a,a+n, greater<ll>());

    for(ll& i : a) cout<<i<<" ";
    cout<<"\n";
    
    for(int i = 0 ; i < k+1 ; i++){
        ans += a[i];
    }
    cout<<ans<<"\n";

}   
     
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    
    freopen("output.txt","w",stdout);
    #endif
    t = 1; cin>>t;
    while(t--) slv();
    return 0;
}