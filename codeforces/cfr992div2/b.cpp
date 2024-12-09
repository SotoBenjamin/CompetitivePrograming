#include "bits/stdc++.h"
#define sz(x) (int)x.size()
#define fi first
#define se second
#define DBG(x) cout << #x << " = " << x << '\n';
#define DBGS(x) cout << #x << " = " << x << ", ";
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
 



        
void slv() {
	ll n; cin>>n;
    ll k = 1;
    ll cnt = 1;
    while( k < n){
        k = (k+1)*2;
        //DBG(k);
        cnt++;
    }
    
    cout<<(cnt)<<"\n";
   
}
 
signed main(){
    freopen("b.in","r",stdin);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}