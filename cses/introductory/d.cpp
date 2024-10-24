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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
const int N = 2e5;
ll p[N];

signed slv(){ 
    //setIO("a");
    int n; cin>>n;
    for(int i = 0 ; i < n ; i++) cin>>p[i];
    ll cnt = 0;
    for(int i = 1 ; i < n ; i++){
        if(p[i] >= p[i-1]) continue;
        cnt += (p[i-1] - p[i]);
        p[i] = p[i-1];
    }
    cout<<cnt<<"\n";
    return 0;
}
     
signed main(){
    int t = 1; 
    while(t--) slv();
    return 0;
}