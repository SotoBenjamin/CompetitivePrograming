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
     
const int inf = INT_MAX;
     
int n,m;     
     
signed slv() {
    scanf("%d %d",&n,&m);
    vector<string> matrix(n);
    for(int i = 0; i < n ; i++) cin>>matrix[i];
    vector<int> p(m);
    for(int i = 0 ; i < m ; i++) scanf("%d",&p[i]);
    
    ll ans = 0;
    for(int j = 0 ; j < m ; j++){
        map<char,ll> mp;
        for(int i = 0 ; i  < n ; i++){
            mp[matrix[i][j]]++;
        }
        ll t = -1;
        for(auto & p : mp){
            // DBG(p.fi);
            // DBG(p.se);
            t = max(t,p.se);
        }
        // DBG(t);
        // DBG(p[j]);
        ans += p[j]*t;
        // DBG(ans);
        // cout<<endl;
    }

    printf("%lld\n",ans);
    return 0;
    
}
     
signed main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}