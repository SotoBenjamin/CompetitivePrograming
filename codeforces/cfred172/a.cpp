#include <bits/stdc++.h>
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
    ll k;
    int n; cin>>n>>k;
    ll a[n];
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    sort(a, a+n);



    ll s = 0;
    for(int i = n - 1 ; i >= 0 ; i--){
        //DBG(a[i]);
        s += a[i];
        if( s > k ){
            s -= a[i];
            break;
        }
    }

    cout<<(k - s)<<"\n"; 
    
}
 
int main(){
    //freopen("a.in","r",stdin);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}