#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <vector>
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
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vpll;
     
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
int t;
int n;

int f(vpii &v , int t){
    int l = 0 , r = sz(v) - 1;
    int idx = 0;
    while(l <= r){
        int m = (l+r)/2;
        if( v[m].fi <= t){
            idx = m;
            l = m+1;
        }
        else{
            r = m-1;
        }
    }
    return idx;
}


int g(vpii& v , int t){
    int l = 0 , r = sz(v) - 1;
    int idx = 0;
    while(l <= r){
        int m = (l+r)/2;
        if( v[m].se >= t){
            idx = m;
            r = m-1;
        }
        else{
            l = m+1;
        }
    }
    return idx;
}

void slv(){
    cin>>n;
    vi a(n);
    for(int& i : a) cin>>i;
    vpii v;
    int l=0;
    for(int i = 1 ; i < n ; i++){
        if( a[i] != a[i-1]){
            v.push_back({l,i-1});
            l = i;
        }   
    }
    v.push_back({l,n-1});

    // for(auto& i : v){
    //     cout<<i.fi<<" "<<i.se<<"\n";
    // }
    // cout<<"\n";
    int q; cin>>q;
    while(q--){
        int x,y; cin>>x>>y;
        int i = f(v,x-1);
        int j = g(v,y-1);
        if( i == j){
            cout<<-1<<" "<<-1<<"\n";
            continue;
        }
        cout<<(x)<<" "<<(v[i+1].fi+1)<<"\n";
    }
    //cout<<"\n";
}   
     
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    
    freopen("output.txt","w",stdout);
    #endif

    cin>>t;
    while(t--) slv();
    
    return 0;
}