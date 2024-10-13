#include <bits/stdc++.h>
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
     
const ll mod = 1e9+7;
     
int nxt() {
    int x; cin >> x;
    return x;
}
     
const ll inf = INT64_MAX;
int n;     
ll s = 0;     
vector<ll> v(20);     

ll ans = inf;
ll s_c = 0;
void f(int i){
    if(i == n){
        ans = min(ans, max(s_c,s - s_c));
        return;
    }
    s_c += v[i];
    f(i+1);
    s_c -= v[i];
    f(i+1);
}

signed slv() {
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        ll item; cin>>item;
        s += item;
        v[i] = item;
    }
    f(0);
    cout<<ans<<"\n";

    return 0;
}
     
signed main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}