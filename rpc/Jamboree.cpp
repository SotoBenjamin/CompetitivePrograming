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
 

ll b[200];



signed slv() {
    int n,m; cin>>n>>m;
    ll a[n];
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    sort(a,a+n, [&](ll a,ll b){
        return a > b;
    });
    
    int j;
    for(j = 0 ; j < min(n,m) ; j++){
        b[j] += a[j];
    }

    int i = m-1;
    for(;j< n ; j++){
        b[i] += a[j];
        i--;
    }

    cout<<*max_element(b,b+m)<<"\n";


    return 0;
}

signed main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}