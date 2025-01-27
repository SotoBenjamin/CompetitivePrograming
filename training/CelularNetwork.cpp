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
int t;
int n,m;

void slv(){
    cin>>m;
    vl a(n),b(m);
    for(ll& i : a) cin>>i;
    for(ll&i : b) cin>>i;
    sort(all(b));
    ll ans  = INT64_MIN;
    for(ll&  i : a){
        auto it = lower_bound(all(b) , i);
        if(it == end(b)){
            it--;
            ans = max(ans,abs(i-*it));
            continue;
        }
        if (it == begin(b)){
            ans = max(ans,abs(i-*it));
            continue;
        }
        auto ft = it;
        ft--;
        ans = max(ans, min(abs(i-*it) , abs(i-*ft)));
    }
    cout<<ans<<"\n";
}    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    
    freopen("output.txt","w",stdout);
    #endif

    while(cin>>n) slv();
    
    return 0;
}