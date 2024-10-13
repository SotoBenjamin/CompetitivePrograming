#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define fi first
#define se second
#define DBG(x) cout << #x << " = " << x << '\n';
#define DBGS(x) cout << #x << " = " << x << ", ";
#define all(x) x.begin() , x.end()
using namespace std;

typedef long long int ll;
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


int n,h;


bool go(vector<int> &a , vector<int> &c , ll k){
    ll current = 0;
    for(int i = 0 ; i < n ; i++){
        ll t = (k - 1)/c[i];
        current += (t+1)*a[i];
        if( current >= h) return true;
    }
    return false;
}


signed slv(){ 
    scanf("%d %d",&h,&n);
    vector<int> a(n),c(n);
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    for(int i = 0 ; i < n ; i++) scanf("%d",&c[i]);
    ll l = 1 , r = 2e13;
    ll ans = 0;
    while(l <= r){
        ll mid = l + (r-l)/2;
        if( go(a,c,mid)){
           ans = mid; 
           r = mid - 1;
        }
        else{
           l = mid + 1;
        }
    }
    // printf("%d\n",go(a,c,1));

    printf("%lld\n",ans);

    return 0;
}
     
signed main(){
    int t = 1; scanf("%d",&t);
    while(t--) slv();
    return 0;
}