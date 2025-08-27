#include <bits/stdc++.h>
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

const int MAX = 2e5 + 5;

int n,m;

int c[MAX];

int parent[MAX];
ll  sz[MAX];


void init(int N){
    for(int i = 0 ; i < N ; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int x){
    if( x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
bool same(int a,int b){
    return find(a) == find(b);
}

void unite(int a,int b){
    a = find(a);
    b = find(b);
    if( sz[a] < sz[b] ) swap(a,b);
    sz[a] += sz[b];
    parent[b] = a;
}



void slv(){
   cin>>n>>m;
   init(n);
   vpii a(m);
   for(int i = 0 ; i < m ; i++){
        int u,v; cin>>u>>v;
        u--;v--;
        a[i] = {u,v};
   }
   for(int i = 0 ; i < n ; i++) cin>>c[i];

    for(auto [u,v] : a){
        if( c[u] != c[v]){
            unite(u,v);
        }
    }

    for(auto [u,v] : a){
        if( c[u] == c[v] && same(u,v)){
            cout<<"Yes"<<"\n";
            return;
        }
    }
    cout<<"No"<<"\n";
    return;
}


     
int main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}
