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
    int n,k; scanf("%d %d",&n,&k);
    vector<int> v;
    map<int,int> mp;
    for(int i = 0 ; i < n ; i++){
        int item; cin>>item;
        mp[item]++;
        if( mp[item] == 1) v.push_back(item);
    } 
    sort(v.begin() , v.end());
    int m = v.size();

    int l = 0 , r = 1;
    ll current = mp[v[0]];
    ll ans = -1;
    while( r < m){
        if( v[r] != v[r-1] + 1){
            ans = max(ans,current);
            current = mp[v[r]];
            l = r;
            r++;
            continue;
        }
        if( r - l >= k){
            ans = max(ans,current);
            current -= mp[v[l]];
            current += mp[v[r]];
            l++;
            r++;
            continue;
        }
        current += mp[v[r]];
        r++;
    }
    ans = max(ans,current);

    printf("%lld\n",ans);

    return 0;
}
     
signed main(){
    int t = 1; scanf("%d",&t);
    while(t--) slv();
    return 0;
}