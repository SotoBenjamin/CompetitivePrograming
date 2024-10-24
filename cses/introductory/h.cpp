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
    ll n; cin>>n;
    ll s = n*(n+1)/2;
    if( s&1 ) {
        cout<<"NO"<<"\n";
        return 0;
    }
    ll s1 = 0;
    vector<int> v,v2;
    int cnt =0 ;
    for(int i = n ; i >= 1 ; i--){
        if( s1 + i > s/2){
            v2.push_back(i);
            continue;
        }
        s1 += i;
        v.push_back(i);
    }
    reverse(all(v));
    reverse(all(v2));
    cout<<"YES"<<"\n";
    cout<<v.size()<<"\n";
    for(auto i : v) cout<<i<<" ";
    cout<<"\n";
    cout<<v2.size()<<"\n";
    for(auto i : v2) cout<<i<<" ";
    cout<<"\n";

    return 0;
}
     
signed main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}