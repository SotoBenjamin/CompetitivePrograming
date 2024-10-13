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
    int x,y,z; ll k;
    scanf("%d %d %d %lld",&x,&y,&z,&k);
    ll ans = 0;
    for(int i = 1 ; i <= x ; i++){
        for(int j = 1 ; j <= y ; j++){
            if(k %(i*j) == 0){
                ll t = k/(i*j);
                ans = max(ans , (x-i+1)*(y-j+1)*(z-t+1) );
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
     
signed main(){
    int t = 1; scanf("%d",&t);
    while(t--) slv();
    return 0;
}