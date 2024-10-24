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
    T b = minV(arg...);
    return min(a,b);
}

vector<ll> pot(1e5+1,1);

void fill(){
    ll ans = 1;
    for(int i = 1 ; i <= 1e5 ; i++){
        ans = (ans*2)%mod;
        pot[i] = ans;
    }
}


signed slv(){ 
    int n; scanf("%d",&n);
    int a[n],b[n];
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    for(int i = 0 ; i < n ; i++) scanf("%d",&b[i]);
    
    for(int i = 0 ; i < n ; i++){
        printf("%lld\n",pot[b[i]]);
    }

    return 0;
}
     
signed main(){
    int t = 1; //cin>>t;
    fill();
    while(t--) slv();
    return 0;
}