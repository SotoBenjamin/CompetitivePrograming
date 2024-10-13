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


template<typename T>
T minV(T a){
    return a;
}

template<typename T, typename ... Args>
T minV(T a , Args... arg){
    T b = minVariadic(arg...);
    return min(a,b);
}


int n,k;

signed slv(){ 
    cin>>n>>k;
    vector<vector<char>> g(n,vector<char>(n));
    for (int i = 0; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>g[i][j];
        }
    }
    
    

    for(int i = 0 ; i < n ; i+=k){
        for(int j = 0 ; j < n ; j+=k){
            cout<<g[i][j];
        }
        cout<<"\n";
    }

    return 0;
}
     
signed main(){
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}