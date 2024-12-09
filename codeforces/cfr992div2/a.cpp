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
	int n,k; cin>>n>>k;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin>>v[i];
        v[i] = v[i] % k;
    }

    map<int,int> mp;

    for(int i = 0 ; i < n ; i++) mp[v[i]]++;

    for(int i = 0 ; i < n ; i++){
        
        if( mp[v[i]] == 1){
            cout<<"YES"<<"\n";
            cout<<(i+1)<<"\n";
            return;
        }
    
    }

    cout<<"NO"<<"\n";
}
 
signed main(){
    freopen("a.in","r",stdin);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}