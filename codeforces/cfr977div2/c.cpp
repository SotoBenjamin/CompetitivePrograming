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
    int n,m,q; cin>>n>>m>>q;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin>>v[i];
    vector<bool> frec(n+1,0);
    vector<int> v1;
    for(int i = 0 ; i < m ; i++){
        int item ; cin>>item;
        if(frec[item] == 0){
            v1.push_back(item);
        }
        frec[item]=1;
    }
    for(int i = 0 ; i < min(n,sz(v1)) ; i++){
        if( v[i] != v1[i]){
            cout<<"TIDAK"<<"\n";
            return 0;
        }
    }

    cout<<"YA"<<"\n";
    return 0;
}
     
signed main(){
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}