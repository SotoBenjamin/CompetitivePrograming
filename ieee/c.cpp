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

const int N = 1e5+5;
ll l;
int n,m;

ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}


struct Line{
    pll dir;
    pll P0;


    Line(){}

    Line(pll _dir , pll _P0){
        dir.first = (_dir.fi)/gcd(_dir.fi,_dir.se);
        dir.second = (_dir.se)/gcd(_dir.fi,_dir.se);
        P0 = _P0;
    }

    bool operator < (Line & other){
        return this->dir.se*other.dir.fi < other.dir.se*this->dir.fi;
    }

};

bool verify(Line l1,Line l2){
    
}


signed slv(){ 
    char op;
    cin>>l>>n>>m;
    vector<Line> a(n);
    vector<Line> b(m);
    for(ll i=0;i<n;i++){
        ll x;
        cin>>op>>x;
        if (op == 'U')
            a[i] = {{x,l}, {0,0}};
        else
            a[i] ={{l,x}, {0,0}};
    }
    
    for(ll i=0;i<n;i++){
        ll x;
        cin>>op>>x;
        if (op == 'U')
            b[i] = {{l - x,-l}, {l,0}};
        else
            b[i] ={{l,-x}, {l,0}};
    }

    sort (a.begin() , a.end());
    ll shapes = 0;





    return 0;
}
     
signed main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}