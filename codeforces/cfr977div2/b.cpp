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
    int n; cin>>n;
    ll x; cin>>x;
    vector<int> v(n,0);
    
    for(int i = 0 ; i < n ; i++){
        int item; cin>>item;
        if(item >= n) continue;
        v[item]++;
    }
    vector<int> mods(n,0);
    for(int i = 0 ; i < n ; i++){
        if(v[i] == 0){
            if( mods[i%x] >=  1){
                mods[i%x] --;
            }
            else{
                cout<<(i)<<"\n";
                return 0;
            }
        }
        else if (v[i] >= 2){
            mods[i%x] += (v[i] -1);
        }
    }
    

    cout<<n<<"\n";

    return 0;
}
     
signed main(){
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}