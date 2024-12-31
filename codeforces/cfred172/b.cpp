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
 
 

int ceildiv(int n , int  k){
    return (n+k-1)/k;
}
 
        
void slv() {
    int n; cin>>n;
    map<int,int> f;
    for(int i = 0 ; i < n ; i++){
        int item; cin>>item;
        f[item]++;
    }
    int cnt1 = 0;
    int s = 0;
    for(auto& p : f){
        if(p.second == 1){
            cnt1++;
        }
        else{
            s++;
        }
    }

    ll ans = ceildiv(cnt1,2)*2  + s;
    cout<<ans<<"\n";

}
 
int main(){
    freopen("b  .in","r",stdin);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}