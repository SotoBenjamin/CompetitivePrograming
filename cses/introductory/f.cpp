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


const int N = 2e5;
ll p[N];

signed slv(){ 
    //setIO("a");
    ll x,y; cin>>x>>y;
    ll mx1;
    if(x % 2 == 0) mx1 = x*x - (y-1); 
    else mx1 = (x-1)*(x-1)  + y;

    if(y % 2 == 0) mx1 = max(mx1 , (y-1)*(y-1) + x);
    else mx1 = max(mx1, y*y - x +1);

    cout<<mx1<<"\n";   

    return 0;
}
     
signed main(){
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}