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
     
     
     
signed slv() {
    string s,t;
    cin>>s>>t;
    int n = min(sz(s),sz(t));
    for(int i = 0 ; i < n ; i++){
        if( s[i] != t[i] ){
            cout<<(i+1)<<"\n";
            return 0;
        }
    }

    if( sz(s) == sz(t)){
        cout<<0<<"\n";
        return 0;
    }

    

    cout<<(n+1)<<"\n";

    return 0;
}
     
signed main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}