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



signed slv(){ 
    int n,x; scanf("%d %d",&n,&x);
    ll s = 0;
    ll ans = -1;
    for(int i = 0 ;i < n ; i++){
        int item; cin>>item;
        s += item;
        ans = max(ans,ll(item));
    }

    ans = max(ans,(s+x-1)/x);
    printf("%lld\n",ans);

    return 0;
}
     
signed main(){
    int t = 1; scanf("%d",&t);
    while(t--) slv();
    return 0;
}